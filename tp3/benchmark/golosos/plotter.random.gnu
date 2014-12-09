set terminal pngcairo size 1280,800
set output outfile
set xlabel 'X mejores elementos a elegir al azar'
set ylabel 'Peso (menor es mejor)'
set boxwidth 0.8
set style data histograms
plot datafile u 2:xtic(1) title 'Aristas',\
  datafile u 3 title 'Conjuntos',\
  datafile u 4 title 'Ambos'
