#!/bin/bash

for i in {1..497}; do
  $TESTDIR/ej3.random_resoluble.rb 42 500 $((250*i)) 1000 | $BINDIR/ej3-ok > /dev/null
done
