#include <stdio.h>
#include <unistd.h> // non-standard Unix-likes only for sleep()

void EscapeSequences(void) {
  char *s = "Hello!";
  char t = 'c';

  t = '\'';
  printf("%s\n", s);
  printf("%c\n", t);
}

void FrequentlyUsedEscapes(void) {
  printf("new\nline\n");
  printf("\"hello\"\n");
  printf("%c\n", '\'');
}

void RarelyUsedEscapes(void) {
  printf("alert!\a\n");

  //  Single Line Status Updates
  for (int i = 10; i >= 0; i--) {
    printf("\rT minus %d second%s... \b", i, i != 1 ? "s" : "");

    fflush(stdout); // Force output to update

    sleep(1); // delay 1 second 
  }

  printf("\rLiftoff!                 \n");

  // The Question Mark Escape
  printf("Doesn't it??!\n"); // Doesn't it|
  printf("Doesn't it?\?!\n"); // Doesn't it??!

  // Numeric Escapes
  printf("A\102C\n"); // ABC

  printf("\xE2\x80\xA2 Bullet 1\n");
  printf("\xE2\x80\xA2 Bullet 2\n");
  printf("\xE2\x80\xA2 Bullet 3\n");


  // /u - four characters, and \U - eight characters
  printf("\u2022 Bullet 1\n");
  printf("\u2022 Bullet 2\n");
  printf("\u2022 Bullet 3\n");

  // Same, but with \U (eight chars)
  printf("\U00002022 Bullet 1\n");

}

int main(void) {
  EscapeSequences();
  FrequentlyUsedEscapes();
  RarelyUsedEscapes();
  return 0;
}

