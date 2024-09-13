/*
Ex 2.

Write a program that defines two floating-point arrays of 12 elements each. The program then asks user to enter tax percentage and yearly income limit up to which the percentage applies to and the (greater) tax percentage that will be applied to income that is over the limit. Then program asks user to enter salary of each month and stores the values in the array. After user has entered all monthly salaries, the program calculates tax for each month.

The program prints all salaries with two decimal precision and the amount of tax for each month.

You need to get familiar with printf field width specifiers to complete this!

Note that decimal points must be aligned as shown above!

The tricky part is the month where (if) the total income goes over the limit. That month part of salary is taxed with lower rate and part of the salary with higher rate.
*/

#include <stdio.h>

int main(void) {
    float income[12], tax[12];
    float tax_rate, tax_rate_over_lim, income_lim;

    printf("Enter tax rate (%%): ");
    scanf("%f", &tax_rate);

    printf("Enter income limit: ");
    scanf("%f", &income_lim);

    printf("Enter tax rate for income over the limit (%%): ");
    scanf("%f", &tax_rate_over_lim);

    // convert from percentage
    tax_rate /= 100;
    tax_rate_over_lim /= 100;

    for(int i = 0; i < 12; i++) {
        printf("Enter income for month %2d: ", i+1);
        scanf("%f", &income[i]);

        if (income[i] > income_lim) {
            tax[i] = income[i] * tax_rate_over_lim;
        } else {
            tax[i] = income[i] * tax_rate;
        }
    }

    printf("month     income       tax\n");
    for(int i = 0; i < 12; i++) {
        printf("%5d %10.2f %9.2f\n", i+1, income[i], tax[i]);
    }

    return 0;
}
