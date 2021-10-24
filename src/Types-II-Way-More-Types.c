#include <stdio.h>
#include <limits.h>

void SignedAndUnsignedIntegers(void) {
  int a;           // signed
  signed int b;    // signed
  signed c;        // signed, "shorthand" for "int" or "signed int", rare
  unsigned int d;  // unsigned 
  unsigned e;      // unsigned, shorthand for "unsigned int"
}


void CharacterTypes(void) {
  char c = 'B';

  printf("%c\n", c); // B
  printf("%d\n", c); // 66 !!

  char a = 10, b = 20;

  printf("%d\n", a + b); // 30 

  char e = 10;
  char d = 'B';

  printf("%d\n", e + d); // 76
}

void MoreIntegerTypes(void) {
  long long int x; // same as - long long x;
  
  short int y; // same as - short x;   

  printf("Type                Min Macro  Max Macro\n");
  printf("char                %d          %d\n", CHAR_MIN, CHAR_MAX);
  printf("signed char         %d          %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("short               %d          %d\n", SHRT_MIN, SHRT_MAX);
  printf("int                 %d          %d\n", INT_MIN, INT_MAX);
  printf("long                %d          %d\n", LONG_MIN, LONG_MAX);
  printf("long long           %d          %d\n", LLONG_MIN, LLONG_MAX);
  printf("unsigned char       %d          %d\n", 0, UCHAR_MAX);
  printf("unsigned short      %d          %d\n", 0, USHRT_MAX);
  printf("unsigned int        %d          %d\n", 0, UINT_MAX);
  printf("unsigned long       %d          %d\n", 0, ULONG_MAX);
  printf("unsigned long long  %d          %d\n", 0, ULLONG_MAX);
  
  printf(
    "float: %zu, double: %zu, long double: %zu\n",
    sizeof(float), sizeof(double), sizeof(long double)
  );
}

void ConstantNumericTypes(void) {
  int a = 0x1A2b; // case doesn't matter for hex digits

  printf("%x\n", a); // 1a2b

  int x = 0b10; // binary
  printf("%d\n", x); // 2

  printf("%e\n", 123456.0); // 1.234560e+05

  double test = 0xa.1p3;

  printf("%a\n", test); // 0x1.42p+6
  printf("%f\n", test); // 80.500000
} 

int main(void) {
  SignedAndUnsignedIntegers();
  CharacterTypes();
  MoreIntegerTypes();
  ConstantNumericTypes();
  return 0;
}

