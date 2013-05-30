var microtime = require('./index')

console.log('microtime.now() =', microtime.now())
console.log('microtime.nowDouble() =', microtime.nowDouble())
console.log('microtime.nowStruct() =', microtime.nowStruct())

console.log('\nGuessing clock resolution...')

var start = microtime.now()
  , minDiff = Infinity
  , minCycles = 10000
  , maxCycles = 100000
  , cycles = maxCycles

for (var i = 0; i < cycles; ++i) {
  var a = microtime.now()
    , b = microtime.now()
    , diff = (b - a) || (b - start)

  if (diff > 0 && diff < minDiff) {
    minDiff = diff
    cycles = minCycles
  }
}

if (minDiff === Infinity) {
  console.log("Unable to guess clock resolution")
} else {
  console.log("Clock resolution observed: " + minDiff + "us")
}
