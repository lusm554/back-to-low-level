#include <stdio.h>
#include <string.h>

int my_strlen(char *s);

int main() {
  /* String Variables */
  char *s = "Hello, World!";

  printf("%s\n", s);

  /* String Variables as Arrays */
  char str[] = "Hello, World!";

  for (int i = 0; i < 13; i++)
    printf("%c\n", str[i]);

  /* String Initializers */
  char *ss = "Hello!"; // ss is opinter to a string literal

  /* 
  ss[0] = 'z'; // ERROR: tried to mutate a string literal! 
  */

  char Ss[] = "Hello!"; // Ss is an array copy of the string
  Ss[0] = "Z"; // No problem

  printf("%s\n", Ss); // Zello!


  /* Getting String Length */
  /*
  strlen - returns length of string in bytes.
  returns type size_t; 
  */  

  char *strr = "hi!";
  size_t strr_len = strlen(strr);

  printf("The string is %zu bytes long.\n", strr_len); 

  /* String Termination */
  char *test_s = "Is it work's?";
  int ll = my_strlen(test_s);

  printf("Test own len function, len: %d. Default func: %d.\n", ll, strlen(test_s));

  /* Copying a String */
  char first_c[] = "Hello, World!";
  char second_c[strlen(first_c)]; //second_c[100]
  
  strcpy(second_c, first_c);
  
  second_c[0] = 'Z';

  printf("%s\n", first_c);
  printf("%s\n", second_c);
  
  return 0;
}

// How works strlen? Count chars until get zero-valued byte (or NUL char).
int my_strlen(char *s) {
  int count = 0;

  while (s[count] != '\0') // Single quotes for single char
    count++;
  
  return count;
}

