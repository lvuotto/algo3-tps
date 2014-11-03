#!/bin/bash

for i in {1..100}; do
  $TESTDIR/ej2.random.rb 13 500 $((10*i)) | $BINDIR/ej2 > /dev/null
done
