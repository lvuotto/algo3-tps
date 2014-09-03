set terminal pngcairo size 1280,800
set output outfile
set title titulo
set xlabel 'Cantidad de tablones'
set ylabel 'Ciclos de clock'
set format x '%.0f'
set format y '%.0f'
plot datafile using 1:3 with lines, x
