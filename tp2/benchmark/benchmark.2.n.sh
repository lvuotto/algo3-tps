#!/bin/bash

for i in {1..100}; do
  $TESTDIR/ej2.random.rb 13 $((10*i)) 1 | $BINDIR/ej2 > /dev/null
done
