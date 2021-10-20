#include <stdio.h>

int main(void) {
  // dir - "IOFiles"

  /* The FILE* Data Type */

  /* Reading Text Files */ 
  FILE *fp; // Var (fp pointer) to represent open file

  fp = fopen("IOFiles/hello.txt", "r"); // Open file for reading

  int c = fgetc(fp); // Read a single char
  printf("%c, %d\n", c, c); // Print char to stdout
  
  fclose(fp); // Close the file when done

  /* End of File: EOF */
  FILE *fp1;
  int cc;

  fp1 = fopen("IOFiles/hello.txt", "r");

  while ((cc = fgetc(fp1)) != EOF)
    printf("%c", cc);
  
  fclose(fp1);

  /* Reading a Line at a Time */
  FILE *quotep;
  char s[1024]; // char buffer to hold bytes
  int linecount = 0;

  /*
  * fgets(char_buffer, max_num_bytes_to_read, file_pointet_read_from);
  * It returns NULL on end-of-file or error.
  */

  quotep = fopen("IOFiles/quote.txt", "r");

  while (fgets(s, sizeof s, quotep) != NULL)
    printf("%d: %s", ++linecount, s);

  fclose(quotep);

  /* Formatted Input */
  FILE *whalesp;  
  char name[1024];
  float length;
  int mass;

  whalesp = fopen("IOFiles/whales.txt", "r");

  while (fscanf(whalesp, "%s %f %d", name, &length, &mass) != EOF)
    printf("%s whale, %d tonnes, %.1f meters\n", name, mass, length);

  /* Writing Text Files */
  FILE *outputp;
  int x = 32;

  outputp = fopen("IOFiles/output.txt", "w"); // since stdout is a file, we can replace fopen and the program would have outputted to the console instead of to a file.
  //outputp = stdout;

  fputc('B', outputp);
  fputc('\n', outputp);
  fprintf(outputp, "x = %d\n", x);
  fputs("Hello, World!\n", outputp);
    
  fclose(outputp);

  /* Binary File I/O */

  // Write
  FILE *writep;
  unsigned char bytes[6] = {5, 37, 0, 88, 255, 12};  

  writep = fopen("IOFiles/output.bin", "wb");
  
  /*
  * fwrite arguments:
  *
  * - pointer to data to write
  * - size of each "piece" of data
  * - count of each "piece" of data
  * - FILE*
  */

  fwrite(bytes, sizeof(char), sizeof bytes / sizeof(char), writep);
  fclose(writep);

  // Read 
  FILE *readp;
  unsigned char _c;

  readp = fopen("IOFiles/output.bin", "rb");

  /*
  * fread arguments:
  *
  * - var pointer for readed char
  * - size of each piece
  * - count of chars
  * - FILE*
  */

  while (fread(&_c, sizeof(char), 1, readp) > 0)
    printf("%d\n", _c);

  fclose(readp);

  /* struct and Number Caveats */
  //  Serialize your binary data when you write it to a stream! This will keep things nice and portable, even if you transfer data files from one architecture to another.

  return 0;
}

