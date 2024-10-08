/*
Ex9

Write a function called find_first that takes two parameters: pointer to constant unsigned integers and an unsigned integer to find and returns an integer. int find_first(const unsigned int *array, unsigned int what);

The function searches for the given number in the array until it is found or the current number in the array is zero. If the number is not found until a zero is seen the program returns -1. If the number is found function returns the index at which the number was found. Note that we don’t pass the size of the array as a parameter but we use zero as an end marker to stop at the end of the array.

Write a program that defines an array of 20 integers and fills the first 19 elements with random numbers in range 1 - 20 and puts a zero as the last number in the array. The program prints the array one number per line.

Program then asks user to enter number to search for or zero to stop. If the number is not zero program calls find_first to see if the number occurs in the array. If the number is found it prints the index where the number is found or “not found”. If user enters zero, the program stops otherwise program asks again user to enter a number to find.
*/

#include <stdio.h>
#include <stdlib.h>

int generate_random_number(int min, int max);
int find_first(const unsigned int *array, unsigned int what);
int read_integer();

int main(void) {
  unsigned int array[20], what, index;

  for(int i = 0; i < 19; i++) {
    array[i] = generate_random_number(1, 20);
  }
  array[19] = 0;

  while(1) {
    printf("Please input a number you want to find or '0' to quit: ");
    what = read_integer();
    if (what == 0) break;

    index = find_first(array, what);
    if (index == -1) {
      printf("not found\n");
    } else {
      printf("The number %d is at index %d.\n", what, index);
    }
  }

  return 0;
}

int find_first(const unsigned int *array, unsigned int what) {
  int i=0;
  while(array[i] != what) {
    if (array[i] == 0) return -1;
    i++;
  }
  
  return i;
}

int read_integer() {
    int tmp = -0x80000000;
    do {
        if (scanf("%d", &tmp) != 1) {
            while(getchar() != '\n') {}
            printf("invalid input, please try again: ");
        }
    } while(tmp == -0x80000000);

    return tmp;
}

int generate_random_number(int min, int max) {
    return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}