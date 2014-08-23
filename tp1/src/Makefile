
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -g -O3 -std=c++0x
BINS = ej1 ej2 ej3
BINDIR = ../bin


.PHONY: all clean


%: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $<
	mv $@ $(BINDIR)/$@


all: $(BINS)

clean:
	rm -f $(BINS)

