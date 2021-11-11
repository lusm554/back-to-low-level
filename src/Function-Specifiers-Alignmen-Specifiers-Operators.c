#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

/* inline for Speed—Maybe */
static inline int add(int x, int y) {
  return x + y;
}

/* noreturn and _Noreturn */ 
noreturn void foo(void) { // this function should never return!
  printf("Have a good day!\n");
  exit(1); // and it doesn't return -- it exist here!
}

void FunctionSpecifiers(void) {
  printf("%d\n", add(1, 2));
}

int main(void) {
  FunctionSpecifiers();
  foo();
  return 0;
}

