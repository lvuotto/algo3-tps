#!/bin/bash

for i in {1..1000}; do
  $TESTDIR/ej1.random.rb 1 50 $((100*i)) 1000 | $BINDIR/ej1 > /dev/null
done
