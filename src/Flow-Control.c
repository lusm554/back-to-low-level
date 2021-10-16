#include <stdio.h>

int main() {
  // If-else
  int x = 10;

  if (x == 10) printf("x = 10\n");

  if (x == 10) {
    printf("x = 10\n");
    printf("This log also in if block\n");
  } else if (x == 11)
    printf("x = 11\n");
  else
    printf("x = %d\n", x);

  // while
  int i = 1;
  while (i <= 10) {
    printf("%d ", i++);
    if (i > 10) 
      printf("\n");
  }
 
  // do while
  int j = 1;
  do {
    printf("%d ", j++);
  } while (j <= 10);
  printf("\n");
   
  // for
  for (int k = 0; k < 10; k++) {
    printf("%d", k);
  }
  printf("\n");

  // case
  int c = 1;
  switch (c) {
    case 0:
      printf("0\n");
      break;
    case 1:
      printf("1\n");
      break;
    default:
      printf("Is not 0 and 1");
      break;
  }

  return 0;
}

