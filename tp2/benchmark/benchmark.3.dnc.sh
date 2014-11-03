#!/bin/bash

for i in {1..200}; do
  $TESTDIR/ej3.random_denso_desconexo.rb 42 $((100*i)) 1000 | $BINDIR/ej3 > /dev/null
done
