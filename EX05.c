/*
Ex 5.

Write a function read_range that takes two integer parameters and returns an integer. The function asks user to enter a number in the range given as parameters. The first parameter is the lowest acceptable value and the second is the highest acceptable value. When user enters a number the input is validated in the following ways:

- A number was successfully read
- The number is in the specified range

If the input is invalid then a descriptive error message is printed and user is asked to enter number again. The function returns only if correct input is given. The function returns the entered number.

The declaration of the function is:

int read_range(int low, int high);

Write a program that “plays” a dice game with user. The game consists of three rounds where program asks user to roll a die and enter the result (1 – 6). The program must use read_range to validate input.

The program cheats and always claims to have one higher than what user rolled except when user rolls six – then program says that it is a tie.
*/

#include <stdio.h>

int read_range(int low, int high);
int read_integer();

int main(void) {
    int dice;

    printf("Let’s play!\n");
    do {
        printf("Roll a die and enter your result.");
        dice = read_range(1, 6);

        switch (dice) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                printf("I got %d. I win!\n", dice+1);
                break;
            case 6:
                printf("I got 6. It is a tie!\n");
        }

    } while( dice != 6) ;

    printf("Better luck next time. Bye!");

    return 0;
}

int read_range(int low, int high) {
    int tmp;
    printf("Enter a number between 1 and 6: ");

    while (1) {
        tmp = read_integer();
        if ( tmp >= low && tmp <= high ) break;

        printf("invalid input, please try again: ");
    }

    return tmp;
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