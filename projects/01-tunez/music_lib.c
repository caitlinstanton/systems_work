#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "music_lib.h"
#include "linked_list.h"

int get_index(char c){
  //'a' = 97, so char - 97 should give index in table if they work like that
  return (int)c - 97;
}

void add_song(char* n, char* a){
  int i = get_index(a[0]);
  table[i] = insert_ordered(table[i], n, a);
}
//add songs

void find_song_in_lib(char* n, char* a){
  int i = get_index(a[0]);
  print_song(find_song(table[i], n));
}
//search for a song

void find_artist_in_lib(char* a){
  print_artist(a);
}
//search for an artist

void print_letter(char l){
  int i = get_index(l);
  print_list(table[i]);
}
//print out all the entries under a certain letter

void print_artist(char* a){
  int i = get_index(a[0]);
  find_artist(table[i], a);
}
//print out all the songs of a certain artist

void print_lib(){
  int i = 0;
  for (; i < 26; i++){
    print_list(table[i]);
  }
}
//print out the entire library

void shuffle(int num){
  for (; num > 0; num --){
    int i = rand() % 26;
    print_song(random_song(table[i]));
  }
}
//shuffle - print out a series (length num) of randomly chosen songs

void delete_song(char* n, char* a){
  int i = get_index(a[0]);
  table[i] = remove_song(table[i], n, a);
}
//delete a song

void clear_lib(){
  int i = 0;
  for (; i < 26; i ++){
    table[i] = free_list(table[i]);
  }
}
//delete all the nodes
