#include <stdio.h>
#include <stdlib.h>

/* Fetch args */
/*
int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; i++) {
    printf("arg %d: %s\n", i, argv[i]);
  }
  return 0;
}
*/

/* Sum of args! v1 */
/*
int main(int argc, char **argv) {
  int total = 0;
  
  for(int i = 1; i < argc; i++) { // start at 1, the first argument
    int value = atoi(argv[i]);    // use strtol() for better error handling

    total += value;
  }
  
  printf("%d\n", total);
  return 0;
}
*/

// alternate way to consume the command line arguments 

/* Sum of args v2 */
/*
int main(int argc, char **argv) {
  int total = 0;

  // Cute trick to get the compiler to stop warning about the
  // unused variable argc:
  (void)argc;

  for (char **p = argv; *p != NULL; p++) {
    int value = atoi(*p); // use strtol() for better error handling
      
    total += value;
  }
    
  printf("%d\n", total);

  return 0;
}
*/

/* Exit status */
/*
int main(int argc, char **argv) {
  if (argc != 3) {
    printf("usage: mult x y\n");
    return EXIT_FAILURE; // indicate to shell that it didn't work
  }

  printf("%d\n", atoi(argv[1]) * atoi(argv[2]));

  return 0;
}
*/

extern char **environ;

int EnvironmentVariables(void) {
  char *val = getenv("FROTZ"); // try to get the value

  // check to make sure it exists
  if (val == NULL) {
    printf("Cannot find the FROTZ env var\n");
    return EXIT_FAILURE;
  }

  printf("Values: %s\n", val);

  // Get all env vars
  for (char **p = environ; *p != NULL; p++) {
    printf("%s\n", *p);
  }

  // or

  for (int i = 0; environ[i] != NULL; i++) {
    //printf("%s\n", environ[i]);
  } 

  return 0;
}

int main(void) {
  int e_status = EnvironmentVariables();
  if (e_status != 0) {
    return e_status;
  }
}

// Get env vars in Unix land
/*
int main(int argc, char **argv, char **env) { // <-- env!
  (void)argc; (void)argv; // suppress unused warnings

  for (char **p = env; *p != NULL; p++) {
    printf("%s\n", *p);
  }
}
*/

