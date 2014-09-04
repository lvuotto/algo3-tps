#!/bin/bash

N=1000

for i in {1..1000}; do
  tests/ej2.random.rb 176 $N | bin/ej2 > /dev/null
  N=$((N + 1000))
done
