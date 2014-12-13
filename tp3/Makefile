SRCDIR=src
BINDIR=bin
TESTDIR=test
BENCHDIR=benchmark
INFORMEDIR=informe
IMGDIR=$(INFORMEDIR)/imagenes


tp:
	$(MAKE) -C $(SRCDIR)

informe:
	$(MAKE) -C $(INFORMEDIR)

test:
	$(MAKE) -C $(TESTDIR)

benchmark:
	$(BENCHDIR)/run.sh $(BINDIR)/kpmp $(TESTDIR)/random-test.rb $(BENCHDIR)

benchmark1:
	$(BENCHDIR)/run.1.sh $(BINDIR)/kpmp $(TESTDIR)/random-test.rb $(BENCHDIR)
benchmark2:
	$(BENCHDIR)/run.2.sh $(BINDIR)/kpmp $(TESTDIR)/random-test.rb $(BENCHDIR)
benchmark3:
	$(BENCHDIR)/run.3.sh $(BINDIR)/kpmp $(TESTDIR)/random-test.rb $(BENCHDIR)
benchmark4:
	$(BENCHDIR)/run.4.sh $(BINDIR)/kpmp $(TESTDIR)/random-test.rb $(BENCHDIR)

plot:
	TESTDIR=$(TESTDIR) BINDIR=$(BINDIR) IMGDIR=$(IMGDIR) $(BENCHDIR)/run.sh

dibujitos:
	$(BENCHDIR)/grafico.sh $(BENCHDIR) $(IMGDIR)
	$(BENCHDIR)/locales/graficar.sh
	$(BENCHDIR)/grasp/graficar.sh

all: tp informe test plot dibujitos

clean:
	$(RM) $(BINDIR)/*

.PHONY: all tp informe test benchmark plot clean
