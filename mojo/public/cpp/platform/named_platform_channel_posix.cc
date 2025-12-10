// Copyright 2018 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "mojo/public/cpp/platform/named_platform_channel.h"

#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#include "base/files/file_util.h"
#include "base/files/scoped_file.h"
#include "base/logging.h"
#include "base/posix/eintr_wrapper.h"
#include "base/rand_util.h"
#include "base/strings/string_number_conversions.h"
#include "build/build_config.h"

namespace mojo {

namespace {

NamedPlatformChannel::ServerName GenerateRandomServerName(
    const NamedPlatformChannel::Options& options) {
  return options.socket_dir
      .AppendASCII(base::NumberToString(base::RandUint64()))
      .value();
}

// Simple wrapper for sockaddr_un storage
struct UnixSocketAddress {
  sockaddr_un address;
  socklen_t length;
};

// This function fills in |addr| with the appropriate data for the
// socket as well as the data's length. Returns true on success, or false on
// failure (typically because |server_name| violated the naming rules). On
// Linux and Android, setting |use_abstract_namespace| to true will return a
// socket address for an abstract non-filesystem socket.
//
// This implementation is based on net::FillUnixAddress to maintain
// compatibility after removing the //net dependency.
bool MakeUnixAddr(const NamedPlatformChannel::ServerName& server_name,
                  bool use_abstract_namespace,
                  UnixSocketAddress* addr) {
  DCHECK(addr);

  // Caller should provide a non-empty path for the socket address.
  if (server_name.empty()) {
    return false;
  }

  sockaddr_un* socket_addr = &addr->address;
  const size_t path_dest_size = sizeof(socket_addr->sun_path);

  // The length of the path, including the nul.
  const size_t path_size = server_name.size() + 1;

  // Non abstract namespace pathname should be null-terminated. Abstract
  // namespace pathname must start with '\0'. So, the size is always greater
  // than socket_path size by 1.
  if (path_size > path_dest_size) {
    return false;
  }

  // Zero out the entire address struct.
  memset(&addr->address, 0, sizeof(addr->address));
  socket_addr->sun_family = AF_UNIX;
  addr->length = path_size + offsetof(sockaddr_un, sun_path);

  if (!use_abstract_namespace) {
    // Copy the path, except the terminating '\0'. sun_path was
    // already filled with zeroes.
    memcpy(socket_addr->sun_path, server_name.data(), server_name.size());
    return true;
  }

#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
  // Convert the path given into abstract socket name. It must start with
  // the '\0' character, skip over it, as it should already be zero. addr_len
  // must specify the length of the structure exactly, as potentially the socket
  // name may have '\0' characters embedded (although we don't support this).
  memcpy(socket_addr->sun_path + 1, server_name.data(), server_name.size());
  return true;
#else
  return false;
#endif
}

// This function creates a unix domain socket, and set it as non-blocking.
// If successful, this returns a PlatformHandle containing the socket.
// Otherwise, this returns an invalid PlatformHandle.
PlatformHandle CreateUnixDomainSocket() {
  // Create the unix domain socket.
  PlatformHandle handle(base::ScopedFD(socket(AF_UNIX, SOCK_STREAM, 0)));
  if (!handle.is_valid()) {
    PLOG(ERROR) << "Failed to create AF_UNIX socket.";
    return PlatformHandle();
  }

  // Now set it as non-blocking.
  if (!base::SetNonBlocking(handle.GetFD().get())) {
    PLOG(ERROR) << "base::SetNonBlocking() failed " << handle.GetFD().get();
    return PlatformHandle();
  }
  return handle;
}

}  // namespace

// static
PlatformChannelServerEndpoint NamedPlatformChannel::CreateServerEndpoint(
    const Options& options,
    ServerName* server_name) {
  ServerName name = options.server_name;
  if (name.empty())
    name = GenerateRandomServerName(options);

  // Make sure the path we need exists.
  base::FilePath socket_dir = base::FilePath(name).DirName();
  if (!base::CreateDirectory(socket_dir)) {
    LOG(ERROR) << "Couldn't create directory: " << socket_dir.value();
    return PlatformChannelServerEndpoint();
  }

  // Delete any old FS instances.
  if (unlink(name.c_str()) < 0 && errno != ENOENT) {
    PLOG(ERROR) << "unlink " << name;
    return PlatformChannelServerEndpoint();
  }

  UnixSocketAddress addr;
  if (!MakeUnixAddr(name, options.use_abstract_namespace, &addr))
    return PlatformChannelServerEndpoint();

  PlatformHandle handle = CreateUnixDomainSocket();
  if (!handle.is_valid())
    return PlatformChannelServerEndpoint();

  // Bind the socket.
  if (bind(handle.GetFD().get(), 
           reinterpret_cast<const sockaddr*>(&addr.address), 
           addr.length) < 0) {
    PLOG(ERROR) << "bind " << name;
    return PlatformChannelServerEndpoint();
  }

  // Start listening on the socket.
  if (listen(handle.GetFD().get(), SOMAXCONN) < 0) {
    PLOG(ERROR) << "listen " << name;
    unlink(name.c_str());
    return PlatformChannelServerEndpoint();
  }

  *server_name = name;
  return PlatformChannelServerEndpoint(std::move(handle));
}

// static
PlatformChannelEndpoint NamedPlatformChannel::CreateClientEndpoint(
    const Options& options) {
  DCHECK(!options.server_name.empty());

  UnixSocketAddress addr;
  if (!MakeUnixAddr(options.server_name, options.use_abstract_namespace,
                    &addr))
    return PlatformChannelEndpoint();

  PlatformHandle handle = CreateUnixDomainSocket();
  if (!handle.is_valid())
    return PlatformChannelEndpoint();

  if (HANDLE_EINTR(connect(handle.GetFD().get(), 
                           reinterpret_cast<const sockaddr*>(&addr.address),
                           addr.length)) < 0) {
    VPLOG(1) << "connect " << options.server_name;
    return PlatformChannelEndpoint();
  }
  return PlatformChannelEndpoint(std::move(handle));
}

}  // namespace mojo
