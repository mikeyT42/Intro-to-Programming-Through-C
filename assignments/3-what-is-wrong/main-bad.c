//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>

void integer_types();
void floating_point_types();
void boolean_type();
void void_type(int i);
void pointer_type();
array_type();
void enum_type();
int struct_type();

int main(void) {
  system("clear");
  puts("---------------------------------------------------------------------");
  puts("\t\t\tWelcome");
  puts("---------------------------------------------------------------------"
       "\n");

  puts("Welcome, we are going to do some data type tests along with some"
       " debugging.");
  puts("\tPlease make sure ALL warnings are gone.");
  puts("\tPlease answer any questions I have posed in comment blocks;"
       " simply enter your answer under my comment.");
  puts(
      "\tPlease be sure that every original printf() statement create output.");

  character_types();
  integer_types();
  floating_point_types();
  boolean_type();
  void_type();
  pointer_type();
  array_type();
  enum_type();
  struct_type();

  puts("---------------------------------------------------------------------");
  puts("\t\t\tThank you.");
  puts("---------------------------------------------------------------------"
       "\n");

  return exit_success;
}

// -----------------------------------------------------------------------------
void character_types() {
  puts("\n----\nCharacter Types\n----");
  unsigned long char_size;
  unsigned long unsigned_char_size;
  unsigned long signed_char_size;

  puts("\t* 1");
  if (sizeof(char) == char_size)
    printf("\t  sizeof(char) = %i\n", (int)sizeof(char));

  puts("\t* 2");
  if (sizeof(unsigned char) == unsigned_char_size)
    printf("\t  sizeof(unsigned char) = %i\n", (int)sizeof(unsigned char));

  puts("\t* 3");
  if (sizeof(signed char) == signed_char_size)
    printf("\t  sizeof(signed char) = %i\n", (int)sizeof(signed char));
}

// -----------------------------------------------------------------------------
void integer_types() {
  puts("\n----\nInteger Types\n----");
  unsigned long short_size;
  unsigned long unsigned_short_size;
  unsigned long signed_short_size;
  unsigned long int_size;
  unsigned long unsigned_int_size;
  unsigned long signed_int_size;
  unsigned long long_size;
  unsigned long unsigned_long_size;
  unsigned long signed_long_size;
  unsigned long long_long_size;
  unsigned long unsigned_long_long_size;
  unsigned long signed_long_long_size;
  unsigned long my_int_size;

  typedef int my_int;

  puts("\t* 1");
  if (sizeof(short) == short_size)
    printf("\t  sizeof(short) = %lu\n", sizeof(short));

  puts("\t* 2");
  if (sizeof(unsigned short) == unsigned_short_size)
    printf("\t  sizeof(unsigned short) = %lu\n", sizeof(unsigned short));

  puts("\t* 3");
  if (sizeof(signed short) == signed_short_size)
    printf("\t  sizeof(signed short) = %lu\n", sizeof(signed short));

  puts("\t* 4");
  if (sizeof(int) == int_size)
    printf("\t  sizeof(int) = %lu\n", sizeof(int));

  puts("\t* 5");
  if (sizeof(unsigned int) == unsigned_int_size)
    printf("\t  sizeof(unsigned int) = %lu\n", sizeof(unsigned int));

  puts("\t* 6");
  if (sizeof(signed int) == signed_int_size)
    printf("\t  sizeof(signed int) = %lu\n", sizeof(signed int));

  puts("\t* 7");
  if (sizeof(long) == long_size)
    printf("\t  sizeof(long) = %lu\n", sizeof(long));

  puts("\t* 8");
  if (sizeof(unsigned long) == unsigned_long_size)
    printf("\t  sizeof(unsigned long) = %lu\n", sizeof(unsigned long));

  puts("\t* 9");
  if (sizeof(signed long) == signed_long_size)
    printf("\t  sizeof(signed long) = %lu\n", sizeof(signed long));

  puts("\t* 10");
  if (sizeof(long long) == long_long_size)
    printf("\t  sizeof(long long) = %lu\n", sizeof(long long));

  puts("\t* 11");
  if (sizeof(unsigned long long) == unsigned_long_long_size)
    printf("\t  sizeof(unsigned long long) = %lu\n",
           sizeof(unsigned long long));

  puts("\t* 12");
  if (sizeof(signed long long) == signed_long_long_size)
    printf("\t  sizeof(signed long long) = %lu\n", sizeof(signed long long));

  /*
   * What size does my_int match with? Why does my_int match the size of that
   * data type? I am looking for a vocabulary word here.
   * Hint: look at how my_int is defined.
   */
  puts("\t* 13");
  if (sizeof(my_int) == my_int_size)
    printf("\t  sizeof(my_int) = %lu\n", sizeof(my_int));
}

