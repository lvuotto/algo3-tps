#!/bin/bash

for i in {5..30}; do
  $GENERADOR 41 $i $(($i * $i / 5)) $((i / 3)) | $KPMP -B 10 -e
  $GENERADOR 42 $i $(($i * $i / 5)) $((i / 3)) | $KPMP -B 10 -e
  $GENERADOR 43 $i $(($i * $i / 5)) $((i / 3)) | $KPMP -B 10 -e
  $GENERADOR 44 $i $(($i * $i / 5)) $((i / 3)) | $KPMP -B 10 -e
  $GENERADOR 45 $i $(($i * $i / 5)) $((i / 3)) | $KPMP -B 10 -e
done
