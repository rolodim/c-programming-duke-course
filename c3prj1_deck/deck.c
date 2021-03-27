#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  for (int i = 0; i < hand->n_cards; i++) {
    print_card(*(hand->cards[i]));
    if (i < hand->n_cards - 1) {
      printf(" ");
    }
  }
}

int deck_contains(deck_t * d, card_t c) {
  for (int i = 0; i < d->n_cards; i++) {
    if ((d->cards[i]->value == c.value) && (d->cards[i]->suit == c.suit) ) {
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  card_t temp;
  int r;
  for (int i = 0; i < d->n_cards; i++) {
    r = random() % d->n_cards;
    temp = *(d->cards)[i];
    *(d->cards)[i] = *(d->cards)[r];
    *(d->cards)[r] = temp;
  }
}

void assert_full_deck(deck_t * d) {
  for (int c = 0; c < d->n_cards; c++) {
    int count = 0; 
    for (int i = 0; i < d->n_cards; i++) {
      if ((d->cards[c]->value == d->cards[i]->value) && (d->cards[c]->suit == d->cards[i]->suit)) {
	count++;
      }
    }
    if (count != 1) {
      assert(0);
    }
  }
  
    
}
