#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define SENTINEL '\n'
#define MAX_INPUT 300
#define CONTINUE 1
#define BREAK 0

int inputLoop();
int keystrokes(char input[]);
int alphaChars(char input[]);
int digitChars(char input[]);
int vowels(char input[]);

int main(void) {
  system("clear");
  printf("-----------------------------------------------------------------\n");
  printf("\tWelcome to the Sentence Data Aggregator\n");
  printf("-----------------------------------------------------------------\n");

  int loopControl = CONTINUE;
  while (loopControl) {
    loopControl = inputLoop();
  }

  printf("-----------------------------------------------------------------\n");
  printf("\t\tThank you and goodbye.\n");
  printf("-----------------------------------------------------------------\n");

  return 0;
}

// -----------------------------------------------------------------------------
int inputLoop() {
  char input[MAX_INPUT];

  printf("\n\nPlease input a sentence. If you want to exit, just hit enter.\n");
  fgets(input, MAX_INPUT, stdin);
  if (input[0] == SENTINEL)
    return BREAK;

  const int totalKeystrokes = keystrokes(input);
  printf("\nKeystrokes: %10i", totalKeystrokes);
  const int totalAlphaChars = alphaChars(input);
  printf("\nAlpha Characters: %4i", totalAlphaChars);
  const int totalDigitChars = digitChars(input);
  printf("\nNumeric Characters: %2i", totalDigitChars);
  const int totalVowels = vowels(input);
  printf("\nVowels: %14i", totalVowels);

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
int alphaChars(char input[]) {
  int totalAlphaChars = 0;

  for (int i = 0; input[i] != SENTINEL; i++) {
    if (!isalpha(input[i]))
      continue;
    else if (isdigit(input[i]))
      continue;
    else if (isspace(input[i]))
      continue;

    totalAlphaChars++;
  }

  return totalAlphaChars;
}

// -----------------------------------------------------------------------------
int digitChars(char input[]) {
  int totalDigitChars = 0;

  for (int i = 0; input[i] != SENTINEL; i++) {
    if (isdigit(input[i]))
      totalDigitChars++;
  }

  return totalDigitChars;
}

// -----------------------------------------------------------------------------
int vowels(char input[]) {
  int totalVowels = 0;

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
      totalVowels++;
      break;
    }
  }

  return totalVowels;
}
