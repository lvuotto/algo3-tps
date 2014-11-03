set terminal pngcairo size 1280,800
set output outfile
set title titulo
set xlabel 'Cantidad de caballos'
set ylabel 'microsegundos'
f(x) = a*x
FIT_LIMIT = 1e-6
fit f(x) datafile u 1:3 via a
plot datafile u 1:3 w dots t 'clock', \
     f(x) w lines t sprintf('%f*x', a)
