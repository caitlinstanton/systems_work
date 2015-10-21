#ifndef MUSIC_LIB_H
#define MUSIC_LIB_H

#include "linked_list.h"

void add_song(song* list, char[] n, char[] a);
//add songs
song* find_song(song* list, char[] n, char[] a);
//search for a song

//search for an artist
void print_letter(song* list, char l);
//print out all the entries under a certain letter
void print_artist(song* list, char[] a);
//print out all the songs of a certain artist
void print_lib(song *list);
//print out the entire library
void shuffle(song *list);
//shuffle - print out a series of randomly chosen songs
song* delete_song(song *list, char[] n, char[] a);
//delete a song
void clear_lib(song *list);
//delete all the nodes

#endif
