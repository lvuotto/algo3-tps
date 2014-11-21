#!/bin/bash

export KPMP=$1
export GENERADOR=$2
export BENCHDIR=$3

BENCHDIR=$3

#~ $BENCHDIR/grasp.sh      2> $BENCHDIR/info.grasp.dat
#~ $BENCHDIR/grasp.a.sh    2> $BENCHDIR/info.grasp.a.dat
#~ $BENCHDIR/grasp.c.sh    2> $BENCHDIR/info.grasp.c.dat
#~ $BENCHDIR/grasp.ac.sh   2> $BENCHDIR/info.grasp.ac.dat
$BENCHDIR/grasp.i.sh    2> $BENCHDIR/info.grasp.i.dat
$BENCHDIR/grasp.i.a.sh  2> $BENCHDIR/info.grasp.i.a.dat
$BENCHDIR/grasp.i.c.sh  2> $BENCHDIR/info.grasp.i.c.dat
$BENCHDIR/grasp.i.ac.sh 2> $BENCHDIR/info.grasp.i.ac.dat
