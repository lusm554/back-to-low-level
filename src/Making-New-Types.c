#include <stdio.h>

/* typedef in Theory */
void typedef_in_theory() {
  typedef int antelope; // make "antelope" an alias for "int"

  antelope x = 10; // type "antelope" is the same as type "int"

  printf("antelope: %d\n", x);
}

/* typedef and structs */
void typedef_and_structs() {
  struct animal {
    char *name;
    int leg_count, speed;
  };

//    original name    new name
//              |         |
//              ↓         ↓
//        |-----------| |----|
  typedef struct animal animal;

  struct animal x; // this works
  animal z; // this also works because "animal" is an alias

  /*
  * the same as the above, just more concise.

//        original name
//        |-----------|
  typedef struct animal {
    char *name;
    int leg_count, speed;
  } animal; // new name

  struct animal y;
  animal z;
  */


  /*
  * anonymous structure

//    Anonymous struct! It has no name!
//          ↓
//        |----|
  typedef struct {
    char *name;
    int leg_count, speed;
  } animal; // new name
  */

  typedef struct {
    int x, y;
  } point;

  point p = {.x=10, .y=20};
  printf("%d, %d\n", p.x, p.y); // 10, 20
}

/* typedef and Other Types */
void typedef_and_other_types() {
  // typedef and Pointers
  typedef int *intptr;
  int a = 10;
  intptr x = &a;

  // Arrays and typedef
  typedef int five_ints[5];

  five_ints y = {1, 2, 3, 4, 5};
  printf("Second int: %d\n", y[1]);
}

int main() {
  /* typedef in Theory */
  typedef_in_theory();
  
  /* typedef and structs */
  typedef_and_structs();

  /* typedef and Other Types */
  typedef_and_other_types();

  return 0;
}

