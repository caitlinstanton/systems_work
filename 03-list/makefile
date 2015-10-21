all: main.o list.o
	gcc main.o list.o

list.o: list.c list.h
	gcc -c list.c

main.o: main.c list.h
	gcc -c main.c

clean: 
	rm *.o
	rm *~

run:
	./a.out
