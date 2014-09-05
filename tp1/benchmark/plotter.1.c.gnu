set terminal pngcairo size 1280,800
set output outfile
set title titulo
set xlabel 'Salto máximo'
set ylabel 'Ciclos de clock (miles)'
f(x) = a
FIT_LIMIT = 1e-6
fit f(x) datafile u 2:3:3 via a
plot datafile u 2:($3/1000) w lines t 'clock', \
     f(x)/1000 w lines t sprintf('%f', a)
