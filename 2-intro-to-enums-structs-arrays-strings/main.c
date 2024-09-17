#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 30

void intro_to_arrays(void);
void calculate_array_length(void);

enum Color { RED, GREEN, BLUE };
void enums(void);

struct Person {
  int age;
  char name[NAME_LEN];
};
void structs(void);

void strings(void);
void string_declarations(void);
void string_to_functions(char string[]);

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  puts("---------------------------------------------------------------------");
  puts("\t\tThis is the \"Whiteboard\" for today.");
  puts("---------------------------------------------------------------------"
       "\n");

  intro_to_arrays();
  calculate_array_length();

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
void intro_to_arrays() {
  puts("----------------------------------------------------");
  puts("\tIntroduction To Arrays.");
  puts("----------------------------------------------------");

  puts("Arrays are a simple data structure. A data structure is something\n"
       "that holds data in a defined organization. Later on in your education\n"
       "you will learn about many kinds of data structures, but arrays are\n"
       "the simplest and are built into C--and most languages. An array is a\n"
       "block of contiguously allocated memory. So, every item in the array\n"
       "is right next to the other and we can name this chunk of memory. This\n"
       "allows us to group items together. How though, do we define an\n"
       "array?\n");

  int array_a[3];

  puts("Here we have declared an int array called array_a with a length of\n"
       "3. The square brackets ([]) make this symbol an array. An array\n"
       "needs a defined length at compilation time, so inside these square\n"
       "brackets we give the length. The length of the array says how many\n"
       "items we can hold in that declared array. All we have declared though\n"
       "is the block of memory. We need to give this array some data. We can\n"
       "do this in a few ways. The first being declaring and initializing,\n"
       "and the second being assignment.\n");

  double array_b[] = {1.25, 2.12, 3.45};
  printf("array_b[%i] = %f", 0, array_b[0]);
  printf("array_b[%i] = %f", 1, array_b[1]);
  printf("array_b[%i] = %f", 2, array_b[2]);

  puts("Here we have declared and initialized a double array called array_b\n"
       "with 3 values; because we have declared and initialized we don't need\n"
       "to explicitely define the array size. This is because the compiler\n"
       "can infer the array length from the initialization. We could also\n"
       "give the array length as well explicitely.\n");

  int array_c[4] = {1, 2, 3};
  printf("array_c[%i] = %i", 0, array_c[0]);
  printf("array_c[%i] = %i", 1, array_c[1]);
  printf("array_c[%i] = %i", 2, array_c[2]);
  printf("array_c[%i] = %i", 3, array_c[3]);

  puts("You may notice that in this case we have a length that is larger than\n"
       "the initialization list. This is valid because C will assign\n"
       "zero-values to the uninitialized items; so, the last item will be a\n"
       "0. Let's now assign values to our first array using our second\n"
       "method.\n");

  array_a[0] = 1;
  array_a[1] = 2;
  array_a[2] = 3;
  printf("array_a[%i] = %i", 0, array_a[0]);
  printf("array_a[%i] = %i", 1, array_a[1]);
  printf("array_a[%i] = %i", 2, array_a[2]);

  puts("In this method we assign data to elements at a certain index in the\n"
       "array. Indexing the array is zero based: the first index is index 0,\n"
       "the second is at index 1, and the third is at index 2. It is\n"
       "imperative that you remember this. Many bugs can be caused by going\n"
       "outside of the bounds of the array or thinking indexing is 1 based.\n"
       "This syntax allows us to get the element at the index. Now, how do we\n"
       "talk about arrays in common language in relation to the index? We\n"
       "say, \"the element at index 0 is 1,\" or \"the item at index 0,\" and\n"
       "what-not.\n");
}

// -----------------------------------------------------------------------------
void calculate_array_length() {
  puts("----------------------------------------------------");
  puts("\tHow To Calculate Array Length.");
  puts("----------------------------------------------------");

  puts("It is possible, in certain instances, to calculate the length of a\n"
       "given array. Let's define an array, and output certain details.\n");

  int array[4];
  printf("sizeof(array) = %lu\n"
         "sizeof(int)   = %lu\n\n",
         sizeof(array), sizeof(int));

  puts("Here we see the size, in bytes, of the total size allocated for the\n"
       "array. We also see the total number of bytes needed to allocate an\n"
       "int variable. You may be able to see where I am going here. We can\n"
       "calculate the length of the array by dividing the total size of the\n"
       "array by the size of the type of thing it holds. Let's see that.\n");

  printf("array length = sizeof(array) / sizeof(array element type)\n"
         "%lu = %lu / %lu\n\n",
         sizeof(array) / sizeof(int), sizeof(array), sizeof(int));
}

