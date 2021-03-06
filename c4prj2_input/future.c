#include <stdio.h>
#include <stdlib.h>
#include "future.h"

void add_future_card(future_cards_t * fc, size_t index, card_t * ptr) {
  if (fc->n_decks <= index) {
    fc->decks = realloc(fc->decks, (index+1) * sizeof(*fc->decks));
    for (size_t i = fc->n_decks; i <= index; i++) {
      fc->decks[i].n_cards = 0;
      fc->decks[i].cards = NULL;
    }
    fc->n_decks = index + 1;
  }
  fc->decks[index].cards = realloc(fc->decks[index].cards, (fc->decks[index].n_cards+1) * sizeof(*fc->decks[index].cards));
  fc->decks[index].cards[fc->decks[index].n_cards] = ptr;
  fc->decks[index].n_cards++;
    
}

void future_cards_from_deck(deck_t * deck, future_cards_t * fc) {
  size_t c = 0;
  //printf("n_cards = %ld, n_decks = %ld\n",deck->n_cards, fc->n_decks);
   for (size_t i = 0; i < fc->n_decks; i++) {
     if (deck->n_cards >= fc->n_decks) {
       if (fc->decks[i].n_cards > 0) {
	for (size_t j = 0; j < fc->decks[i].n_cards; j++) {
	  fc->decks[i].cards[j]->value = deck->cards[c]->value;
	  fc->decks[i].cards[j]->suit = deck->cards[c]->suit;
	}
	c++;
       }
     }
     else {
       fprintf(stderr, "Too few cards in the deck!\n");
       return;
     }
  }
}
