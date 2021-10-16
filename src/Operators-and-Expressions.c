#include <stdio.h>

int main() {
  // Think, i can skip arithmetic...

  // Ternary 
  int tr = 1;
  int n = !!tr ? 10 : 20;

  printf("%d\n", n);

  // Pre-and-Post Increment-and-Decrement
  int i, j;
    
  i = 10;
  j = 5 + i++;

  printf("%d, %d\n", i, j); // 11, 15

  i = 10;
  j = 5 + ++i;
  
  printf("%d, %d\n", i, j); // 11, 16

  // The Comma Operator
  int x, y;

  x = 1, y = 2;
  printf("%d, %d\n", x, y);

  for (x = 0, y = 0; y < 10; x--, y++) {}
  printf("%d, %d\n", x, y);

  // Also, skip conditional and boolean operators
  
  // The sizeof Operator
  // Get size (in bytes) of particular variable or data type uses in memory.
  int whatsize;
  size_t sizeOfWhatSize;

  sizeOfWhatSize = sizeof whatsize;
  
  /*
  * %zu – print positive size_t
  * %zd – print negative size_t
  */

  printf("%zu\n", sizeOfWhatSize); // 4 bytes in my system
  printf("%zu\n", sizeof 3.14); // 8 bytes in my system
    
  printf("%zu\n", sizeof(int)); // 4 bytes in my system
  printf("%zu\n", sizeof(char)); // 1 on all systems

  return 0;
}
