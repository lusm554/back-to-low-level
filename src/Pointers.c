#include <stdio.h>

void increment(int *p) { // accepts a pointer to an int
  ++(*p);
  // or *p = *p + 1;
}

int main() {
  int i = 10;
  // &i – address of i, pointer

  // %p – prints a pointer
  printf("i = %d, address = %p\n", i, &i);

  // How write pointer to var??
  int *i_pointer = &i; 
  printf("%p\n", i_pointer);
   
  // How get data by pointer(address)?
  int n;
  int *p_n; // this is NOT a dereference, this is type "int*" 

  p_n = &n;
  n = 10;

  // Dereference
  *p_n = 20; // p_n is now 20, like n = 20

  printf("%d\n", n); // 20
  printf("%d\n", *p_n); // 20, dereference p_n is the same as n

  // Examples
  int count = 10;
  int *p_count = &count;

  increment(p_count);
  printf("%d\n", count);

  //–––––––––––––––––––
  
  int input = 0;
  scanf("%d", &input);
  printf("Your input: %d\n", input);

  // A Note on Declaring Pointers   
  /*
  int a;
  int *b;
  
  --same--

  int a, *b;

  --same--
  int *b, a;

  */

  // sizeof and Pointers
  int *s;
  printf("Size of pointer: %zu\n", sizeof s);
  printf("Size of int type: %zu\n", sizeof *s);
  
  return 0;
}
