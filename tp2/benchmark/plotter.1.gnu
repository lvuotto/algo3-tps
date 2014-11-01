set terminal pngcairo size 1280,800
set output outfile
set title titulo
set xlabel 'Cantidad de vuelos'
set ylabel 'milisegundos'
f(x) = a*x*log(x)
FIT_LIMIT = 1e-6
fit f(x) datafile u 1:2:2 via a
plot datafile u 1:($2/1000000) w dots t 'clock', \
     f(x)/1000000 w lines t sprintf('%f*x', a)
