#!/bin/bash

BENCHDIR=$1
TESTDIR=$2
BINDIR=$3
IMGDIR=$4
export BENCHDIR TESTDIR BINDIR IMGDIR

$BENCHDIR/benchmark.3.sh 2> $BENCHDIR/info.3.dat
gnuplot -e "datafile='$BENCHDIR/info.3.dat'" \
        -e "outfile='$IMGDIR/grafico-3.png'" \
        -e "titulo='Problema 3 - benchmark aleatorio'" \
$BENCHDIR/plotter.3.gnu 2>&1 > /dev/null

$BENCHDIR/benchmark.3.m.sh 2> $BENCHDIR/info.3.m.dat
gnuplot -e "datafile='$BENCHDIR/info.3.m.dat'" \
        -e "outfile='$IMGDIR/grafico-3-m.png'" \
        -e "titulo='Problema 3 - benchmark aleatorio'" \
$BENCHDIR/plotter.3.m.gnu 2>&1 > /dev/null
