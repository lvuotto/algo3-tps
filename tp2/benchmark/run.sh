#!/bin/bash

BENCHDIR=$1
TESTDIR=$2
BINDIR=$3
IMGDIR=$4
export BENCHDIR TESTDIR BINDIR IMGDIR

$BENCHDIR/benchmark.1.v.sh 2> $BENCHDIR/info.1.v.dat
gnuplot -e "datafile='$BENCHDIR/info.1.v.dat'" \
        -e "outfile='$IMGDIR/grafico-1-v.png'" \
        -e "titulo='Problema 1 - benchmark aleatorio'" \
$BENCHDIR/plotter.1.gnu

$BENCHDIR/benchmark.1.c.sh 2> $BENCHDIR/info.1.c.dat
gnuplot -e "datafile='$BENCHDIR/info.1.c.dat'" \
        -e "outfile='$IMGDIR/grafico-1-c.png'" \
        -e "titulo='Problema 1 - benchmark aleatorio'" \
$BENCHDIR/plotter.1.gnu

$BENCHDIR/benchmark.1.mejor.sh 2> $BENCHDIR/info.1.mejor.dat
gnuplot -e "datafile='$BENCHDIR/info.1.mejor.dat'" \
        -e "outfile='$IMGDIR/grafico-1-mejor.png'" \
        -e "titulo='Problema 1 - benchmark mejor caso'" \
$BENCHDIR/plotter.1.gnu

$BENCHDIR/benchmark.1.peor.sh 2> $BENCHDIR/info.1.peor.dat
gnuplot -e "datafile='$BENCHDIR/info.1.peor.dat'" \
        -e "outfile='$IMGDIR/grafico-1-peor.png'" \
        -e "titulo='Problema 1 - benchmark peor caso'" \
$BENCHDIR/plotter.1.gnu
