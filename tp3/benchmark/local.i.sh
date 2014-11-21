#!/bin/bash

for i in {10..50}; do
  $GENERADOR 41 $((10 * $i)) $((50 * $i)) $((1 + $i / 10)) > $BENCHDIR/local.41.i.tmp
  $KPMP -g -B 1 < $BENCHDIR/local.41.i.tmp >> $BENCHDIR/local.41.i.tmp 2> /dev/null
  $KPMP -B 10 -l -v intercambiar < $BENCHDIR/local.41.i.tmp
  $GENERADOR 42 $((10 * $i)) $((50 * $i)) $((1 + $i / 10)) > $BENCHDIR/local.42.i.tmp
  $KPMP -g -B 1 < $BENCHDIR/local.42.i.tmp >> $BENCHDIR/local.42.i.tmp 2> /dev/null
  $KPMP -B 10 -l -v intercambiar < $BENCHDIR/local.42.i.tmp
  $GENERADOR 43 $((10 * $i)) $((50 * $i)) $((1 + $i / 10)) > $BENCHDIR/local.43.i.tmp
  $KPMP -g -B 1 < $BENCHDIR/local.43.i.tmp >> $BENCHDIR/local.43.i.tmp 2> /dev/null
  $KPMP -B 10 -l -v intercambiar < $BENCHDIR/local.43.i.tmp
  $GENERADOR 44 $((10 * $i)) $((50 * $i)) $((1 + $i / 10)) > $BENCHDIR/local.44.i.tmp
  $KPMP -g -B 1 < $BENCHDIR/local.44.i.tmp >> $BENCHDIR/local.44.i.tmp 2> /dev/null
  $KPMP -B 10 -l -v intercambiar < $BENCHDIR/local.44.i.tmp
  $GENERADOR 45 $((10 * $i)) $((50 * $i)) $((1 + $i / 10)) > $BENCHDIR/local.45.i.tmp
  $KPMP -g -B 1 < $BENCHDIR/local.45.i.tmp >> $BENCHDIR/local.45.i.tmp 2> /dev/null
  $KPMP -B 10 -l -v intercambiar < $BENCHDIR/local.45.i.tmp
done

rm -f local.*.i.tmp
