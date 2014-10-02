#!/bin/bash

BENCHDIR=$1
IMGDIR=$2

$BENCHDIR/benchmark.1.c.sh 2> $BENCHDIR/info.1.c.dat
gnuplot -e "datafile='$BENCHDIR/info.1.c.dat'" \
        -e "outfile='$IMGDIR/grafico-1-c.png'" \
        -e "titulo='Problema 1 - benchmark aleatorio'" \
        $BENCHDIR/plotter.1.c.gnu

$BENCHDIR/benchmark.3.poda.sh 2> $BENCHDIR/info.3.poda.dat
gnuplot -e "datafile='$BENCHDIR/info.3.poda.dat'" \
        -e "outfile='$IMGDIR/grafico-3-poda.png'" \
        -e "titulo='Problema 3 - poda (orden descendente)'" \
        $BENCHDIR/plotter.3.gnu

$BENCHDIR/benchmark.3.poda.a.sh 2> $BENCHDIR/info.3.poda.a.dat
gnuplot -e "datafile='$BENCHDIR/info.3.poda.a.dat'" \
        -e "outfile='$IMGDIR/grafico-3-poda-a.png'" \
        -e "titulo='Problema 3 - poda (orden ascendente)'" \
        $BENCHDIR/plotter.3.gnu

$BENCHDIR/benchmark.3.poda.p.sh 2> $BENCHDIR/info.3.poda.p.dat
gnuplot -e "datafile='$BENCHDIR/info.3.poda.p.dat'" \
        -e "outfile='$IMGDIR/grafico-3-poda-p.png'" \
        -e "titulo='Problema 3 - poda (promedio, orden descendente)'" \
        $BENCHDIR/plotter.3.gnu

$BENCHDIR/benchmark.3.poda.a.p.sh 2> $BENCHDIR/info.3.poda.a.p.dat
gnuplot -e "datafile='$BENCHDIR/info.3.poda.a.p.dat'" \
        -e "outfile='$IMGDIR/grafico-3-poda-a-p.png'" \
        -e "titulo='Problema 3 - poda (promedio, orden ascendente)'" \
        $BENCHDIR/plotter.3.gnu
