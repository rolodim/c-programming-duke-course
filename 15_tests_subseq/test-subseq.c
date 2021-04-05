#include <stdio.h>
#include <stdlib.h>
#define NUM_CASES (4)

size_t maxSeq(int * array, size_t n);

int main(void) {
  
  int passedTests = 0;
  size_t result;

  int arr1[] = { 0, 1, 2, 3, 4, -4, -3, -2, 0 };
  result = maxSeq(arr1, 9);
  if (result == 5) {
    passedTests++;
  };

  int arr2[] = { };
  result = maxSeq(arr2, 0);
  if (result == 0) {
    passedTests++;
  };

  int arr3[] = { 0 , 0 };
  result = maxSeq(arr3, 2);
  if (result == 1) {
    passedTests++;
  };

  int arr4[] = { 1, 1, 2, 2};
  result = maxSeq(arr4, 4);
  if (result == 2) {
    passedTests++;
  };
  
  if (passedTests == 4) {
    return EXIT_SUCCESS;
  }
  else {
    return EXIT_FAILURE;
  };
}
