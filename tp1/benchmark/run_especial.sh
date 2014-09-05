#!/bin/bash

BENCHDIR=$1
IMGDIR=$2

$BENCHDIR/benchmark.1.c.sh 2> $BENCHDIR/info.1.c.dat
gnuplot -e "datafile='$BENCHDIR/info.1.c.dat'" \
        -e "outfile='$IMGDIR/grafico-1-c.png'" \
        -e "titulo='Problema 1 - benchmark aleatorio'" \
        $BENCHDIR/plotter.1.c.gnu
