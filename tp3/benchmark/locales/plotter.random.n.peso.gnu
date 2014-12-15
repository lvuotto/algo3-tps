set terminal pngcairo size 1280,800
set output outfile
set xlabel 'Cantidad de vértices'
set ylabel 'Peso total'
plot datafile u 1:3 smooth bezier with lines title 'Mover',\
  datafile u 1:5 smooth bezier with lines title 'Intercambiar'
