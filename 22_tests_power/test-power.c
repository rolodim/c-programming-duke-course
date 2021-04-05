#include <stdlib.h>
#include <stdio.h>

unsigned power(unsigned x, unsigned y);

unsigned powerTest(unsigned x, unsigned y) {
  if (y <= 0) {
    return 1;
  }
  else {
    while (y > 1) {
      x *= x;
      y--;
    }
    return x;
  } 
};

typedef struct case_type {
  unsigned x;
  unsigned y;
} case_t;

int main(void) {
  
  case_t c1 = { 0, 0 };
  case_t c2 = { -5, 1 };
  case_t c3 = { 1, 2 };
  case_t c4 = { 4, 3 };

  if (power(c1.x, c1.y) != 1) {
    exit(EXIT_FAILURE);
    printf("Test 1 failed!\n");
  };
  if (power(c2.x, c2.y) != -5) {
    exit(EXIT_FAILURE);
    printf("Test 2 failed!\n");
  };
  if (power(c3.x, c3.y) != 1) {
    exit(EXIT_FAILURE);
    printf("Test 1 failed!\n");
  };
  if (power(c4.x, c4.y) != 64) {
    exit(EXIT_FAILURE);
    printf("Test 1 failed!\n");
  };
  printf("All the tests are completed seccessfully!\n");
  return EXIT_SUCCESS;
  
}
