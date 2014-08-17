
TP1DIR = tp1
TP2DIR = tp2
TP3DIR = tp3


.PHONY: all clean


all: tp1 tp2 tp3

tp1:
	make -C $(TP1DIR)

tp2:
	make -C $(TP2DIR)

tp3:
	make -C $(TP3DIR)

clean:
	make -C $(TP1DIR) clean
	make -C $(TP2DIR) clean
	make -C $(TP3DIR) clean

