#!/bin/bash

N=100

for i in {1..1000}; do
  tests/ej2.mejor.rb $N | bin/ej2 > /dev/null
  N=$((N + 100))
done