// -----------------------------------------------------------------------------
void floating_point_types() {
  puts("\n----\nFloating Point Types\n----");
  unsigned long float_size;
  unsigned long double_size;

  puts("\t* 1");
  if (sizeof(float) == float_size)
    printf("\t  sizeof(float) = %lu\n", sizeof(float));

  puts("\t* 2");
  if (sizeof(double) == double_size)
    printf("\t  sizeof(double) = %lu\n", sizeof(double));
}

// -----------------------------------------------------------------------------
void boolean_type() {
  puts("\n----\nBoolean Type\n----");
  unsigned long boolean_size;

  puts("\t* 1");
  if (sizeof(bool) == boolean_size)
    printf("\t  sizeof(bool) = %lu\n", sizeof(bool));
}

// -----------------------------------------------------------------------------
void void_type() {
  puts("\n----\nVoid Type\n----");
  unsigned long void_size;

  puts("\t* 1");
  if (sizeof(void) == void_size)
    printf("\t  sizeof(void) = %lu\n", sizeof(void));
}

// -----------------------------------------------------------------------------
void pointer_type() {
  puts("\n----\nPointer Type\n----");
  unsigned long int_pointer_size;
  unsigned long double_pointer_size;
  unsigned long void_pointer_size;

  /*
   * BONUS:
   * There is interesting behavior here. Do you have a best guess on why the
   * sizes are all the same?
   */
  puts("\t* 1");
  if (sizeof(int *) == int_pointer_size)
    printf("\t  sizeof(int*) = %lu\n", sizeof(int *));

  puts("\t* 2");
  if (sizeof(double *) == double_pointer_size)
    printf("\t  sizeof(double*) = %i\n", sizeof(double *));

  puts("\t* 3");
  if (sizeof(void *) == void_pointer_size)
    printf("\t  sizeof(void*) = %lu\n", sizeof(void *));
}

// -----------------------------------------------------------------------------
void array_type() {
  puts("\n----\nArray Type\n----");
  unsigned long char10_array_size = 1 * ;
  unsigned long int10_array_size = * 10;
  unsigned long int6_array_size;
  unsigned long double10_array_size;
  int array_length;
  int what_is_my_calculated_length[10];// Doesn't need to be initialized for our
                                       // purposes.

  puts("\t* 1");
  if (sizeof(char[10]) == char10_array_size)
    printf("\t  sizeof(char[10]) = %lu\n", sizeof(char[10]));

  puts("\t* 2");
  if (sizeof(int[10]) == int10_array_size)
    printf("\t  sizeof(int[10]) = %lu\n", sizeof(int[10]));

  puts("\t* 3");
  if (sizeof(int[6]) == int6_array_size)
    printf("\t  sizeof(int[6]) = %lu\n", sizeof(int[6]));

  puts("\t* 4");
  if (sizeof(double[10]) == double10_array_size)
    printf("\t  sizeof(double[10]) = %lu\n", sizeof(double[10]));

  puts("\t* 5");
  if ((sizeof(what_is_my_calculated_length) / sizeof(int)) == array_Length)
    printf("\t  length of what_is_my_calculated_length = %lu\n",
           sizeof(what_is_my_calculated_length) / sizeof(int));
}

// -----------------------------------------------------------------------------
void enum_type() {
  puts("\n----\nEnum Type\n----");
  unsigned long red_enum_size;

  enum color { RED, GREEN, BLUE };

  puts("\t* 1");
  if (sizeof(RED) == red_enum_size)
    printf("\t  sizeof(color.Red) = %lu\n", sizeof(RED));

  /*
   * Why do you think the size is the size it is; what is enum's underlying
   * type?
   * Hint: printf()
   */
}

// -----------------------------------------------------------------------------
void struct_type() {
  puts("\n----\nDeveloper Designed Struct Type\n----");
  unsigned long person_struct_size = 34;
  unsigned long color_struct_size;

  struct color {
    int rgb;
    int alpha;
  };

  puts("\t* 1");
  if (sizeof(struct color) == color_struct_size)
    printf("\t  sizeof(struct color) = %lu\n", sizeof(struct color));

  struct person {
    int age;
    char name[30];
  };

  /*
   * Why is there a bug here? Why is the size not as expected? Give an
   * explanation as to why in as much detail as you can: I am looking for a
   * particular vocab word here.
   * Hint: double check lesson 2.
   */
  puts("\t* 2");
  if (sizeof(struct person) == person_struct_size)
    printf("\t  sizeof(struct person) = %lu\n", sizeof(struct person));
}
