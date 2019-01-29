{
  'targets': [
    {
      'target_name': 'microtime',
      'sources': [ 'src/microtime.cc' ],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      'conditions': [
        ['OS=="mac"',
          {
            'xcode_settings': {
              # https://github.com/nodejs/node/pull/23685#issuecomment-430408541
              'MACOSX_DEPLOYMENT_TARGET': '10.9',
            },
          }
        ]]
    }
  ]
}
