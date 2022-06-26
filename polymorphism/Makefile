cc = g++	

FLAG = -Wall -c -std=c++17 -g

all: monkey.o dolphin.o main.o animal.o
	$(cc) -o test -g monkey.o dolphin.o main.o animal.o

main.o: main.cc
	$(cc) $(FLAG) main.cc

animal.o: animal.h animal.cc
	$(cc) $(FLAG) animal.h animal.cc

monkey.o: monkey.h monkey.cc
	$(cc) $(FLAG) monkey.h monkey.cc

dolphin.o: dolphin.h dolphin.cc
	$(cc) $(FLAG) dolphin.h dolphin.cc

clean:
	rm dolphin.o monkey.o main.o *.gch animal.o