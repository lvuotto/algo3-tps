#!/bin/bash

for i in {10..100}; do
  $GENERADOR 41 $((10 * $i)) $((100 * $i)) $((1 + $i / 10)) > $BENCHDIR/local.41.tmp
  $KPMP -g -B 1 < $BENCHDIR/local.41.tmp >> $BENCHDIR/local.41.tmp 2> /dev/null
  $KPMP -B 10 -l < $BENCHDIR/local.41.tmp
  $GENERADOR 42 $((10 * $i)) $((100 * $i)) $((1 + $i / 10)) > $BENCHDIR/local.42.tmp
  $KPMP -g -B 1 < $BENCHDIR/local.42.tmp >> $BENCHDIR/local.42.tmp 2> /dev/null
  $KPMP -B 10 -l < $BENCHDIR/local.42.tmp
  $GENERADOR 43 $((10 * $i)) $((100 * $i)) $((1 + $i / 10)) > $BENCHDIR/local.43.tmp
  $KPMP -g -B 1 < $BENCHDIR/local.43.tmp >> $BENCHDIR/local.43.tmp 2> /dev/null
  $KPMP -B 10 -l < $BENCHDIR/local.43.tmp
  $GENERADOR 44 $((10 * $i)) $((100 * $i)) $((1 + $i / 10)) > $BENCHDIR/local.44.tmp
  $KPMP -g -B 1 < $BENCHDIR/local.44.tmp >> $BENCHDIR/local.44.tmp 2> /dev/null
  $KPMP -B 10 -l < $BENCHDIR/local.44.tmp
  $GENERADOR 45 $((10 * $i)) $((100 * $i)) $((1 + $i / 10)) > $BENCHDIR/local.45.tmp
  $KPMP -g -B 1 < $BENCHDIR/local.45.tmp >> $BENCHDIR/local.45.tmp 2> /dev/null
  $KPMP -B 10 -l < $BENCHDIR/local.45.tmp
done
