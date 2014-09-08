
BINS = informe.pdf
BINDIR = ../bin


.PHONY: all clean


informe.pdf: informe.tex problema1.tex problema2.tex problema3.tex
	pdflatex $<
	mv $@ $(BINDIR)

all: $(BINS)

clean:
	rm -f $(BINDIR)/$(BINS)
