#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}

void readLine(FILE * f) {
  char ** lines = NULL;
  char * line = NULL;
  size_t size;
  size_t i = 0;
  while (getline(&line, &size, f) >= 0) {
      lines = realloc(lines, (i + 1) * sizeof(*lines));
      lines[i] = line;
      line = NULL;
      i++;
    }
  free(line);
  sortData(lines, i);
  for (size_t j = 0; j < i; j++) {
    printf("%s", lines[j]);
    free(lines[j]);
  }
  free(lines);
}

int main(int argc, char ** argv) {
  if (argc == 1) {
    readLine(stdin);
  }
  else {
    for (size_t i = 1; i < argc; i++) {
      FILE * f = fopen(argv[i], "r");
      if (f == NULL) {
	fprintf(stderr, "The file is empty: %s\n", argv[i]);
	return EXIT_FAILURE;
      }
      readLine(f);
      if (fclose(f) != 0) {
	fprintf(stderr, "Failed to close the input file!\n");
	return EXIT_FAILURE;
      }
    }
  }
      
  //WRITE YOUR CODE HERE!
  
  return EXIT_SUCCESS;
}
