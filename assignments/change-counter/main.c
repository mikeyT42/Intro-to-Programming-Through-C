#include <stdio.h>
#include <stdlib.h>

#define SENTINEL -1

typedef enum { CONTINUE, BREAK } loop_control;

loop_control input_loop(void);
void calculate_change(double *input_cost, int *num_quarters, int *num_dimes,
                      int *num_nickels, int *num_pennies);

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
  if (input_cost < 0 || input_cost > 1) {
    printf("\n%s%s\n\n", "You entered a number greater than 1 or less than",
           " zero that is not\n-1; please try again.");
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
void calculate_change(double *input_cost, int *num_quarters, int *num_dimes,
                      int *num_nickels, int *num_pennies) {
  int cost_cents = 0;
  int change = 0;

  cost_cents =
      *input_cost * 100; // + 0.5 fix truncation error; I wonder if I need this?
  printf("cost_cents = %i\n", cost_cents);
  change = cost_cents;
  printf("change = %i\n", change);
  *num_quarters = change / 25;
  printf("num_quarters = %i\n", *num_quarters);
  change %= 25; // The change remainder.
  printf("change remainder = %i\n", change);
  *num_dimes = change / 10;
  printf("num_dimes = %i\n", *num_dimes);
  change %= 10;
  printf("change remainder = %i\n", change);
  *num_nickels = change / 5;
  printf("num_nickels = %i\n", *num_nickels);
  change %= 5;
  printf("change remainder = %i\n", change);
  *num_pennies = change; // and finally what's left!.
  printf("num_pennies = %i\n", *num_pennies);
}
