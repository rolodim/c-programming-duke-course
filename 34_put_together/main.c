#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  FILE * f = fopen(filename, "r");
  if (f == NULL) {
    fprintf(stderr, "File %s is empty!\n", filename);
    return NULL;
  }
  char * line = NULL;
  size_t size;
  char * value;
  counts_t * resultCounts = createCounts();
  while (getline(&line, &size, f) >= 0) {
    char * nl = strchr(line, '\n');
    *nl = '\0';
    value = lookupValue(kvPairs, line);
    addCount(resultCounts, value);
  }
  free(line);
  if (fclose(f) != 0) {
    fprintf(stderr, "Failed to close the input file!\n");
    return NULL;
  }
  return resultCounts;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
 //read the key/value pairs from the file named by argv[1] (call the result kv)
  if (argc < 3) {
    fprintf(stderr, "Too few agruments!\n");
    return EXIT_FAILURE;
  }

  kvarray_t * kv = readKVs(argv[1]);
    
 //count from 2 to argc (call the number you count i)
  for (size_t i = 2; i < argc; i++) {
    
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)
    counts_t * c = countFile(argv[i], kv);
    
    //compute the output file name from argv[i] (call this outName)
    char * outName = computeOutputFileName(argv[i]);

    //open the file named by outName (call that f)
    FILE * f = fopen(outName, "w");

    //print the counts from c into the FILE f
    printCounts(c, f);

    //close f
    if (fclose(f) != 0) {
      fprintf(stderr, "Failed to close the counts file!\n");
      return EXIT_FAILURE;
    }

    //free the memory for outName and c
    free(outName);
    freeCounts(c);
  }

 //free the memory for kv
  freeKVs(kv);

  return EXIT_SUCCESS;
}
