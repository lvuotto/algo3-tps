#!/bin/bash

N=1

for i in {1..25}; do
  tests/ej3.random.rb 176 $N $((2*N)) | bin/ej3-poda-a > /dev/null
  N=$((N + 1))
done
