#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 30

void arrays(void);
void intro_to_arrays(void);
void calculate_array_length(void);

void strings(void);
void string_declarations(void);
void string_to_functions(char string[]);
const char *returning_string_literals(void);

typedef enum { RED, GREEN, BLUE } color;

void enums(void);

typedef struct {
  int age;
  char name[NAME_LEN];
} person;

typedef struct {
  int x;
  int y;
} point;

void structs(void);

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  puts("---------------------------------------------------------------------");
  puts("\t\tThis is the \"Whiteboard\" for today.");
  puts("---------------------------------------------------------------------"
       "\n");

  arrays();
  strings();
  enums();
  structs();

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
void arrays() {
  intro_to_arrays();
  calculate_array_length();
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
  printf("array_b[%i] = %f\n", 0, array_b[0]);
  printf("array_b[%i] = %f\n", 1, array_b[1]);
  printf("array_b[%i] = %f\n\n", 2, array_b[2]);

  puts("Here we have declared and initialized a double array called array_b\n"
       "with 3 values; because we have declared and initialized we don't need\n"
       "to explicitely define the array size. This is because the compiler\n"
       "can infer the array length from the initialization. We could also\n"
       "give the array length as well explicitely.\n");

  int array_c[4] = {1, 2, 3};
  printf("array_c[%i] = %i\n", 0, array_c[0]);
  printf("array_c[%i] = %i\n", 1, array_c[1]);
  printf("array_c[%i] = %i\n", 2, array_c[2]);
  printf("array_c[%i] = %i\n\n", 3, array_c[3]);

  puts("You may notice that in this case we have a length that is larger than\n"
       "the initialization list. This is valid because C will assign\n"
       "zero-values to the uninitialized items; so, the last item will be a\n"
       "0. Let's now assign values to our first array using our second\n"
       "method.\n");

  array_a[0] = 1;
  array_a[1] = 2;
  array_a[2] = 3;
  printf("array_a[%i] = %i\n", 0, array_a[0]);
  printf("array_a[%i] = %i\n", 1, array_a[1]);
  printf("array_a[%i] = %i\n\n", 2, array_a[2]);

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
void strings() {
  puts("------------------------------------------------------------");
  puts("\tIntroduction To Strings.");
  puts("------------------------------------------------------------\n");

  puts("Finally, we'll go over some string basics. Strings in 'C' are\n"
       "character arrays. Because they are arrays, they have a fixed size at\n"
       "declaration. If you accidentally iterate over that size, or try to\n"
       "put a string that is bigger than the declared size, you will have\n"
       "undefined behavior.\n");

  string_declarations();
  char string[] = "Foo bar";
  string_to_functions(string);
  const char *returned_string = returning_string_literals();
  printf("Here is our returned string literal:\n\n"
         "\t%s\n\n",
         returned_string);
}

// -----------------------------------------------------------------------------
void string_declarations() {
  puts("----------------------------------------------------");
  puts("\tDeclaring String Variables.");
  puts("----------------------------------------------------");

  puts("Strings are a special kind of array. They are a character array with\n"
       "a null-terminator character. It is not printable, so you won't see\n"
       "it, but it's there. This null-terminator allows 'C', and you, to stop\n"
       "at the end of the string. Let's see one way we can initialize a\n"
       "string.\n");

  char s[14] = {'H', 'e', 'l', 'l', 'o', ',', ' ',
                'W', 'o', 'r', 'l', 'd', '!', '\0'};
  printf("s = %s\n\n", s);

  puts("As you can see, printf() stops when the null-terminator is reached.\n"
       "Most of the time though, we iterate over a string with the length.\n"
       "We can get the length in a few ways. We know it when we declare a\n"
       "string but when getting input there is not guarantee that the whole\n"
       "array has been used by text. So, we can also use the strlen()\n"
       "function from string.h library.\n");

  const int len = strlen(s);
  printf("len = %i\n\n", len);

  puts("The strlen() function does not include the null-terminator character\n"
       "length calculation. You do NOT want to put the strlen() function call\n"
       "in a loop because each iteration will re-calculate the length of the\n"
       "string. Since the strlen() basically just iterates over a string and\n"
       "counts until it reaches the null-terminator, you actually end up\n"
       "iterating the array a bunch of times! This is terrible for\n"
       "performance, so get the length of a string before you enter a loop.\n");
  puts("The most common way to create a string is with a string literal. We\n"
       "don't need to include the char array size when doing it like this\n"
       "(or even the way before but no one does it like that) because the\n"
       "compiler can easily figure it out.\n");

  char s2[] = "Foo";
  printf("%s\n\n", s2);

  puts("Declaring and initializing in this way is far more common. The\n"
       "null-terminator character is automatically added using this method,\n"
       "which is nice. Really, all of these puts() and format strings for\n"
       "printf() are string literals. The only difference is they are not\n"
       "assigned to a variable.\n");

  char text[] =
      "Really, I can also write like this and then give it to puts().\n";
  puts(text);
  char format_string[] = "I can even do this! My favorite number is %i.\n\n";
  printf(format_string, 50);

  puts("Strings can also just be defined and then filled in later.\n");

  char string[4];
  char c = 'a';
  string[0] = c;
  string[1] = c;
  string[2] = c;
  string[3] = '\0';
  printf("%s\n\n", string);

  puts("If we don't add the null-terminator at the end of the string, there\n"
       "is no guarantee that garbage won't be printed from standard library\n"
       "functions; we'll go over why that is when we talk about arrays in\n"
       "a greater degree a couple lessons from now.\n");
}

// -----------------------------------------------------------------------------
void string_to_functions(char string[]) {
  puts("----------------------------------------------------");
  puts("\tPassing String Variables to Functions.");
  puts("----------------------------------------------------");

  puts("We're going to do some very basic string passing to functions.\n");
  printf("\tLet's simply print string: %s\n\n", string);

  puts("That is it for now, we'll talk much more about arrays and strings\n"
       "another time.\n");
}

// -----------------------------------------------------------------------------
const char *returning_string_literals() {
  puts("----------------------------------------------------");
  puts("\tReturning String Literals.");
  puts("----------------------------------------------------");

  puts("Returning strings--and arrays in general--is a bit of a complicated\n"
       "topic. It's not exactly possible to return a string variable--we will\n"
       "go over why in a few classes from now--but we can return a string\n"
       "literal. We can do this because string literals live for the life of\n"
       "the program. A string variable is different. We'll get to it. Let's\n"
       "return a string literal now.\n");

  return "I am a returned string!";
}

// -----------------------------------------------------------------------------
void enums() {
  puts("----------------------------------------------------");
  puts("\tIntroduction To Enumerations.");
  puts("----------------------------------------------------");

  puts("We now start getting into making our own types. An enumeration is a\n"
       "way to define named constant symbols that are grouped together by a\n"
       "common idea. Let's go over this with an example. At the top of this\n"
       "file I have used the typedef keyword which says that we are defining\n"
       "a new type--we can use the typedef keyword on other types as well to\n"
       "create aliases to other types like, \"typedef int my_int\"--we then\n"
       "say we are defining an enum with the enum keyword; after that we\n"
       "define enumeration values; and finally give this enumeration a name.\n"
       "Now, how then do we use this enum? Like any other type really, with\n"
       "one caveat: we can only assign the values that we have defined as a\n"
       "part the enum to a variable of our enum type. Let's see this in\n"
       "practice.\n");

  color red = RED;

  puts("Look at that! Pretty neat right! We can make grouped symbols with\n"
       "symbolic values. Now, why would we do this? For one, we can make\n"
       "certain limited symbols valid for ourselves and other developers to\n"
       "use: everyone knows the values because we have defined the values!\n"
       "This is particularly useful for error codes. We could have an enum\n"
       "defined for error codes and return that enumeration type from a\n"
       "validation function so that we can get specific errors without having\n"
       "to memorize error code integers.\n");
  puts("How though, are enumerations stored in memory? They need to be\n"
       "something. Let's output our enumeration.\n");

  printf("red = %i\n", red);
  color green = GREEN;
  printf("green = %i\n\n", green);

  puts("Wow, look at that, 2 integers that have gone up incrementally.\n"
       "Enumerations are just integers. How does C decide what integer to\n"
       "make a symbol? It is done in order. The first one is 0, the second is\n"
       "1, etc.\n");
}

// -----------------------------------------------------------------------------
void structs() {
  puts("----------------------------------------------------");
  puts("\tIntroduction To Structures.");
  puts("----------------------------------------------------");

  puts("Structures allow us to define complex types in C. This allows us to\n"
       "define data that should be grouped together to represent something in\n"
       "our code. Structures are an incredibly powerful tool for the\n"
       "developer to utilize. Let's go over structures with an example. I\n"
       "have defined a structure at the top of this file. First, we use the\n"
       "typedef keyword; after that the struct keyword is used to signify a\n"
       "struct definition is coming; then the curly brackets are used to hold\n"
       "the declarations of the data members that are a part of this struct.\n"
       "These data members are given a type and a name: each member goes on\n"
       "its own line and is ended with a semicolon. After the curly brackets\n"
       "goes the name of the struct itself. Now, how do we use our defined\n"
       "struct? Let's see the syntax below.\n");

  person michael = {.age = 28, .name = "Michael"};
  printf("name = %s, age = %i\n\n", michael.name, michael.age);

  puts("I have declared a variable of type person with a variable name of\n"
       "michael. I have then initialized the variable at the same time: the\n"
       "syntax to do this is with the curly brackets. Each data member in the\n"
       "defined struct must be given a value, so we give it one. We do this\n"
       "by using the \"dot operator\" before the name of the data member and\n"
       "then assign a value to that data member: each data member is\n"
       "separated with a comma. We could optionally not include the data\n"
       "member names in the declaration, but the value need to exactly match\n"
       "the struct definition order. If there are 2 integers defined next to\n"
       "each other, it gets confusing. I think it is a bad practice, so I\n"
       "will enforce the way I have shown above. Now, how do we use the data\n"
       "in the struct? We use the variable name, and then access each member\n"
       "using the dot operator like how we've done in the call to printf().\n"
       "How, though, do we assign values to a struct's members after we have\n"
       "already declared it. This can be problematic depending on the kinds\n"
       "of data in the struct. Let's try this with our struct.\n");

  person thomas;
  thomas.age = 14;
  // This line creates an error.
  // thomas.name = "Thomas";
  strcpy(thomas.name, "Thomas");
  printf("name = %s, age = %i\n\n", thomas.name, thomas.age);

  puts("Here we see that we can assign to the age member just fine after\n"
       "declaration, but we can't simply assign to the name member\n"
       "afterwords: why is that? Strings--and arrays in general--are special.\n"
       "Arrays can't be assigned to in bulk after declaration like primitive\n"
       "types. This is because after declaration they are initialized to\n"
       "something; either what we say or what C says. If we don't say, then C\n"
       "initializes \"zero values\" to the members of the array: for integers\n"
       "that is 0, for floating point (decimal) numbers it is 0.0, and for\n"
       "strings it is a bunch of null-terminator characters. So, to change\n"
       "those characters later we have to assign to the elements in that\n"
       "string one at a time. We can do this ourselves, or use functions\n"
       "provided to us in the standard library. In the above example I opt to\n"
       "call strcpy() from the string.h library because we haven't gone over\n"
       "loops. We provide a string to this function and now we have\n"
       "\"assigned\" to our name string.\n");

  const size_t size_int = sizeof(int);
  const size_t size_char = sizeof(char);
  const size_t size_name_len_char = sizeof(char[NAME_LEN]);
  printf(
      "We will now go over something that is moderately important about\n"
      "structs that you should be aware of: how C sizes them. Depending on\n"
      "the data member types and how many data members there, the size of a\n"
      "defined struct will change. Let's see if we can figure out the size\n"
      "of our person struct. Here are the sizes of it's data members:\n\n"
      "\tsizeof(int)      = %lu\n"
      "\tsizeof(char)     = %lu\n"
      "\tsizeof(char[%i]) = %lu\n\n"
      "Knowing these values, and knowing that we have an int and a char array\n"
      "with a length of %i as a part of our person struct we can calculate\n"
      "the size of our person struct to be:\n\n"
      "\t%lu + %lu = %lu.\n\n"
      "Let's see if we are correct:\n\n"
      "\tsizeof(person) = %lu\n\n"
      "Woa! We aren't correct? The math is so simple, what could possibly be\n"
      "wrong? Well, something special is happening when it comes to structure\n"
      "sizing.\n\n",
      size_int, size_char, NAME_LEN, size_name_len_char, NAME_LEN, size_int,
      size_name_len_char, size_int + size_name_len_char, sizeof(person));

  puts("The size of a structure is determined not just by the data member\n"
       "types, but also by padding. Depending on the data member types, C may\n"
       "insert padding between the data members in memory. What does this\n"
       "\"look\" like in memory? Here is a way it can be shown.\n");
  puts("\t|  age  | 0x0\n"
       "\t|  age  | 0x1\n"
       "\t|  age  | 0x2\n"
       "\t|  age  | 0x3\n"
       "\t|  name | 0x4\n"
       "\t|  name | 0x5\n"
       "\t|  ...  | ...\n"
       "\t|  name | 0x34\n"
       "\t|  pad  | 0x35\n"
       "\t|  pad  | 0x36\n");
  puts("An int in most 64-bit systems require 4-byte (32 bits) alignment (not\n"
       "8 bytes or 64 bits). This is because an int is a 32-bit type, and\n"
       "aligning it to 4-byte boundaries provides optimal performance.\n"
       "Therefore, when placing an int in memory, the compiler ensures it\n"
       "starts at an address that is a multiple of 4. A char data type\n"
       "requires no alignment because it is just 1 byte. However, when you\n"
       "have an array like char name[30], the array itself doesn’t require\n"
       "alignment, but padding may be added at the end of the structure to\n"
       "ensure overall alignment. The largest alignment requirement in the\n"
       "person struct is that of the int (4 bytes). After placing int and the\n"
       "30 bytes of the char array, the total size of the structure is 34n\n"
       "bytes. This is not a multiple of 4, so 2 padding bytes are added at\n"
       "the end to round the structure's size to a multiple of 4, making it\n"
       "36 bytes in total.\n");
  printf("Now that we have seen a structure with padding, let's see a\n"
         "structure without any padding:\n\n"
         "\tsizeof(int)   = %lu\n"
         "\tsizeof(point) = %lu\n\n"
         "\t| x | 0x0\n"
         "\t| x | 0x1\n"
         "\t| x | 0x2\n"
         "\t| x | 0x3\n"
         "\t| y | 0x4\n"
         "\t| y | 0x5\n"
         "\t| y | 0x6\n"
         "\t| y | 0x7\n\n"
         "As you can see, we don't have any padding. The point struct\n"
         "contains 2 ints, so it only needs 8 bytes. We then don't need any\n"
         "padding for alignment because 8 is a multiple of 4.\n\n",
         sizeof(int), sizeof(point));
}
