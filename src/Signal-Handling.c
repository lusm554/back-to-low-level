#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int count = 0;

void HandlingSignalsWithSignal(void) {
  char s[1024]; 

  signal(SIGINT, SIG_IGN); // Ignore SIGINT, caused by ^C

  printf("Try hitting ^C...\n");

  // Wait for a line of input so the program doesn't just exit
  fgets(s, sizeof s, stdin);
}

void sigint_handler(int signum) {
  // The compiler is allowed to run:
  //
  //    signal(signum, SIG_DFL)
  //
  // when the hander is first called. So we reset the haldner here:
  signal(SIGINT, sigint_handler);

  (void)signum; // get rid of unused variable warning

  count++;                      // undefined behavior
  printf("\nCount: %d\n", count); // undefined behavior
  
  if (count == 2) {
    printf("Exiting!\n");       // undefined behavior
    exit(0);
  }
}

void WritingSignalHandlers(void) {
  signal(SIGINT, sigint_handler);

  printf("Try hitting ^C\n");

  for(;;); // wait here forever   
} 

int main(void) {
  //HandlingSignalsWithSignal();
  WritingSignalHandlers();
  return 0;
}

