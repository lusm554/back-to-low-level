#include <stdio.h>

struct test {
  char *str_field;
  int some_num;
};

void set_str_field(struct test *t, char *str);
void set_str_field_arrow(struct test *t, char *str);

int main() {
  /* Declaring a Struct */
  struct car {
    char *name;
    float price;
    int speed;
  };

  struct car audi;

  audi.name = "Audi RS 7 Sportback";
  audi.price = 145349.86;
  audi.speed = 305; // km/h

  printf("Name:          %s\n", audi.name);
  printf("Price:         %f\n", audi.price);
  printf("Max speed(km): %d\n", audi.speed);

  /* Struct Initializers */
  // Now with an initializer! Should be same field order as in the struct declarationl
  struct car bmw = {"BMW M5 CS", 138376.00, 305};  

  printf("Name:          %s\n", bmw.name);
  printf("Price:         %f\n", bmw.price);
  printf("Max speed(km): %d\n", bmw.speed);


  // price field will be 0.0
  struct car mercedes = {.name="Mercedes-AMG GT", .speed=325};

  printf("Name:          %s\n", mercedes.name);
  printf("Price:         %f\n", mercedes.price);
  printf("Max speed(km): %d\n", mercedes.speed);

  /* Passing Structs to Functions */
  struct test test1 = {.some_num=1};
  set_str_field(&test1, "test_132423"); // Call func with struct pointer and test string

  printf("Field after simple func: %s\n", test1.str_field);

  /* The Arrow Operator */
  struct test test2 = {.some_num=2};
  set_str_field_arrow(&test2, "test...");

  printf("Field after arrow func: %s\n", test2.str_field);
  /*
  * Which method use?
  * If you have a struct, use dot (.).
  * If you have a pointer to a struct, use arrow (->).
  */

  /* Copying and Returning structs */
  struct car a, b;

  b = a; // copy the struct

  return 0;
}

void set_str_field(struct test *t, char *str) {
  // t.str_field = str; // ERROR, because dot operator only works on structs, it doesn't work on pointers to structs.
  (*t).str_field = str;
}

void set_str_field_arrow(struct test *t, char *str) {
  // This is 100% equivalent to the func above
  t->str_field = str;
}

