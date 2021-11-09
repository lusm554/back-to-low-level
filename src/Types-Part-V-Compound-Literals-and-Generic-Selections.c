#include <stdio.h>

int sum(int p[], int count) {
  int total = 0;

  for (int i = 0; i < count; i++)
    total += p[i];

  return total;
}

struct coord {
  int x, y;
};

void print_coord(struct coord c) {
  printf("%d, %d\n", c.x, c.y);
}

void print_coord2(struct coord *c) {
  printf("%d, %d\n", c->x, c->y);
}

void CompoundLiterals(void) {
//4warning unnamed array of ints       
//  |             |
//|-----|----------------------|
  (void)(int []){1, 2, 3, 4, 5};

  // store a reference to the array
  int *p = (int []){1, 2, 3, 4, 5};

  printf("%d\n", p[0]); // 1

  // the same, as above
  int samep[] = {1, 2, 3, 4, 5};
  printf("%d\n", samep[0]); // 1


  /* Passing Unnamed Objects to Functions */
  printf("%d\n", sum(samep, 5)); // 15

  // Skip variable
  //                   p[]        count
  //          |------------------|  |
  int s = sum((int []){1, 2, 3, 4}, 4);
  printf("%d\n", s); // 10


  /* Unnamed structs */

  //struct coord t = {.x=10, .y=20};

  print_coord((struct coord){.x=10, .y=20}); // 10, 20


  /* Pointers to Unnamed Objects */
  
  print_coord2(&(struct coord){.x=20, .y=20}); // 20, 20
}

void GenericSelections(void) {
  int i;
  long l;
  float f;
  double d;
  char c; 

  char *s = _Generic(i,
              int: "that variable is an int",
              float: "that variable is an float",
              default: "that variable is some type"
            );

  printf("%s\n", s);

  #define TYPESTR(x) _Generic((x), \
                       int: "int", \
                       long: "long", \
                       float: "float", \
                       double: "double", \
                       default: "something else")

	printf("i is type %s\n", TYPESTR(i));
	printf("l is type %s\n", TYPESTR(l));
	printf("f is type %s\n", TYPESTR(f));
	printf("d is type %s\n", TYPESTR(d));
	printf("c is type %s\n", TYPESTR(c));  

	// Macro that gives back a format specifier for a type
	#define FMTSPEC(x) _Generic((x), \
											 int: "%d", \
											 long: "%ld", \
											 float: "%f", \
											 double: "%f", \
											 char: "%s")	
											 // TODO: add more types

	#define PRINT_VAL(x) { \
		char fmt[512]; \
		snprintf(fmt, sizeof fmt, #x " = %s\n", FMTSPEC(x)); \
		printf(fmt, (x)); \
	}	

  i = 10;
  f = 3.14;
  char *ss = "Hello, World!";

  PRINT_VAL(i);
  PRINT_VAL(f);
  //PRINT_VAL(ss);
}

int main(void) {
  CompoundLiterals();
  GenericSelections();
  return 0;
}
 
