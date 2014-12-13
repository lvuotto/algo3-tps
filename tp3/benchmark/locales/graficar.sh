gnuplot -e "xlabel='Cantidad de vértices'" -e "datafile='benchmark/locales/sobre_n.dat'" -e "outfile='informe/imagenes/local-random-n-tiempo.png'" benchmark/locales/plotter.random.n.tiempo.gnu 2>&1
gnuplot -e "xlabel='Cantidad de vértices'" -e "datafile='benchmark/locales/sobre_n.dat'" -e "outfile='informe/imagenes/local-random-n-peso.png'" benchmark/locales/plotter.random.n.peso.gnu 2>&1
gnuplot -e "xlabel='Cantidad de vértices'" -e "datafile='benchmark/locales/sobre_n.dat'" -e "outfile='informe/imagenes/local-goloso-n-tiempo.png'" benchmark/locales/plotter.goloso.n.tiempo.gnu 2>&1
gnuplot -e "xlabel='Cantidad de vértices'" -e "datafile='benchmark/locales/sobre_n.dat'" -e "outfile='informe/imagenes/local-goloso-n-peso.png'" benchmark/locales/plotter.goloso.n.peso.gnu 2>&1
gnuplot -e "xlabel='Cantidad de conjuntos'" -e "datafile='benchmark/locales/sobre_k.dat'" -e "outfile='informe/imagenes/local-random-k-tiempo.png'" benchmark/locales/plotter.random.n.tiempo.gnu 2>&1
gnuplot -e "xlabel='Cantidad de conjuntos'" -e "datafile='benchmark/locales/sobre_k.dat'" -e "outfile='informe/imagenes/local-random-k-peso.png'" benchmark/locales/plotter.random.n.peso.gnu 2>&1
gnuplot -e "xlabel='Cantidad de conjuntos'" -e "datafile='benchmark/locales/sobre_k.dat'" -e "outfile='informe/imagenes/local-goloso-k-tiempo.png'" benchmark/locales/plotter.goloso.n.tiempo.gnu 2>&1
gnuplot -e "xlabel='Cantidad de conjuntos'" -e "datafile='benchmark/locales/sobre_k.dat'" -e "outfile='informe/imagenes/local-goloso-k-peso.png'" benchmark/locales/plotter.goloso.n.peso.gnu 2>&1
