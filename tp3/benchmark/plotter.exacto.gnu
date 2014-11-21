set terminal pngcairo size 1280,800
set output outfile
set xlabel 'Cantidad de vértices'
set ylabel 'microsegundos'
#f(x) = a*x*log(x)
FIT_LIMIT = 1e-6
#fit f(x) datafile u 1:3 via a
plot datafile u 1:4 w points pt 7 ps 0.5 t 'tiempo'
#     f(x) w lines t sprintf('%f*x*log(x)', a)
