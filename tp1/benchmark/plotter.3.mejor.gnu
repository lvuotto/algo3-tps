set terminal pngcairo size 1280,800
set output outfile
set title titulo
set xlabel 'Cantidad de productos químicos'
set ylabel 'Ciclos de clock'
#set format x '%.0f'
#set format y '%.0f'
f(x) = a*gamma(x+1)
FIT_LIMIT = 1e-6
fit f(x) datafile using 1:3 via a
plot datafile using 1:3 with lines title 'clock', f(x) with lines
