#!/bin/bash

N=1

for i in {1..50}; do
  tests/ej2.random.rb 176 $N $((2 * N)) | bin/ej1 > /dev/null
  N=$((N + 1))
done
