CXXFLAGS=-Wall -Wextra -Werror -pedantic -g -O3 -std=c++0x
BINS=ej1 ej2 ej3
BINDIR=../bin
BT=-DBT_ORDENAR
BTA=$(BT) -DBT_ASCENDENTE
BTP=$(BT) -DBT_PROMEDIO
BTAP=$(BTA) -DBT_PROMEDIO


.PHONY: all clean


#%: %.cc %.h
#	$(CXX) $(CXXFLAGS) -o $@ $<
#	mv $@ $(BINDIR)/$@


all: $(BINS)
	mv $(BINS) $(BINDIR)

podas: ej3.cc ej3.h
	$(CXX) $(CXXFLAGS) $(BT)   $< -o ej3-poda
	$(CXX) $(CXXFLAGS) $(BTA)  $< -o ej3-poda-a
	$(CXX) $(CXXFLAGS) $(BTP)  $< -o ej3-poda-p
	$(CXX) $(CXXFLAGS) $(BTAP) $< -o ej3-poda-ap
	mv ej3-poda* $(BINDIR)

clean:
	rm -f $(BINS)
