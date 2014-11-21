#!/bin/bash

BENCHDIR=$1
IMGDIR=$2

gnuplot -e "datafile='$BENCHDIR/info.exacto.dat.promedio'" \
        -e "outfile='$IMGDIR/grafico-exacto.png'" \
$BENCHDIR/plotter.exacto.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.greedy.dat.promedio'" \
        -e "outfile='$IMGDIR/grafico-greedy.png'" \
$BENCHDIR/plotter.greedy.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.greedy.a.dat.promedio'" \
        -e "outfile='$IMGDIR/grafico-greedy-a.png'" \
$BENCHDIR/plotter.greedy.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.greedy.c.dat.promedio'" \
        -e "outfile='$IMGDIR/grafico-greedy-c.png'" \
$BENCHDIR/plotter.greedy.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.greedy.ac.dat.promedio'" \
        -e "outfile='$IMGDIR/grafico-greedy-ac.png'" \
$BENCHDIR/plotter.greedy.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.local.dat.promedio'" \
        -e "outfile='$IMGDIR/grafico-local.png'" \
$BENCHDIR/plotter.local.gnu 2>&1 > /dev/null

gnuplot -e "datafile='$BENCHDIR/info.local.i.dat.promedio'" \
        -e "outfile='$IMGDIR/grafico-local-i.png'" \
$BENCHDIR/plotter.local.gnu 2>&1 > /dev/null

#~ gnuplot -e "datafile='$BENCHDIR/info.grasp.dat.promedio'" \
#~         -e "outfile='$IMGDIR/grafico-grasp.png'" \
#~ $BENCHDIR/plotter.grasp.gnu 2>&1 > /dev/null
#~ 
#~ gnuplot -e "datafile='$BENCHDIR/info.grasp.a.dat.promedio'" \
#~         -e "outfile='$IMGDIR/grafico-grasp-a.png'" \
#~ $BENCHDIR/plotter.grasp.gnu 2>&1 > /dev/null
#~ 
#~ gnuplot -e "datafile='$BENCHDIR/info.grasp.c.dat.promedio'" \
#~         -e "outfile='$IMGDIR/grafico-grasp-c.png'" \
#~ $BENCHDIR/plotter.grasp.gnu 2>&1 > /dev/null
#~ 
#~ gnuplot -e "datafile='$BENCHDIR/info.grasp.ac.dat.promedio'" \
#~         -e "outfile='$IMGDIR/grafico-grasp-ac.png'" \
#~ $BENCHDIR/plotter.grasp.gnu 2>&1 > /dev/null
#~ 
#~ gnuplot -e "datafile='$BENCHDIR/info.grasp.i.dat.promedio'" \
#~         -e "outfile='$IMGDIR/grafico-grasp-i.png'" \
#~ $BENCHDIR/plotter.grasp.gnu 2>&1 > /dev/null
#~ 
#~ gnuplot -e "datafile='$BENCHDIR/info.grasp.i.a.dat.promedio'" \
#~         -e "outfile='$IMGDIR/grafico-grasp-i-a.png'" \
#~ $BENCHDIR/plotter.grasp.gnu 2>&1 > /dev/null
#~ 
#~ gnuplot -e "datafile='$BENCHDIR/info.grasp.i.c.dat.promedio'" \
#~         -e "outfile='$IMGDIR/grafico-grasp-i-c.png'" \
#~ $BENCHDIR/plotter.grasp.gnu 2>&1 > /dev/null
#~ 
#~ gnuplot -e "datafile='$BENCHDIR/info.grasp.i.ac.dat.promedio'" \
#~         -e "outfile='$IMGDIR/grafico-grasp-i-ac.png'" \
#~ $BENCHDIR/plotter.grasp.gnu 2>&1 > /dev/null
