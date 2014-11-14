#!/bin/bash

BENCHDIR=$1
TESTDIR=$2
BINDIR=$3
IMGDIR=$4
export BENCHDIR TESTDIR BINDIR IMGDIR

#~ $BENCHDIR/benchmark.1.v.sh 2> $BENCHDIR/info.1.v.dat
#~ gnuplot -e "datafile='$BENCHDIR/info.1.v.dat'" \
#~         -e "outfile='$IMGDIR/grafico-1-v.png'" \
#~         -e "titulo='Problema 1 - benchmark aleatorio'" \
#~ $BENCHDIR/plotter.1.gnu 2>&1 > /dev/null
#~ 
#~ $BENCHDIR/benchmark.1.c.sh 2> $BENCHDIR/info.1.c.dat
#~ gnuplot -e "datafile='$BENCHDIR/info.1.c.dat'" \
#~         -e "outfile='$IMGDIR/grafico-1-c.png'" \
#~         -e "titulo='Problema 1 - benchmark aleatorio'" \
#~ $BENCHDIR/plotter.1.gnu 2>&1 > /dev/null
#~ 
#~ $BENCHDIR/benchmark.1.mejor.sh 2> $BENCHDIR/info.1.mejor.dat
#~ gnuplot -e "datafile='$BENCHDIR/info.1.mejor.dat'" \
#~         -e "outfile='$IMGDIR/grafico-1-mejor.png'" \
#~         -e "titulo='Problema 1 - benchmark mejor caso'" \
#~ $BENCHDIR/plotter.1.gnu 2>&1 > /dev/null
#~ 
#~ $BENCHDIR/benchmark.1.peor.sh 2> $BENCHDIR/info.1.peor.dat
#~ gnuplot -e "datafile='$BENCHDIR/info.1.peor.dat'" \
#~         -e "outfile='$IMGDIR/grafico-1-peor.png'" \
#~         -e "titulo='Problema 1 - benchmark peor caso'" \
#~ $BENCHDIR/plotter.1.gnu 2>&1 > /dev/null
#~ 
$BENCHDIR/benchmark.2.k.sh 2> $BENCHDIR/info.2.k.o0.dat
gnuplot -e "datafile='$BENCHDIR/info.2.k.o0.dat'" \
        -e "outfile='$IMGDIR/grafico-2-k-o0.png'" \
        -e "titulo='Problema 2 - benchmark aleatorio en caballos'" \
$BENCHDIR/plotter.2.k.gnu 2>&1 > /dev/null
#~ 
#~ $BENCHDIR/benchmark.2.n.sh 2> $BENCHDIR/info.2.n.dat
#~ gnuplot -e "datafile='$BENCHDIR/info.2.n.dat'" \
#~         -e "outfile='$IMGDIR/grafico-2-n.png'" \
#~         -e "titulo='Problema 2 - benchmark aleatorio en tamaño'" \
#~ $BENCHDIR/plotter.2.n.gnu 2>&1 > /dev/null

#~ $BENCHDIR/benchmark.3.sh 2> $BENCHDIR/info.3.dat
#~ gnuplot -e "datafile='$BENCHDIR/info.3.dat'" \
#~         -e "outfile='$IMGDIR/grafico-3.png'" \
#~         -e "titulo='Problema 3 - benchmark aleatorio'" \
#~ $BENCHDIR/plotter.3.gnu 2>&1 > /dev/null

#~ $BENCHDIR/benchmark.3.m.sh 2> $BENCHDIR/info.3.m.dat
#~ gnuplot -e "datafile='$BENCHDIR/info.3.m.dat'" \
#~         -e "outfile='$IMGDIR/grafico-3-m.png'" \
#~         -e "titulo='Problema 3 - benchmark aleatorio'" \
#~ $BENCHDIR/plotter.3.gnu 2>&1 > /dev/null

#~ $BENCHDIR/benchmark.3.dnc.sh 2> $BENCHDIR/info.3.dnc.dat
#~ gnuplot -e "datafile='$BENCHDIR/info.3.dnc.dat'" \
#~         -e "outfile='$IMGDIR/grafico-3-dnc.png'" \
#~         -e "titulo='Problema 3 - Denso no conexo'" \
#~ $BENCHDIR/plotter.3.gnu 2>&1 > /dev/null
