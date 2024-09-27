/*
# Car sales manager

Write a program to keep track of car sales. The program stores car informaDon in a CSV-file. Each row of the file contains informaDon about one car:
• Make
• Model
• Mileage
• Purchase date
• Purchase price
• Selling date
• Selling price

Program must have at least the following funcDonality:
• Add a car – ask user to enter the information described above and append it to the end of the file
• Print a report where the cars are sorted by profit (selling price – purchase price) in descending order
• Print a report where the cars are sorted by the sell time (difference between selling date and purchase date)
• Both reports must start with the total profit made.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 100

typedef struct Car
{
    char make[MAX];
    char model[MAX];
    int mileage;
    char purchase_date[MAX]; // Y-m-d
    int purchase_price;
    char selling_date[MAX]; // Y-m-d
    int selling_price;
    int profit;
} Car;

void add_car(char *filename);
void print_report_profit(char *filename);
void print_report_time(char *filename);
int compare_profit(const void *car1, const void *car2);
int compare_sell_time(const void *car1, const void *car2);

int main(void) {
    char filename[MAX];
    int choice;

    // Get the filename
    printf("Enter the filename to save data: ");
    scanf("%s", filename);

    // Menu
    while (true) {
        printf("1. Add a car\n");
        printf("2. Print a report where the cars are sorted by profit\n");
        printf("3. Print a report where the cars are sorted by the sell time\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_car(filename);
                break;
            case 2:
                print_report_profit(filename);
                break;
            case 3:
                print_report_time(filename);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void add_car(char *filename) {
  Car car;
  FILE *file;

  file = fopen(filename, "a+");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }

  // Create a new car info
  printf("Enter make: ");
  scanf("%s", car.make);
  printf("Enter model: ");
  scanf("%s", car.model);
  printf("Enter mileage: ");
  scanf("%d", &car.mileage);
  printf("Enter purchase date[Y-m-d]: ");
  scanf("%s", car.purchase_date);
  printf("Enter purchase price: ");
  scanf("%d", &car.purchase_price);
  printf("Enter selling date[Y-m-d]: ");
  scanf("%s", car.selling_date);
  printf("Enter selling price: ");
  scanf("%d", &car.selling_price);

  fprintf(file, "%s,%s,%d,%s,%d,%s,%d\n", car.make, car.model, car.mileage, car.purchase_date, car.purchase_price, car.selling_date, car.selling_price);
  fclose(file);
}

void print_report_profit(char *filename) {
  Car cars[MAX];
  Car temp;
  int i = 0;
  int total_profit = 0;
  FILE *file;

  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }

  // Read the file as csv format
  while (fscanf(file, "%[^,],%[^,],%d,%[^,],%d,%[^,],%d\n", cars[i].make, cars[i].model, &cars[i].mileage, cars[i].purchase_date, &cars[i].purchase_price, cars[i].selling_date, &cars[i].selling_price) != EOF) {
    cars[i].profit = cars[i].selling_price - cars[i].purchase_price;
    total_profit += cars[i].profit;
    i++;
  }

  // Sort the cars by profit
  qsort(cars, i, sizeof(cars[0]), compare_profit);

  printf("Total profit: %d\n", total_profit);
  for (int j = 0; j < i; j++) {
    printf("Make: %s\n", cars[j].make);
    printf("Model: %s\n", cars[j].model);
    printf("Mileage: %d\n", cars[j].mileage);
    printf("Purchase date: %s\n", cars[j].purchase_date);
    printf("Purchase price: %d\n", cars[j].purchase_price);
    printf("Selling date: %s\n", cars[j].selling_date);
    printf("Selling price: %d\n", cars[j].selling_price);
    printf("Profit: %d\n\n", cars[j].profit);
  }
  fclose(file);
}

void print_report_time(char *filename) {
  Car cars[MAX];
  Car temp;
  int i = 0;
  int total_profit = 0;
  FILE *file;

  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }

  // Read the file as csv format
  while (fscanf(file, "%[^,],%[^,],%d,%[^,],%d,%[^,],%d\n", cars[i].make, cars[i].model, &cars[i].mileage, cars[i].purchase_date, &cars[i].purchase_price, cars[i].selling_date, &cars[i].selling_price) != EOF) {
    cars[i].profit = cars[i].selling_price - cars[i].purchase_price;
    total_profit += cars[i].profit;
    i++;
  }
  
  // Sort the cars by selling time
  qsort(cars, i, sizeof(cars[0]), compare_sell_time);

  printf("Total profit: %d\n", total_profit);
  for (int j = 0; j < i; j++) {
    printf("Make: %s\n", cars[j].make);
    printf("Model: %s\n", cars[j].model);
    printf("Mileage: %d\n", cars[j].mileage);
    printf("Purchase date: %s\n", cars[j].purchase_date);
    printf("Purchase price: %d\n", cars[j].purchase_price);
    printf("Selling date: %s\n", cars[j].selling_date);
    printf("Selling price: %d\n\n", cars[j].selling_price);
  }
  fclose(file);
}

// Compare functions
int compare_profit(const void *car1, const void *car2) {
  if (((Car *)car1)->profit < ((Car *)car2)->profit) {
    return 1;
  } else if (((Car *)car1)->profit > ((Car *)car2)->profit) {
    return -1;
  } else {
    return 0;
  }
}
int compare_sell_time(const void *car1, const void *car2) {
  time_t t1, t2;
  struct tm tm1, tm2;

  strptime(((Car *)car1)->selling_date, "%Y-%m-%d", &tm1);
  strptime(((Car *)car2)->selling_date, "%Y-%m-%d", &tm2);
  t1 = mktime(&tm1);
  t2 = mktime(&tm2);

  if (difftime(t1, t2) < 0) {
    return 1;
  } else if (difftime(t1, t2) > 0) {
    return -1;
  } else {
    return 0;
  }
}