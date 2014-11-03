#!/bin/bash

for i in {1..1000}; do
  $TESTDIR/ej3.random.rb 42 $((100*i)) $((200*i)) 1000 | $BINDIR/ej3 > /dev/null
done
