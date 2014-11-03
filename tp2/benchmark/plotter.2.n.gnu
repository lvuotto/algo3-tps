set terminal pngcairo size 1280,800
set output outfile
set title titulo
set xlabel 'Cantidad de casilleros'
set ylabel 'microsegundos'
f(x) = a*x*x
FIT_LIMIT = 1e-6
fit f(x) datafile u 2:3 via a
plot datafile u 2:3 w dots t 'clock', \
     f(x) w lines t sprintf('%f*x*x', a)
