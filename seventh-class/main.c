#include <stdio.h>
#include <stdlib.h>

void understanding_malloc(void);
void understanding_free(void);
void undertanding_calloc(void);
void understanding_realloc(void);

int *returning_a_local_array(void);
char *returning_a_built_string(void);

void security_vulnerability_with_realloc(void);
void memory_leak(void);
void memory_leak_no_free(void);
void memory_leak_lost_pointer(void);
void memory_leak_realloc_failure(void);
void dangling_pointer(void);
void allocating_structs(void);

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
  understanding_free();

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
void understanding_malloc() {
  puts("-----------------------------------------------------");
  puts("\t\tUnderstanding malloc.");
  puts("-----------------------------------------------------\n");

  puts("The function, malloc (memory allocate), is our first function to go\n"
       "over: it is the most basic one. This function takes in only a data\n"
       "size of type size_t. Let's try this out by allocating a single int.\n");

  int *integer = (int *)malloc(sizeof(int));

  puts("Pretty straightforward, right? We give malloc the size of data we\n"
       "need, and then cast the return value of a void* to an int*. The\n"
       "function, malloc(), returns to us an address to the data that was\n"
       "allocated on the heap. If it fails to do so, then we get a NULL\n"
       "pointer. Now, why does malloc return a void*? A void pointer is a\n"
       "generic pointer: it is a pointer to any kind of data. It returns that\n"
       "type because malloc has no idea what you are allocating, only that\n"
       "you give it a particular size. Plus, when the function is written,\n"
       "there is no way to know what the exact pointer will be pointing to,\n"
       "so malloc returns a void* to point to any kind of data--hence the\n"
       "void. How, though, can we even have a pointer to some unknown data?\n"
       "Remember, all pointers have the same byte size, so that way we can\n"
       "point to any kind of data and the compiler can still tell our program\n"
       "the exact size data to allocate onto the stack. This stack memory\n"
       "then gives us the ability to reference memory out in the heap. We\n"
       "then cast void* to our particular type in order to use our pointer\n"
       "with the data we actually have allocated.\n");
  puts("Let's actually use this pointer to our dynamically allocated memory.\n"
       "Let's assign a value into our address.\n");

  *integer = 10;

  puts("We get to use it just the same as any other pointer. That is simply\n"
       "all we have anyway! Let's see what this data and its address looks\n"
       "like:\n");
  printf("\tinteger | %lu -> %i\n\n", (size_t)integer, *integer);

  puts("Pretty cool, right! We get to actually use this data the same way we\n"
       "have always used our pointers. There are though, other things we\n"
       "still need to talk about when it comes to dynamic memory. Since we\n"
       "are the owners of our data and therefore its lifetime, we need to de-\n"
       "allocate the data we have created. This is where the free() function\n"
       "comes into play. I'm going to call it here, and then lets talk about\n"
       "it in the coming section.\n");

  free(integer);
}

// -----------------------------------------------------------------------------
void understanding_free() {
  puts("-----------------------------------------------------");
  puts("\t\tUnderstanding free.");
  puts("-----------------------------------------------------\n");

  double *number = (double *)malloc(sizeof(double));
}
