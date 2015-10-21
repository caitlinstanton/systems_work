#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"
#include "music_lib.h"

void music_lib_test(){
  int i;
  for (i = 0; i < 26; i++) {
    table[i] = NULL;
  }

  printf("\nMAIN FUNCTION BORROWED FROM PERIOD 8 ARIEL_LEVY&SAMUEL_ZHANG \n because they had nice formatting \nactual code still ours :P\n\n");
  
  printf("\n-- Adding songs --\n");
  add_song("somebody to love", "queen");
  add_song("bohemian rhapsody", "queen");
  add_song("another one bites the dust", "queen");
  add_song("hotel california", "eagles");
  add_song("blank space", "taylor swift");
  add_song("old pine", "ben howard");
  add_song("yesterday", "the beatles");
  add_song("hey jude", "the beatles");
  add_song("crazy in love", "beyonce");
  add_song("halo", "beyonce");
  add_song("fluorescent adolescent", "arctic monkeys");
  add_song("a certain romance", "arctic monkeys");
  add_song("london calling", "the clash");
  add_song("(i can't get no) satisfaction", "the rolling stones");
  add_song("total eclipse of the heart", "bonnie tyler");
  add_song("someday", "the strokes");
  add_song("a-punk", "vampire weekend");
  add_song("song 2", "blur");
  print_lib();
  
  printf("\n-- Printing 't' artists --\n");
  print_letter('t');
  
  printf("\n-- Printing 'beyonce' songs --\n");
  print_artist("beyonce");
  
  printf("\n-- Search for 'someday' by 'the strokes' --\n");
  find_song_in_lib("someday", "the strokes");
  
  printf("\n-- Search for 'the beatles' --\n");
  find_artist_in_lib("the beatles");
  
  printf("\n-- Shuffle 2 songs --\n");
  //  shuffle(2);
  printf("-- Shuffle 5 songs --\n");
  //shuffle(5);
  printf("-- Shuffle doesn't work... --\n");
  
  printf("\n-- Delete 'a-punk' by 'vampire weekend' --\n");
  delete_song("a-punk", "vampire weekend");
  printf("\n-- Print Library --\n");
  print_lib();

    
  printf("\n-- Delete everything! --\n\n");
  clear_lib();
  
  print_lib();
}

int main() {
  music_lib_test();
  return 0;
}
