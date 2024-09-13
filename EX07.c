/*
Ex 7.

Write a function named read_positive. The function takes a pointer to int as a parameter and returns a bool.

bool read_positive(int *value);

The function asks (=prints) user to enter a positive number. If user enters a valid number and the number is positive the function stores the number using the pointer and returns true. If reading number fails or number is not positive function returns false without making changes to the value using pointer.

Write a program that “plays” a guessing game with user. The program asks user to guess how much money it has and after the guess claims to twice as much plus 20 euros. Program must use the function above to ask user to enter the number. If reading fails, function returns false, program asks to enter a number again. Program stops when user has entered an incorrect value three times.
*/

#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *positive);
int read_integer();

int main(void) {
  int value, miss=0;

  while (miss < 3) {
    printf("Guess how much money I have!\n");
    if (read_positive(&value)) {
      printf("You didn’t get it right. I have %d euros.\n", value*2+20);
    } else {
      printf("Incorrect input.\n");
      miss++;
    }
  }

  printf("I give up! See you later!\n");
  return 0;
}

bool read_positive(int *value) {
    int tmp;
    printf("Enter a positive number: ");
    if (scanf("%d", &tmp) == 1 && tmp > 0) {
        *value = tmp;
        return true;
    }
    while (getchar() != '\n'); // clear buffer
    return false;
}
