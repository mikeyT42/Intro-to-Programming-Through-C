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

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
void character_types() {
  puts("\n----\nCharacter Types\n----");
  unsigned long charSize;
  unsigned long unsignedCharSize;
  unsigned long signedCharSize;

  puts("\t* 1");
  if (sizeof(char) == charSize)
    printf("\t  sizeof(char) = %i\n", (int)sizeof(char));

  puts("\t* 2");
  if (sizeof(unsigned char) == unsignedCharSize)
    printf("\t  sizeof(unsigned char) = %i\n", (int)sizeof(unsigned char));

  puts("\t* 3");
  if (sizeof(signed char) == signedCharSize)
    printf("\t  sizeof(signed char) = %i\n", (int)sizeof(signed char));
}

// -----------------------------------------------------------------------------
void integer_types() {
  puts("\n----\nInteger Types\n----");
  unsigned long shortSize;
  unsigned long unsignedShortSize;
  unsigned long signedShortSize;
  unsigned long intSize;
  unsigned long unsignedIntSize;
  unsigned long signedIntSize;
  unsigned long longSize;
  unsigned long unsignedLongSize;
  unsigned long signedLongSize;
  unsigned long longLongSize;
  unsigned long unsignedLongLongSize;
  unsigned long signedLongLongSize;
  unsigned long myIntSize;

  typedef int MyInt;

  puts("\t* 1");
  if (sizeof(short) == shortSize)
    printf("\t  sizeof(short) = %lu\n", sizeof(short));

  puts("\t* 2");
  if (sizeof(unsigned short) == unsignedShortSize)
    printf("\t  sizeof(unsigned short) = %lu\n", sizeof(unsigned short));

  puts("\t* 3");
  if (sizeof(signed short) == signedShortSize)
    printf("\t  sizeof(signed short) = %lu\n", sizeof(signed short));

  puts("\t* 4");
  if (sizeof(int) == intSize)
    printf("\t  sizeof(int) = %lu\n", sizeof(int));

  puts("\t* 5");
  if (sizeof(unsigned int) == unsignedIntSize)
    printf("\t  sizeof(unsigned int) = %lu\n", sizeof(unsigned int));

  puts("\t* 6");
  if (sizeof(signed int) == signedIntSize)
    printf("\t  sizeof(signed int) = %lu\n", sizeof(signed int));

  puts("\t* 7");
  if (sizeof(long) == longSize)
    printf("\t  sizeof(long) = %lu\n", sizeof(long));

  puts("\t* 8");
  if (sizeof(unsigned long) == unsignedLongSize)
    printf("\t  sizeof(unsigned long) = %lu\n", sizeof(unsigned long));

  puts("\t* 9");
  if (sizeof(signed long) == signedLongSize)
    printf("\t  sizeof(signed long) = %lu\n", sizeof(signed long));

  puts("\t* 10");
  if (sizeof(long long) == longLongSize)
    printf("\t  sizeof(long long) = %lu\n", sizeof(long long));

  puts("\t* 11");
  if (sizeof(unsigned long long) == unsignedLongLongSize)
    printf("\t  sizeof(unsigned long long) = %lu\n",
           sizeof(unsigned long long));

  puts("\t* 12");
  if (sizeof(signed long long) == signedLongLongSize)
    printf("\t  sizeof(signed long long) = %lu\n", sizeof(signed long long));

  /*
   * Why is the size the way it is?
   */
  puts("\t* 13");
  if (sizeof(MyInt) == myIntSize)
    printf("\t  sizeof(MyInt) = %lu\n", sizeof(MyInt));
}

// -----------------------------------------------------------------------------
void floating_point_types() {
  puts("\n----\nFloating Point Types\n----");
  unsigned long floatSize;
  unsigned long doubleSize;

  puts("\t* 1");
  if (sizeof(float) == floatSize)
    printf("\t  sizeof(float) = %lu\n", sizeof(float));

  puts("\t* 2");
  if (sizeof(double) == doubleSize)
    printf("\t  sizeof(double) = %lu\n", sizeof(double));
}

