#!/bin/bash

BENCHDIR=$1
IMGDIR=$2

for i in 1 2 3; do
  echo $i
  $BENCHDIR/benchmark.$i.sh 2> $BENCHDIR/info.$i.dat
  gnuplot -e "datafile='$BENCHDIR/info.$i.dat'" \
          -e "outfile='$IMGDIR/grafico-$i.png'" \
          -e "titulo='Problema $i - benchmark aleatorio'" \
  $BENCHDIR/plotter.$i.gnu
#  xdg-open $IMGDIR/grafico.$i.png
  $BENCHDIR/benchmark.$i.peor.sh 2> $BENCHDIR/info.$i.peor.dat
  gnuplot -e "datafile='$BENCHDIR/info.$i.peor.dat'" \
          -e "outfile='$IMGDIR/grafico-$i-peor.png'" \
          -e "titulo='Problema $i - benchmark peor caso'" \
          $BENCHDIR/plotter.$i.peor.gnu
#  xdg-open $IMGDIR/grafico.$i.peor.png
  $BENCHDIR/benchmark.$i.mejor.sh 2> $BENCHDIR/info.$i.mejor.dat
  gnuplot -e "datafile='$BENCHDIR/info.$i.mejor.dat'" \
          -e "outfile='$IMGDIR/grafico-$i-mejor.png'" \
          -e "titulo='Problema $i - benchmark mejor caso'" \
          $BENCHDIR/plotter.$i.mejor.gnu
#  xdg-open $IMGDIR/grafico.$i.mejor.png
done
