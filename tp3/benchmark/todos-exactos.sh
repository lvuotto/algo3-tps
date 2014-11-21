#!/bin/bash

export KPMP=$1
export GENERADOR=$2
export BENCHDIR=$3

BENCHDIR=$3

for k in {1..5}; do
  for i in {10..25}; do
    $BENCHDIR/exacto.sh 2> $BENCHDIR/todos.exacto.dat
