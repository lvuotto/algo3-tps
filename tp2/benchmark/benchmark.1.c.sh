#!/bin/bash

for i in {1..200}; do
  $TESTDIR/ej1.random.rb 1 $((10*i)) 10000 1000 | $BINDIR/ej1 > /dev/null
done
