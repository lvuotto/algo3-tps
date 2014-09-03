
BINDIR = bin
SRCDIR = src
INFORMEDIR = informe
TESTDIR = tests
BENCHDIR = benchmark


.PHONY: all clean


tp:
	make -C $(SRCDIR)

informe:
	make -C $(INFORMEDIR)

test:
	make -C $(TESTDIR)

plot:
	$(BENCHDIR)/benchmark.1.sh 2> $(BENCHDIR)/info.1.dat
	gnuplot -e "datafile='$(BENCHDIR)/info.1.dat'" \
                -e "outfile='$(BENCHDIR)/grafico.1.png'" \
                $(BENCHDIR)/plotter.gnu
	xdg-open $(BENCHDIR)/grafico.1.png
	$(BENCHDIR)/benchmark.2.sh 2> $(BENCHDIR)/info.2.dat
	gnuplot -e "datafile='$(BENCHDIR)/info.2.dat'" \
                -e "outfile='$(BENCHDIR)/grafico.2.png'" \
                $(BENCHDIR)/plotter.gnu
	xdg-open $(BENCHDIR)/grafico.2.png
	$(BENCHDIR)/benchmark.3.sh 2> $(BENCHDIR)/info.3.dat
	gnuplot -e "datafile='$(BENCHDIR)/info.3.dat'" \
                -e "outfile='$(BENCHDIR)/grafico.3.png'" \
                $(BENCHDIR)/plotter.gnu
	xdg-open $(BENCHDIR)/grafico.3.png

all: tp

clean:
	rm -f $(BINDIR)/*
