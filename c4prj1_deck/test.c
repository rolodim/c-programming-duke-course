#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

deck_t * createEmptyDeck(void);

int main(void) {
  deck_t * d;
  d = createEmptyDeck();
  print_hand(d);
  return EXIT_SUCCESS;
}
