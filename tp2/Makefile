
BINDIR = bin
SRCDIR = src
INFORMEDIR = informe
TESTDIR = tests
BENCHDIR = benchmark
IMGDIR = $(INFORMEDIR)/imagenes


.PHONY: all informe test clean


tp:
	make -C $(SRCDIR)

informe:
	make -C $(INFORMEDIR)
	xdg-open $(BINDIR)/informe.pdf

test:
	make -C $(TESTDIR)

plot:
	$(BENCHDIR)/run.sh $(BENCHDIR) $(TESTDIR) $(BINDIR) $(IMGDIR)

plot2:
	$(BENCHDIR)/run2.sh $(BENCHDIR) $(TESTDIR) $(BINDIR) $(IMGDIR)

graficos:
	$(BENCHDIR)/grafico.sh $(BENCHDIR) $(TESTDIR) $(BINDIR) $(IMGDIR)

all: tp

clean:
	rm -f $(BINDIR)/*
