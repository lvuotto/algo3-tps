
BINDIR = bin
SRCDIR = src
INFORMEDIR = informe
TESTDIR = tests
BENCHDIR = benchmark
IMGDIR = $(INFORMEDIR)/imagenes


.PHONY: all clean


tp:
	make -C $(SRCDIR)

informe:
	make -C $(INFORMEDIR)

test:
	make -C $(TESTDIR)

plot:
	$(BENCHDIR)/run.sh $(BENCHDIR) $(IMGDIR)


all: tp

clean:
	rm -f $(BINDIR)/*
