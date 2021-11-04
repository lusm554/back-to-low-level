#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void on_exit_1(void) {
  printf("Exit handler 1 called!\n");
}

void on_exit_2(void) {
  printf("Exit handler 2 called!\n");
}

void on_quick_exit_1(void) {
  printf("Quick exit handler 1 called!\n");
}

void on_quick_exit_2(void) {
  printf("Quick exit handler 2 called!\n");
}

int main(void) {
  // Setting Up Exit Handlers with atexit(), called reverse order of registration
  /*
  atexit(on_exit_1);
  atexit(on_exit_2);
  printf("About to exit...\n");
  */

  // Quicker Exits with quick_exit()
  /*
  at_quick_exit(on_quick_exit_1);
  at_quick_exit(on_quick_exit_2);
  
  atexit(on_exit); // This won't ne called
    
  printf("About to quick exit...\n");
  quick_exit(0);
  */

  // Exiting Sometimes: assert()
  #define PI 3.14159
  assert(PI > 3); // sure enough, it is, so carry on
}

