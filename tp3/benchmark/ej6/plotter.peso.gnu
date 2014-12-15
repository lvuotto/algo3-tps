set terminal pngcairo size 1280,800
set output outfile
set xlabel 'Cantidad de vértices'
set ylabel 'Peso total'
plot datafile u 1:3 smooth bezier with lines title 'GRASP repetir mejor 34 veces',\
  datafile u 1:13 smooth bezier with lines title 'GRASP 47 veces',\
  datafile u 1:5 smooth bezier with lines title 'Exacto',\
  datafile u 1:7 smooth bezier with lines title 'Goloso sin aleatorizar',\
  datafile u 1:9 smooth bezier with lines title 'GRASP aleatorizar ambos',\
  datafile u 1:11 smooth bezier with lines title 'GRASP intercambiar' lt rgb '#000000'
