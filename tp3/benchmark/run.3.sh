#!/bin/bash

export KPMP=$1
export GENERADOR=$2
export BENCHDIR=$3

BENCHDIR=$3

$BENCHDIR/local.sh   2> $BENCHDIR/info.local.dat
$BENCHDIR/local.i.sh 2> $BENCHDIR/info.local.i.dat
