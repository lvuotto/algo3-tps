CXXFLAGS=-Wall -Wextra -Werror -pedantic -O3 -ggdb -std=c++0x
BINS=kpmp-exacto kpmp-hg kpmp-hl kpmp-grasp
OBJS=kpmp.o
BINDIR=../bin


all:
	g++ -Wall -Wextra -Werror -pedantic -O3 -ggdb -std=c++0x kpmp.cc -o kpmp
	mv kpmp $(BINDIR)

kpmp.o: kpmp.h

%: %.cc kpmp.o
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(BINS) $(OBJS)

.PHONY: all clean
