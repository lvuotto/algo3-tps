#!/bin/bash

C=100

for i in {1..1000}; do
  tests/ej1.random.rb 0 100000 $C | bin/ej1 > /dev/null
  C=$((C + 100))
done
