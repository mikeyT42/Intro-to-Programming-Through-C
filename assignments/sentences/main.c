#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define SENTINEL '\n'
#define MAX_INPUT 300
#define CONTINUE 1
#define BREAK 0

int input_loop();
int keystrokes(char input[]);
int alpha_chars(char input[]);
int digit_chars(char input[]);
int vowels(char input[]);

int main(void) {
  system("clear");
  printf("-----------------------------------------------------------------\n");
  printf("\tWelcome to the Sentence Data Aggregator\n");
  printf("-----------------------------------------------------------------\n");

  int loop_control;
  do {
    loop_control = input_loop();
  } while (loop_control);

  printf("-----------------------------------------------------------------\n");
  printf("\t\tThank you and goodbye.\n");
  printf("-----------------------------------------------------------------\n");

  return 0;
}

// -----------------------------------------------------------------------------
int input_loop() {
  char input[MAX_INPUT];

  printf("\n\nPlease input a sentence. If you want to exit, just hit enter.\n");
  fgets(input, MAX_INPUT, stdin);
  if (input[0] == SENTINEL)
    return BREAK;

  const int total_keystrokes = keystrokes(input);
  printf("\nKeystrokes: %10i", total_keystrokes);
  const int total_alpha_chars = alpha_chars(input);
  printf("\nAlpha Characters: %4i", total_alpha_chars);
  const int total_digit_chars = digit_chars(input);
  printf("\nNumeric Characters: %2i", total_digit_chars);
  const int total_vowels = vowels(input);
  printf("\nVowels: %14i", total_vowels);

  return CONTINUE;
}

// -----------------------------------------------------------------------------
int keystrokes(char input[]) {
  int keystrokes = 0;

  for (int k = 0; input[k] != SENTINEL; k++) {
    input[k] = toupper(input[k]);
    keystrokes++;
  }

  return keystrokes;
}

// -----------------------------------------------------------------------------
int alpha_chars(char input[]) {
  int total_alpha_chars = 0;

  for (int i = 0; input[i] != SENTINEL; i++) {
    if (!isalpha(input[i]))
      continue;
    else if (isdigit(input[i]))
      continue;
    else if (isspace(input[i]))
      continue;

    total_alpha_chars++;
  }

  return total_alpha_chars;
}

// -----------------------------------------------------------------------------
int digit_chars(char input[]) {
  int total_digit_chars = 0;

  for (int i = 0; input[i] != SENTINEL; i++) {
    if (isdigit(input[i]))
      total_digit_chars++;
  }

  return total_digit_chars;
}

// -----------------------------------------------------------------------------
int vowels(char input[]) {
  int total_vowels = 0;

  for (int i = 0; input[i] != SENTINEL; i++) {
    if (!isalpha(input[i]))
      continue;
    else if (isdigit(input[i]))
      continue;
    else if (isspace(input[i]))
      continue;

    switch (input[i]) {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      total_vowels++;
      break;
    }
  }

  return total_vowels;
}
