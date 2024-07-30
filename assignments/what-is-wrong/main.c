#include <stdbool.h>
#include <stdio.h>

void characterTypes();
void integerTypes();
void floatingPointTypes();
void booleanType();
void voidType();
void pointerType();
void arrayType();
void enumType();
void structType();

int main(void) {
  puts("Welcome, we are going to do some data type tests along with some"
       " debugging.");
  puts("\tPlease make sure ALL warnings are gone.");
  puts("\tPlease answer any questions I have posed in comment blocks;"
       " simply enter your answer under my comment.");
  puts(
      "\tPlease be sure that every original printf() statement create output.");

  characterTypes();
  integerTypes();
  floatingPointTypes();
  booleanType();
  voidType();
  pointerType();
  arrayType();
  enumType();
  structType();

  return 0;
}

// -----------------------------------------------------------------------------
void characterTypes() {
  puts("\n----\nCharacter Types\n----");
  unsigned long charSize = 1;
  unsigned long unsignedCharSize = 1;
  unsigned long signedCharSize = 1;

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
void integerTypes() {
  puts("\n----\nInteger Types\n----");
  unsigned long shortSize = 2;
  unsigned long unsignedShortSize = 2;
  unsigned long signedShortSize = 2;
  unsigned long intSize = 4;
  unsigned long unsignedIntSize = 4;
  unsigned long signedIntSize = 4;
  unsigned long longSize = 8;
  unsigned long unsignedLongSize = 8;
  unsigned long signedLongSize = 8;
  unsigned long longLongSize = 8;
  unsigned long unsignedLongLongSize = 8;
  unsigned long signedLongLongSize = 8;
  unsigned long myIntSize = 4;

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
void floatingPointTypes() {
  puts("\n----\nFloating Point Types\n----");
  unsigned long floatSize = 4;
  unsigned long doubleSize = 8;

  puts("\t* 1");
  if (sizeof(float) == floatSize)
    printf("\t  sizeof(float) = %lu\n", sizeof(float));

  puts("\t* 2");
  if (sizeof(double) == doubleSize)
    printf("\t  sizeof(double) = %lu\n", sizeof(double));
}

// -----------------------------------------------------------------------------
void booleanType() {
  puts("\n----\nBoolean Type\n----");
  unsigned long booleanSize = 1;

  puts("\t* 1");
  if (sizeof(bool) == booleanSize)
    printf("\t  sizeof(bool) = %lu\n", sizeof(bool));
}

// -----------------------------------------------------------------------------
void voidType() {
  puts("\n----\nVoid Type\n----");
  unsigned long voidSize = 1;

  puts("\t* 1");
  if (sizeof(void) == voidSize)
    printf("\t  sizeof(void) = %lu\n", sizeof(void));
}

// -----------------------------------------------------------------------------
void pointerType() {
  puts("\n----\nPointer Type\n----");
  unsigned long intPointerSize = 8;
  unsigned long doublePointerSize = 8;
  unsigned long voidPointerSize = 8;

  /*
   * BONUS:
   * There is interesting behavior here. Do you have a best guess on why the
   * sizes are the way they are?
   *
   * The sizes are the same because a pointer holds a address, so it is a
   * special number size.
   */
  puts("\t* 1");
  if (sizeof(int *) == intPointerSize)
    printf("\t  sizeof(int*) = %lu\n", sizeof(int *));

  puts("\t* 2");
  if (sizeof(double *) == doublePointerSize)
    printf("\t  sizeof(double*) = %lu\n", sizeof(double *));

  puts("\t* 3");
  if (sizeof(void *) == voidPointerSize)
    printf("\t  sizeof(void*) = %lu\n", sizeof(void *));
}

// -----------------------------------------------------------------------------
void arrayType() {
  puts("\n----\nArray Type\n----");
  unsigned long char10ArraySize = 1 * 10;
  unsigned long int10ArraySize = 4 * 10;
  unsigned long int6ArraySize = 4 * 6;
  unsigned long double10ArraySize = 8 * 10;
  int arrayLength = 10;
  int whatIsMyCalculatedLength[10];

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
void enumType() {
  puts("\n----\nEnum Type\n----");
  unsigned long redEnumSize = 4;

  enum Color { RED, GREEN, BLUE };

  puts("\t* 1");
  if (sizeof(RED) == redEnumSize)
    printf("\t  sizeof(Color.Red) = %lu\n", sizeof(RED));

  /*
   * Why do you think the size is the size it is; what is enum's underlying
   * type?
   * Hint: printf()
   */
  printf("GREEN = %i\n", GREEN);
}

// -----------------------------------------------------------------------------
void structType() {
  puts("\n----\nDeveloper Designed Struct Type\n----");
  unsigned long personStructSize = 36;
  unsigned long colorStructSize = 8;

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
   *
   * There is data alignment padding. 2 extra bytes are used to make memory
   * access more efficient.
   */
  puts("\t* 2");
  if (sizeof(struct Person) == personStructSize)
    printf("\t  sizeof(struct Person) = %lu\n", sizeof(struct Person));
}
