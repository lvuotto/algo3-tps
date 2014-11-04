#!/bin/bash

for i in {1..1000}; do
  $TESTDIR/ej3.random.rb 42 1000 $((1000 + 999*i)) 1000 | $BINDIR/ej3 > /dev/null
done
