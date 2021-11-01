#include <stdio.h> 

void BehaviorOfEnum(void) {
  // Numbering
  enum {
    zero,
    one,
    two,
    three,
    four,
  };

  printf("%d %d\n", zero, three);

  // force
  enum {
    X=3,
    Y=3,
    Z=43,
  };

  // if values ommited
  enum {
    A,   // 0, default starting value
    B,   // 1
    C=5, // 5, manually set
    D,   // 6
    E,   // 7
    F=2, // 2, manually set
    G,   // 3
    H,   // 4
  };

  printf("%d, %d %d, %d\n", C, D, F, G);

  // Trailing Commas
  enum {
    XX=23,
    YY=452,
    ZZ=21, // <-- Trailing comma
  };

  // In short, enums are a great way to write nice, scoped, typed, clean code.
}

int main(void) {
  BehaviorOfEnum();
  return 0;
}

