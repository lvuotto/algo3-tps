#!/bin/bash

N=1

for i in {1..30}; do
  tests/ej3.random.rb 176 $N $((1000 * N)) | bin/ej3 > /dev/null
  N=$((N + 1))
done
