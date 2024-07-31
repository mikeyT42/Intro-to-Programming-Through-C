#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 10
#define SENTINEL 0

typedef enum { CONTINUE, BREAK } loop_control;
typedef enum { GOOD, NAN } validation_codes;

loop_control input_loop(void);
validation_codes validate(const double input[]);

void sums(const double input[], const unsigned int input_len,
          double *const sum_positive, double *const sum_negative,
          double *const sum_overall, unsigned int *const count_positive,
          unsigned int *const count_negative,
          unsigned int *const count_overall);

void average(const double sum_positive, const double sum_negative,
             const double sum_overall, const unsigned int count_positive,
             const unsigned int count_negative,
             const unsigned int count_overall, double *const average_positive,
             double *const average_negative, double *const average_overall);

void print_table(const double input[], const unsigned int input_len,
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
  double input[MAX_INPUT];
  unsigned int input_len;
  printf("Please input up to %i floating point or integer numbers. Seperate\n"
         "them with spaces. To signify the end of input enter a 0.\n\n",
         MAX_INPUT);
  for (int i = 0, input_len = 0; i < MAX_INPUT; i++, input_len++) {
    scanf("%lg", &input[i]);
    printf("%lg\n", input[i]);
    if (input[i] == SENTINEL)
      break;
  }

  return CONTINUE;
}
