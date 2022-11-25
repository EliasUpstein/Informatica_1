#
#  Makefile
#  
#  Autor: Leandro Beretta <lea.beretta@gmail.com>
#
#  Informática I - UTN.BA
#

LIBS = -lm
CFLAGS = -Wall

SRC = $(wildcard *.c)

all: dado

dado: $(SRC)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
	
clean: 
	rm -f ./*.o *~ *.*~
	rm -f dado