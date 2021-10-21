#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void AddingToPointers(void) {
  int a[5] = {11, 22, 33, 44, 55};
  
  int *p = &a[0]; // or int *p = a; works just as well

  printf("%d\n", *p); // 11
  
  // Print next element in the array!
  printf("%d\n", *(p + 1)); // 22
  
  //printf("%d\n", *p); // 11
  // the same
  //printf("%d\n", *(p + 0)); // 11
 
  int arr_len = sizeof a / sizeof(int);
  for (int i = 0; i < arr_len; i++) {
    printf("From arr: %d\n", *(p + i));
  }
}

void ChangingPointers(void) {
  int a[] = {11, 22, 33, 44, 55, 999};
  
  int *p = &a[0];

  while (*p != 999) { // while the thing p poits to isn't 999
    printf("%d\n", *p);
    p++; // move p to point to the next int!
  }
}

int my_strlen(char *s);

void SubtractingPointers(void) {
  int len = my_strlen("Hello, World!");
  printf("Len: %d\n", len);
}

void ArrayPointerEquivalence(void) {
  // fundamental formula of array/pointer equivalence: a[b] == *(a + b)
  // The spec is specific, as always, declaring: E1[E2] is identical to (*((E1)+(E2)))
   
  int a[] = {11, 22, 33, 44, 55};

  int *p = a; // pointer to the first element of a, 11

  int arr_len = sizeof a / sizeof(int);

  for (int i = 0; i < arr_len; i++)
    printf("%d ", a[i]); // array notation with a

  printf("\n");

  for (int i = 0; i < arr_len; i++)
    printf("%d ", p[i]); // array notation with p

  printf("\n");

  for (int i = 0; i < arr_len; i++) 
    printf("%d ", *(a + i)); // pointer notation with a

  printf("\n");

  for (int i = 0; i < arr_len; i++)
    printf("%d ", *(p + 1)); // pointer notation with p

  printf("\n");

  for (int i = 0; i < arr_len; i++)
    printf("%d ", *(p++)); // moving pointer p
    //printf("%d ", *(a++)); // moving array var a -- ERROR!
  
  printf("\n");
}

void ArrayPointerEquivalenceInFunctionCalls(void) {
  char s[] = "Apple";
  char *t = "Orange";

  printf("%d\n", my_strlen(s)); // works!
  printf("%d\n", my_strlen(t)); // works, too!
  // int my_strlen(char *s) // works!
  // int my_strlen(char s[]) // also, works!
}

void voidPointers(void) {
  // void *memcpy(void *s1, void *s2, size_t n);
  
  char s[] = "!!!";
  char t[100];
  
  size_t str_len = sizeof s; // because char is always one byte 
  memcpy(t, s, str_len); // copy 4 bytes -- including the NUL terminator!

  printf("%s\n", t); // "!!!"

  int a[] = {1, 2, 3};
  int b[3];

  memcpy(b, a, 3 * sizeof(int)); // copy 3 ints of data

  printf("%d\n", b[2]); // 3

  // Conversion is easy: you can just assign into a variable of the desired type

  char sa = 'X'; // single char

  void *p = &sa; // p points to the 'X'
  char *q = p;  // q also points to the 'X'

  //printf("%c\n", *p); // ERROR - cannot dereference void*!
  printf("%c\n", *q); // X
}

void *my_memcpy(void *dest, void *src, int byte_count);

void TestMyMemcpy(void) {
  char *str = "Hello!";
  char new_str[100];

  my_memcpy(new_str, str, sizeof str);

  printf("%s\n", new_str);
}

// the type of structure we're going to sort
struct animal {
  char *name;
  int leg_count;
};

// This is a comparison function called by qsort() to help it determine
// what exactly to sort by
int compar(const void *elem1, const void *elem2) {
  // We know we're sorting struct animals, so let's make both
  // arguments pointers to srtuct animals
  const struct animal *a1 = elem1;
  const struct animal *a2 = elem2;

  // Return <0 =0 >0 depending on whatever we want to sort by.
  
  // return the difference in the leg_counts
  return a1->leg_count - a2->leg_count;
}

void voidExample(void) {
  // array of 4 different struct animals
  struct animal a[4] = {
    {.name="Dog", .leg_count=4},
    {.name="Monkey", .leg_count=2},
    {.name="Antelope", .leg_count=4},
    {.name="Snake", .leg_count=0}
  };
  
  // This call is saying: qsort array a, which has 4 elems, and each elem is sizeof(strcut animal)
  // bytes big, and this is the function that will compare any two elems.  
  qsort(a, 4, sizeof(struct animal), compar);

  // print them all out
  for (int i = 0; i < 4; i++)
    printf("%d: %s\n", a[i].leg_count, a[i].name);
}

int main(void) {
  AddingToPointers();
  ChangingPointers();
  SubtractingPointers();
  ArrayPointerEquivalence();
  ArrayPointerEquivalenceInFunctionCalls();
  voidPointers();
  voidExample();
  return 0;
}

void *my_memcpy(void *dest, void *src, int byte_count) {
  // Convert void*s to char*s
  char *s = src, *d = dest; 

  while (byte_count--)
    *d++ = *s++;

  // just return the destination
  return dest;
}

int my_strlen(char *s) {
  char *p = s; // (get first char pointer)  start scanning from the beginning of the string

  // Scan until we find the NUL char
  while (*p != '\0')
    p++;

  // return the difference in pointers
  return p - s;
}

