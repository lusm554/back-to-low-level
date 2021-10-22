#include <stdio.h>

void VariableHiding(void) {
  int i = 10;

  {
    int i = 20;
    printf("%d\n", i);
  }

  printf("%d\n", i);
}

void ForLoopScope(void) {
  for (int i = 0; i < 5; i++) {
    int i = 666; // hides the i in the for-loop scope
    printf("%d\n", i); // 666
  }
}

int main(void) {
  VariableHiding();
  ForLoopScope();

  return 0;
}
