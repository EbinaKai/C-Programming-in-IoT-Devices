/*
EX 16.

Write a program that asks user to enter numbers or to enter end to stop entering numbers. If user enters any other text except end the program prints an error message and discards the input. The program must store the numbers in a linked list where each node is dynamically allocated.

typedef struct node {
  int number;
  struct node *next;
} nnode;

When user enters end the program prints all entered numbers, frees the allocated memory and then ends.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
  int number;
  struct node *next;
} nnode;

void print_list(struct node *);
void free_list(struct node *);
void replace_space2null(char *str);

int main(void){
  nnode *head = NULL;
  nnode *tail = NULL;
  char buf[50];
  char *endptr;
  int number;

  while(true) {
    // Get user input
    printf("Please input number or 'end' to quit: ");
    fgets(buf, 50, stdin);
    replace_space2null(buf);

    if (strcmp(buf, "end") == 0) {
      break;
    }

    // Check if input is a number
    number = strtol(buf, &endptr, 10);
    if (*endptr != '\0') {
      printf("Error: Invalid input. Please enter a number.\n");
      continue;
    }

    // Add number to the list
    nnode *new_node = malloc(sizeof(nnode));

    if (new_node == NULL) {
      printf("メモリ割り当てエラー\n");
      return 1;
    }
    new_node->number = number;
    new_node->next = NULL;
    
    if (head == NULL) {
      head = new_node;
      tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
  }

  // Print the list
  printf("Entered numbers:\n");
  print_list(head);

  // Free the list
  free_list(head);

	return 0;
}

void print_list(struct node *head){
  struct node *current = head;
  while(current != NULL){
    printf("%d\n", current->number);
    current = current->next;
  }
}

void free_list(struct node *head){
  struct node *current = head;
  struct node *next;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
}

void replace_space2null(char *str) {
  int length = strlen(str);
  if (str[length - 1] == '\n') {
    str[length - 1] = '\0';
  }
}