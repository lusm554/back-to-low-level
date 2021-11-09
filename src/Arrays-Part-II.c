#include <stdio.h>

// the compiler is going to assume that any array you pass to the function will be at least 4 elements
int func_st(int p[static 4]) {
  (void)p;
  return 1;
}

void staticForArraysInParameterLists(void) {
  int a[] = {1, 2, 3, 4};
  int b[] = {1, 2, 3, 4, 5};
  int c[] = {1, 2, 3};

  func_st(a); // ok
  func_st(b); // ok
  //func_st(c); // undefined behavior! c is under 4 elements!
  
  (void)c; // prevent warning
}

void EquivalentInitializers(void) {
  int a[3][2] = { 1, 2, 3, 4, 5, 6 };
  
  for (int i = 0; i < 3; i++)
    printf("i = %d, [%d, %d]\n", i, a[i][0], a[i][1]);

  // fill the whole array with 0
  int b[3][2] = {0};
}

int main(void) {
  staticForArraysInParameterLists();
  EquivalentInitializers();
  return 0;
}

