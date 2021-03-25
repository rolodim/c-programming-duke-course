#include <stdlib.h>

void rotate(char matrix[10][10]) {
  char tempMatrix[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tempMatrix[i][j] = matrix[i][j];
    }
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      matrix[i][j] = tempMatrix[10 - j - 1][i];
    }
  }
}
