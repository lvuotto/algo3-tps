#!/bin/bash

N=1000

for i in {1..1000}; do
  tests/ej1.peor.rb 3476 $N 1 | bin/ej1 > /dev/null
  N=$((N + 1000))
done
