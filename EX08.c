/*
Ex 8.

Write a function called print_numbers that takes two parameters: pointer to constant integers and number of integers to print.

void print_numbers(const int *array, int count);

The function prints the numbers on separate lines in eight characters wide field.

Write a program that defines an array of 15 integers and fills the array with random numbers and then uses the function to print the array contents.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_numbers(const int *array, int count);

int main(void) {
  int array[15], count=15;
  srand((unsigned int)time(NULL));

  for (int i = 0; i < count; i++) {
    array[i] = rand() % 100000000; // eight digits random number
  }

  print_numbers(array, count);
  
  return 0;
}

void print_numbers(const int *array, int count) {
  for (int i = 0; i < count; i++) {
    printf("%8d\n", array[i]);
  }
}
