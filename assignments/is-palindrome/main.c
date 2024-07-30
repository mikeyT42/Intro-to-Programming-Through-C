#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 100
#define SENTINEL '\n'
#define CONTINUE true
#define BREAK false

bool input_loop(void);
void clean_input(char input[]);
bool is_palindrome(const char input[]);

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  printf("-----------------------------------------------------------------\n");
  printf("\tWelcome to the Palindrome Checker\n");
  printf("-----------------------------------------------------------------\n");

  bool loop_control;
  do {
    loop_control = input_loop();
  } while (loop_control);

  printf("-----------------------------------------------------------------\n");
  printf("\t\tDhank you, come again.\n");
  printf("-----------------------------------------------------------------\n");

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
bool input_loop(void) {
  puts("Please enter a string that is a palindrome; if you want to exit then\n"
       "then just hit enter. It can be a sentence or a word.\n");

  char input[INPUT_SIZE];
  fgets(input, INPUT_SIZE, stdin);
  if (input[0] == SENTINEL)
    return BREAK;

  clean_input(input);
  if (is_palindrome(input))
    printf("\n\"%s\" is a palindrome.\n\n", input);
  else
    printf("\n\"%s\" is not a palindrome.\n\n", input);

  return CONTINUE;
}

// -----------------------------------------------------------------------------
void clean_input(char input[]) {
  puts("----\nCleaing the input.\n----");
  // Get rid of the \n from the end of the input.
  const int len = strlen(input);
  input[len - 1] = '\0';

  for (int i = 0; input[i] != '\0'; i++) {
    input[i] = tolower(input[i]);
    printf("input[i=%i] = %c\n", i, input[i]);
    if (isalnum(input[i]))
      continue;

    // Get rid of the space character by pushing the next chars back one.
    for (int j = i; input[j] != '\0'; j++) {
      printf("input[j=%i] = %c\n", j, input[j]);
      input[j] = input[j + 1];
    }
  }
}

// -----------------------------------------------------------------------------
bool is_palindrome(const char input[]) {
  puts("----\nChecking For Palindrome\n----");
  const int len = strlen(input);
  for (int i = 0; i < len / 2; i++) {
    printf("input[%i] = %c\n", i, input[i]);
    printf("input[%i - %i - 1] = %c\n", len, i, input[len - i - 1]);
    if (isspace(input[i]))
      continue;
    if (input[i] != input[len - i - 1])
      return false;
  }

  return true;
}
