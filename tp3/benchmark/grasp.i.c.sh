#!/bin/bash

for i in {10..50}; do
  $GENERADOR 41 $((10 * $i)) $((50 * $i)) $((1 + $i / 20)) | $KPMP -B 10 -G -v intercambiar -r conjuntos
  $GENERADOR 42 $((10 * $i)) $((50 * $i)) $((1 + $i / 20)) | $KPMP -B 10 -G -v intercambiar -r conjuntos
  $GENERADOR 43 $((10 * $i)) $((50 * $i)) $((1 + $i / 20)) | $KPMP -B 10 -G -v intercambiar -r conjuntos
  $GENERADOR 44 $((10 * $i)) $((50 * $i)) $((1 + $i / 20)) | $KPMP -B 10 -G -v intercambiar -r conjuntos
  $GENERADOR 45 $((10 * $i)) $((50 * $i)) $((1 + $i / 20)) | $KPMP -B 10 -G -v intercambiar -r conjuntos
done
