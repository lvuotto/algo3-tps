#!/bin/bash

N=100

for i in {1..2000}; do
  tests/ej2.peor.rb 176 $N | bin/ej2 > /dev/null
  N=$((N + 100))
done
