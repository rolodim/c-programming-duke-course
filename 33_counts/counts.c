#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  counts_t * c = malloc(sizeof(*c));
  c->size = 0;
  c->counts = NULL;
  c->unknown = 0;
  return c;
}

int isInArray(counts_t * c, const char * name) {
  for (int i = 0; i < c->size; i++) {
    if (strcmp(c->counts[i]->string, name) == 0) {
      c->counts[i]->string = name;
      c->counts[i]->count++;
      return i;
    }
  }
  return -1;
}
      

void addCount(counts_t * c, const char * name) {
  if (name == NULL) {
    c->unknown++;
  }
  else {
    int index = isInArray(c, name);
    if (index < 0) {
      c->counts = realloc(c->counts, (c->size+1) * sizeof(*c->counts));
      c->counts[c->size] = malloc(sizeof(*c->counts[c->size]));
      c->counts[c->size]->string = name;
      c->counts[c->size]->count = 1;
      c->size++;
    }
  }
}
      
void printCounts(counts_t * c, FILE * outFile) {
  for (size_t i = 0; i < c->size; i++) {
    fprintf(outFile, "%s: %ld\n", c->counts[i]->string, c->counts[i]->count);
  }
  if (c->unknown > 0) {
    fprintf(outFile, "<unknown> : %ld\n", c->unknown);
  }
}

void freeCounts(counts_t * c) {
  for (size_t i = 0; i < c->size; i++) {
    free(c->counts[i]);
  }
  free(c->counts);
  free(c);
}
