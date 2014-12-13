set terminal pngcairo size 1280,800
set output outfile
set xlabel xlabel
set ylabel 'Peso total'
plot datafile u 1:5 w points pt 7 ps 0.8 title 'Sin aleatorizar',\
  datafile u 1:5 w points pt 7 ps 0.8 title 'Aristas',\
  datafile u 1:7 w points pt 7 ps 0.8 title 'Conjuntos',\
  datafile u 1:9 w points pt 7 ps 0.8 title 'Ambos'
