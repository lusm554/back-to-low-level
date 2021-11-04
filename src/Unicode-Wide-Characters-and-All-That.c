#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <stdlib.h>
#include <locale.h>

void UnicodeInC(void) {
  // /u for 16-bit Unicode code points
  char *s = "\u20AC1.23"; 

  printf("%s\n", s); // €1.23

  // /U for 32-bit Unicode code points
  s = "\U0001D4D1";
    
  printf("%s\n", s); // prints a math letter "B"
}

void MultibyteCharacters(void) {
  char *s = "\u20AC1.23";  // €1.23
  printf("%zu\n", strlen(s)); // 7 on my system
}

void UsingWideCharactersAndwchar_t(void) {
  wchar_t *s = L"Hello, world!";
  wchar_t c = L'B';
  
  printf("%ls %lc\n", s, c);

  // Multibyte to wchar_t Conversions
  // get out of the C locale to one that likely has the euro symbol
  setlocale(LC_ALL, "");
  
  // original multibyte string with a euro symbol (unicode point 20ac)
  char *mb_string = "The cost is \u20ac1.23"; // €1.23
  size_t mb_len = strlen(mb_string);

  // wide character array that will hold the converted string
  wchar_t wc_string[128];  // holds up to 128 wide characters
  
  // convert the MB string to WC; this returns the number of wide chars
  size_t wc_len = mbstowcs(wc_string, mb_string, 128);

  printf("multibyte: \"%s\" (%zu bytes)\n", mb_string, mb_len);
  printf("wide char: \"%ls\" (%zu bytes)\n", wc_string, wc_len);
}

int main(void) {
  UnicodeInC();
  MultibyteCharacters();
	UsingWideCharactersAndwchar_t();
  return 0;
}

