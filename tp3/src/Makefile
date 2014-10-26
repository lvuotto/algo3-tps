CXXFLAGS=-Wall -Wextra -Werror -pedantic -O3 -ggdb -stc=c++0x
BINS=kpmp-exacto kpmp-hg kpmp-hl kpmp-grasp


all: $(BINS)
	mv $(BINS) $(BINDIR)

clean:
	$(RM) $(BINS)

.PHONY: all clean
