set terminal pngcairo size 1280,800
set output outfile
set xlabel 'Cantidad de vértices'
set ylabel 'Milisegundos'
plot datafile u 1:($2/1000) smooth bezier with lines title 'GRASP repetir mejor 34 veces',\
  datafile u 1:($12/1000) smooth bezier with lines title 'GRASP 47 veces',\
  datafile u 1:($6/1000) smooth bezier with lines title 'Goloso sin aleatorizar',\
  datafile u 1:($8/1000) smooth bezier with lines title 'GRASP aleatorizar ambos',\
  datafile u 1:($10/1000) smooth bezier with lines title 'GRASP intercambiar'
