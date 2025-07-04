all: dstring.o main.o
	g++ -Wall -g main.o dstring.o -o run.o

val:
	valgrind --track-origins=yes -s ./run.o

run:
	./run.o

dstring.o: dstring.cpp dstring.h 
	g++ -Wall -g -c dstring.cpp 

main.o: main.cpp dstring.h 
	g++ -Wall -g -c main.cpp 

clean:
	rm -rf *.o