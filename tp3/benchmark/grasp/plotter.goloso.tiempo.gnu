set terminal pngcairo size 1280,800
set output outfile
set xlabel xlabel
set ylabel 'Microsegundos'
plot datafile u 1:2 w points pt 7 ps 0.8 title 'Sin aleatorizar',\
  datafile u 1:4 w points pt 7 ps 0.8 title 'Aristas',\
  datafile u 1:6 w points pt 7 ps 0.8 title 'Conjuntos',\
  datafile u 1:8 w points pt 7 ps 0.8 title 'Ambos'
