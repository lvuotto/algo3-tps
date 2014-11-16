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

plot:
	TESTDIR=$(TESTDIR) BINDIR=$(BINDIR) IMGDIR=$(IMGDIR) $(BENCHDIR)/run.sh

all: tp informe test plot

clean:
	$(RM) $(BINDIR)/*

.PHONY: all tp informe test benchmark plot clean
