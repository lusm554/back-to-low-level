#include <stdio.h>
#include <stdlib.h>
#include <math.h> // for sqrt()

// #include <stdio.h>    - built-in header (system includes)
// #include "myheader.h" - local files from the current dir (personal uncludes)

// Simple Macros
#define HELLO "Hello, World"
#define PI 3.14159

//  If Defined, #ifdef and #endif
#define EXTRA_HAPPY

// General Conditional: #if, #elif
#define HAPPY_FACTOR 1

// Losing a Macro: #undef
#define GOATS

void Built_in_Macros(void);
void MacrosWithArguments(void);

int main() {
  printf("%s, %f\n", HELLO, PI);

  // If defined
#ifdef EXTRA_HAPPY
  printf("I'm extra happy!\n");
#endif

  // If not defined
#ifndef EXTRA_HAPPY
  printf("I'm just regular\n");
#endif

  // else
#ifdef EXTRA_HAPPY
  printf("Else work!, EXTRA_HAPPY defined\n");
#else
  printf("Else work!, EXTRA_HAPPY not defined")
#endif

#if HAPPY_FACTOR == 0
  printf("I'm not happy!\n");
#elif HAPPY_FACTOR == 1
  printf("I'm just regular\n");
#else
  printf("I'm extra happy!\n");
#endif

#if 0
  printf("All this code");
  pritnf("commented out");
#endif

#if defined FOO
  printf("FOO defined\n");
#elif defined BAR
  printf("BAR defined\n");
#endif

  // Losing a Macro: #undef
#ifdef GOATS
  printf("GOATS detected!\n"); // prints
#endif

#undef GOATS // make GOATS no longer defined

#ifdef GOATS
  printf("GOATS detected!\n"); // doesn't print
#endif 

	Built_in_Macros();
  MacrosWithArguments();

  return 0;
}

void Built_in_Macros(void) {
  printf("\n");
	printf("This function: %s\n", __func__);
	printf("This file: %s\n", __FILE__);
	printf("This line: %d\n", __LINE__);
	printf("Compiled on: %s %s\n", __DATE__, __TIME__);
	printf("C Version: %ld\n", __STDC_VERSION__); 
}

void MacrosWithArguments(void) {
  // Macros with One Argument
  #define SQR(x) ((x) * (x))

  printf("%d\n", SQR(12));
  printf("%d\n", SQR(3 + 4));

  //  Macros with More than One Argument
  #define TRIANGLE_AREA(w, h) (0.5 * (w) * (h))

	#define QUADP(a, b, c) ((-(b) + sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
	#define QUADM(a, b, c) ((-(b) - sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
  //         macro              replacement
  //     ______________ ______________________________
  //     |            | |                            |
	#define QUAD(a, b, c) QUADP(a, b, c), QUADM(a, b, c)  
  
  printf("2*x^2 + 10*x + 5 = 0\n");
  printf("x = %f or x = %f\n", QUAD(2, 10, 5));

  // Macros with Variable Arguments

  // Combine the first two arguments to a single number
  // then have a commalist of the rest of them:
  #define X(a, b, ...) (10*(a) + 20*(b)), __VA_ARGS__

  printf("%d %f %s %d\n", X(5, 4, 3.14, "Hi!", 12));

  
  // You can also “stringify” __VA_ARGS__ by putting a # in front of it
  #define _X(...) #__VA_ARGS__
  printf("%s\n", _X(1, 2, 3));

  // Stringification
  #define STR(x) #x
    
  printf("%s\n", STR(3.14));

  #define PRINT_INT_VAL(x) printf("%s = %d\n", #x, x);

  int a = 5;

  PRINT_INT_VAL(a); // prints "x = 5"
  
  // Concatenation
  #define CAT(a, b) a ## b
    
  printf("%f\n", CAT(3.14, 1592)); // 3.141592
  
  // Multiline Macros
  #define PRINT_NUMS_TO_PRODUCT(a, b) { \
    int product = (a) * (b); \
    for (int i = 0; i < product; i++) { \
      printf("%d\n", i); \
    } \
  }
  
  PRINT_NUMS_TO_PRODUCT(2, 4); // outputs numbers from 0 to 7

  // Example: An Assert Macro
	#define ASSERT(c, m) \
	{ \
			if (!(c)) { \
					fprintf(stderr, __FILE__ ":%d: assertion %s failed: %s\n", \
													__LINE__, #c, m); \
					exit(1); \
			} \
	}

  int x = 30;
  ASSERT(x < 20, "x must be under 20");

  //  The #error Directive
  #ifndef __STDC_IEC_559__
    #warning I really need IEEE-754 floating point to compile. Sorry!
    //#error I really need IEEE-754 floating point to compile. Sorry!
  #endif


  // The #line Directive
  #line 300 "newfilename" 
}

