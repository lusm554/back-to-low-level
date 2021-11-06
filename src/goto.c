#include <stdio.h>

void ASimpleExample(void) {
  printf("One\n");
  printf("Two\n");
  
  goto skil_3;

  printf("Three\n");

skil_3:

  printf("Five!\n");
}

void LabeledContinue(void) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 5; k++) {
        printf("%d, %d, %d\n", i, j, k);

        goto continue_i; // now continuing the i loop!
      }
    }
continue_i: ;
  }
}

void LabeledBreak(void) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d, %d\n", i, j);
      goto break_i; // now breaking out of the i loop!
    }
  }

break_i: 

  printf("Done!\n");
}

int main(void) {
  ASimpleExample();
  LabeledContinue();
  LabeledBreak();
  return 0;
}

