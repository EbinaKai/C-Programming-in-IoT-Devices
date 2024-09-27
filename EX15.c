/*
Ex 15.

Write a program that reads data from a text file into an array of structures. The size of the array is 40 elements.

The structure is defined as:

typedef struct menu_item_ {
  char name[50];
  double price;
} menu_item;

The program asks user to enter a filename. Then program tries to open the file in textmode for reading. If opening the file fails the program prints an error message with the filename to stderr and then exits.

Program reads data from the text file into the array until end of file or the array is full. Each row of the file contains data of one structure. The members are separated by semicolons. For example:

Mega double burger with bacon and cheese; 23.50
Belgian style fries with vegan mayo; 5.60

When reading ends the program closes the file and prints the content of the array in formatted columns. Price is printed into a field of eight characters with two decimals precision followed by the name of the item. Unused elements are not printed.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct menu_item_ {
  char name[50];
  double price;
} menu_item;

int main(void){
  int length;
  char filename[256], line[256];
  menu_item items[40];
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

  // read items
  int i = 0;
  while (fgets(line, sizeof(line), file) != NULL && i < 40) {
    char *name_part = strtok(line, ";");
    char *price_part = strtok(NULL, "\n");

    // get price and name
    if (name_part && price_part) {
      strncpy(items[i].name, name_part, sizeof(items[i].name) - 1);
      items[i].name[sizeof(items[i].name) - 1] = '\0';  // end of string
      items[i].price = atof(price_part);  // convert string to double
      i++;
    }
  }

  // close file
  fclose(file);

  // print items
  for (int i = 0; i < 40; i++) {
    if (items[i].name[0] == '\0') {
      break;
    }
    printf("%8.2f %s\n", items[i].price, items[i].name);
  }

  return 0;
}