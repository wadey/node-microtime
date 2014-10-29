{
  'targets': [
    {
      'target_name': 'microtime',
      'sources': [ 'src/microtime.cc' ],
      'include_dirs' : [ '<!(node -e "require(\'nan\')")' ],
      'defines': ['WINVER=0x0602']
    }
  ]
}
