#include "cards.h"
#include <stdio.h>

int main(void) {
  card_t card1;
  card1 = card_from_num(5);
  // printf("Testing ranking .... %s\n", ranking_to_string(FLUSH));
  print_card(card1);
}
