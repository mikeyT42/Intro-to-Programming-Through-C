#include <stdio.h>
#include <stdlib.h>

void echo(int my_int);
int return_my_int(int my_int);
char i_am_a(void);
int add(int x, int y);

int main(void) {
  puts("I am in main.");
  echo(10);
  puts("I am in main.");
  echo(2);
  puts("I am in main.");
  int my_int_is_ten = 10;
  my_int_is_ten = return_my_int(my_int_is_ten);
  printf("i_am_a returned %c.\n", i_am_a());

  int z = add(9, 10);
  printf("z = %d\n", z);

  int e = 20;
  int o = 30;
  z = add(e, o);
  printf("z = %d\n", z);

  return EXIT_SUCCESS;
}

void echo(int my_int) {
  puts("I am echo.");
  printf("%d\n", my_int);
}

int return_my_int(int my_int) {
    return my_int;
}

char i_am_a() {
   return 'b'; 
}

int add(int x, int y) {
   printf("x = %d\n", x);
   printf("y = %d\n", y);
   printf("x + y = %d\n", x + y);
   return x + y;
}
