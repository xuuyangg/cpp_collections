cc = g++

FLAGS = -Wall -c -g

all: double_link.h main.o
	$(cc) -o test -g main.o double_link.h


main.o: main.cc
	$(cc) $(FLAGS) main.cc


clean:
	rm test main.o