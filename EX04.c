/*
Ex 4.

Write a function called read_integer that takes no parameters and returns an integer. The function reads a single integer. If the reading fails the function prints “invalid input” and tries to read an integer again. When an integer is successfully read the function returns the integer.

The declaration of the function is: 

int read_integer(void);

Write a program that asks user to enter positive integers or a negative number to stop. The program must use read_integer-function to read the number. The program calculates and prints the average of the entered numbers excluding the negative number. For example, if user enters: 1 3 4 2 7 -1, the program prints 3.4 as the average.

The program must print the average with three decimal precision.
*/

#include <stdio.h>

int read_integer(void);

int main(void) {
    int total=0, count=0, tmp;

    while (1) {
        printf("Enter positive numbers or negative to stop: ");
        tmp = read_integer();
        if (tmp<0) break;

        total += tmp;
        count++;
    }

    printf("You entered %d positive numbers. The average is: %.3f", count, (float)total / count);

    return 0;
}

int read_integer(void) {
    int tmp = -0x80000000;
    do {
        if (scanf("%d", &tmp) != 1) {
            while(getchar() != '\n') {}
            printf("invalid input\n");
            printf("Please try again: ");
        }
    } while(tmp == -0x80000000);
    return tmp;
}