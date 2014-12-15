set terminal pngcairo size 1280,800
set output outfile
set xlabel xlabel
set ylabel 'Peso total'
plot datafile u 1:5 smooth bezier with lines title 'Sin aleatorizar',\
  datafile u 1:5 smooth bezier with lines title 'Aristas',\
  datafile u 1:7 smooth bezier with lines title 'Conjuntos',\
  datafile u 1:9 smooth bezier with lines title 'Ambos'
