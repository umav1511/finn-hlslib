#!/bin/sh
lli=${LLVMINTERP-lli}
exec $lli \
    /home/uma/Desktop/graduation_project/finn_hlslib/finn-hlslib/hls-syn-add/sol1/.autopilot/db/a.g.bc ${1+"$@"}
