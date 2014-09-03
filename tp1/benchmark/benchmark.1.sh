#!/bin/bash

N=1000

for i in {1..1000}; do
  tests/ej1.random.rb 176 $N 20 | bin/ej1 > /dev/null
  N=$((N + 1000))
done
