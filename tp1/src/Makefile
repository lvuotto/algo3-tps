
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -g -O3 -std=c++11
BINS = ej1 ej2 ej3
BINDIR = ../bin


.PHONY: all clean


%: %.cc
	$(CXX) $(CXXFLAGS) -o $@ $<
	mv $@ $(BINDIR)/$@


all: $(BINS)

clean:
	rm -f $(BINS)

