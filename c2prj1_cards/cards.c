#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2);
  assert(c.value <= VALUE_ACE); // Checking value
  assert((c.suit >= SPADES && c.suit < NUM_SUITS)); // Checking suit
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
  case FULL_HOUSE: return "FULL_HOUSE";
  case FLUSH: return "FLUSH";
  case STRAIGHT: return "STRAIGHT";
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
  case TWO_PAIR: return "TWO_PAIR";
  case PAIR: return "PAIR";
  case NOTHING: return "NOTHING";
  default: return "Invalid ranking"; break;
  }
}

char value_letter(card_t c) {
  char charValue;
  if (c.value >= 2 && c.value <=10) {
    charValue = c.value % 10 + '0';
  }
  else {
    switch (c.value) {
      case VALUE_JACK: charValue = 'J'; break;
      case VALUE_QUEEN: charValue = 'Q'; break;
      case VALUE_KING: charValue = 'K'; break;
      case VALUE_ACE: charValue = 'A'; break;
      default: charValue = 'e'; break;
    }
  }
  return charValue;
}

char suit_letter(card_t c) {
  switch (c.suit) {
  case SPADES: return 's';
  case HEARTS: return 'h';
  case DIAMONDS: return 'd';
  case CLUBS: return 'c';
  default: return 'e';
  }
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));
}

card_t value_from_letter(char value) {
  card_t card;
  switch (value) {
  case 'J': card.value = VALUE_JACK; break;
  case 'Q': card.value = VALUE_QUEEN; break;
  case 'K': card.value = VALUE_KING; break;
  case 'A': card.value = VALUE_ACE; break;
  case '0': card.value = 10; break;
  default: card.value = value - '0'; break;
  }
  return card;
}

card_t suit_from_letter(char suit) {
  card_t card;
  switch (suit) {
  case 's': card.suit = SPADES; break;
  case 'h': card.suit = HEARTS; break;
  case 'd': card.suit = DIAMONDS; break;
  case 'c': card.suit = CLUBS; break;
  default: card.suit = NUM_SUITS; break;
  }
  return card;
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  temp = value_from_letter(value_let);
  temp = suit_from_letter(suit_let);
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  if (c >= 0 && c < 52) {
    temp.value = c % 13 + 2;
    temp.suit = c / 13;
  }
  return temp;
}
