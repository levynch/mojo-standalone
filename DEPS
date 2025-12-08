use_relative_paths = True

gclient_gn_args_file = 'build/config/gclient_args.gni'
gclient_gn_args = [
  'build_with_chromium',
  'generate_location_tags',
]

skip_child_includes = [
  'src',
]

vars = {
  'build_with_chromium': False,
  'generate_location_tags': False,

  'download_remoteexec_cfg': False,
  'rbe_instance': Str('projects/rbe-chrome-untrusted/instances/default_instance'),
  'reclient_package': 'infra/rbe/client/',
  'reclient_version': 're_client_version:0.138.0.e854224-gomaip',
  'rewrapper_cfg_project': Str(''),

  'chromium_git': 'https://chromium.googlesource.com',

  'abseil_revision': 'c54e50d9f14471146af9f1f357b3c525c2ff5bb7',
  'build_revision': '0347b49096ca873f595c8e285c9bb3e256131f42',
  'buildtools_revision': '5df641722f2e50623646d702e0046fb68c0f5ce1',
  'boringssl_git': 'https://boringssl.googlesource.com',
  'boringssl_revision': '815857bdc3ba18bc666851ac3adf69a668624a1c',
  'catapult_revision': '6fd8bbe723677254ff1130a1a416988b8b3e285e',
  'chromium_googletest_revision': '91e8a4cf5607164178e0455bbea40845c9b0d93c',
  'chromium_re2_revision': '581c1f779dffb7d5ffd4296b79736c9ce961caae',
  'chromium_testing_revision': '6bf7e8e674b4552e12d140378e4394e7970e3fbc',
  'clang_format_revision': 'c2725e0622e1a86d55f14514f2177a39efea4a0e',
  'clang_revision': 'f0aeeca2d4eea4ade7308a31bc4023fc52614332',
  'compiler_rt_revision': 'd4d5a24a5514088089ccbaebda6576da640f04e8',
  'depot_tools_revision': '8e49ae5de847360974fb5352cd23ca2794d57222',
  'fuzztest_revision': 'ba63065cba4696b712f5e16606e5a56c3918696d',
  'gn_version': 'git_revision:c5a0003bcc2ac3f8d128aaffd700def6068e9a76',
  'googletest_revision': '4fe3307fb2d9f86d19777c7eb0e4809e9694dde7',
  'libcxx_revision':       '454a561737fb62e75ba82bfae9fb07ee64acdd68',
  'libcxxabi_revision':    'de02e5d57052b3b6d5fcd76dccde9380bca39360',
  'llvm_libc_revision':    '74b25173cba70124bff5da97cc339d90c516c5f6',
  'ninja_version': 'version:3@1.12.1.chromium.4',
  're2_revision': 'e7aec5985072c1dbe735add802653ef4b36c231a',
  # siso CIPD package version.
  'siso_version': 'git_revision:0915813c4c786240e12d03aa3018c02bab4df14f',
}

