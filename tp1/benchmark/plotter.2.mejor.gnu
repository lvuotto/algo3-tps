set terminal pngcairo size 1280,800
set output outfile
set title titulo
set xlabel 'Cantidad de edificios'
set ylabel 'Ciclos de clock (millones)'
f(x) = a*x*log(x)
FIT_LIMIT = 1e-6
fit f(x) datafile u 1:2 via a
plot datafile u 1:($2/1000000) w lines t 'clock', \
     f(x)/1000000 w lines t sprintf('%f*x*log(x)', a)
