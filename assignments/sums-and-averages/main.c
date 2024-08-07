#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10
#define MAX_INPUT_STRING 256
#define SENTINEL '\n'

typedef enum { CONTINUE, BREAK } loop_control;

loop_control input_loop(void);
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
  double numbers[MAX_NUMBERS];
  char input[MAX_INPUT_STRING];
  printf("Please input up to %i floating point or integer numbers. Seperate\n"
         "them with spaces. Simply enter a newline character to exit.\n\n",
         MAX_NUMBERS);
  fgets(input, MAX_INPUT_STRING, stdin);

  if (input[0] == SENTINEL)
    return BREAK;

  const int num_matches =
      sscanf(input, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &numbers[0],
             &numbers[1], &numbers[2], &numbers[3], &numbers[4], &numbers[5],
             &numbers[6], &numbers[7], &numbers[8], &numbers[9]);
  if (num_matches <= 0) {
    puts("You did not enter any valid numbers; please try again.\n");
    return CONTINUE;
  }

  double sum_positive, sum_negative, sum_overall;
  sum_positive = sum_negative = sum_overall = 0.0;
  unsigned int count_positive, count_negative, count_overall;
  count_positive = count_negative = count_overall = 0;
  double average_positive, average_negative, average_overall;
  average_positive = average_negative = average_overall = 0.0;

  sums(numbers, num_matches, &sum_positive, &sum_negative, &sum_overall,
       &count_positive, &count_negative, &count_overall);
  average(sum_positive, sum_negative, sum_overall, count_positive,
          count_negative, count_overall, &average_positive, &average_negative,
          &average_overall);
  print_table(numbers, num_matches, sum_positive, sum_negative, sum_overall,
              average_positive, average_negative, average_overall,
              count_positive, count_negative, count_overall);

  return CONTINUE;
}

// -----------------------------------------------------------------------------
void sums(const double numbers[], const unsigned int numbers_len,
          double *const sum_positive, double *const sum_negative,
          double *const sum_overall, unsigned int *const count_positive,
          unsigned int *const count_negative,
          unsigned int *const count_overall) {
  for (int i = 0; i < numbers_len; i++) {
    if (numbers[i] >= 0) {
      *sum_positive += numbers[i];
      (*count_positive)++;
    } else {
      *sum_negative += numbers[i];
      (*count_negative)++;
    }
    *sum_overall += numbers[i];
    (*count_overall)++;
  }
}

// -----------------------------------------------------------------------------
void average(const double sum_positive, const double sum_negative,
             const double sum_overall, const unsigned int count_positive,
             const unsigned int count_negative,
             const unsigned int count_overall, double *const average_positive,
             double *const average_negative, double *const average_overall) {
  if (count_positive == 0)
    *average_positive = 0;
  else
    *average_positive = sum_positive / count_positive;

  if (count_negative == 0)
    *average_negative = 0;
  else
    *average_negative = sum_negative / count_negative;

  *average_overall = sum_overall / count_overall;
}

// -----------------------------------------------------------------------------
void print_table(const double numbers[], const unsigned int numbers_len,
                 const double sum_positive, const double sum_negative,
                 const double sum_overall, const double average_positive,
                 const double average_negative, const double average_overall,
                 const unsigned int count_positive,
                 const unsigned int count_negative,
                 const unsigned int count_overall) {
  printf("\nStatistics:\n");
  printf("%18s%16s%14s\n", "Number:", "Total:", "Average:");
  printf("Positive:%9u%16.3f%14.3f\n", count_positive, sum_positive,
         average_positive);
  printf("Negative:%9u%16.3f%14.3f\n", count_negative, sum_negative,
         average_negative);
  printf("Overall:%10u%16.3f%14.3f\n\n", count_overall, sum_overall,
         average_overall);
}