deps = {
  'third_party/clang-format/script':
     Var('chromium_git') +
     '/external/github.com/llvm/llvm-project/clang/tools/clang-format.git@' +
     Var('clang_format_revision'),

  'build': '{chromium_git}/chromium/src/build.git@{build_revision}',
  'buildtools': '{chromium_git}/chromium/src/buildtools.git@{buildtools_revision}',

  'buildtools/linux64': {
    'packages': [
      {
        'package': 'gn/gn/linux-amd64',
        'version': Var('gn_version'),
      },
    ],
    'dep_type': 'cipd',
    'condition': 'host_os == "linux"',
  },

  'buildtools/mac': {
    'packages': [
      {
        'package': 'gn/gn/mac-${{arch}}',
        'version': Var('gn_version'),
      },
    ],
  },

  'buildtools/win': {
    'packages': [
      {
        'package': 'gn/gn/windows-amd64',
        'version': Var('gn_version'),
      }
    ],
    'dep_type': 'cipd',
    'condition': 'host_os == "win"',
  },

  'buildtools/reclient': {
     'packages': [
       {
         'package': Var('reclient_package') + '${{platform}}',
         'version': Var('reclient_version'),
       }
     ],
     'dep_type': 'cipd',
   },

  'testing': '{chromium_git}/chromium/src/testing.git@{chromium_testing_revision}',
  'third_party/abseil-cpp': '{chromium_git}/chromium/src/third_party/abseil-cpp@{abseil_revision}',
  'third_party/boringssl/src':
    Var('boringssl_git') + '/boringssl.git' + '@' +  Var('boringssl_revision'),
  'third_party/catapult': '{chromium_git}/catapult.git@{catapult_revision}',
  'third_party/ced/src':
    Var('chromium_git') + '/external/github.com/google/compact_enc_det.git' + '@' + 'ba412eaaacd3186085babcd901679a48863c7dd5',
  'third_party/compiler-rt/src':
    '{chromium_git}/external/github.com/llvm/llvm-project/compiler-rt.git@{compiler_rt_revision}',
  'third_party/depot_tools': '{chromium_git}/chromium/tools/depot_tools.git@{depot_tools_revision}',
  'third_party/fuzztest/src':
    Var('chromium_git') + '/external/github.com/google/fuzztest.git' + '@' + Var('fuzztest_revision'),
  'third_party/googletest':
      '{chromium_git}/chromium/src/third_party/googletest.git@{chromium_googletest_revision}',
  'third_party/googletest/src':
      '{chromium_git}/external/github.com/google/googletest@{googletest_revision}',
  'third_party/google_benchmark/src':
    Var('chromium_git') + '/external/github.com/google/benchmark.git' + '@' + '761305ec3b33abf30e08d50eb829e19a802581cc',
  'third_party/icu':
    Var('chromium_git') + '/chromium/deps/icu.git' + '@' + 'ff35c4f9df23800935ff9f34203152c6b3c7881e',
  'third_party/jsoncpp/source':
    Var('chromium_git') + '/external/github.com/open-source-parsers/jsoncpp.git'
      + '@' + '42e892d96e47b1f6e29844cc705e148ec4856448', # release 1.9.4
  'third_party/libc++/src':
      '{chromium_git}/external/github.com/llvm/llvm-project/libcxx.git@{libcxx_revision}',

  'third_party/libc++abi/src':
      '{chromium_git}/external/github.com/llvm/llvm-project/libcxxabi.git@{libcxxabi_revision}',
  'third_party/sqlite/src':
    Var('chromium_git') + '/chromium/deps/sqlite.git' + '@' + '7d348fc79216a09b864ff881d8561a6222301666',

  'third_party/llvm-build/Release+Asserts': {
    'dep_type': 'gcs',
    'bucket': 'chromium-browser-clang',
    'objects': [
      {
        # The Android libclang_rt.builtins libraries are currently only included in the Linux clang package.
        'object_name': 'Linux_x64/clang-llvmorg-22-init-14273-gea10026b-1.tar.xz',
        'sha256sum': '1ef7b1d60fb433100c27b4552b44577ab86ef5394531d1fbebc237db64a893fd',
        'size_bytes': 56552908,
        'generation': 1762971374100697,
        'condition': 'host_os == "linux" or checkout_android',
      },
      {
        'object_name': 'Linux_x64/llvmobjdump-llvmorg-22-init-14273-gea10026b-1.tar.xz',
        'sha256sum': 'ec1d88867045b8348659f7a8f677d12aa91d7d61a68603a82bad1926bf57c3b0',
        'size_bytes': 5723188,
        'generation': 1762971374436694,
        'condition': '(checkout_linux or checkout_mac or checkout_android) and host_os == "linux"',
      },
      {
        'object_name': 'Mac/clang-llvmorg-22-init-14273-gea10026b-1.tar.xz',
        'sha256sum': 'f266b79576d4fc0075e9380b68b8879ec2bc9617c973e7bdea694ec006f43636',
        'size_bytes': 54056416,
        'generation': 1762971376161293,
        'condition': 'host_os == "mac" and host_cpu == "x64"',
      },
      {
        'object_name': 'Mac/clang-mac-runtime-library-llvmorg-22-init-14273-gea10026b-1.tar.xz',
        'sha256sum': '6f2d61383a3c0ab28286e5a57b7e755eb14726bb9a73a7737b685488eae18b90',
        'size_bytes': 1010052,
        'generation': 1762971385382392,
        'condition': 'checkout_mac and not host_os == "mac"',
      },
      {
        'object_name': 'Mac/llvmobjdump-llvmorg-22-init-14273-gea10026b-1.tar.xz',
        'sha256sum': '9a282bf252e0c7ac88152844f347428e02970aa22941fb583439ce72134f0161',
        'size_bytes': 5607404,
        'generation': 1762971376526568,
        'condition': 'host_os == "mac" and host_cpu == "x64"',
      },
      {
        'object_name': 'Mac_arm64/clang-llvmorg-22-init-14273-gea10026b-1.tar.xz',
        'sha256sum': 'a7b7caf53f4e722234e85aecfdbb3eeb94608c37394672bebd074d6b2f300362',
        'size_bytes': 45184380,
        'generation': 1762971386895625,
        'condition': 'host_os == "mac" and host_cpu == "arm64"',
      },
      {
        'object_name': 'Mac_arm64/llvmobjdump-llvmorg-22-init-14273-gea10026b-1.tar.xz',
        'sha256sum': 'c5ee70e78ae5aa7a0d9b613ea5a8e21629438f12acb50bca0f7e18fae6abfe0a',
        'size_bytes': 5353832,
        'generation': 1762971387217357,
        'condition': 'host_os == "mac" and host_cpu == "arm64"',
      },
      {
        'object_name': 'Win/clang-llvmorg-22-init-14273-gea10026b-1.tar.xz',
        'sha256sum': '483b9b2809c3f53b9640e77d83ca6ab3017a0974979d242198abf23d99639e62',
        'size_bytes': 48337640,
        'generation': 1762971401378315,
        'condition': 'host_os == "win"',
      },
      {
        'object_name': 'Win/clang-win-runtime-library-llvmorg-22-init-14273-gea10026b-1.tar.xz',
        'sha256sum': 'd8b3310760c3a8f5dac4801583f7872601f4ba312742b0bf530f043ce6b6f36f',
        'size_bytes': 2520664,
        'generation': 1762971410370409,
        'condition': 'checkout_win and not host_os == "win"',
      },
      {
        'object_name': 'Win/llvmobjdump-llvmorg-22-init-14273-gea10026b-1.tar.xz',
        'sha256sum': '00c4dab7747534548e2111b3adbdbf9ef561887e18c7d6de4c7e273af799c190',
        'size_bytes': 5742908,
        'generation': 1762971401692156,
        'condition': '(checkout_linux or checkout_mac or checkout_android) and host_os == "win"',
      },
    ]
  },

  'third_party/llvm-libc/src':
    '{chromium_git}/external/github.com/llvm/llvm-project/libc.git@{llvm_libc_revision}',

  'third_party/ninja': {
    'packages': [
      {
        'package': 'infra/3pp/tools/ninja/${{platform}}',
        'version': Var('ninja_version'),
      }
    ],
    'dep_type': 'cipd',
  },
  'third_party/nasm': {
      'url': Var('chromium_git') + '/chromium/deps/nasm.git' + '@' +
      'e2c93c34982b286b27ce8b56dd7159e0b90869a2'
  },
  # Pull down Node binaries for WebUI toolchain.
  # The Linux binary is always downloaded regardless of host os and architecture
  # since remote node actions run on Linux worker.
  # See also //third_party/node/node.gni
  'third_party/node/linux': {
      'dep_type': 'gcs',
      'condition': 'non_git_source',
      'bucket': 'chromium-nodejs',
      'objects': [
          {
              'object_name': 'fa98c6432de572206bc5519f85e9c96bd518b039',
              'sha256sum': 'fb563633b5bfe2d4307075c54c6bb54664a3b5ec6bc811f5b15742720549007a',
              'size_bytes': 50288755,
              'generation': 1730835522207929,
              'output_file': 'node-linux-x64.tar.gz',
          },
      ],
  },
  # The Mac x64/arm64 binaries are downloaded regardless of host architecture
  # since it's possible to cross-compile for the other architecture. This can
  # cause problems for tests that use node if the test device architecture does
  # not match the architecture of the compile machine.
  'third_party/node/mac': {
      'dep_type': 'gcs',
      'condition': 'host_os == "mac" and non_git_source',
      'bucket': 'chromium-nodejs',
      'objects': [
          {
              'object_name': '4c8952a65a1ce7a2e4cff6db68f9b7454c46349f',
              'sha256sum': 'fadb4530fbe6e35ed298848c66102a0aa7d92974789e6222c4eadee26a381e7e',
              'size_bytes': 45672893,
              'generation': 1730835514382259,
              'output_file': 'node-darwin-x64.tar.gz',
          },
      ],
  },
  'third_party/node/mac_arm64': {
      'dep_type': 'gcs',
      'condition': 'host_os == "mac" and non_git_source',
      'bucket': 'chromium-nodejs',
      'objects': [
          {
              'object_name': '0886aa6a146cb5c213cb09b59ed1075982e4cb57',
              'sha256sum': 'd39e2d44d58bb89740b9aca1073959fc92edbdbbe810a5e48448e331cf72c196',
              'size_bytes': 44929037,
              'generation': 1730835518292126,
              'output_file': 'node-darwin-arm64.tar.gz',
          },
      ],
  },
  'third_party/node/win': {
      'dep_type': 'gcs',
      'condition': 'host_os == "win" and non_git_source',
      'bucket': 'chromium-nodejs',
      'objects': [
          {
              'object_name': '907d7e104e7389dc74cec7d32527c1db704b7f96',
              'sha256sum': '7447c4ece014aa41fb2ff866c993c708e5a8213a00913cc2ac5049ea3ffc230d',
              'size_bytes': 80511640,
              'generation': 1730835526374028,
              'output_file': 'node.exe',
          },
      ],
  },
  # Pull down NPM dependencies for WebUI toolchain.
  'third_party/node/node_modules': {
    'bucket': 'chromium-nodejs',
    'dep_type': 'gcs',
    'condition': 'non_git_source',
    'objects': [
      {
        'object_name': '98801808b75afb8221eff1c0cfbf3190363279b6',
        'sha256sum': '64e9949eb8e4cbe5c74b59aacf131942e290253bd931d1fc0af09326ceab74fd',
        'size_bytes': 9686243,
        'generation': 1760483611783891,
        'output_file': 'node_modules.tar.gz',
      },
    ],
  },
  'third_party/protobuf-javascript/src':
    Var('chromium_git') + '/external/github.com/protocolbuffers/protobuf-javascript' + '@' + 'e6d763860001ba1a76a63adcff5efb12b1c96024',

  'third_party/re2':
      '{chromium_git}/chromium/src/third_party/re2.git@{chromium_re2_revision}',
  'third_party/re2/src':
      '{chromium_git}/external/github.com/google/re2.git@{re2_revision}',

  'tools/clang': {
    'url': '{chromium_git}/chromium/src/tools/clang.git@{clang_revision}',
    'condition': 'not build_with_chromium',
  },
  'third_party/perfetto':
    Var('chromium_git') + '/external/github.com/google/perfetto.git' + '@' + '1fee17ae6961fa613d0faaedffde18d1eb80a614',
  'third_party/siso/cipd': {
    'packages': [
      {
        'package': 'build/siso/${{platform}}',
        'version': Var('siso_version'),
      }
    ],
    'condition': 'non_git_source',
    'dep_type': 'cipd',
  },

  # Update prebuilt Rust toolchain.
  'hird_party/rust-toolchain': {
    'dep_type': 'gcs',
    'bucket': 'chromium-browser-clang',
    'condition': 'not rust_force_head_revision',
    'objects': [
      {
        'object_name': 'Linux_x64/rust-toolchain-15283f6fe95e5b604273d13a428bab5fc0788f5a-1-llvmorg-22-init-8940-g4d4cb757.tar.xz',
        'sha256sum': '2bdaea0b11cb11a8f2f4dcb79b0dbb4bf38e2bd22479ff8014f55b9b6890e135',
        'size_bytes': 142044388,
        'generation': 1758743116775859,
        'condition': 'host_os == "linux" and non_git_source',
      },
      {
        'object_name': 'Mac/rust-toolchain-15283f6fe95e5b604273d13a428bab5fc0788f5a-1-llvmorg-22-init-8940-g4d4cb757.tar.xz',
        'sha256sum': '351347e1930a900c63b3953cdb10775b73572c6145e389f3820ba920816d46ca',
        'size_bytes': 135891820,
        'generation': 1758743118329536,
        'condition': 'host_os == "mac" and host_cpu == "x64"',
      },
      {
        'object_name': 'Mac_arm64/rust-toolchain-15283f6fe95e5b604273d13a428bab5fc0788f5a-1-llvmorg-22-init-8940-g4d4cb757.tar.xz',
        'sha256sum': '33d6b8cf4fc6617aa98888a46bc1dbef29ae9a9ebd01c3f248ef8c08ec5f198b',
        'size_bytes': 123302332,
        'generation': 1758743119839246,
        'condition': 'host_os == "mac" and host_cpu == "arm64"',
      },
      {
        'object_name': 'Win/rust-toolchain-15283f6fe95e5b604273d13a428bab5fc0788f5a-1-llvmorg-22-init-8940-g4d4cb757.tar.xz',
        'sha256sum': '4f6dfa230e5d401bf9aadd804142b412467177b17d50a3f52a8c69c1957aa2db',
        'size_bytes': 199998880,
        'generation': 1758743121322555,
        'condition': 'host_os == "win"',
      },
    ],
  },

  'base/tracing/test/data': {
    'bucket': 'perfetto',
    'objects': [
      {
        'object_name': 'test_data/chrome_fcp_lcp_navigations.pftrace-ae01d849fbd75a98be1b7ddd5a8873217c377b393a1d5bbd788ed3364f7fefc3',
        'sha256sum': 'ae01d849fbd75a98be1b7ddd5a8873217c377b393a1d5bbd788ed3364f7fefc3',
        'size_bytes': 2398645,
        'generation': 1697714434866488,
        'output_file': 'chrome_fcp_lcp_navigations.pftrace'
      },
      {
        'object_name': 'test_data/chrome_input_with_frame_view.pftrace-a93548822e481508c728ccc5da3ad34afcd0aec02ca7a7a4dad84ff340ee5975',
        'sha256sum': 'a93548822e481508c728ccc5da3ad34afcd0aec02ca7a7a4dad84ff340ee5975',
        'size_bytes': 6392331,
        'generation': 1711402389089075,
        'output_file': 'chrome_input_with_frame_view.pftrace'
      },
      {
        'object_name': 'test_data/scroll_offsets_trace_2.pftrace-2ddd9f78d91d51e39c72c520bb54fdc9dbf1333ae722e87633fc345159296289',
        'sha256sum': '2ddd9f78d91d51e39c72c520bb54fdc9dbf1333ae722e87633fc345159296289',
        'size_bytes': 1496388,
        'generation': 1712592637141461,
        'output_file': 'scroll_offsets_trace_2.pftrace'
      },
      {
        'object_name': 'test_data/top_level_java_choreographer_slices-8001e73b2458e94f65a606bb558a645ba5bca553b57fe416001f6c2175675a8a',
        'sha256sum': '8001e73b2458e94f65a606bb558a645ba5bca553b57fe416001f6c2175675a8a',
        'size_bytes': 5323017,
        'generation': 1671708979893186,
        'output_file': 'top_level_java_choreographer_slices'
      },
      {
        'object_name': 'test_data/chrome_page_load_all_categories_not_extended.pftrace.gz-6586e9e2bbc0c996caddb321a0374328654983733e6ffd7f4635ac07db32a493',
        'sha256sum': '6586e9e2bbc0c996caddb321a0374328654983733e6ffd7f4635ac07db32a493',
        'size_bytes': 1277750,
        'generation': 1652442088902445,
        'output_file': 'chrome_page_load_all_categories_not_extended.pftrace.gz'
      },
      {
        'object_name': 'test_data/speedometer_21.perfetto_trace.gz-8a159b354d74a3ca0d38ce9cd071ef47de322db4261ee266bfafe04d70310529',
        'sha256sum': '8a159b354d74a3ca0d38ce9cd071ef47de322db4261ee266bfafe04d70310529',
        'size_bytes': 891088,
        'generation': 1716566741068306,
        'output_file': 'speedometer_21.perfetto_trace.gz'
      },
      {
       'object_name': 'test_data/speedometer_3.perfetto_trace.gz-b2c77fbe2c17363432a1ad0c05c1c1c20d3ebc62bda92c041d39918011af6f02',
        'sha256sum': 'b2c77fbe2c17363432a1ad0c05c1c1c20d3ebc62bda92c041d39918011af6f02',
        'size_bytes': 1301036,
        'generation': 1716566914245446,
        'output_file': 'speedometer_3.perfetto_trace.gz'
      },
      {
        'object_name': 'test_data/scroll_jank_with_pinch.pftrace-8587d2016fdb5d39b5f852704b6e3925e9e6527af01696396be767bed04d4a45',
        'sha256sum': '8587d2016fdb5d39b5f852704b6e3925e9e6527af01696396be767bed04d4a45',
        'size_bytes': 3914720,
        'generation': 1717497788778335,
        'output_file': 'scroll_jank_with_pinch.pftrace'
      },
      {
        'object_name': 'test_data/cpu_powerups_1.pb-70f5511ba0cd6ce1359e3cadb4d1d9301fb6e26be85158e3384b06f41418d386',
        'sha256sum': '70f5511ba0cd6ce1359e3cadb4d1d9301fb6e26be85158e3384b06f41418d386',
        'size_bytes': 2033064,
        'generation': 1669652389509708,
        'output_file': 'cpu_powerups_1.pb'
      },
      {
        'object_name': 'test_data/chrome_5672_histograms.pftrace.gz-a09bd44078ac71bcfbc901b0544750e8344d0d0f6f96e220f700a5a53fa932ee',
        'sha256sum': 'a09bd44078ac71bcfbc901b0544750e8344d0d0f6f96e220f700a5a53fa932ee',
        'size_bytes': 1127472,
        'generation': 1684946598804577,
        'output_file': 'chrome_5672_histograms.pftrace.gz'
      },
      {
        'object_name': 'test_data/chrome_custom_navigation_trace.gz-ff68279e3cec94076b69259d756eed181a63eaf834d8b956a7f4ba665fabf939',
        'sha256sum': 'ff68279e3cec94076b69259d756eed181a63eaf834d8b956a7f4ba665fabf939',
        'size_bytes': 7572484,
        'generation': 1666713705258900,
        'output_file': 'chrome_custom_navigation_trace.gz'
      },
      {
        'object_name': 'test_data/scroll_offsets.pftrace-62101edb5204fec8bea30124f65d4e49bda0808d7b036e95f89445aaad6d8d98',
        'sha256sum': '62101edb5204fec8bea30124f65d4e49bda0808d7b036e95f89445aaad6d8d98',
        'size_bytes': 769741,
        'generation': 1693402148909129,
        'output_file': 'scroll_offsets.pftrace'
      },
      {
        'object_name': 'test_data/chrome_input_with_frame_view_new.pftrace-e901ad9577088e62c921dd8bfcb43d652ecf49fa69b5b57f81bb3d27dbe94e12',
        'sha256sum': 'e901ad9577088e62c921dd8bfcb43d652ecf49fa69b5b57f81bb3d27dbe94e12',
        'size_bytes': 1967821,
        'generation': 1719520814352733,
        'output_file': 'chrome_input_with_frame_view_new.pftrace'
      },
      {
        'object_name': 'test_data/scroll_m131.pftrace-14171c9e502a65a454f39fe14fce8b313c7012a2c14394bed496fc93b1644b0d',
        'sha256sum': '14171c9e502a65a454f39fe14fce8b313c7012a2c14394bed496fc93b1644b0d',
        'size_bytes': 1247290,
        'generation': 1729619115836875,
        'output_file': 'scroll_m131.pftrace'
      },
      {
        'object_name': 'test_data/scroll_m132.pftrace-779e1fa6cab1abc0ab2dcafa4bbbf826ea8fc052878886ab168c783ca32f3bbe',
        'sha256sum': '779e1fa6cab1abc0ab2dcafa4bbbf826ea8fc052878886ab168c783ca32f3bbe',
        'size_bytes': 1854184,
        'generation': 1732117381568969,
        'output_file': 'scroll_m132.pftrace'
      },
      {
        'object_name': 'test_data/scroll_m132_with_atrace.pftrace-b1fe189738a4a714cef7dd13b12318c89d6c4345fbe65096b4680ffa79f2872a',
        'sha256sum': 'b1fe189738a4a714cef7dd13b12318c89d6c4345fbe65096b4680ffa79f2872a',
        'size_bytes': 18887098,
        'generation': 1730148514067154,
        'output_file': 'scroll_m132_with_atrace.pftrace'
      },
      {
        'object_name': 'test_data/scroll_m133beta.pftrace-2acc70545be1caeb3fb43218ab52872c2c749b49577b973cb8400057c680fc19',
        'sha256sum': '2acc70545be1caeb3fb43218ab52872c2c749b49577b973cb8400057c680fc19',
        'size_bytes': 1448694,
        'generation': 1738338471679054,
        'output_file': 'scroll_m133beta.pftrace'
      },
      {
        'object_name': 'test_data/scroll_with_input_not_forwarded_to_renderer.pftrace-ceb2ff3cb64c99ddb28a29867bc82f1491c4b413bfacd8638551b80936240faf',
        'sha256sum': 'ceb2ff3cb64c99ddb28a29867bc82f1491c4b413bfacd8638551b80936240faf',
        'size_bytes': 729606,
        'generation': 1732902685002882,
        'output_file': 'scroll_with_input_not_forwarded_to_renderer.pftrace'
      },
    ],
    'dep_type': 'gcs'
  },
}

