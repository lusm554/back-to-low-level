#include <stdio.h>
// for access to sumbolic boolean names
#include <stdbool.h>

int main() {
  // Variable Names  
  int a = 1;
  int __ = 2;
  int b1 = 3;
  int a_a1 = 4;
  int A_A1 = 5;

  printf("%d\n", a);
  printf("%d\n", __);
  printf("%d\n", b1);
  printf("%d\n", a_a1);
  printf("%d\n", A_A1);

  // Variable Types
  int intt = 456;
  float fl = 0.01;
  char c[2] = "s";
  char *s = "game";
  
  printf("%d\n", intt);
  printf("%f\n", fl);
  printf("%s\n", c);
  printf("%s\n", s);
  
  bool b = true;
  if (b) { printf("b is true! (btw, this line use <stdbook.h>)\n"); }

  int bTrue = 1;
  int bFalse = 0;
  if (bTrue && !bFalse) { printf("In C, 0 means \"false\", and non-zero means \"true\"\n"); }

  return 0;
}

