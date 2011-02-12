# node-microtime

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
accuracy.

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

## Tested On

    Node.js 0.2.6
      - OS X 10.6.6
      - Ubuntu 10.04

    Node.js 0.4.0
      - OS X 10.6.6
