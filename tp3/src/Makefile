CXXFLAGS=-Wall -Wextra -Werror -pedantic -O3 -ggdb -std=c++0x
BINS=kpmp
DEPS=particion.o conjunto_de_vertices.o grafo.o \
     kpmp-exacto.o kpmp-grasp.o kpmp-hg.o kpmp-hl.o
BINDIR=../bin


all: $(BINS)
	mv $(BINS) $(BINDIR)

kpmp: $(DEPS) shuffle_vector.h

particion.o: conjunto_de_vertices.o

conjunto_de_vertices.o: grafo.o

kpmp-hg.o: kpmp-hg.h shuffle_vector.h

%.o: %.h

clean:
	$(RM) $(DEPS)
	$(RM) $(BINS)

.PHONY: all clean
