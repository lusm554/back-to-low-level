#include <stdio.h>

// int function
int plus_one(int n) {
  return n + 1;
}

// void function, indicate that you don't return a value
void hello(void) {
  printf("Hello\n");
}

// Increment int, but actually...
void increment(int a) {
  a++;
}

void foo(void); // Prototype for compiler

int main() {
  int i = plus_one(1);
  printf("%d\n", i);

  hello();

  int test = 10;
  increment(test);
  printf("%d\n", test); // magic! It's 10.

  foo();

  return 0;
}

void foo(void) { // Definition
  printf("Functions under the main cool!!\n");
}

