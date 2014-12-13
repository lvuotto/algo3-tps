set terminal pngcairo size 1280,800
set output outfile
set xlabel 'Cantidad de vértices'
set ylabel 'Microsegundos'
plot datafile u 1:6 w points pt 7 ps 0.5 title 'Mover',\
  datafile u 1:8 w points pt 7 ps 0.8 title 'Intercambiar'
