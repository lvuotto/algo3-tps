#!/bin/bash

export KPMP=$1
export GENERADOR=$2
export BENCHDIR=$3

BENCHDIR=$3

$BENCHDIR/exacto.sh 2> $BENCHDIR/info.exacto.dat
