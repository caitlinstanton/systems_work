#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "linked_list.c"
#include "music_lib.h"

int list_test() {

  song* list = NULL;
	
  printf("-- Adding songs --\n");
  list = insert_front(list, "teenagers", "my chemical romance");
  list = insert_front(list, "ghost of you", "my chemical romance");
  list = insert_front(list, "the only hope for me is you", "my chemical romance");
  list = insert_ordered(list, "back in black", "ac/dc");
  list = insert_ordered(list, "bulls on parade", "rage against the machine");
  list = insert_ordered(list, "american idiot", "green day");
  list = insert_ordered(list, "basket case", "green day");
  print_list(list);
	
  printf("-- Finding 'ghost of you' --\n");
  print_song(find_song(list, "ghost of you"));
	
  printf("-- Finding green day --\n");
  print_song(find_artist(list, "green day"));
	
  printf("-- Finding two random songs --\n");
  print_song(random_song(list));
  print_song(random_song(list));
	
  printf("-- Removing 'the only hope for me is you' --\n");
  list = remove_song(list, "the only hope for me is you", "my chemical romance");
  print_list(list);
  printf("-- Removing 'basket case' --\n");
  list = remove_song(list, "basket case", "green day");
  print_list(list);
  
  printf("-- Freeing list --\n");
  list = free_list(list);
  print_list(list);
}

void music_lib_test(){
  int i;
  for (i = 0; i < 26; i++) {
    table[i] = NULL;
  }
  
  printf("\n-- Adding songs --\n");
  add_song("cyanide", "metallica");
  add_song("master of puppets", "metallica");
  add_song("sad but true", "metallica");
  add_song("demons", "imagine dragons");
  add_song("blank space", "taylor swift");
  add_song("this is how i disappear", "my chemical romance");
  add_song("thank you", "mkto");
  add_song("classic", "mkto");
  add_song("hello", "evanescence");
  add_song("everybodys fool", "evanescence");
  add_song("la la latch", "pentatonix");
  add_song("rather be", "pentatonix");
  add_song("whoa whoa whoa", "watsky");
  add_song("i knew you were trouble", "taylor swift");
  add_song("worth it", "little mix");
  add_song("hey everybody", "five seconds of summer");
  add_song("jet black heart", "five seconds of summer");
  add_song("girl almighty", "one direction");
  print_lib();
  
  printf("\n-- Printing 'm' artists --\n");
  print_letter('m');
  
  printf("\n-- Printing 'evanescence' songs --\n");
  print_artist("evanescence");
  
  printf("\n-- Search for 'blank space' by taylor swift --\n");
  find_song_in_lib("blank space", "taylor swift");
  
  printf("\n-- Search for 'five seconds of summer' --\n");
  find_artist_in_lib("five seconds of summer");
  
  printf("\n-- Shuffle 2 songs --\n");
  shuffle(2);
  printf("-- Shuffle 5 songs --\n");
  shuffle(5);
  
  printf("\n-- Delete 'jet black heart' by five seconds of summer --\n");
  delete_song("jet black heart", "five seconds of summer");
  printf("search for 'jet black heart': [should be null]");
  find_song_in_lib("jet black heart", "five seconds of summer");
    
  printf("\n-- Delete everything! --\n");
  clear_lib();
  
  print_lib();
}

int main() {
  list_test();
  music_lib_test();
  return 0;
}


