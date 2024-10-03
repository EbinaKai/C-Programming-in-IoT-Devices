/*
Ex 19.

Extend program of Ex15 so that after reading the file content the program asks user to choose sorting order of the menu. User can choose to sort by price or by name.

Write comparison functions for sorting by name and by price and use qsort() from standard library to sort the array before printing.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int count_line(FILE *file);
int compare_name(const void *item1, const void *item2);
int compare_price(const void *item1, const void *item2);

typedef struct menu_item_ {
  char name[50];
  double price;
} menu_item;

int main(void){
  int length;
  char filename[256], line[256];
  char sort_by;
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

  // count line from file pointer
  int line_count = count_line(file);
  menu_item items[line_count];

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

  while(true) {
    printf("Sort by name or price? [n/p]: ");
    scanf("%c", &sort_by);
    if (sort_by == 'n') {
      // sort by name
      qsort(items, i, sizeof(items[0]), compare_name);
      break;
    } else if (sort_by == 'p') {
      qsort(items, i, sizeof(items[0]), compare_price);
      break;
    } else {
      fprintf(stderr, "Error: Invalid sorting option\n");
    }
  }

  // print items
  for (int i = 0; i < 40; i++) {
    if (items[i].name[0] == '\0') {
      break;
    }
    printf("%8.2f %s\n", items[i].price, items[i].name);
  }

  return 0;
}

// count line from file pointer
int count_line(FILE *file) {
  int count = 0;
  char line[256];
  rewind(file);
  while (fgets(line, sizeof(line), file) != NULL) {
    count++;
  }
  rewind(file);
  return count;
}

// compare functions
int compare_name(const void *item1, const void *item2) {
  return strcmp(((menu_item *)item1)->name, ((menu_item *)item2)->name);
}

int compare_price(const void *item1, const void *item2) {
  if (((menu_item *)item1)->price < ((menu_item *)item2)->price) {
    return -1;
  } else if (((menu_item *)item1)->price > ((menu_item *)item2)->price) {
    return 1;
  } else {
    return 0;
  }
}