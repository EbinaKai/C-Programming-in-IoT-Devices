/*
Ex 6.

Write a program that prints a menu and asks user to select an operation. The operations are:

- Roll D6
- Roll D10
- Quit

Input must be validated and a descriptive error message must be printed if input is invalid. Rolling D6 prints a random number in the range of 1 – 6 and rolling D10 prints a random number in the range of 1 – 10. If user does not select quit the program prints the menu again.

Use functions to structure your program.
See: https://en.cppreference.com/w/c/numeric/random/rand for how to produce random numbers in a range.
*/

#include <stdio.h>
#include <stdlib.h>

int read_integer();
void print_menu();
int generate_random_number(int min, int max);

int main(void)
{
    int option=1;

    while (option != 3) {
        print_menu();
        option = read_integer();
        if (option < 1 || option > 3) {
            printf("Invalid Input... Please try again.\n");
            continue;
        }
        switch (option) {
            case 1:
                printf("Roll D6: %d\n", generate_random_number(1, 6));
                break;
            case 2:
                printf("Roll D10: %d\n", generate_random_number(1, 10));
                break;
            case 3:
            default:
                break;
        }
    }

    return 0;
}

void print_menu() {
    printf("Please select from menu by number\n");
    printf("Roll D6  (1)\n");
    printf("Roll D10 (2)\n");
    printf("Quit     (3)\n");
    printf("Please input your selection: ");
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