// -----------------------------------------------------------------------------
void boolean_type() {
  puts("\n----\nBoolean Type\n----");
  unsigned long booleanSize;

  puts("\t* 1");
  if (sizeof(bool) == booleanSize)
    printf("\t  sizeof(bool) = %lu\n", sizeof(bool));
}

// -----------------------------------------------------------------------------
void void_type() {
  puts("\n----\nVoid Type\n----");
  unsigned long voidSize;

  puts("\t* 1");
  if (sizeof(void) == voidSize)
    printf("\t  sizeof(void) = %lu\n", sizeof(void));
}

// -----------------------------------------------------------------------------
void pointer_type() {
  puts("\n----\nPointer Type\n----");
  unsigned long intPointerSize;
  unsigned long doublePointerSize;
  unsigned long voidPointerSize;

  /*
   * BONUS:
   * There is interesting behavior here. Do you have a best guess on why the
   * sizes are the way they are?
   */
  puts("\t* 1");
  if (sizeof(int *) == intPointerSize)
    printf("\t  sizeof(int*) = %lu\n", sizeof(int *));

  puts("\t* 2");
  if (sizeof(double *) == doublePointerSize)
    printf("\t  sizeof(double*) = %i\n", sizeof(double *));

  puts("\t* 3");
  if (sizeof(void *) == voidPointerSize)
    printf("\t  sizeof(void*) = %lu\n", sizeof(void *));
}

// -----------------------------------------------------------------------------
void array_type() {
  puts("\n----\nArray Type\n----");
  unsigned long char10ArraySize = 1 * ;
  unsigned long int10ArraySize = * 10;
  unsigned long int6ArraySize;
  unsigned long double10ArraySize;
  int arrayLength0;
  int whatIsMyCalculatedLength[10]; // Doesn't need to be initialized for our
                                    // purposes.

  puts("\t* 1");
  if (sizeof(char[10]) == char10ArraySize)
    printf("\t  sizeof(char[10]) = %lu\n", sizeof(char[10]));

  puts("\t* 2");
  if (sizeof(int[10]) == int10ArraySize)
    printf("\t  sizeof(int[10]) = %lu\n", sizeof(int[10]));

  puts("\t* 3");
  if (sizeof(int[6]) == int6ArraySize)
    printf("\t  sizeof(int[6]) = %lu\n", sizeof(int[6]));

  puts("\t* 4");
  if (sizeof(double[10]) == double10ArraySize)
    printf("\t  sizeof(double[10]) = %lu\n", sizeof(double[10]));

  puts("\t* 5");
  if ((sizeof(whatIsMyCalculatedLength) / sizeof(int)) == arrayLength)
    printf("\t  length of whatIsMyCalculatedLength = %lu\n",
           sizeof(whatIsMyCalculatedLength) / sizeof(int));
}

// -----------------------------------------------------------------------------
void enum_type() {
  puts("\n----\nEnum Type\n----");
  unsigned long redEnumSize;

  enum Color { RED, GREEN, BLUE };

  puts("\t* 1");
  if (sizeof(RED) == redEnumSize)
    printf("\t  sizeof(Color.Red) = %lu\n", sizeof(RED));

  /*
   * Why do you think the size is the size it is; what is enum's underlying
   * type?
   * Hint: printf()
   */
}

// -----------------------------------------------------------------------------
void struct_type() {
  puts("\n----\nDeveloper Designed Struct Type\n----");
  unsigned long personStructSize = 34;
  unsigned long colorStructSize;

  struct Color {
    int rgb;
    int alpha;
  };

  puts("\t* 1");
  if (sizeof(struct Color) == colorStructSize)
    printf("\t  sizeof(struct Color) = %lu\n", sizeof(struct Color));

  struct Person {
    int age;
    char name[30];
  };

  /*
   * Why is there a bug here? Why is the size not correct? Give an explanation
   * as to why in as much detail as you can: I am looking for a particular
   * vocab word here.
   */
  puts("\t* 2");
  if (sizeof(struct Person) == personStructSize)
    printf("\t  sizeof(struct Person) = %lu\n", sizeof(struct Person));
}
