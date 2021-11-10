#include <stdio.h>

int main(void) {
  /* Use Case: Self-Referential Structures */
  struct node {
    int val;
    struct node *next; // struct node is incomplete, but that's OK!
  };

  struct a {
    struct b *x; // reference to a 'struct b'
  };

  struct b {
    struct a *x; // reference to a 'struct a'
  };
  
  /* Completing Incomplete Types */ 

  struct foo; // incomplete type

  struct foo *p; // pointer, no problem
  
  // struct foo f; // Error: incomplete type!

  struct foo {
    int x, y, z;
  }; // now the struct foo is complete!

  struct foo f; // Success
    
  void *pp; // OK: pointer to incomplete type

  //void v; // Error: declare variale of incomplete type

  //printf("%d\n", *pp); // Error: dereference incomplete type

  (void)p; (void)f; (void)pp; // prevent warnings

  return 0;
}

