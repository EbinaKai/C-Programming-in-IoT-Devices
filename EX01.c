/*
# EX 1.

Write a program that:
1. Asks user to enter the price of a bus ticket
2. Asks user to enter the price of a taxi trip
3. Asks user to enter how much money he/she has
4. If user has not enough money for either type tells user to walk and then the program stops
5. Asks user to choose taxi or bus (use numbers for selection)
6. Checks if user has enough money for the selected trip type
    -  If User has enough money reduce the money by the selected trip’s price and print how much money is left, and go back to step 4
    -  If user has not enough money for the selected trip type then tell that to user and go back to step 4
*/

#include <stdio.h>

int main(void)
{
    float bus_price, taxi_price, possession_money;
    int chosen_transport;

    printf("Enter bus price: ");
    scanf("%f", &bus_price);
    printf("Enter taxi price: ");
    scanf("%f", &taxi_price);
    printf("How mach money do you have?: ");
    scanf("%f", &possession_money);

    while (1) {

        if (bus_price > possession_money && taxi_price > possession_money ) {
            printf("You don't have enough money, you should use your legs.");
            break;
        }

        printf("Which way do you want to use?\n");
        printf("1) Bus  (%.2f euro)\n", bus_price);
        printf("2) Taxi (%.2f euro)\n", taxi_price);
        printf("Enter your choice: ");
        scanf("%d", &chosen_transport);

        if (chosen_transport < 1 || chosen_transport > 2) {
            printf("Try again...\n");
            continue;
        }

        if (chosen_transport == 1 && bus_price <= possession_money) {
            printf("You choice the bus.\n");
            possession_money -= bus_price;
        } else if (chosen_transport == 2 && taxi_price <= possession_money) {
            printf("You choice the taxi.\n");
            possession_money -= taxi_price;
        } else {
            printf("You don't have enough money to use the way.\n");
        }

        printf("You have %.2f euro left.\n", possession_money);
    }

    return 0;
}
