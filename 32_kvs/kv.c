#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvarray_t * readKVs(const char * fname) {
  kvarray_t * map = malloc(sizeof(*map));
  char * line = NULL;
  map->elements = NULL;
  size_t s;
  size_t i = 0;
  FILE * f = fopen(fname, "r");
  if (f == NULL) {
    fprintf(stderr, "File (%s) is empty!\n", fname);
    return NULL;
  }
  while (getline(&line, &s, f) >= 0) {
    map->elements = realloc(map->elements, (i+1) * sizeof(map->elements));
    map->elements[i] = malloc(sizeof(*map->elements[i]));
    size_t index = strchr(line, '=') - line;
    char * nl = strchr(line, '\n');
    *nl = '\0';
    line[index] = '\0';
    map->elements[i]->key = line;
    map->elements[i]->value = &line[index+1];
    line = NULL;
    i++;
  }
  free(line);
  map->size = i;
  if (fclose(f) != 0) {
    fprintf(stderr, "Failed to close the input file!\n");
    return NULL;
  }
  return map;
}

void freeKVs(kvarray_t * pairs) {
  for (size_t i = 0; i < pairs->size; i++) {
    free(pairs->elements[i]->key);
    free(pairs->elements[i]);
  }
  free(pairs->elements);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  for (size_t i = 0; i < pairs->size; i++) {
    printf("key = '%s' value = '%s'\n", pairs->elements[i]->key, pairs->elements[i]->value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  for (size_t i = 0; i < pairs->size; i++) {
    if (strcmp(pairs->elements[i]->key, key) == 0) {
      return pairs->elements[i]->value;
    }
  }
  return NULL;
}
