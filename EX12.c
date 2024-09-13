/*
Ex 12.

Write a function count_words that takes two strings as a parameter and returns an integer. The function counts the number of times the second string occurs in the first string and returns the count. Use strstr() from standard library to find the strings. Note that if the string is found you need to advance past the current occurrence before searching again. Hint: use a pointer to the string and use pointer arithmetic to advance it past the current match.

Prototype of the function:
int count_words(const char* str, const char *word);

Write a program that asks user to enter a string and a word. Then program calls count_words and prints the return value. If the word was “stop” the program stops otherwise it asks user to enter a string and a word again.
*/

#include <stdio.h>
#include <string.h>

int count_words(const char* str, const char *word);
void replace_space2null(char *str);

int main(void){
  char text[256], word[256];
  int count;

  while(1) {
    printf("Please input text[256]: ");
    fgets(text, 256, stdin);
    replace_space2null(text);

    printf("Please input search word[256] or 'stop' to quit: ");
    fgets(word, 256, stdin);
    replace_space2null(word);

    count = count_words(text, word);
    printf("The number of words '%s' in the text is %d\n", word, count);

    // quit
    if (strcmp(word, "stop") == 0) {
      printf("See you next time!\n");
      break;
    }
  }
	return 0;
}

int count_words(const char* str, const char *word) {
  const char* pos = str;
  int count = 0, length;
  length = strlen(word);

  while ((pos = strstr(pos, word)) != NULL) {
    count ++;
    pos += length;
  }

  return count;
}

void replace_space2null(char *str) {
  int length = strlen(str);
  if (str[length - 1] == '\n') {
    str[length - 1] = '\0';
  }
}