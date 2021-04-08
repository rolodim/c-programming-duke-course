#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

deck_t * createEmptyDeck(void);

int main(void) {
  deck_t * d;
  d = createEmptyDeck();
  for (size_t i = 0; i < 51; i++) {
    add_card_to(d, card_from_num(i));
  }
  add_empty_card(d);    
  print_hand(d);
  free_deck(d);
  printf("\n");
  return EXIT_SUCCESS;
}
