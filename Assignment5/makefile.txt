all: prog sprog

prog: dynamicArray.o main.o toDoList.o
	gcc -g -Wall -std=c99 -o prog dynamicArray.o toDoList.o main.o

sprog: dynamicArray.o main2.o toDoList.o 
	gcc -g -Wall -std=c99 -o sprog dynamicArray.o toDoList.o main2.o

main.o: main.c dynamicArray.h toDoList.h
	gcc -g -Wall -std=c99 -c main.c

main2.o: main2.c dynamicArray.h toDoList.h 
	gcc -g -Wall -std=c99 -c main2.c

dynamicArray.o: dynamicArray.c dynamicArray.h
	gcc -g -Wall -std=c99 -c dynamicArray.c

toDoList.o: toDoList.c toDoList.h
	gcc -g -Wall -std=c99 -c toDoList.c

clean:
	rm *.o
	rm prog
	rm sprog
