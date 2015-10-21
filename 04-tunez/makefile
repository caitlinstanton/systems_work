all: main.c music_lib.o linked_list.o
	gcc main.c music_lib.o linked_list.o

music_lib.o: music_lib.c music_lib.h linked_list.o
	gcc -c music_lib.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c 

run: all
	./a.out

clean: 
	rm *.o
	rm *~
