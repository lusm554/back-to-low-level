#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AllocatingAndDeallocating(void) {
  int *p = malloc(sizeof(int)); // allocate space for a single int
  // --same--
  //int *p = malloc(sizeof *p); // *p is an int, so same as sizeof(int)

  *p = 12; // store something there
  printf("%d\n", *p); // 12

  free(p); // all done with that memory

  //*p = 3241; // ERROR: undefined behavior! Use after free()!
}

void ErrorChecking(void) {
  int *x;

  /*
  x = malloc(sizeof(int) * 10);
  if (x == NULL) {
    printf("Error allocating 10 ints\n");
  }
  */

  // same

  if ((x = malloc(sizeof(int) * 10)) == NULL) 
    printf("Error allocating 10 ints\n");
}

void AllocatingSpaceForAnArray(void) {
  int *p = malloc(sizeof(int) * 10); // allocate space for 10 ints

  // assing values
  for (int i = 0; i < 10; i++)
    p[i] = i + 1; 

  // print all values
  for (int i = 0; i < 10; i++)
    printf("%d ", p[i]);
  
  // free the space
  free(p);

  printf("\n");
}

void AnAlternativeCalloc(void) {
  int *p = calloc(sizeof(int), 10); // allocate space for 10 int with calloc, initialized to 0
  
  // allocate space for 10 ints with malloc(), initialized to 0
  int *q = malloc(sizeof(int) * 10);
  memset(q, 0, sizeof(int) * 10); // set to 0
  
  // Test
  for (int i = 0; i < 10; i++) {
    printf("p: %d q: %d\n", *(p + i), *(q + i));
  }

  // Free the space
  free(p);
  free(q);
}

int ChangingAllocatedSize(void) {
  // allocate space for 20 floats
  float *p = malloc(sizeof *p * 20); // sizeof *p same as sizeof(float)  

  // Assing them fractional values 0.0-1.0
  for (int i = 0; i < 20; i++)
    p[i] = i / 20.0; 
  
  // buf wait! let's actually make this an array of 40 elems
  float *new_p = realloc(p, sizeof *p * 40);

  if (new_p == NULL) {
    printf("Error reallocing\n");
    return 1;
  }

  // if we did, we can just reassing p
  p = new_p;

  // and assign the new elems values in the range 1.0-2.0
  for (int i = 20; i < 40; i++)
    p[i] = 1.0 + (i - 20) / 20.0; 

  // print all values 0.0-2.0 in the 40 elems
  for (int i = 0; i < 40; i++)
    printf("i %d: %f\n", i, p[i]);

  free(p);
  return 0;
}

// Reading in Lines of Arbitrary Length
char *readline(FILE *fp) {
  int offset = 0;  // index next char goes in the buffer
  int bufsize = 4; // preferably power of 2 initial size  
  char *buf;       // the buffer
  int c;           // the character we've read in

  buf = malloc(bufsize); // allocate intitial buffer

  if (buf == NULL) // error check
    return NULL;

  // main loop--read until newline or EOF
  while (c = fgetc(fp), c != '\n' && c != EOF) {
    
    // check if we're out of room in the buffer accounting
    // for the extra byte for the NUL terminator
    if (offset == bufsize - 1) { // -1 for the NUL terminator
      bufsize *= 2; // 2x the space
      
      char *new_buf = realloc(buf, bufsize);

      if (new_buf == NULL) {
        free(buf); // on error, free and bail
        return NULL;
      }
      
      buf = new_buf; // successful realloc
    }
    
    buf[offset++] = c; // add the byte onto the buffer
  }

  // if at EOF and we read no bytes, free the buffer and
  // return NULL to indicate we're at EOF
  if (c == EOF && offset == 0)  {
    free(buf);
    return NULL;
  }

  // shrink to fit
  if (offset < bufsize - 1) { // if we're short of the end
    char *new_buf = realloc(buf, offset + 1); // +1 for NUL terminator

    // if successful, point buf to new_buf;
    // otherwise we'll just leave buf where it is
    if (new_buf != NULL)
      buf = new_buf;
  }

  // add the NUL terminator
  buf[offset] = '\0';

  return buf;
}

void ReadingInLinesOfArbitraryLength() {
  FILE *fp = fopen("IOFiles/foo.txt", "r");

  char *line;

  while ((line = readline(fp)) != NULL) {
    printf("%s\n", line);
    free(line);
  }

  fclose(fp);

  /* realloc() with NULL */
  /*
  char *p = malloc(3490);
  -- same --
  char *p = realloc(NULL, 3490);

  // Example
  int *p = NULL;
  int length = 0;

  while (!done) {
    length += 10;
    p = realloc(p, sizeof *p * length);

    // do cool things
  }
  // In that example, we didn't need an initial malloc() since p was NULL to start.
  */
}

void AlignedAllocations(void) {
  // allocate 256 bytes aligned on a 64-byte boundary 
  char *p = aligned_alloc(64, 256); // 256 = 64 * 4  

  // cope a string in there and print it
  strcpy(p, "Hello, World!");
  printf("%s\n", p);

  // free the space
  free(p);
}

int main(void) {
  AllocatingAndDeallocating();
  ErrorChecking();
  AllocatingSpaceForAnArray();
  AnAlternativeCalloc();
  int status = ChangingAllocatedSize();
  if (status != 0)
    return status;
  ReadingInLinesOfArbitraryLength();
  AlignedAllocations();

  return 0;
}

