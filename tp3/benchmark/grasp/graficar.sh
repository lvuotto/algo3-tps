gnuplot -e "xlabel='X mejores elementos a elegir al azar'" -e "datafile='benchmark/grasp/goloso_x.dat'" -e "outfile='informe/imagenes/grasp-goloso-x-peso.png'" benchmark/grasp/plotter.goloso.peso.gnu 2>&1
gnuplot -e "xlabel='X mejores elementos a elegir al azar'" -e "datafile='benchmark/grasp/goloso_x.dat'" -e "outfile='informe/imagenes/grasp-goloso-x-tiempo.png'" benchmark/grasp/plotter.goloso.tiempo.gnu 2>&1
gnuplot -e "xlabel='Cantidad de vértices'" -e "datafile='benchmark/grasp/goloso_n.dat'" -e "outfile='informe/imagenes/grasp-goloso-n-peso.png'" benchmark/grasp/plotter.goloso.peso.gnu 2>&1
gnuplot -e "xlabel='Cantidad de vértices'" -e "datafile='benchmark/grasp/goloso_n.dat'" -e "outfile='informe/imagenes/grasp-goloso-n-tiempo.png'" benchmark/grasp/plotter.goloso.tiempo.gnu 2>&1
gnuplot -e "xlabel='Cantidad de conjuntos'" -e "datafile='benchmark/grasp/goloso_k.dat'" -e "outfile='informe/imagenes/grasp-goloso-k-peso.png'" benchmark/grasp/plotter.goloso.peso.gnu 2>&1
gnuplot -e "xlabel='Cantidad de conjuntos'" -e "datafile='benchmark/grasp/goloso_k.dat'" -e "outfile='informe/imagenes/grasp-goloso-k-tiempo.png'" benchmark/grasp/plotter.goloso.tiempo.gnu 2>&1

gnuplot -e "xlabel='X mejores elementos a elegir al azar'" -e "datafile='benchmark/grasp/local_x.dat'" -e "outfile='informe/imagenes/grasp-local-x-peso.png'" benchmark/grasp/plotter.goloso.peso.gnu 2>&1
gnuplot -e "xlabel='X mejores elementos a elegir al azar'" -e "datafile='benchmark/grasp/local_x.dat'" -e "outfile='informe/imagenes/grasp-local-x-tiempo.png'" benchmark/grasp/plotter.goloso.tiempo.gnu 2>&1
gnuplot -e "xlabel='Cantidad de vértices'" -e "datafile='benchmark/grasp/local_n.dat'" -e "outfile='informe/imagenes/grasp-local-n-peso.png'" benchmark/grasp/plotter.goloso.peso.gnu 2>&1
gnuplot -e "xlabel='Cantidad de vértices'" -e "datafile='benchmark/grasp/local_n.dat'" -e "outfile='informe/imagenes/grasp-local-n-tiempo.png'" benchmark/grasp/plotter.goloso.tiempo.gnu 2>&1
gnuplot -e "xlabel='Cantidad de conjuntos'" -e "datafile='benchmark/grasp/local_k.dat'" -e "outfile='informe/imagenes/grasp-local-k-peso.png'" benchmark/grasp/plotter.goloso.peso.gnu 2>&1
gnuplot -e "xlabel='Cantidad de conjuntos'" -e "datafile='benchmark/grasp/local_k.dat'" -e "outfile='informe/imagenes/grasp-local-k-tiempo.png'" benchmark/grasp/plotter.goloso.tiempo.gnu 2>&1
