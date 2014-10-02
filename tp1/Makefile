BINDIR=bin
SRCDIR=src
INFORMEDIR=informe
TESTDIR=tests
BENCHDIR=benchmark
IMGDIR=$(INFORMEDIR)/imagenes


.PHONY: all tp informe test plot clean


tp:
	$(MAKE) -C $(SRCDIR)

informe:
	$(MAKE) -C $(INFORMEDIR)
	xdg-open $(BINDIR)/informe.pdf

test:
	$(MAKE) -C $(TESTDIR)

plot:
	$(MAKE) -C $(SRCDIR)
	$(MAKE) -C $(SRCDIR) podas
	$(BENCHDIR)/run_especial.sh $(BENCHDIR) $(IMGDIR)
	$(BENCHDIR)/run.sh $(BENCHDIR) $(IMGDIR)


all: tp test plot

clean:
	$(RM) $(BINDIR)/*
