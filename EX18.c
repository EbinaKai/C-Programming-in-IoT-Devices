/*
EX 18.

Write a program that asks user to enter a number in the range from 0 to 15 or a negative number to stop. If user enters a number between 0 and 15 the program generates a random number and prints it in hexadecimal. Then program shifts the number to the right by the amount user entered and uses bitwise and to clear all other bits except bits 0-5 and prints the result in hexadecimal with two digits and leading zeros.

Note: bit numbering starts from 0
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int number;
  int random;
  int mask;

  while (1) {
    printf("Please enter a number in the range from 0 to 15 or a negative number to quit: ");
    scanf("%d", &number);

    if (number < 0) {
      break;
    }

    if (number < 0 || number > 15) {
      printf("Error: Number must be in the range from 0 to 15.\n");
      continue;
    }

    random = rand() % 65536;
    printf("Random number: %X\n", random);

    mask = 0x3F;
    random >>= number;
    random &= mask;

    printf("Result: %04X\n", random);
  }

  return 0;
}