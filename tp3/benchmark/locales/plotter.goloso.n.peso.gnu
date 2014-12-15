set terminal pngcairo size 1280,800
set output outfile
set ylabel 'Peso total'
plot datafile u 1:7 smooth bezier with lines title 'Mover',\
  datafile u 1:9 smooth bezier with lines title 'Intercambiar'
