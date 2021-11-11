#include <stdio.h>
#include <pthread.h>

#ifdef __STDC_NO_THREADS__
#error I need threads to build this progam!
#endif
// it seems that clang on MacOS don't support <threads.h>

int main(void) {
  // http://beej.us/guide/bgc/html/split/multithreading.html
  return 0;
}

