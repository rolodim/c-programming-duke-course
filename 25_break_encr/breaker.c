#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <assert.h>

void counting(FILE * f, unsigned * array) {
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

int maxValue(unsigned * array, unsigned n) {
  int max = array[0];
  for (int i = 0; i < n; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

int maxIndex(unsigned * array, unsigned m, unsigned n) {
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
    fprintf(stderr, "Could not open file\n");
    return EXIT_FAILURE;
  }
  unsigned chars[26] = { 0 };
  counting(f, chars);
  unsigned key;
  unsigned maxCount = maxValue(chars, ALP);
  if (!maxCount) {
    fprintf(stderr, "No characters in the file!\n");
    return EXIT_FAILURE;
  }
  key = maxIndex(chars, maxCount, ALP);
  assert(key < 26 && key >= 0);
  key = (22 + key) % 26;
  printf("%d\n", key);

  if (fclose(f) != 0) {
    fprintf(stderr, "Failed to clode the input file!\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
