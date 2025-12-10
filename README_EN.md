# Chromium Base Library

This is an experimental project aimed at extracting the Mojo module from Chromium to use it as a standalone cross-platform IPC communication library. The project includes Chromium's base library and Mojo-related components.

## Version Information

- **Chromium Tag**: 143.0.7490.0
- **Chromium Revision**: ba1244a6ca103fa348994c5a6d078dbe4ed96e4b

## Installation Steps

### 1. Install System Dependencies (Linux)

On Ubuntu/Debian systems, install the following dependencies first:

```bash
sudo apt-get update
sudo apt-get install -y pkg-config libfuse2
```

### 2. Get depot_tools

Install [`depot_tools`](https://commondatastorage.googleapis.com/chrome-infra-docs/flat/depot_tools/docs/html/depot_tools_tutorial.html#_setting_up) and make sure it's in your PATH.

### 3. Sync Dependencies

Then from within the repository root:

```bash
gclient sync
```

This will automatically download all required third-party dependencies and toolchains.

### 4. Generate Build Files

Use GN (Generate Ninja) to generate build files:

```bash
# Generate Debug build configuration
gn gen out/Debug

# Generate Release build configuration
gn gen out/Release --args='is_debug=false'
```

### 5. Build the Project

Use Ninja to compile:

```bash
# Build Debug version
ninja -C out/Debug mojo_unittests

# Build Release version
ninja -C out/Release mojo_unittests
```

## Build Configuration Options

You can customize build configuration with `--args` parameter:

```bash
# View all available build arguments
gn args out/Debug --list

# Custom build configuration example
gn gen out/Custom --args='
  is_debug=false
  is_component_build=true
  use_goma=false
'
```

## Running Tests

```bash
# Build and run all tests
ninja -C out/Debug base_unittests
out/Debug/base_unittests

# Run specific tests
out/Debug/base_unittests --gtest_filter=TestName.*
```

## More Information

- [Chromium Build Documentation](https://chromium.googlesource.com/chromium/src/+/main/docs/README.md)
- [Windows Build Instructions](https://chromium.googlesource.com/chromium/src/+/main/docs/windows_build_instructions.md)
- [GN Reference](https://gn.googlesource.com/gn/+/main/docs/reference.md)
- [Ninja Build System](https://ninja-build.org/)
