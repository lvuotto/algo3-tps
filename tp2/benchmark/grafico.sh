#!/bin/bash

BENCHDIR=$1
TESTDIR=$2
BINDIR=$3
IMGDIR=$4
export BENCHDIR TESTDIR BINDIR IMGDIR

gnuplot -e "datafile='$BENCHDIR/info.1.v.dat'" \
        -e "outfile='$IMGDIR/grafico-1-v.png'" \
        -e "titulo='Problema 1 - benchmark aleatorio'" \
$BENCHDIR/plotter.1.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.1.c.dat'" \
        -e "outfile='$IMGDIR/grafico-1-c.png'" \
        -e "titulo='Problema 1 - benchmark aleatorio'" \
$BENCHDIR/plotter.1.c.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.1.mejor.dat'" \
        -e "outfile='$IMGDIR/grafico-1-mejor.png'" \
        -e "titulo='Problema 1 - benchmark mejor caso'" \
$BENCHDIR/plotter.1.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.1.peor.dat'" \
        -e "outfile='$IMGDIR/grafico-1-peor.png'" \
        -e "titulo='Problema 1 - benchmark peor caso'" \
$BENCHDIR/plotter.1.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.2.k.dat'" \
        -e "outfile='$IMGDIR/grafico-2-k.png'" \
        -e "titulo='Problema 2 - benchmark aleatorio en caballos'" \
$BENCHDIR/plotter.2.k.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.2.k.volatile.dat'" \
        -e "outfile='$IMGDIR/grafico-2-k-volatile.png'" \
        -e "titulo='Problema 2 - benchmark aleatorio en caballos'" \
$BENCHDIR/plotter.2.k.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.2.n.dat'" \
        -e "outfile='$IMGDIR/grafico-2-n.png'" \
        -e "titulo='Problema 2 - benchmark aleatorio en tamaño'" \
$BENCHDIR/plotter.2.n.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.3.dat'" \
        -e "outfile='$IMGDIR/grafico-3.png'" \
        -e "titulo='Problema 3 - benchmark aleatorio'" \
$BENCHDIR/plotter.3.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.3.m.dat'" \
        -e "outfile='$IMGDIR/grafico-3-m.png'" \
        -e "titulo='Problema 3 - benchmark aleatorio'" \
$BENCHDIR/plotter.3.m.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.3.dnc.dat'" \
        -e "outfile='$IMGDIR/grafico-3-dnc.png'" \
        -e "titulo='Problema 3 - Denso no conexo'" \
$BENCHDIR/plotter.3.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.3.dnc.cubico.dat'" \
        -e "outfile='$IMGDIR/grafico-3-dnc-cubico.png'" \
        -e "titulo='Problema 3 - Denso no conexo'" \
$BENCHDIR/plotter.3.cubico.gnu 2>&1 > /dev/null
