#!/bin/bash

for i in {1..100}; do
  $TESTDIR/ej1.random.1 $((100*i)) 10000 100000 | $BINDIR/ej1 > /dev/null
done
