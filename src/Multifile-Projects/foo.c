#include <stdio.h>

#ifndef BAR_H // if BAR_H isn't defined
#define BAR_H

// File bar.h
int add(int, int); // add the prototype

#endif // End of the #ifndef BAR_H

int main() {
  printf("%d\n", add(2, 3)); // 5
  return 0;
}

