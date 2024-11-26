#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SENTINEL -1

typedef enum { CONTINUE, BREAK } loop_control;

loop_control input_loop(void);
bool validate(const double input_cost);
void calculate_change(double *const input_cost, int *const num_quarters,
                      int *const num_dimes, int *const num_nickels,
                      int *const num_pennies);

int main(void) {
  system("clear");
  puts("-----------------------------------------------------------------");
  puts("\t\tWelcome to the change counter!");
  puts("-----------------------------------------------------------------");

  loop_control l;
  do {
    l = input_loop();
  } while (l == CONTINUE);

  puts("\n-----------------------------------------------------------------");
  puts("\t\tThank you, and goodbye.");
  puts("-----------------------------------------------------------------");

  return 0;
}

// -----------------------------------------------------------------------------
loop_control input_loop(void) {
  double input_cost = 0.0;
  int num_quarters = 0;
  int num_dimes = 0;
  int num_nickels = 0;
  int num_pennies = 0;

  puts("Enter the amount you spent to two decimal places: the input must be\n"
       "between 0 and 1: -1 is to exit.\n");

  scanf("%lf", &input_cost);
  if (input_cost == SENTINEL)
    return BREAK;

  if (validate(input_cost)) {
    puts("You entered a number greater than 1 or less than zero that is not\n"
         "-1; please try again.\n");
    return CONTINUE;
  }

  calculate_change(&input_cost, &num_quarters, &num_dimes, &num_nickels,
                   &num_pennies);

  printf("\nThe amount you gave was $%g, your change is %i Quarters,\n%i"
         " Dimes, %i Nickels, and %i Pennies.\n\n",
         input_cost, num_quarters, num_dimes, num_nickels, num_pennies);

  return CONTINUE;
}

// -----------------------------------------------------------------------------
bool validate(const double input_cost) {
  return input_cost < 0 || input_cost > 1;
}

// -----------------------------------------------------------------------------
void calculate_change(double *const input_cost, int *const num_quarters,
                      int *const num_dimes, int *const num_nickels,
                      int *const num_pennies) {
  int cost_cents = 0;
  int change = 0;

  cost_cents = *input_cost * 100;
  change = cost_cents;
  *num_quarters = change / 25;
  change %= 25;
  *num_dimes = change / 10;
  change %= 10;
  *num_nickels = change / 5;
  change %= 5;
  *num_pennies = change;
}
