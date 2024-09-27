/*
Ex 14.

Write a program that reads lines of text in to an array of strings. The maximum length of the line is 80 characters and the maximum number of lines is 100.

The program asks user to enter a filename. Then program tries to open the file in textmode for reading. If opening the file fails the program prints an error message with the filename to stderr and then exits. The program reads lines from the file into the array until the file ends or the array is full (100 lines read). Then program closes the file.

Then program converts all letters to upper case (see toupper() – function).

Then program opens the file for writing in text mode and writes all read lines to file and closes the file.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
  int length;
  char filename[256], line[100][80];
  FILE *file;

  printf("Please input file path[256]: ");
  fgets(filename, 256, stdin);

  // remove newline character
  length = strlen(filename);
  if (filename[length - 1] == '\n') {
    filename[length - 1] = '\0';
  }

  // open file
  file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error: Cannot open file %s\n", filename);
    return 1;
  }

  // read lines
  for (int i = 0; i <= 100; i++) {
    if (fgets(line[i], 80, file) == NULL) {
      break;
    }
  }

  // close file
  fclose(file);

  // convert to upper case
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j < 80; j++) {
      if (line[i][j] == '\0') {
        break;
      }
      line[i][j] = toupper(line[i][j]);
    }
  }

  // open file for writing
  file = fopen("output.txt", "w");
  if (file == NULL) {
    fprintf(stderr, "Error: Cannot open file output.txt\n");
    return 1;
  }

  // write lines
  for (int i = 0; i <= 100; i++) {
    if (line[i][0] == '\0') {
      break;
    }
    fprintf(file, "%s", line[i]);
  }

  // close file
  fclose(file);

	return 0;
}