# node-microtime

[![npm](https://img.shields.io/npm/dm/microtime.svg)](https://www.npmjs.com/package/microtime)
[![npm](https://img.shields.io/npm/v/microtime.svg)](https://www.npmjs.com/package/microtime)

Date.now() will only give you accuracy in milliseconds. This module calls
`gettimeofday(2)` to get the time in microseconds and provides it in a few
different formats. The same warning from that function applies:
_The resolution of the system clock is hardware dependent, and the time may
be updated continuously or in ``ticks.''_

## N-API Support

As of version `3.0.0`, this library is built using the [N-API](https://nodejs.org/api/n-api.html) library. This should allow you to upgrade to newer versions of Node.js without having to reinstall / rebuild this library.

Version `3.0.0` and later also bundle prebuilt binaries for common systems in
the npm package itself. These will be used if the version of Node you are using
supports N-API ([>= v6.14.2](https://nodejs.org/api/n-api.html#n_api_n_api_version_matrix)), otherwise the binary will be recompiled on install.

# Installation

    npm install microtime

# Usage

### microtime.now()

Get the current time in microseconds as an integer.

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
