
BINDIR = bin
SRCDIR = src
INFORMEDIR = informe
TESTDIR = test


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
