# node-microtime

[![Travis Build](https://img.shields.io/travis/wadey/node-microtime.svg?label=linux,%20os%20x)](https://travis-ci.org/wadey/node-microtime)
[![AppVeyor Build](https://img.shields.io/appveyor/ci/WadeSimmons/node-microtime.svg?label=windows)](https://ci.appveyor.com/project/WadeSimmons/node-microtime)
[![npm](https://img.shields.io/npm/dm/microtime.svg)](https://www.npmjs.com/package/microtime)
[![npm](https://img.shields.io/npm/v/microtime.svg)](https://www.npmjs.com/package/microtime)

Date.now() will only give you accuracy in milliseconds. This module calls
`gettimeofday(2)` to get the time in microseconds and provides it in a few
different formats. The same warning from that function applies:
_The resolution of the system clock is hardware dependent, and the time may
be updated continuously or in ``ticks.''_

# Installation

    npm install microtime

# Usage

### microtime.now()

Get the current time in microseconds as an integer. Since JavaScript can only
represent integer values accurately up to `Math.pow(2, 53)`, this value will
be accurate up to _Tue, 05 Jun 2255 23:47:34 GMT_.

### microtime.nowDouble()

Get the current time in seconds as a floating point number with microsecond
accuracy (similar to `time.time()` in Python and `Time.now.to_f` in Ruby).

### microtime.nowStruct()

Get the current time and return as a list with seconds and microseconds (matching the return value of `gettimeofday(2)`).

# Example

    > var microtime = require('microtime')
    > microtime.now()
    1297448895297028
    > microtime.nowDouble()
    1297448897.600976
    > microtime.nowStruct()
    [ 1297448902, 753875 ]

## Estimating clock resolution

Starting with version 0.1.3, there is a test script that tries to guess the clock resolution. You can run it with `npm test microtime`. Example output:

    microtime.now() = 1298960083489806
    microtime.nowDouble() = 1298960083.511521
    microtime.nowStruct() = [ 1298960083, 511587 ]

    Guessing clock resolution...
    Clock resolution observed: 1us

## Warning for Cygwin users

It appears that Cygwin only implements `gettimeofday(2)` with [millisecond accuracy](http://old.nabble.com/gettimeofday---millisecond-accuracy-p21085475.html).
