#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "rotate.c"

#define SIZE 10

void rotate(char matrix[10][10]);

int main(int argc, char ** argv) {

  if (argc != 2) {
    fprintf(stderr, "Input file is not given!\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL) {
    fprintf(stderr, "The file is empty!\n");
    return EXIT_FAILURE;
  }

  char matrix[SIZE][SIZE+2];
  char result[SIZE][SIZE];
  int r = 0;
  while (fgets(matrix[r], SIZE + 2, f) != NULL) {
    if (((strchr(matrix[r], '\n') - matrix[r]) != matrix[r][SIZE])) {
      fprintf(stderr, "Incorrect line in the input file - %d\n", r);
      return EXIT_FAILURE;
    }
    //printf("Row %d \\n found in %d position.\n", i, (int)(strchr(matrix[i], '\n') - matrix[i]));
    for (int j = 0; j < SIZE; j++) {
      result[r][j] = matrix[r][j];
    }
    if (r == SIZE - 1) {
      break;
    }
    r++;
  }
  if (r != SIZE - 1) {
    fprintf(stderr, "Invalid input matrix. Number of the rows: %d\n", r);
    return EXIT_FAILURE;
  }
  rotate(result);
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%c", result[i][j]);
    }
    printf("\n");
  }
      

  if (fclose(f) != 0) {
    fprintf(stderr, "Failed to close the input file!\n");
    return EXIT_FAILURE;
  }
  
  return EXIT_SUCCESS;
}
