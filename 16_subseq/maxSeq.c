#include <stdio.h>
#include <stdlib.h>

int isIncreasing(int a, int b) {
  if (a > b) {
    return 1;
  }
  else {
    return 0;
  }
}

size_t maxSeq(int * array, size_t n) {
  size_t result = 1;
  size_t count = 1;
  if (n != 0) {
    for (int i = 0; i < n - 1; i++) {
      if (array[i] < array[i+1]) {
	count++;
	if (count > result) {
	  result = count;
	}
      }
      else {
	count = 1;
      }
    }
    return result;
  }
  else {
    return 0;
  }
}
