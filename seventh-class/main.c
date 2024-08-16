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

  puts("What about allocating a dynamically allocated array: what would that\n"
       "look like? We still use malloc(), but this time we multiply the size\n"
       "of the things we want to store by the amount of things we want to\n"
       "store (the array length).\n");

  const unsigned int len = 10;
  int *integers = (int *)malloc(sizeof(int) * len);

  puts("We have now allocated a block of contiguos memory on the heap that\n"
       "can store 10 integers. Let's use this block of memory by filling it\n"
       "with data and then printing that data out.\n");

  for (int i = 0; i < len; i++)
    integers[i] = i + 1;
  for (int i = 0; i < len; i++)
    printf("\tintegers[%i] = %i\n", i, integers[i]);
  puts("");

  puts("Pretty great that we can allocate and then use this memory just like\n"
       "we have been using it in the past. Nothing different here other than\n"
       "how we manage the memory itself.\n");

  free(integers);
}

// -----------------------------------------------------------------------------
void understanding_free() {
  puts("-----------------------------------------------------");
  puts("\t\tUnderstanding free.");
  puts("-----------------------------------------------------\n");

  puts("The free() function takes a pointer to dynamically allocated memory\n"
       "and de-allocates it. Why is this important to do? We need to de-\n"
       "allocate the memory we allocate because, if we don't, we will eat up\n"
       "our program's memory through memory leaks. We will go over memory\n"
       "in more detail in a second, but just know a memory leak is data on\n"
       "the heap that is still allocated, and therefore not able to be\n"
       "allocated by another call to one of the allocation function, but is\n"
       "not freed up when we are done with it for whatever reason. So, always\n"
       "be careful to FREE YOUR MEMORY when it is done being used. Anyway,\n"
       "what does it look like to actually free some dynamically allocated\n"
       "memory? Let's see that in action.\n");

  double *number = (double *)malloc(sizeof(double));
  *number = 1.0;
  free(number);

  puts("We give the address to the block of memory we have allocated, and\n"
       "then our program de-allocates that memory. What does that really mean\n"
       "though? The memory is not zeroed out when we free our memory. Really\n"
       "all that happens is that that memory we allocated is now able to be\n"
       "used by the system again for our program's purposes; either for the\n"
       "stack or heap. Nothing else is done. Later in this lesson, we'll see\n"
       "what kinds of issues this creates for us as the developer.\n");
  puts("Now though, how would we de-allocate an array we have dynamically\n"
       "allocated?");

  double *numbers = (double *)malloc(sizeof(double) * 20);
  free(numbers);

  puts("As you can see here, the call to free is the same. We simply pass the\n"
       "pointer to the first address of the array and then free() de-\n"
       "allocates the whole array. How is that possible though if the only\n"
       "data we give it is the pointer? The pointer does have the length of\n"
       "array available to it? The system knows how many bytes is allocated\n"
       "for this block of memory in the heap. So, there is some meta-data\n"
       "that is stored and when free() is called that data is utilized to de-\n"
       "allocate the entire block of memory, freeing it for future\n"
       "allocations.\n");
}
