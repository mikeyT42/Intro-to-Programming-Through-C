#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 10
#define MAX_INPUT_STRING 50
#define SENTINEL 0

typedef enum { CONTINUE, BREAK } loop_control;
typedef enum { GOOD, NAN, MORE_THAN_MAX } validation_codes;

loop_control input_loop(void);
void clean_input(char input[]);
validation_codes validate(const char input[]);

void sums(const double numbers[], const unsigned int numbers_len,
          double *const sum_positive, double *const sum_negative,
          double *const sum_overall, unsigned int *const count_positive,
          unsigned int *const count_negative,
          unsigned int *const count_overall);

void average(const double sum_positive, const double sum_negative,
             const double sum_overall, const unsigned int count_positive,
             const unsigned int count_negative,
             const unsigned int count_overall, double *const average_positive,
             double *const average_negative, double *const average_overall);

void print_table(const double numbers[], const unsigned int numbers_len,
                 const double sum_positive, const double sum_negative,
                 const double sum_overall, const double average_positive,
                 const double average_negative, const double average_overall,
                 const unsigned int count_positive,
                 const unsigned int count_negative,
                 const unsigned int count_overall);

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  printf("-----------------------------------------------------------------\n");
  printf("\tWelcome to the Summer and Averager\n");
  printf("-----------------------------------------------------------------\n");

  loop_control l;
  do {
    l = input_loop();
  } while (l == CONTINUE);

  printf("-----------------------------------------------------------------\n");
  printf("\t\tDhank you, come again.\n");
  printf("-----------------------------------------------------------------\n");

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
loop_control input_loop(void) {
  double numbers[MAX_INPUT_STRING];
  char input[MAX_NUMBERS];
  unsigned int input_len;
  printf("Please input up to %i floating point or integer numbers. Seperate\n"
         "them with spaces.\n\n",
         MAX_NUMBERS);
  fgets(input, MAX_INPUT_STRING, stdin);
  if (input[0] == SENTINEL)
    return BREAK;
  validate(input);
  clean_input(input);

  return CONTINUE;
}

// -----------------------------------------------------------------------------
validation_codes validate(const char input[]) {return GOOD;}

// -----------------------------------------------------------------------------
void clean_input(char input[]) { input[strlen(input) - 1] = '\0'; }
