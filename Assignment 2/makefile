all: prog

prog: dynArray.o stackapp.o
	gcc -g -Wall -std=c99 -o prog dynArray.o stackapp.o

stackapp.o: stackapp.c dynArray.h
	gcc -g -Wall -std=c99 -c stackapp.c

dynArray.o: dynArray.c dynArray.h 
	gcc -g -Wall -std=c99 -c dynArray.c	
		
clean:
	rm dynArray.o
	rm stackapp.o
	rm prog
