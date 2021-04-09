#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "future.h"

int main(int argc, char ** argv) {

  FILE * f = fopen(argv[1], "r");
  future_cards_t * fc = malloc(sizeof(*fc));
  fc->n_decks = 0;
  fc->decks = NULL;
  size_t * n_hands = malloc(sizeof(*n_hands));
  deck_t ** hands = read_input(f, n_hands, fc);

  print_hand(hands[0]);
  printf("\n");
  print_hand(hands[1]);
  printf("\n");
  free_deck(hands[0]);
  
  return EXIT_SUCCESS;
  
}
