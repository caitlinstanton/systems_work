#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song;

void print_song(song* s);

song* insert_front(song* list, char* n, char* a);
//insert nodes at the front

//song* insert_after(song* list, char*n, char* a);

song* insert_ordered(song* list, char* n, char* a);
//insert nodes in order

void print_list(song* list);
//print the entire list

song* find_song(song* list, char* n);
//find and return a pointer to an individual song based on song name

song* find_artist(song* list, char* a);
//find and return a pointer to the first song of an artist based on artist name

int length(song* list);

song* random_song(song*list);
//return a pointer to a random song in the list

song* remove_song(song*list, char* n, char* a);
//remove a single node from the list
//could also be void, but i think removing usually returns the thing

song* free_list(song*list);
//free the entire list
//or return a pointer to the beginning of the list?

#endif
