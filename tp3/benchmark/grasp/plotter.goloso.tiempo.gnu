set terminal pngcairo size 1280,800
set output outfile
set xlabel xlabel
set ylabel 'Microsegundos'
plot datafile u 1:2 smooth bezier with lines title 'Sin aleatorizar',\
  datafile u 1:4 smooth bezier with lines title 'Aristas',\
  datafile u 1:6 smooth bezier with lines title 'Conjuntos',\
  datafile u 1:8 smooth bezier with lines title 'Ambos'
