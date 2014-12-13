set terminal pngcairo size 1280,800
set output outfile
set ylabel 'Peso total'
plot datafile u 1:7 w points pt 7 ps 0.5 title 'Mover',\
  datafile u 1:9 w points pt 7 ps 0.8 title 'Intercambiar'
