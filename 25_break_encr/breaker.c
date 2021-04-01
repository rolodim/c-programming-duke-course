#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

void counting(FILE * f, int * array) {
  int c;
  while ((c = fgetc(f)) != EOF) {
    if (isalpha(c)) {
      c = tolower(c);
      c -= 'a';
      c %= 26;
      array[c]++;
    }
  }
}

int maxValue(int * array, int n) {
  int max = array[0];
  for (int i = 0; i < n; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

int maxIndex(int * array, int m, int n) {
  for (int i = 0; i < n; i++) {
    if (array[i] == m) {
      return i;
    }
  }
  return -1;
}


int main(int argc, char ** argv) {
  const int ALP = 26;
  if (argc != 2) {
    fprintf(stderr, "Usage: decrypt file is not found\n");
    return EXIT_FAILURE;
    }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "Could not open file");
    return EXIT_FAILURE;
  }
  int chars[26] = { 0 };
  counting(f, chars);
  int key;
  key = maxIndex(chars, maxValue(chars, ALP), ALP);
  assert(key < 26 && key >= 0);
  printf(key);

  if (fclose(f) != 0) {
    fprintf(stderr, "Failed to clode the input file!");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
