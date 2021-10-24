#include <stdio.h>
#include <stdlib.h>

void NumericValueToString(void) {
  char s[10];
  float f = 3.14;

  // convert "f" to string, storing in "s", writing at most 10 chars
  // including the NUL terminator
  
  snprintf (s, 10, "%f", f); 

  printf("String value: %s\n", s); // String value: 3.140000

  // for double we'd use %lf. Or a long double, %LF.
}

void String2NumericValue(void) {
  char *pi = "3.14159";
  float f;

  f = atof(pi);

  printf("Str to dig: %f\n", f);

  //int x = atoi("what?"); // get undefined behavior from weird things like this
  
  char *s = "3490";

  // Convert string s, a number in base 10, to an unsigned long int.
  // NULL means we don't care to learn about any error information

  unsigned long x = strtoul(s, NULL, 10);

  printf("%lu\n", x);

  s = "101010"; // what's the meaning of this number
    
  // conver string s, a number in base 2, to an unsigned long int
  unsigned long y = strtoul(s, NULL, 2);

  printf("%lu\n", y); // 42


  char *ss = "34x90"; // "x" is not a valid digit in base 10!
  char *badchar;

  // convert string s, a number in base 10, to an unsigned long int

  unsigned long int xx = strtoul(ss, &badchar, 10);

  // it tries to convert as much as possible, so gets this far:

  printf("%lu\n", xx); // 34
  
  // but we can see the offending bad char because badchar
  // points to it!
  
  printf("Invalid char: %c\n", *badchar); // "x"

  
  // TEST
  
  s = "3490";
  char *MaybeBadChar;

  // convert string s, a number in base 10, to an unsigned long int
  unsigned long int Xx = strtoul(s, &MaybeBadChar, 10);

  // check if things went well

  if (*MaybeBadChar == '\0') {
    printf("Success! %lu\n", Xx);
  } else {
    printf("Partial conversion: %lu\n", x);
    printf("Invalid char: %c\n", *MaybeBadChar); 
  }
}

void Casting(void) {
  int x = 10;
  long int y = (long int)x + 12;
}

int main(void) {
  NumericValueToString();
  String2NumericValue();
  Casting();

  int x = 666;
  int *p = &x;

  //printf("%p\n", p); // warning: format specifies type 'void *' but the argument has type 'int *'
  printf("%p\n", (void *)p); // the solution is use cast (void *)

  return 0;
} 

