#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert((c.value >= 2 && c.value <= VALUE_ACE)); // Checking value
  assert((c.suit >= SPADES && c.suit < NUM_SUITS)); // Checking suit
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r) {
  case STRAIGHT_FLUSH: return "Straight Flush";
  case FOUR_OF_A_KIND: return "Four Of a Kind";
  case FULL_HOUSE: return "Full House";
  case FLUSH: return "Flush";
  case STRAIGHT: return "Straight";
  case THREE_OF_A_KIND: return "Three Of a Kind";
  case TWO_PAIR: return "Two Pair";
  case PAIR: return "Pair";
  case NOTHING: return "Nothing";
  default: return "Invalid ranking"; break;
  }
}

char value_letter(card_t c) {
  return 'x';
}


char suit_letter(card_t c) {
  return 'x';
  
}

void print_card(card_t c) {

}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  return temp;
}
