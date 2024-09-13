#include <stdio.h>
#include <string.h>

// NEW sections from lesson 1.
void intro_to_arrays(void);
void calculate_array_length(void);
void enums(void);
void structs(void);
// New sections from lesson 3.
void strings();
void string_declarations();
void string_to_functions(char string[]);

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

// =============================================================================
//                             String Basics
// =============================================================================
void strings() {
  puts("\n\n============================================================");
  puts("\tString Basics");
  puts("============================================================\n");

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
