/*
Ex 10.

Write a program that asks user to enter a string. Program must use fgets to read user input and remove the linefeed at the end of the string. Then program prints the length of the string and checks if the string is “stop”. If it is the program stops else program asks user to enter a new string (and prints the length etc.).
*/

#include <stdio.h>
#include <string.h>

int main(void) {
  char buffer[256];
  int length;

  while(1) {
    printf("Please input a string: ");
    fgets(buffer, 256, stdin);
    
    length = strlen(buffer);

    if (buffer[length - 1] == '\n') {
      buffer[--length] = '\0';
    }

    printf("The string is length: %d\n", length);
    if (strcasecmp(buffer, "stop") == 0) {
      printf("You input 'stop'.\n");
      return 0;
    }
  }
}

