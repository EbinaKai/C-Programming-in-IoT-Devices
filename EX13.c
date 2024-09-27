/*
Ex 13.

Write a program that asks user to enter a filename. Then program tries to open the file in textmode for reading. If opening the file fails the program prints an error message with the filename to stderr and then exits. If the file is opened the program starts reading integers from the file until reading fails or the file ends. When reading stops the program prints the count of numbers and the lowest and highest number that was read from the file. Then program closes the file.

For testing make a few text files with integers using your favourite text editor.
*/

#include <stdio.h>
#include <string.h>

int main(void){
  char filename[256];
  int length, count=0, min=0x7FFFFFFF, max=-0x80000000, buf;
  FILE *file;

  printf("Please input file path[256]: ");
  fgets(filename, 256, stdin);

  // remove newline character
  length = strlen(filename);
  if (filename[length - 1] == '\n') {
    filename[length - 1] = '\0';
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error: Cannot open file %s\n", filename);
    return 1;
  }

  // read integers
  while (fscanf(file, "%d", &buf) == 1) {
    count++;
    if (buf < min) {
      min = buf;
    }
    if (buf > max) {
      max = buf;
    }
  }

  // print result
  printf("The number of integers in the file is %d\n", count);
  printf("The lowest number is %d\n", min);
  printf("The highest number is %d\n", max);

	return 0;
}