#!/bin/bash

export KPMP=$1
export GENERADOR=$2
export BENCHDIR=$3

BENCHDIR=$3

$BENCHDIR/greedy.sh    2> $BENCHDIR/info.greedy.dat
$BENCHDIR/greedy.a.sh  2> $BENCHDIR/info.greedy.a.dat
$BENCHDIR/greedy.c.sh  2> $BENCHDIR/info.greedy.c.dat
$BENCHDIR/greedy.ac.sh 2> $BENCHDIR/info.greedy.ac.dat
