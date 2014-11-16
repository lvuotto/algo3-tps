#!/bin/bash

export KPMP=$1
export GENERADOR=$2
export BENCHDIR=$3

BENCHDIR=$3

$BENCHDIR/exacto.sh > $BENCHDIR/info.exacto.dat
$BENCHDIR/greedy.sh > $BENCHDIR/info.greedy.dat
$BENCHDIR/local.sh > $BENCHDIR/info.local.dat
$BENCHDIR/grasp.sh > $BENCHDIR/info.grasp.dat
