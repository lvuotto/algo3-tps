set terminal pngcairo size 1280,800
set output outfile
set xlabel 'Iteraciones (X)'
set ylabel 'Microsegundos'
plot datafile u 1:3 smooth bezier with lines title 'Mejor luego de X veces',\
  datafile u 1:5 smooth bezier with lines title 'Cuando el mejor se repite X veces'
