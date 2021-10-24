#include <stdio.h>

void Const(void) {
  const int x = 2;

  //x = 4; // Error: cannot assign to variable 'x' with const-qualified type 'const int'

  printf("%d\n", x);
}

void foo(const int x) {
  printf("%d\n", x + 10); // ok, doesn't modify "x"
}

void ConstAndPoints(void) {
  int x[] = {10, 20};
  const int *p = x;

  p++; // We can modify p, no problem

  //*p = 30; // Error: read-only variable is not assignable
 
  int *const newp; // We can't modify "p" with pointer arithmetic 

  //newp++; // Error!

  // But we can modify what they point to
  int y = 10;
  int *const yp = &y;

  *yp = 20; // Set "x" to 20, no problem

  // const int *const p; // Can't modify p or *p!
} 

void swap(int *restrict a, int *restrict b);

void FunWithRestrict(void) {
  int x = 10, y = 20;

  printf("x: %d, y: %d\n", x, y);

  swap(&x, &y); // OK! "a" and "b", above, point to different things  

  printf("x: %d, y: %d\n", x, y);

  swap(&x, &x); // Undefined behavior! "a" and "b" point to the same thing

  printf("x: %d, y: %d\n", x, y);
}

void counter(void);

void StorageClassSpecifiers() {
  /* static in Block Scope */
  
  counter(); // This has been called 1 times
  counter(); // This has been called 2 times
  counter(); // This has been called 3 times

  static int foo; // Default starting value is '0'

  /* register */
  register int a; // Make "a" as fast to use as possible
  //int *p = &a; // ERROR: address of register variable requested
  
  register int b[] = {1, 2, 3, 4, 5};
  //int *p = &b; // ERROR: address of register variable requested
  
  //int *p = b[2]; // WARNING

  /* A bit of history.
  Registers stored in CPU, this is why they are super fast to access compared to RAM,
  so using them gets you a speed boost. But they're not in RAM, so they don't have 
  an associated memory address.
  */
}

int main() {
  Const();
  foo(11);
  ConstAndPoints();
  FunWithRestrict();
  StorageClassSpecifiers();
  return 0;
}

void swap(int *restrict a, int *restrict b) {
  int t;

  t = *a;
  *a = *b;
  *b = t;
}

void counter(void) {
  static int count = 1; // This is initialized one time

  printf("This has been called %d times\n", count);

  count++;
}

