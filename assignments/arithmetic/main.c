#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int add(int x, int y);
int subtract(int x, int y);
int multiply(int x, int y);
int divide(int x, int y);
int remainder_of(int x, int y);
double power(int x, int y);

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  printf("-----------------------------------------------------------------\n");
  printf("\t\t\tWelcome\n");
  printf("-----------------------------------------------------------------\n");

  int x = 5;
  int y = 2;
  int result;

  result = add(x, y);
  printf("result = %i\n\n", result);

  result = subtract(x, y);
  printf("result = %i\n\n", result);

  result = multiply(x, y);
  printf("result = %i\n\n", result);

  result = divide(x, y);
  printf("result = %i\n\n", result);

  result = remainder_of(x, y);
  printf("result = %i\n\n", result);

  double result2 = power(x, y);
  printf("result = %f\n\n", result2);

  printf("-----------------------------------------------------------------\n");
  printf("\t\t\tThank you.\n");
  printf("-----------------------------------------------------------------\n");

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
int add(int x, int y) {
  printf("adding %i to %i\n", x, y);
  return x + y;
}

// -----------------------------------------------------------------------------
int subtract(int x, int y) {
  printf("subtracting %i from %i\n", y, x);
  return x - y;
}

// -----------------------------------------------------------------------------
int multiply(int x, int y) {
  printf("multiplying %i by %i\n", x, y);
  return x * y;
}

// -----------------------------------------------------------------------------
int divide(int x, int y) {
  printf("dividing %i by %i\n", x, y);
  return x / y;
}

// -----------------------------------------------------------------------------
int remainder_of(int x, int y) {
  printf("getting the remainder of the division of %i by %i\n", x, y);
  return x % y;
}

// -----------------------------------------------------------------------------
double power(int x, int y) {
  printf("raising %i to the power of %i\n", x, y);
  return pow(x, y);
}
