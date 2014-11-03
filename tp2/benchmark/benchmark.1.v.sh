#!/bin/bash

for i in {1..200}; do
  $TESTDIR/ej1.random.rb 1 $((100*i)) $((1000*i)) 100000 | $BINDIR/ej1 > /dev/null
done
