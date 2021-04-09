#include <stdlib.h>
#include <stdio.h>
#include "input.h"
#include "future.h"

deck_t * createEmptyDeck(void);

int main(int argc, char ** argv) {

  FILE * f = fopen(argv[1], "r");
  future_cards_t * fc = malloc(sizeof(*fc));
  fc->n_decks = 0;
  fc->decks = NULL;
  size_t * n_hands = malloc(sizeof(*n_hands));
  deck_t ** hands = read_input(f, n_hands, fc);
  deck_t * d = createEmptyDeck();
  add_card_to(d, card_from_letters('A', 's'));
  add_card_to(d, card_from_letters('A', 'h'));
  add_card_to(d, card_from_letters('A', 'c'));
  add_card_to(d, card_from_letters('K', 's'));
  add_card_to(d, card_from_letters('Q', 's'));
  add_card_to(d, card_from_letters('J', 's'));
  
  future_cards_from_deck(d, fc);
  future_cards_from_deck(d, fc);
  future_cards_from_deck(d, fc);
  future_cards_from_deck(d, fc);
  
  //print_hand(hands[0]);
  printf("\n");
  //print_hand(hands[1]);
  printf("\n");
  free_deck(hands[0]);
  
  return EXIT_SUCCESS;
  
}
