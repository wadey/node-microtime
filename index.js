var binding

//
// Try catch here around multiple build paths to support
// `node@0.4.x` and `node@0.6.x`.
// (from https://github.com/indexzero/daemon.node)
//
try { binding = require('./build/default/microtime') }
catch (ex) { binding = require('./build/Release/microtime') }

exports.now = binding.now
exports.nowDouble = binding.nowDouble
exports.nowStruct = binding.nowStruct
