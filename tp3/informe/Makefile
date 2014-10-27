
BINS = informe.pdf
BINDIR = ../bin


.PHONY: all clean


informe.pdf: informe.tex ej1.tex ej2.tex ej3.tex ej4.tex ej5.tex ej6.tex
	pdflatex $<
	mv $@ $(BINDIR)

all: $(BINS)

clean:
	rm -f $(BINDIR)/$(BINS)
