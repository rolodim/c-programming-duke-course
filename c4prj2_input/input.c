#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include <ctype.h>

deck_t * createEmptyDeck(void);

size_t chars_to_int(char * c, size_t j) {
  if (j < 3) {
    return c[1]-'0';
  }
  else {
    return (c[1]-'0') * 10 + (c[2] - '0');
  }
}

deck_t * hand_from_string(const char * str, future_cards_t * fc) {
  deck_t * d = createEmptyDeck();
  char c[4];
  size_t j = 0;
  if (strlen(str) > 12) {
    for (size_t i = 0; i < strlen(str); i++) {
      if (!isspace(str[i])) {
	c[j] = str[i];
	j++;
      }
      if (j > 1 && !isdigit(str[i+1])) {
	if (c[0] == '?') {
	  printf("Value = %c, Index = %ld\n", c[0], chars_to_int(c, j));
	  add_future_card(fc, chars_to_int(c, j), add_empty_card(d));
	}
	else {
	  add_card_to(d, card_from_letters(c[0], c[1]));
	}
	j = 0;
      }
    }
  }
  else {
    printf("Number of the cards in the hand is too small!\n");
    return NULL;
  }
  return d;
}

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc) {
  if (f == NULL) {
    fprintf(stderr, "Input file is empty!\n");
    return NULL;
  }
  deck_t ** hands = NULL;
  char * line = NULL;
  size_t size;
  size_t d = 0;
  char * nl;
  while (getline(&line, &size, f) >=0) {
    nl = strchr(line, '\n');
    *nl = '\0';
    hands = realloc(hands, (d+1) * sizeof(*hands)); 
    hands[d] = hand_from_string(line, fc);
    line = NULL;
    d++;
  }
  free(line);
  *n_hands = d;

  return hands;
}
