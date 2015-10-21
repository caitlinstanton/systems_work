#ifndef MUSIC_LIB_H
#define MUSIC_LIB_H

#include "linked_list.h"

song *table[26];

int get_index(char c);

void add_song(char* n, char* a);
//add songs
void find_song_in_lib(char* n, char* a);
//search for a song
void find_artist_in_lib(char* a);
//search for an artist
void print_letter(char l);
//print out all the entries under a certain letter
void print_artist(char* a);
//print out all the songs of a certain artist
void print_lib();
//print out the entire library
void shuffle();
//shuffle - print out a series of randomly chosen songs
void delete_song(char* n, char* a);
//delete a song
void clear_lib();
//delete all the nodes

#endif
