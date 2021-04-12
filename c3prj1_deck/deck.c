#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
#define FULL_DECK 52

void print_hand(deck_t * hand){
  for (int i = 0; i < hand->n_cards; i++) {
    print_card(*(hand)->cards[i]);
    printf(" ");
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
  for (int i = 0; i < d->n_cards / 4; i++) {
    r = random() % d->n_cards;
    temp = *(d->cards)[i];
    *(d->cards)[i] = *(d->cards)[r];
    *(d->cards)[r] = temp;
  }
}

void assert_full_deck(deck_t * d) {
  card_t card;
  for (int c = 0; c < d->n_cards; c++) {
    int count = 0;
    card = *(d->cards)[c];
    //assert_card_valid(card);
    for (int i = 0; i < d->n_cards; i++) {
      if ((card.value == d->cards[i]->value) && (card.suit == d->cards[i]->suit)) {
	count++;
      }
    }
    assert(count == 1);
  }
}

void add_card_to(deck_t * deck, card_t c) {
  deck->cards = realloc(deck->cards, (deck->n_cards+1) * sizeof(*deck->cards));
  deck->cards[deck->n_cards] = malloc(sizeof(*deck->cards[deck->n_cards])); //change to correct type representation
  deck->cards[deck->n_cards]->value = c.value;
  deck->cards[deck->n_cards]->suit = c.suit;
  deck->n_cards++;
}

card_t * add_empty_card(deck_t * deck) {
  card_t c;
  c.value = 0;
  c.suit = 0;
  add_card_to(deck, c);
  return deck->cards[deck->n_cards-1];
}

deck_t * createEmptyDeck(void) {
  deck_t * d;
  d = malloc(sizeof(*d));
  d->cards = NULL;
  d->n_cards = 0;
  return d;
}

deck_t * make_deck_exclude(deck_t * excluded_cards) {
  deck_t * d;
  d = malloc(sizeof(*d));
  d->cards = NULL;
  d->n_cards = 0;
  for (size_t i = 0; i < FULL_DECK; i++) {
    card_t c = card_from_num(i);
    if (!deck_contains(excluded_cards, c)) {
      add_card_to(d, c);
    }
  }
  return d;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
  deck_t hands_d;
  hands_d.cards = NULL;
  hands_d.n_cards = 0;
  for (size_t i = 0; i < n_hands; i++) {
    for (size_t j = 0; j < hands[i]->n_cards; j++) {
      add_card_to(&hands_d, *hands[i]->cards[j]);
    }
  }
  
  return make_deck_exclude(&hands_d);
}

void free_deck(deck_t * deck) {
  for (size_t i = 0; i < deck->n_cards; i++) {
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}
