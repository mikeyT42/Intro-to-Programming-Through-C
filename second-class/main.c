#include <stdio.h>
#include <string.h>

int how_many_in_array();
void using_if_statements();
void some_enum_stuff();
void what_struct();

// -----------------------------------------------------------------------------
int main(void) {
  int how_many = how_many_in_array();
  printf("how many elements in char array = %i\n", how_many);

  using_if_statements();
  some_enum_stuff();
  what_struct();

  return 0;
}

// -----------------------------------------------------------------------------
void using_if_statements() {
  int the_size_of_int = 4;
  short the_size_of_double = 8;

  if (the_size_of_int == 4) 
    printf("int size = %li\n", sizeof(int));

  if (the_size_of_double == 8)
    printf("double size = %li\n", sizeof(double));
}

// -----------------------------------------------------------------------------
int how_many_in_array() {
  char array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  printf("size of char array = %li\n", sizeof(array));
  printf("char size = %li\n", sizeof(char));

  return sizeof(array) / sizeof(char);
}

// -----------------------------------------------------------------------------
void some_enum_stuff() {
  enum Color { RED, GREEN, BLUE };

  enum Color red = RED;
  printf("red = %i\n", red);

  enum Color green = RED;
  printf("green = %i\n", green);

  if (red != green)
    puts("Duh... red isn't green.");
  else
    puts("Wait, red should never be green!");
}

// -----------------------------------------------------------------------------
void what_struct() {
  struct Person {
    int age;
    char name[3];
  };

  struct Person michael = {.age = 28, .name = "Mi"};

  struct Person thomas;
  thomas.age = 14;
  //thomas.name = "Thomas";
  strcpy(thomas.name, "Th");

  printf("name = %s, age = %i\n", michael.name, michael.age);
  printf("name = %s, age = %i\n", thomas.name, thomas.age);

  printf("sizeof Person = %li\n", sizeof(struct Person));
}