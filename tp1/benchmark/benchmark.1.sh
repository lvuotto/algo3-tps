#!/bin/bash

N=100

for i in {1..1000}; do
  tests/ej1.random.rb $i $N 20 | bin/ej1 > /dev/null
  N=$((N + 100))
done