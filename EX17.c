/*
EX 17.

Write a password generator function that takes three parameters: character pointer, integer (size of the array), a const char pointer (a word) and returns a bool. The function generates password and stores it in the array and returns true. The length of the generated password is the 𝑙𝑒𝑛𝑔𝑡ℎ 𝑜𝑓 𝑤𝑜𝑟𝑑 × 2 + 1 characters. If the password does not fit in the string function returns false and does not modify the string.

The password must contain the word given as a parameter so that password starts with a random printable character and every other letter is a letter from the word and every other is a random printable character. The password ends with a random printable character. Note that printable characters are not limited to alphanumerical characters.

Write a program that asks user to enter a word to place in the password or to enter “stop” to stop the program. The size of the string to read the word into must be 32. If user does not enter stop the program generates a password using the generator function. If a password is generated successfully the program prints it otherwise an error message is printed. Then the program asks for another word.

For example:
User enters: metropolia
Program prints: #m%eGtqrHo&p2o+lBimaY

You don’t need to use colours. They are just a visual aid. The random characters will naturally be different on your program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_WORD_SIZE 32

bool generate_password(char *password, int size, const char *word);
void replace_space2null(char *str);

int main(void) {
  char word[MAX_WORD_SIZE];

  while (true) {
    printf("Please enter a word or 'stop' to quit: ");
    fgets(word, MAX_WORD_SIZE, stdin);
    replace_space2null(word);

    if (strcmp(word, "stop") == 0) {
      break;
    }

    int word_len = strlen(word);
    int password_len = word_len * 2 + 1;
    char* password = (char*)malloc(password_len + 1);
    if (!generate_password(password, password_len + 1, word)) {
      printf("Error: Password generation failed.\n");
    } else {
      printf("Generated password: %s\n", password);
    }

    free(password);
  }

  return 0;
}

bool generate_password(char *password, int size, const char *word) {
  int word_len = strlen(word);
  int required_size = word_len * 2 + 1;
  if (size < required_size + 1) {
    return false;
  }

  const char printable[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
  int printable_size = strlen(printable);

  // rand initialization
  srand((unsigned int)time(NULL));

  int i = 0;
  password[i++] = printable[rand() % printable_size];
  for (int j = 0; j < word_len; ++j) {
    password[i++] = word[j];
    if (i <= required_size) {
      password[i++] = printable[rand() % printable_size];
    }
  }
  password[i] = '\0'; // ヌル終端
  return true;
}

void replace_space2null(char *str) {
  int length = strlen(str);
  if (str[length - 1] == '\n') {
    str[length - 1] = '\0';
  } else if (str[length - 1] != '\0') {
    str[length - 1] = '\0';
  }
}