/*
Ex11

Write a function called replace_char that takes two strings as parameters and returns an integer.

The first string is the string to modify and the second is a string containing two characters. The function finds every occurrence of the first character of the second string and replaces them with

the second character. For example:
char text[80] = “I am so tired of Python. C is much better language”;
count = replace_char(test, “e3”);

The call above will find every occurrence of ‘e’ and replace it with ‘3’.

Prototype of the function:
int replace_char(char *str, const char *repl);

The function returns the number of characters replaced. The return value can be zero if no characters were found or if the second string does not contain two characters.

Write a program that asks user to enter both strings and then calls replace_char. The program prints both return value and the modified string if the return value is greater than zero. If the return value is zero program prints “String was not modified”.
*/

#include <stdio.h>
#include <string.h>

int replace_char(char *str, char *param);

int main(void) {
  char text[256], param[3];
  int length, count;

  printf("Please input text[256]: ");
  fgets(text, 256, stdin);
  length = strlen(text);

  if (text[length - 1] == '\n') {
    text[--length] = '\0';
    printf("replace characters with spaces\n");
  }

  printf("Enter two characters to replace (e.g., 'e3'): ");
  fgets(param, 3, stdin);
  printf("%s\n", param);

  length = strlen(text);
  
  count = replace_char(text, param);
  if ( count > 0 ) {
    printf("Modified characters count: %d\n", count);
    printf("Modified string -> %s\n", text);
  } else {
    printf("String was not modified\n");
  }
  
  return 0;

}

int replace_char(char *str, char *param) {
  int length = strlen(str);
  int count = 0;

  for(int i = 0; i < length; i++) {
    if (str[i] == param[0]) {
      str[i] = param[1];
      count++;
    }
  }
  return count;
}