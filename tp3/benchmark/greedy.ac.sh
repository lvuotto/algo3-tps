#!/bin/bash

for i in {10..100}; do
  $GENERADOR 41 $((10 * $i)) $((50 * $i)) $((1 + $i / 20)) | $KPMP -B 10 -g
  $GENERADOR 42 $((10 * $i)) $((50 * $i)) $((1 + $i / 20)) | $KPMP -B 10 -g
  $GENERADOR 43 $((10 * $i)) $((50 * $i)) $((1 + $i / 20)) | $KPMP -B 10 -g
  $GENERADOR 44 $((10 * $i)) $((50 * $i)) $((1 + $i / 20)) | $KPMP -B 10 -g
  $GENERADOR 45 $((10 * $i)) $((50 * $i)) $((1 + $i / 20)) | $KPMP -B 10 -g
done
