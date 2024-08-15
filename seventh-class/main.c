#include <stdio.h>
#include <stdlib.h>

void understanding_malloc(void);
void undertanding_calloc(void);
void understanding_realloc(void);
void understanding_free(void);

int *returning_a_local_array(void);
char *returning_a_built_string(void);

void security_vulnerability_with_realloc(void);
void memory_leak_no_free(void);
void memory_leak_lost_pointer(void);
void dangling_pointer(void);

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  puts("---------------------------------------------------------------------");
  puts("\t\tThis is the \"Whiteboard\" for today.");
  puts("---------------------------------------------------------------------"
       "\n");

  puts("We finally now get to dynamic memory; or heap allocated memory. This\n"
       "will be our final class in this course. After learning this, you now\n"
       "have a great foundation of understanding on how C works, how the\n"
       "computer works--to a degree--and how the \"magic\" of some other\n"
       "languages are kind of working in the background. Allocating our own\n"
       "memory also gives us the ability to make more advanced data\n"
       "structures, and more flexibility with arrays and strings. There are a\n"
       "few functions to make our own memory, along with some potential\n"
       "issues that we could run into that we will go over.\n");

  understanding_malloc();

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
void understanding_malloc() {
  puts("-----------------------------------------------------");
  puts("\t\tUnderstanding malloc.");
  puts("-----------------------------------------------------\n");

  puts("The function, malloc (memory allocate), is our first function to go\n"
       "over: it is the most basic one. This function takes in only a data\n"
       "size of type size_t. Let's try this out by allocating a sinlge int:\n\n"
       "\tint *integer = (int *)malloc(sizeof(int));\n");

  int *integer = (int *)malloc(sizeof(int));

  puts("Pretty straightforward, right? We give malloc the size of data we\n"
       "need, and then cast the return value of a void* to an int*: we get\n"
       "back the address to our data that malloc was able to allocate onto\n"
       "the heap. Now, why would malloc return a void*? It returns that type\n"
       "because malloc has idea what you are allocating, only that you give\n"
       "it a particular size. Plus, when the function is written, there is no\n"
       "way to know what ht exact pointer will be, so malloc returns a void*\n"
       "to point to any kind of data--hence the void. We then cast void* to\n"
       "our particular type in order to use our pointer with the data we\n"
       "actually want.\n");
  puts("Let's actually use this pointer to our dynamically allocated memory.\n"
       "Let's assign a value into our address:\n\n"
       "\t*integer = 10;\n");

  *integer = 10;

  puts("We get to use it just the same as any other pointer. That is simply\n"
       "all we have anyway! Let's see what this data and it's address looks\n"
       "like:\n");
  printf("integer | %lu -> %i\n\n", (size_t)integer, *integer);

  free(integer);
}
