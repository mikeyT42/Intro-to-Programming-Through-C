#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10
#define MAX_INPUT_STRING 256
#define SENTINEL '\n'

typedef enum { CONTINUE, BREAK } loop_control;

typedef struct {
  double positive;
  double negative;
  double overall;
} sums;

typedef struct {
  unsigned int positive;
  unsigned int negative;
  unsigned int overall;
} counts;

typedef struct {
  double positive;
  double negative;
  double overall;
} averages;

loop_control input_loop(void);
void sum_and_count(const double numbers[], const unsigned int numbers_len,
                   sums *const sums, counts *const counts);
void average(const sums sums, const counts counts, averages *const averages);
void print_table(const sums sums, const counts counts, const averages averages);

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

  // TODO: Bug with the first input not being a number skips the rest of numbers
  const int num_matches =
      sscanf(input, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &numbers[0],
             &numbers[1], &numbers[2], &numbers[3], &numbers[4], &numbers[5],
             &numbers[6], &numbers[7], &numbers[8], &numbers[9]);
  if (num_matches <= 0) {
    puts("You did not enter any valid numbers; please try again.\n");
    return CONTINUE;
  }

  sums sums = {.positive = 0, .negative = 0, .overall = 0};
  counts counts = {.positive = 0, .negative = 0, .overall = 0};
  averages averages = {.positive = 0, .negative = 0, .overall = 0};

  sum_and_count(numbers, num_matches, &sums, &counts);
  average(sums, counts, &averages);
  print_table(sums, counts, averages);

  return CONTINUE;
}

// -----------------------------------------------------------------------------
void sum_and_count(const double numbers[], const unsigned int numbers_len,
                   sums *const sums, counts *const counts) {
  for (int i = 0; i < numbers_len; i++) {
    if (numbers[i] >= 0) {
      sums->positive += numbers[i];
      counts->positive++;
    } else {
      sums->negative += numbers[i];
      counts->negative++;
    }
    sums->overall += numbers[i];
    counts->overall++;
  }
}

// -----------------------------------------------------------------------------
void average(const sums sums, const counts counts, averages *const averages) {
  if (counts.positive == 0)
    averages->positive = 0;
  else
    averages->positive = sums.positive / counts.positive;

  if (counts.negative == 0)
    averages->negative = 0;
  else
    averages->negative = sums.negative / counts.negative;

  if (sums.overall == 0 || counts.overall == 0)
    averages->overall = 0;
  else
    averages->overall = sums.overall / counts.overall;
}

// -----------------------------------------------------------------------------
void print_table(const sums sums, const counts counts,
                 const averages averages) {
  printf("\nStatistics:\n");
  printf("%18s%16s%14s\n", "Number:", "Total:", "Average:");
  printf("Positive:%9u%16.3f%14.3f\n", counts.positive, sums.positive,
         averages.positive);
  printf("Negative:%9u%16.3f%14.3f\n", counts.negative, sums.negative,
         averages.negative);
  printf("Overall:%10u%16.3f%14.3f\n\n", counts.overall, sums.overall,
         averages.overall);
}
