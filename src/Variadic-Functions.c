#include <stdio.h>
#include <stdarg.h>

void EllipsesInFunctionSignatures(int a) {
  printf("a is %d\n", a); // a is 1
}

int add(int count, ...) {
  int total = 0;
  va_list va;

  va_start(va, count); // start with arguments after "count"

  for (int i = 0; i < count; i++) {
    int n = va_arg(va, int); // get the next int

    total += n;
  }

  va_end(va); // all done
  
  return total;
}

void GettingTheExtraArguments(void) {
  printf("%d\n", add(2, 1, 2)); // 3 
  printf("%d\n", add(5, 1, 2, 32, 32, 32)); // 99
}

int my_printf(int serial, const char *format, ...) {
  va_list va;

  // do my custom work
  printf("The serial number is: %d\n", serial);

  // then pass the rest off to vprintf()
  va_start(va, format);
  int rv = vprintf(format, va);
  va_end(va);

  return rv;
}

void LibraryFunctionsThatUseva_lists(void) {
  int x = 10;
  float y = 2.4;

  my_printf(23414, "smth", x, y);
}

int main(void) {
  EllipsesInFunctionSignatures(1);
  GettingTheExtraArguments();
  LibraryFunctionsThatUseva_lists();
  return 0;
}

