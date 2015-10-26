all: rand.o
	gcc rand.o

rand.o: rand.c
	gcc -c rand.c

run: all
	./a.out

clean:
	rm *.o
	rm a.out
