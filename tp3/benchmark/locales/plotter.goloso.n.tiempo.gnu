set terminal pngcairo size 1280,800
set output outfile
set xlabel 'Cantidad de vértices'
set ylabel 'Microsegundos'
plot datafile u 1:6 smooth bezier with lines title 'Mover',\
  datafile u 1:8 smooth bezier with lines title 'Intercambiar'
