#include <stdio.h>
#include <stddef.h>

void Pointers2Pointers(void) {
  int x = 3490; // Type: int
  int *p = &x;  // Type: pointer to an int
  int **q = &p; // Type: pointer to pointer to int


  printf("%d\n", *p); // 3490
  printf("Address to *p: %p p: %p\n", (void *)*q, (void *)p);
  printf("x from q: %d, x from p: %d\n", **q, *p);
  
  // Pointer Pointers and const
  int y = 23415;
  int *const yp = &y;
  int *const *const yq = &yp; // More const!
  (void)yq; // prevent warnings
}

void MultibyteValues(void) {
  struct foo {
    char a;
    int b;
  };

  struct foo x = {0x12, 0x12345678};
  unsigned char *p = (unsigned char *)&x;

  printf("Bytes:\n");
  for (size_t i = 0; i < sizeof x; i++) {
    printf("  %02X\n", p[i]);
  }
}

void PointerDifferences(void) {
  int cats[100];

  int *f = cats + 20;
  int *g = cats + 60;

  ptrdiff_t d = g - f; // defference is 40

  printf("Pointer Differences:\n"); 
  printf("%td\n", d); // print decimal: 40
  printf("%tX\n", d); // print hex:     28
}

void print_int(int n);
int add(int a, int b);
int mult(int a, int b);
void print_math(int (*op)(int, int), int x, int y);

void Pointers2Functions(void) {
  // Declare p to be a pointer to a function.
  // This function returns a float, and takes two ints as arguments.
  
  float (*p)(int, int); // same as: float(*p)(int a, int b);
  (void)p; // prevent warnings
  
  // Assign pp to point to print_int:
  void (*pp)(int) = print_int;
  
  pp(3490);

  print_math(add, 5, 4);
  print_math(mult, 4, 5);
}

int main(void) {
  Pointers2Pointers();
  MultibyteValues();
  PointerDifferences();
  Pointers2Functions();
  return 0;
}

// for: Multibyte Values
void *my_memcpy(void *dest, const void *src, size_t n) {
  // Make local variables for src and dest, but of type unsigned char
  
  const unsigned char *s = src;
  unsigned char *d = dest;

  while (n-- > 0) // For the given number of bytes
    *d++ = *s++;  // Copy source byte to dest byte

  // Most copy functions return a pointer to the dest as a convenience
  // to the caller
  
  return dest;
}

void print_int(int n) {
  printf("%d\n", n);
}

int add(int a, int b) {
  return a + b;
}

int mult(int a, int b) {
  return a * b;
}

void print_math(int (*op)(int, int), int x, int y) {
  int result = op(x, y);

  printf("%d\n", result);
}

