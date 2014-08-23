
BINDIR = bin
SRCDIR = src
INFORMEDIR = informe
TESTDIR = tests


-PHONY: all clean


tp:
	make -C $(SRCDIR)

informe:
	make -C $(INFORMEDIR)

test:
	make -C $(TESTDIR)

all: tp

clean:
	rm -f $(BINDIR)/*
