#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"
#include "future.h"
#include "input.h"

size_t which_hand_won(deck_t ** hands, size_t * n_hands) {
  size_t resultInd = 0;
  size_t winnerInd = 0;
  for (size_t h = 1; h < *n_hands; h++) {
    if (compare_hands(hands[winnerInd], hands[h]) < 0) {
      winnerInd = h;
      resultInd = winnerInd;
    }
    else {
      if (!compare_hands(hands[winnerInd], hands[h])) {
	resultInd = *n_hands;
      }
    }   
  }
  return resultInd;
}

int main(int argc, char ** argv) {
  if (argc < 2) {
    fprintf(stderr, "Please, provide input file!\n");
    return EXIT_FAILURE;
  }
  size_t numTrials = 10000;
  if (argc == 3) {
    numTrials = atoi(argv[2]);
  }
  FILE * f = fopen(argv[1], "r");
  future_cards_t * fc = malloc(sizeof(*fc));
  fc->n_decks = 0;
  fc->decks = NULL;
  size_t * n_hands = malloc(sizeof(*n_hands));
  deck_t ** hands = read_input(f, n_hands, fc);
  deck_t * deck = build_remaining_deck(hands, *n_hands);
  size_t * table = calloc(*n_hands + 1, sizeof(*table));
  for (size_t i = 0; i < numTrials; i++) {
    shuffle(deck);
    future_cards_from_deck(deck, fc);
    table[which_hand_won(hands, n_hands)]++;
  }
  for (size_t i = 0; i < *n_hands; i++) {
    double per = (double)table[i] / (double)numTrials * 100;
    printf("Hand %zu won %zu / %zu times (%.2f%%)\n", i, table[i], numTrials, per);
  }
  printf("And there were %zu ties\n", table[*n_hands]);

  for (size_t i = 0; i < *n_hands; i++) {
    for (size_t j = 0; j < hands[i]->n_cards; j++) {
      free(hands[i]->cards[j]);
    }
    free(hands[i]->cards);
    free(hands[i]);
  }
  free(hands);
  for (size_t i = 0; i < fc->n_decks; i++) {
    free(fc->decks[i].cards);
  }
  free(fc->decks);
  free_deck(deck);
  free(fc);
  free(n_hands);
  free(table);
  
  if (fclose(f) != 0) {
    fprintf(stderr, "Failed to close the input file!\n");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