hooks = [
  # Download and initialize "vpython" VirtualEnv environment packages for
  # Python3. We do this before running any other hooks so that any other
  # hooks that might use vpython don't trip over unexpected issues and
  # don't run slower than they might otherwise need to.
  {
    'name': 'vpython3_common',
    'pattern': '.',
    'action': [ 'vpython3',
                '-vpython-spec', '.vpython3',
                '-vpython-tool', 'install',
    ],
  },

  {
    'name': 'sysroot_x86',
    'pattern': '.',
    'condition': 'checkout_linux and (checkout_x86 or checkout_x64)',
    'action': ['python3', 'build/linux/sysroot_scripts/install-sysroot.py',
               '--arch=x86'],
  },
  {
    'name': 'sysroot_x64',
    'pattern': '.',
    'condition': 'checkout_linux and checkout_x64',
    'action': ['python3', 'build/linux/sysroot_scripts/install-sysroot.py',
               '--arch=x64'],
  },

  {
    # Case-insensitivity for the Win SDK. Must run before win_toolchain below.
    'name': 'ciopfs_linux',
    'pattern': '.',
    'condition': 'checkout_win and host_os == "linux"',
    'action': [ 'python3',
                'third_party/depot_tools/download_from_google_storage.py',
                '--no_resume',
                '--no_auth',
                '--bucket', 'chromium-browser-clang/ciopfs',
                '-s', 'build/ciopfs.sha1',
    ]
  },

  {
    # Update the Windows toolchain if necessary.  Must run before 'clang' below.
    'name': 'win_toolchain',
    'pattern': '.',
    'condition': 'checkout_win',
    'action': ['python3', 'build/vs_toolchain.py', 'update', '--force'],
  },
  {
    # Update the Mac toolchain if necessary.
    'name': 'mac_toolchain',
    'pattern': '.',
    'condition': 'checkout_mac or checkout_ios',
    'action': ['python3', 'build/mac_toolchain.py'],
  },

  {
    # Update the Windows toolchain if necessary.  Must run before 'clang' below.
    'name': 'win_toolchain',
    'pattern': '.',
    'condition': 'checkout_win',
    'action': ['python3', 'build/vs_toolchain.py', 'update', '--force'],
  },
  {
    # Update the Mac toolchain if necessary.
    'name': 'mac_toolchain',
    'pattern': '.',
    'condition': 'checkout_mac or checkout_ios',
    'action': ['python3', 'build/mac_toolchain.py'],
  },

  # Update LASTCHANGE.
  {
    'name': 'lastchange',
    'pattern': '.',
    'action': ['python3', 'build/util/lastchange.py', '-o',
               'build/util/LASTCHANGE']
  },

  # Don't let the DEPS'd-in depot_tools self-update.
  {
    'name': 'disable_depot_tools_selfupdate',
    'pattern': '.',
    'action': [
      'python3',
      'third_party/depot_tools/update_depot_tools_toggle.py',
      '--disable',
    ],
  },

  # Configure remote exec cfg files
  {
    # Use luci_auth if on windows and using chrome-untrusted project
    'name': 'download_and_configure_reclient_cfgs',
    'pattern': '.',
    'condition': 'download_remoteexec_cfg and host_os == "win"',
    'action': ['python3',
               'buildtools/reclient_cfgs/configure_reclient_cfgs.py',
               '--rbe_instance',
               Var('rbe_instance'),
               '--reproxy_cfg_template',
               'reproxy.cfg.template',
               '--rewrapper_cfg_project',
               Var('rewrapper_cfg_project'),
               '--use_luci_auth_credshelper',
               '--quiet',
               ],
  },  {
    'name': 'download_and_configure_reclient_cfgs',
    'pattern': '.',
    'condition': 'download_remoteexec_cfg and not host_os == "win"',
    'action': ['python3',
               'buildtools/reclient_cfgs/configure_reclient_cfgs.py',
               '--rbe_instance',
               Var('rbe_instance'),
               '--reproxy_cfg_template',
               'reproxy.cfg.template',
               '--rewrapper_cfg_project',
               Var('rewrapper_cfg_project'),
               '--quiet',
               ],
  },
  {
    'name': 'configure_reclient_cfgs',
    'pattern': '.',
    'condition': 'not download_remoteexec_cfg',
    'action': ['python3',
               'buildtools/reclient_cfgs/configure_reclient_cfgs.py',
               '--rbe_instance',
               Var('rbe_instance'),
               '--reproxy_cfg_template',
               'reproxy.cfg.template',
               '--rewrapper_cfg_project',
               Var('rewrapper_cfg_project'),
               '--skip_remoteexec_cfg_fetch',
               '--quiet',
               ],
  },
  # Configure Siso for developer builds.
  {
    'name': 'configure_siso',
    'pattern': '.',
    'action': ['python3',
               'build/config/siso/configure_siso.py',
               '--rbe_instance',
               Var('rbe_instance'),
               ],
  },
  {
    # Build the rust toolchain from tip-of-tree, against tip-of-tree LLVM.
    # Note: On Win, this should run after win_toolchain, as it may use it.
    'name': 'rust_tot',
    'pattern': '.',
    'condition': 'rust_force_head_revision',
    'action': ['vpython3', 'tools/rust/build_rust.py',
               '--rust-force-head-revision',
               '--llvm-force-head-revision',
               '--entire-toolchain',
               '--skip-test'],
  },
]

