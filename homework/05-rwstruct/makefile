all: rwstruct.o
	gcc rwstruct.o

rwstruct.o: rwstruct.c
	gcc -c rwstruct.c

run: all
	./a.out

clean:
	rm *.o
	rm a.out
