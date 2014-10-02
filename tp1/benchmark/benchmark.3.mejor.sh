#!/bin/bash

N=1

for i in {1..25}; do
  tests/ej3.random.rb 176 $N $((1000000 * N)) | bin/ej3 > /dev/null
  N=$((N + 1))
done
