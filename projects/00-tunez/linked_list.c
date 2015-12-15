#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"

void print_song(song* s){
  printf("%s - %s \n", s->artist, s-> name);
}

song* insert_front(song* list, char* n, char* a){
  song* added = (song*)malloc(sizeof(song));
  strncpy(added->name, n, strlen(n));
  strncpy(added->artist, a, strlen(a));
  added->next = list;
  return added;
}
//insert nodes at the front

/*
song* insert_after(song* list, char* n, char* a){
  song* added = (song*)malloc(sizeof(song));
  strncpy(added->name, n, strlen(n));
  strncpy(added->artist, a, strlen(a));
  added->next = list->next;
  list->next = added;
  return added;
}
*/

song* insert_ordered(song* list, char* n, char* a) {
  if (list == NULL) {
    return insert_front(list, n, a);
  } else if (strcmp(a, list->artist) < 0) {
    return insert_front(list, n, a);
  } else if (strcmp(a, list->artist) == 0 &&
	     strcmp(n, list->name) <0) {
    return insert_front(list, n, a);
  }
  list->next = insert_ordered(list->next, n, a);
  return list;
}
//insert nodes in order

void print_list(song* list) {
  while(list) {
    print_song(list);
    list = list->next;
  }
}
//print the entire list

song* find_song(song* list, char* n) {
  while (list) {
    if (strcmp(list->name, n) == 0) {
      print_song(list);
      return list;
    }
    list = list->next;
  }
  printf("Song does not exist\n");
  return list;
}
//find and return a pointer to an individual song based on song name

song* find_artist(song* list, char* a) {
  while (list) {
    if (strcmp(list->artist,a) == 0) {
      while (strcmp(list->artist,a) == 0) {
	print_song(list);
	list = list->next;
      }
      return list;
    }
    list = list->next;
  }
  printf("Artist does not exist");
  return list;
}
//find and return a pointer to the first song of an artist based on artist name

int length(song* list){
  int ctr = 0;
  while (list){
    ctr ++;
    list = list->next;
  }
  return ctr;
}

song* random_song(song*list) {
  int random = rand() % length(list);
  while (random){
    list = list->next;
    random --;
  }
  return list;
}
//return a pointer to a random song in the list

song* remove_song(song*list, char*n, char*a) {
  if (!list){
    return list;
  }
  if ( strcmp(n, list->name) == 0 && strcmp(a, list->artist) == 0 ) {
    song *temp = list->next;
    free(list);
    return temp;
  }
  list->next = remove_song(list->next, n, a);
  return list;
  /*
  while (list){
    if (strcmp(list->artist, a) == 0 && 
	strcmp(list->name, n) == 0){
      song* temp = list->next;
      free(list);
      return list->next;
    }
    list = list->next;
  }
  return list;
  */
}
//remove a single node from the list
//could also be void, but i think removing usually returns the thing

song* free_list(song*list) {
  if (list == NULL){
    return list;
  }
  free_list(list->next);
  free(list);
  list = NULL;
  return list;
}
//free the entire list
//return a pointer to the beginning of the list?

