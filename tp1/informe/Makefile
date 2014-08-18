
BINS = informe.pdf
BINDIR = ../bin


.PHONY: all clean


%.pdf: %.tex
	pdflatex $<
	mv $@ $(BINDIR)

all: $(BINS)

clean:
	rm -f $(BINDIR)/$(BINS)