// -----------------------------------------------------------------------------
void enums() {
  puts("----------------------------------------------------");
  puts("\tIntroduction To Enumerations.");
  puts("----------------------------------------------------");

  enum Color red = RED;
  printf("red = %i\n", red);

  enum Color green = RED;
  printf("green = %i\n", green);
}

// -----------------------------------------------------------------------------
void structs() {

  struct Person michael = {.age = 28, .name = "Michael"};

  struct Person thomas;
  thomas.age = 14;
  // thomas.name = "Thomas";
  strcpy(thomas.name, "Thomas");

  printf("name = %s, age = %i\n", michael.name, michael.age);
  printf("name = %s, age = %i\n", thomas.name, thomas.age);

  printf("sizeof Person = %li\n", sizeof(struct Person));
}

// -----------------------------------------------------------------------------
void strings() {
  puts("------------------------------------------------------------");
  puts("\tIntroduction To Strings.");
  puts("------------------------------------------------------------\n");

  puts("Finally, we'll go over some string basics. Strings in 'C' are\n"
       "character arrays. Because they are arrays, they have a fixed size at\n"
       "declaration. If you accidentally iterate over that size, or try to\n"
       "put a string that is bigger than the declared size, you will have\n"
       "undefined behavior.");

  string_declarations();
  char string[] = "Foo bar";
  string_to_functions(string);
}

// -----------------------------------------------------------------------------
void string_declarations() {
  puts("----------------------------------------------------");
  puts("\tDeclaring String Variables");
  puts("----------------------------------------------------");

  puts("Strings are a special kind of array. They are a character array with\n"
       "a null-terminator character. It is not printable, so you won't see\n"
       "it, but it's there. This null-terminator allows 'C', and you, to stop\n"
       "at the end of the string. Let's see one way we can initialize a\n"
       "string.\n");

  char s[14] = {'H', 'e', 'l', 'l', 'o', ',', ' ',
                'W', 'o', 'r', 'l', 'd', '!', '\0'};
  printf("s = %s\n", s);

  puts("\nAs you can see, printf() stops when the null-terminator is reached.\n"
       "We can as well.\n");

  for (int i = 0; s[i] != '\0'; i++) {
    printf("%c", s[i]);
  }
  printf("\n");

  puts("\nMost of the time though, we iterate over a string with the length.\n"
       "We can get the length in a few ways. We know it when we declare a\n"
       "string but when getting input there is not guarantee that the whole\n"
       "array has been used by text. So, we can also use the strlen()\n"
       "function from string.h library.\n");

  const int len = strlen(s);
  printf("len = %i\n", len);

  puts("\nThe strlen() function does not include the null-terminator\n"
       "character for iteration. You do NOT want to put the strlen() function\n"
       "call in a \"for\" declaration because each iteration will\n"
       "re-calculate the length of the string. Since the strlen() basically\n"
       "just iterates over a string and counts until it reaches the\n"
       "null-terminator, you actually end up iterating the array a bunch of\n"
       "times! This is terrible for performance, so get the length of a\n"
       "string before you enter a loop.\n");
  puts("The most common way to create a string is with a string literal. We\n"
       "don't need to include the char array size when doing it like this\n"
       "(or even the way before but no one does it like that) because the\n"
       "compiler can easily figure it out.\n");

  char s2[] = "Foo";
  printf("%s\n", s2);

  puts("\nDeclaring and initializing in this way is far more common. The\n"
       "null-terminator character is automatically added using this method,\n"
       "which is nice. Really, all of these puts() and format strings for\n"
       "printf() are string literals. The only difference is they are not\n"
       "assigned to a variable.");
  char text[] =
      "\nReally, I can also write like this and then give it to puts().";
  puts(text);

  char format_string[] = "\nI can even do this! My favorite number is %i.\n";
  printf(format_string, 50);

  puts("\nStrings can also just be defined and then filled in later.");

  char string[10];
  char c = 'a';
  for (int i = 0; i < 10; i++, c++) {
    if (i == 10 - 1) {
      string[i] = '\0';
      continue;
    }
    string[i] = c;
  }
  printf("\n%s\n", string);

  puts("\nIf we don't add the null-terminator at the end of the string, there\n"
       "is no guarantee that garbage won't be printed from standard library\n"
       "functions; we'll go over why that is when we talk about arrays in\n"
       "general next week.");
}

// -----------------------------------------------------------------------------
void string_to_functions(char string[]) {
  puts("----------------------------------------------------");
  puts("\tPassing String Variables to Functions");
  puts("----------------------------------------------------");

  puts("We're going to do some very basic string passing to functions.\n");
  printf("\tLet's simply print string: %s\n", string);

  puts("\nAnd now, lets do a simpe loop.\n");
  for (int i = 0; string[i] != '\0'; i++)
    printf("%c", string[i]);

  puts("\n\nThat is it for now, we'll talk much more about arrays and strings\n"
       "another time.");
}
