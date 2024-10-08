#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void understanding_malloc(void);
void understanding_free(void);
void undertanding_calloc(void);
void understanding_realloc(void);

int *returning_a_local_array(void);
char *returning_a_built_string(void);

void understanding_memory_leaks(void);
void memory_leak_no_free(void);
void memory_leak_lost_pointer(void);
void memory_leak_realloc_failure(void);
void memory_leak_nested_malloc_failure(void);
void understanding_dangling_pointers(void);
void understanding_freeing_freed_memory(void);
void understanding_realloc_security_vulnerability(void);

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
  undertanding_calloc();
  understanding_realloc();

  int *array = returning_a_local_array();
  puts("We now have ownership of this array and can iterate over it just like\n"
       "any other array. Let's see that:\n");
  for (int i = 0; i < 3; i++)
    printf("\tarray[%i] = %i\n", i, array[i]);
  puts("");
  puts("One thing to note is how to manage the length of the array. One way\n"
       "we could do this is by making a struct with a length of our array and\n"
       "a pointer to the array. We could declare out here a length and then\n"
       "pass it to our array creation function. We could even use constants\n"
       "to define a heap allocated array that wouldn't ever change. These are\n"
       "a potential few strategies on array length saving. Another thing to\n"
       "keep in mind is the neccessity to free this array now that this\n"
       "function is the owner of the data.\n");
  free(array);

  char *string = returning_a_built_string();
  printf("This function is now the owner of the string. Let's check out the\n"
         "string to see what its value is and show that we have really\n"
         "returned our string from inside the function.\n\n"
         "\tstring = %s\n\n"
         "As you can see, we have actually returned our string and can use it\n"
         "like any other string. Just make sure to free the string once done\n"
         "with it.\n\n",
         string);
  free(string);

  understanding_memory_leaks();
  understanding_dangling_pointers();
  understanding_freeing_freed_memory();
  understanding_realloc_security_vulnerability();

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
  if (!integer) {
    puts("Was not able to allocate memory for integer.\n\n");
    exit(EXIT_FAILURE);
  }

  puts("Pretty straightforward, right? We give malloc the size of data we\n"
       "need, and then cast the return value of a void* to an int*. The\n"
       "function, malloc(), returns to us an address to the data that was\n"
       "allocated on the heap. If it fails to do so, then we get a NULL\n"
       "pointer. We must be sure to check for NULL after every call to\n"
       "malloc() just in case this happened: we can't use a NULL pointer.\n"
       "Plus, that means no memory was even allocated!\n\n"
       "Now, why does malloc() return a void*? A void pointer is a generic\n"
       "pointer: it is a pointer to any kind of data. It returns that type\n"
       "because malloc() has no idea what you are allocating, only that you\n"
       "give it a particular size. Plus, when the function was written there\n"
       "was no way to know what the exact pointer will be pointing to, so\n"
       "malloc() returns a void* to point to any kind of data--hence the void\n"
       "part. How, though, can we even have a pointer to some unknown data?\n"
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

  const unsigned int LEN = 10;
  int *integers = (int *)malloc(sizeof(int) * LEN);
  if (!integers) {
    puts("Was not able to allocate memory for integers.\n\n");
    exit(EXIT_FAILURE);
  }

  puts("We have now allocated a block of contiguos memory on the heap that\n"
       "can store 10 integers. Let's use this block of memory by filling it\n"
       "with data and then printing that data out.\n");

  for (int i = 0; i < LEN; i++)
    integers[i] = i + 1;
  for (int i = 0; i < LEN; i++)
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
       "leaks in more detail in another section; but just know a memory leak\n"
       "is data on the heap that is still allocated and therefore not able\n"
       "to be allocated by another call to one of the allocation functions.\n"
       "So, always be careful to FREE YOUR MEMORY when it is done being used.\n"
       "Anyway, what does it look like to actually free some dynamically\n"
       "allocated memory? Let's see that in action.\n");

  double *number = (double *)malloc(sizeof(double));
  if (!number) {
    puts("Was not able to allocate memory for number.\n\n");
    exit(EXIT_FAILURE);
  }

  *number = 1.0;
  free(number);

  puts("We give the address to the block of memory we have allocated, and\n"
       "then our program de-allocates that memory. What does that really mean\n"
       "though? The memory is not zeroed out when we free our memory. Really\n"
       "all that happens is that that memory we allocated is now able to be\n"
       "used by the system again for our program's purposes, either for the\n"
       "stack or heap. Nothing else is done. Later in this lesson, we'll see\n"
       "what kinds of issues this creates for us as the developer.\n");
  puts("Next, how would we de-allocate an array we have dynamically\n"
       "allocated?\n");

  double *numbers = (double *)malloc(sizeof(double) * 20);
  if (!numbers) {
    puts("Was not able to allocate memory for numbers.\n\n");
    exit(EXIT_FAILURE);
  }
  free(numbers);

  puts("As you can see here, the call to free is the same. We simply pass the\n"
       "pointer to the first address of the array and then free() de-\n"
       "allocates the whole array. How is that possible though if the only\n"
       "data we give it is the pointer? Does the pointer have the length of\n"
       "the array available to it? The system knows how many bytes is\n"
       "allocated for this block of memory in the heap--we did provide that\n"
       "size when we allocated it. So, there is some meta-data that is\n"
       "stored; and when free() is called that data is utilized to de-\n"
       "allocate the entire block of memory, freeing it for future\n"
       "allocations.\n");
}

// -----------------------------------------------------------------------------
void undertanding_calloc() {
  puts("-----------------------------------------------------");
  puts("\t\tUnderstanding calloc.");
  puts("-----------------------------------------------------\n");

  puts("The calloc() function (clear allocate) is another function in the\n"
       "memory allocation family. What makes it different than malloc? After\n"
       "allocating the block of memory that was requested, it then zeroes the\n"
       "memory it allocated for you. This guarantees that there is no junk\n"
       "data already there; but, why is there junk data in the first place?\n"
       "This is because free() doesn't zero the data it is freeing; it simply\n"
       "makes that block of addresses available again for further allocation.\n"
       "Let's see how we would use calloc() to make some memory for\n"
       "ourselves.\n");

  float *number = (float *)calloc(1, sizeof(float));
  if (!number) {
    puts("Was not able to allocate memory for number.\n\n");
    exit(EXIT_FAILURE);
  }

  printf("\tnumber before = %f\n", *number);
  *number = 2.0;
  printf("\tnumber after = %f\n\n", *number);

  free(number);

  puts(
      "As you can see, this guarantees that the value at the address we have\n"
      "allocated is going to be a zero value. This function, just like\n"
      "malloc(), can fail if the memory we asked for in the call to calloc()\n"
      "is not able to be allocated: in this case we get NULL. We need to make\n"
      "sure to check for that with every call. Now, we can also use this\n"
      "function to allocate arrays, which is what it is usually used for.\n");

  float *numbers = (float *)calloc(10, sizeof(float));
  if (!numbers) {
    puts("Was not able to allocate memory for numbers.\n\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < 10; i++)
    printf("\tnumbers[%i] = %f\n", i, numbers[i]);
  puts("\t--------");
  for (int i = 0; i < 10; i++)
    numbers[i] = i + 1;
  for (int i = 0; i < 10; i++)
    printf("\tnumbers[%i] = %f\n", i, numbers[i]);
  puts("");

  free(numbers);

  puts("This function is only useful if you need to guarantee, for whatever\n"
       "reason, that the new memory will be all zeroes; that it will be\n"
       "clear. This could be useful for security functionality where\n"
       "sensitive data is going to be written and you need to guarantee\n"
       "nothing is there: it can also be used for avoiding undefined behavior\n"
       "if you try to access memory that already has values in it right after\n"
       "new memory was allocated without first zeroing it. There are a myriad\n"
       "of reasons. Just know, that zeroing the memory does take time. This\n"
       "method can be much slower than malloc() because it needs to set each\n"
       "address to zero before giving it to you.\n");
}

// -----------------------------------------------------------------------------
void understanding_realloc() {
  puts("-----------------------------------------------------");
  puts("\t\tUnderstanding realloc.");
  puts("-----------------------------------------------------\n");

  puts("The realloc() function is for re-allocating already existing memory.\n"
       "It takes an existing pointer to allocated data on the heap, and then\n"
       "re-allocates that space with a new size. That size is the second\n"
       "argument provided to the function. It then returns a pointer to the\n"
       "re-allocated memory: it could either be a new memory location, or the\n"
       "same memory location. It all depends on the available space right\n"
       "next to the currently allocated block of memory. Let's first go over\n"
       "the simple case and move on from there.\n");

  const int LEN = 3;
  printf("Let's say we have allocated an array of length %i into the heap.\n\n",
         LEN);

  int *array = (int *)malloc(sizeof(int) * LEN);
  if (!array) {
    fprintf(stderr, "Could not malloc array.\n\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < LEN; i++) {
    array[i] = i + 1;
    printf("\tarray[%i] = %i\n", i, array[i]);
  }
  puts("");

  const int NEW_LEN = LEN + 3;
  printf("We then give that array to realloc() and ask for that array to be\n"
         "resized into an array of length %i. What would that look like?\n\n",
         NEW_LEN);
  // Incorrectly handling realloc return value on purpose. Will get to this in
  // later section.
  array = (int *)realloc(array, sizeof(int) * NEW_LEN);
  for (int i = LEN; i < NEW_LEN; i++) {
    array[i] = i + 1;
    printf("\tarray[%i] = %i\n", i, array[i]);
  }
  puts("");

  puts("What happened here? When we called realloc(), the block of memory\n"
       "that we already owned was extended by our call to realloc(). This\n"
       "function puts the new memory asked for contiguosly against our\n"
       "already allocated memory. So, nothing has happened with our values in\n"
       "array that we already assigned to, we just tacked-on the additional\n"
       "bytes that we have asked for. Let's see our dynamically grown array\n"
       "in its totality.\n");

  for (int i = 0; i < NEW_LEN; i++)
    printf("\tarray[%i] = %i\n", i, array[i]);
  puts("");

  puts("Incredible, right! This is an extremely useful ability; but, what\n"
       "were to happen if we tried to re-allocate a block of memory, but the\n"
       "block couldn't grow in the previous way because there was other\n"
       "allocated memory right next to it? Well, since there isn't free\n"
       "memory right next to our allocated memory, realloc() will find a\n"
       "contiguous block of memory of the size we requested somewhere else\n"
       "and then copy the previous memory into the new location before\n"
       "returning the pointer to that new block of memory. As you can\n"
       "imagine, this is much slower than the previous way because of the\n"
       "data copy; but, it is neccessary in this case. This is the reason\n"
       "why realloc() returns a pointer. In the first case, the pointer that\n"
       "is returned is the same as the pointer supplied in the first\n"
       "argument; in this second case, the pointer returned is a new pointer\n"
       "and therefore differs from the pointer supplied to it in the first\n"
       "argument. It is therefore very important to always assign the\n"
       "pointer returned from realloc() to a variable. This function can\n"
       "also return NULL if the re-allocation could not be performed. We\n"
       "will go over this particular error case later as certain steps need\n"
       "to be accomplished in order to guard against memory leaks. Now, let's\n"
       "see how we can make realloc() give us a new pointer. I will\n"
       "allocate a block of memory: this memory will be allocated very\n"
       "close to our array. Then, I will grow the first array: since there\n"
       "won't be enough space right next to the first array, realloc() will\n"
       "copy our data to a new location and give us a new pointer.\n");

  int *array2 = (int *)malloc(10 * sizeof(int));
  if (!array2) {
    fprintf(stderr, "Could not allocate array2.\n\n");
    free(array);
    exit(EXIT_FAILURE);
  }
  printf("array2 = %li\n", (long)array2);

  const int NEW_LEN2 = NEW_LEN + 1000;
  printf("array before = %li\n", (long)array);
  // Incorrectly handling realloc return value on purpose. Will get to this in
  // later section.
  array = (int *)realloc(array, NEW_LEN2 * sizeof(int));
  printf("array after  = %li\n", (long)array);

  for (int i = NEW_LEN; i < NEW_LEN2; i++) {
    array[i] = i + 1;
  }
  printf("\tarray[%i] = %i\n", 2, array[2]);
  printf("\tarray[%i] = %i\n", NEW_LEN2 - 1, array[NEW_LEN2 - 1]);
  puts("");

  free(array);
  free(array2);

  puts("The function realloc() does not zero old memory if it has to move the\n"
       "memory to a new location. It basically frees the memory after the\n"
       "copy. This can lead to some serious issues in certain cases that\n"
       "we'll get to in another sub-lesson.\n");
}

// -----------------------------------------------------------------------------
int *returning_a_local_array() {
  puts("-----------------------------------------------------");
  puts("\t\tReturning A Local Array.");
  puts("-----------------------------------------------------\n");

  puts("Recall how in the lesson on arrays we found that it wasn't possible\n"
       "to return an array out of a function; and how we found out the heart\n"
       "of the reason being how the stack is automatically managed for us?\n"
       "Well, we can now finally overcome this limitation! We can use a heap\n"
       "(dynamically allocated) array whose lifetime we get to manage\n"
       "ourselves. This allows us to return a pointer not to stack allocated\n"
       "memory, but heap allocated memory. Let's define an array and fill it\n"
       "with some data.\n");

  const int LEN = 3;
  int *array = (int *)malloc(sizeof(int) * LEN);
  if (!array) {
    fprintf(stderr, "Could not allocate array.\n\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < LEN; i++)
    array[i] = i + 1;

  printf("Here we have defined an int array and allocated it on the heap with\n"
         "a length of %i. We then initialized each element in the array. We\n"
         "can now return this array because it will not be freed when we exit\n"
         "the function like in stack (automatic) memory. Because we are\n"
         "returning the pointer to this array, we are actually giving\n"
         "ownership of this array to the calling function. That means the\n"
         "calling function is responsible to free this data, not this\n"
         "function.\n\n",
         LEN);

  return array;
}

// -----------------------------------------------------------------------------
char *returning_a_built_string() {
  puts("-----------------------------------------------------");
  puts("\tReturning A Locally Built String.");
  puts("-----------------------------------------------------\n");

  puts("Returning strings is basically the same problem as with arrays,\n"
       "though there are some caveats with strings. We have to use string\n"
       "manipulation functions to achieve our goals. We'll go over only a\n"
       "couple of these functions: strncpy() and strcpy(). One thing to note\n"
       "is that these function will work on any kind of string, even stack\n"
       "allocated strings.\n");
  puts("Let's first go over a simple way of creating a string using a string\n"
       "literal. The first function we will go over is strcpy().\n");

  const int STRING_LEN = 8;
  char *string = (char *)malloc(sizeof(char) * STRING_LEN);
  if (!string) {
    fprintf(stderr, "Could not allocate string.\n\n");
    exit(EXIT_FAILURE);
  }

  strcpy(string, "Michael");
  printf("\tstring = %s\n\n", string);

  printf(
      "As you can see, we define a char pointer called string which points\n"
      "to %i characters. %s is %i characters long, which includes the null-\n"
      "terminator. The null-terminator needs to be included in the string\n"
      "length when allocating the string: otherwise you will have obvious\n"
      "problems. The function strcpy(), takes a source pointer to a string\n"
      "and a destination pointer to write to. Our source is a string literal\n"
      "which is not assigned to a variable, which is nice for this particular\n"
      "function. It is really only useful for such a simple case as there are\n"
      "no protections for a source string length that is bigger than the\n"
      "destination string's length. The source string must always be less\n"
      "than or equal to the destination string--including the null-\n"
      "terminator. So, even in such a simple case you must still make sure\n"
      "the string literal will fit into the allocated string. Like all heap\n"
      "allocated memory, we must free it once we're done with it. Let's now\n"
      "move on to the safer strncpy().\n\n",
      STRING_LEN, string, STRING_LEN);
  free(string);

  puts("Let's allocate another string onto the heap.\n");

  const unsigned int STRING2_LEN = 7;
  char *string2 = (char *)malloc(sizeof(char) * STRING2_LEN);
  if (!string2) {
    fprintf(stderr, "Could not allocate string2.\n\n");
    exit(EXIT_FAILURE);
  }

  char darien[7] = "Darien";
  strncpy(string2, darien, STRING2_LEN);
  printf("\tstring2 = %s\n\n", string2);

  puts("In this function we provide the source and destination strings like\n"
       "before, but this time with an added bonus argument. This final\n"
       "argument is used to copy characters up to the given length. If that\n"
       "is reached without writing the null-terminator--for example the\n"
       "allocated length being small--then the null-terminator is not writen\n"
       "and you have a non-null-terminated string; which is an invalid\n"
       "string. Now, while this still isn't great, it is better than the\n"
       "previous function's outcome that overwrites memory it doesn't own!\n"
       "So, still make sure that the length provided is still greater than or\n"
       "to the destination string's size. Now that we have a string, let's\n"
       "return it.\n");

  return string2;
}

// -----------------------------------------------------------------------------
void understanding_memory_leaks() {
  puts("-----------------------------------------------------");
  puts("\t\tUnderstanding Memory Leaks.");
  puts("-----------------------------------------------------\n");

  puts("In this sub-lesson we are going to talk about a class of bugs called\n"
       "\"memory leaks.\" This bug class is when we allocate memory onto the\n"
       "heap, but don't free that memory when we are done with it. The leaked\n"
       "memory then sits in the heap for the life of the program, unable to\n"
       "be de-allocated. This eats up our available memory; and if the leak\n"
       "is great enough, and the program runs long enough, then our program\n"
       "leaks all of its available memory and crashes. This bug class is\n"
       "incredibly difficult to find once it occurs. In this bug class,\n"
       "prevention is the best cure.\n");

  memory_leak_no_free();
  memory_leak_lost_pointer();
  memory_leak_realloc_failure();
  memory_leak_nested_malloc_failure();

  puts("-----------------------------------------------------");
  puts("\tEnd of Understanding Memory Leaks.");
  puts("-----------------------------------------------------\n");
}

// -----------------------------------------------------------------------------
void memory_leak_no_free() {
  puts("----------------------------------------");
  puts("    Memory Leak From Not Freeing.");
  puts("----------------------------------------\n");

  puts("The first way to leak memory is to quite simply not free memory\n"
       "that was allocated on the heap. Let's make this happen in a few ways,\n"
       "starting with the simplest way.\n");

  double *i_will_not_be_freed = (double *)malloc(sizeof(double));
  if (!i_will_not_be_freed) {
    fprintf(stderr, "Could not allocate i_will_not_be_freed.\n\n");
    exit(EXIT_FAILURE);
  }
  *i_will_not_be_freed = 1.0;
  // i_will_not_be_freed should be freed sometime before this function returns.

  puts("Here I have allocated some memory. Let's say I don't free this memory\n"
       "in this function, and I don't return the pointer to this memory out\n"
       "of this function, thereby transferring ownership of this data. What\n"
       "would happen? Well, we won't have access to this pointer anymore\n"
       "because we have returned, and therefore we won't have a pointer to\n"
       "free. Also, since we didn't free this variable before we returned, it\n"
       "will never be freed. This block of memory then stays in the heap\n"
       "until our program crashes or until the program is exited. A worse\n"
       "memory leak is when we forget to free memory inside of a loop: let's\n"
       "see what that looks like.\n");

  for (int i = 0; i < 20; i++) {
    int *not_freed = (int *)malloc(sizeof(int));
    if (!not_freed) {
      fprintf(stderr, "Could not allocate not_freed.\n\n");
      exit(EXIT_FAILURE);
    }
    *not_freed = i;
    // not_freed should be freed by the end of EACH loop iteration.
  }

  puts("Having a memory leak inside of a loop is particularly bad. As long as\n"
       "the loop runs, new memory will be leaked for each iteration. Leaking\n"
       "memory like this will crash your program much faster. Also, if you\n"
       "have have a function call with a memory leak inside of a loop, the\n"
       "affect is the same. What is also particularly bad is that you can't\n"
       "free all of the allocated data during each iteration after the loop\n"
       "exits because each pointer was lost.\n");
}

// -----------------------------------------------------------------------------
void memory_leak_lost_pointer() {
  puts("----------------------------------------");
  puts("  Memory Leak From Losing a Pointer.");
  puts("----------------------------------------\n");

  puts("You may notice from the previous sub-lesson that losing pointers is\n"
       "the heart of the \"forgetting to free\" issue. This issue, though,\n"
       "can be more broad. The previous issue had to do with forgetting to\n"
       "free before the scope of the function was exited, while the issue we\n"
       "are going to go over here is losing the pointer to our memory before\n"
       "we even exit the function. Let's make this bug occur.\n");

  int *lost = (int *)malloc(sizeof(int));
  if (!lost) {
    fprintf(stderr, "Could not allocate lost.\n\n");
    exit(EXIT_FAILURE);
  }
  *lost = 10;

  // lost should be freed before another allocation.
  lost = (int *)malloc(sizeof(int));
  if (!lost) {
    fprintf(stderr, "Could not allocate lost.\n\n");
    exit(EXIT_FAILURE);
  }
  *lost = 20;
  free(lost);

  puts("The code above looks pretty innocent, but a grave error has occurred:\n"
       "our memory has been leaked by losing a pointer to our allocated\n"
       "memory. How did we lose our pointer? We have freed our memory after\n"
       "it like good a developer; so, we aren't leaking our memory in that\n"
       "way. The problem is that we call malloc() a second time and save the\n"
       "new address malloc() returns to the same variable we have already\n"
       "allocated to before freeing that memory. Therefore, we have\n"
       "overwritten our address to our first block of memory before we freed\n"
       "that block of memory. Now that we lost the address, that block can\n"
       "never be freed.\n");
}

// -----------------------------------------------------------------------------
void memory_leak_realloc_failure() {
  puts("----------------------------------------");
  puts("  Memory Leak From realloc() Failure.");
  puts("----------------------------------------\n");

  puts("We will see yet again that the heart of a memory leak is the loss of\n"
       "a pointer to that memory. This is what can occur when a call to\n"
       "realloc() fails to allocate the requested memory. As we know, when\n"
       "realloc() fails it returns a NULL pointer. It doesn't though, free\n"
       "the old memory in this case. If we overwrite our original pointer\n"
       "with NULL, then we have lost the address to the original memory and\n"
       "can't free it. Let's see what this looks like in practice.\n");

  unsigned long len = 3;
  int *numbers_leaked = (int *)malloc(sizeof(int) * len);
  if (!numbers_leaked) {
    fprintf(stderr, "Could not allocate numbers_leaked.\n\n");
    exit(EXIT_FAILURE);
  }

  len = 999999999999999;
  numbers_leaked = (int *)realloc(numbers_leaked, sizeof(int) * len);
  if (!numbers_leaked) {
    puts("");
    fprintf(stderr,
            "Could not realloc numbers_leaked. I have introduced a leak.\n\n");
  }
  // Can't free numbers as numbers points to nothing; hence, the leak.
  printf("\tnumbers_leaked = %p\n\n", numbers_leaked);

  puts("One would think that handling a realloc() failure like this would be\n"
       "alright, but it's not. We have assigned the address of numbers_leaked\n"
       "a value of NULL. Therefore, we have lost the original address of\n"
       "numbers_leaked! How would we properly handle this? We need to save\n"
       "the return value of realloc() into a temporary pointer. Then, we\n"
       "check if that pointer is NULL; and if it is then we handle that. If\n"
       "it is a valid address, then we assign our temporary pointer to our\n"
       "heap allocated memory pointer. Let's see what that looks like.\n");

  len = 3;
  int *numbers = (int *)malloc(sizeof(int) * len);
  if (!numbers) {
    fprintf(stderr, "Could not allocate numbers.\n\n");
    exit(EXIT_FAILURE);
  }

  len = 999999999999999;
  int *tmp = (int *)realloc(numbers, sizeof(int) * len);
  if (!tmp) {
    fprintf(stderr, "\nCould not re-allocate numbers.\n\n");
  } else {
    // This won't ever execute in our case.
    numbers = tmp;
  }
  printf("\tnumbers = %p\n"
         "\ttmp     = %p\n\n",
         numbers, tmp);
  free(numbers);
  /*
   * We could also write it like this if we can return a NULL pointer.
   *
   * if (!tmp) {
   *   fprintf(stderr, "Could not re-allocate numbers.\n\n");
   *   free(numbers);
   *   return NULL;
   * }
   * numbers = tmp;
   * free(numbers);
   */

  puts("By not overwriting our original pointer, we get to free later using\n"
       "the numbers pointer. If it was successful, then numbers would be\n"
       "overwritten with the new address that is stored in the tmp pointer.\n"
       "By saving into a temporary pointer like this, we get to guard against\n"
       "a failed re-allocation.\n");
}

// -----------------------------------------------------------------------------
void memory_leak_nested_malloc_failure() {
  puts("-----------------------------------------");
  puts("Memory Leak From Nested malloc() Failure.");
  puts("-----------------------------------------\n");

  puts("This is an issue when allocating structs on the heap; but, not all\n"
       "structs, only structs that have pointer data members. All pointer\n"
       "data members in a struct need to be allocated on the heap, whether or\n"
       "not these pointers are to arrays, other structs, or a single thing.\n"
       "So, when I say, \"nested,\" I mean the struct itself is heap\n"
       "allocated, and n members are allocated on the heap. What kinds of\n"
       "errors can occur when we have data heap allocated inside of a struct\n"
       "that is itself heap allocated? Well, the errors we will have specific\n"
       "to these nested allocations is going to be with freeing this data.\n");
  puts("When we free a struct pointer we need to first free any heap\n"
       "allocated memory. So, first we free a data member that is a pointer\n"
       "to heap allocated memory; and then we free the pointer to the heap\n"
       "allocated struct. Let's first see what it looks like to define a\n"
       "struct with pointer data and to then allocate that struct and its\n"
       "members.\n");

  typedef struct {
    size_t length;
    int *data;
  } list_t;

  list_t *list = (list_t *)malloc(sizeof(list_t));
  if (!list) {
    fprintf(stderr, "Could not allocate list.\n\n");
    exit(EXIT_FAILURE);
  }

  list->length = 3;
  list->data = (int *)malloc(sizeof(int) * list->length);
  if (!list->data) {
    fprintf(stderr, "Could not allocate list->data.\n\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < list->length; i++)
    list->data[i] = i + 1;

  printf("\t\tlist->length = %li\n", list->length);
  for (int i = 0; i < list->length; i++)
    printf("\t\tlist->data[%i] = %i\n", i, list->data[i]);
  puts("");

  puts("We have defined a new type of a struct called list_t (list type),\n"
       "which contains 2 members, a size_t length and an int pointer called\n"
       "data. We first allocate the list_t, and then we assign 3 to our\n"
       "list's length and then allocate an array of integers of our defined\n"
       "length. Let's purposefully create a memory leak.\n");

  free(list);

  puts("There we go, we now have a memory leak: we leaked the data pointer.\n"
       "The data pointer wasn't first freed and now we have a serious\n"
       "problem. The pointer to our data resides in the freed block of memory\n"
       "in list. We could try and free that block since we still have a\n"
       "pointer to it--which is a separate bug if we reference it--but the\n"
       "address of data isn't guaranteed to be overwritten by another\n"
       "allocation. The data block is still an in-use block of memory--\n"
       "according to the system--because it was never de-allocated. So, what\n"
       "would it look like to handle this correctly? Let's see.\n");

  list_t *list2 = (list_t *)malloc(sizeof(list_t));
  if (!list2) {
    fprintf(stderr, "Could not allocate list.\n\n");
    exit(EXIT_FAILURE);
  }

  list2->length = 3;
  list2->data = (int *)malloc(sizeof(int) * list2->length);
  if (!list2->data) {
    fprintf(stderr, "Could not allocate list->data.\n\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < list2->length; i++)
    list2->data[i] = i * 2;

  printf("\t\tlist2->length = %li\n", list2->length);
  for (int i = 0; i < list2->length; i++)
    printf("\t\tlist2->data[%i] = %i\n", i, list2->data[i]);
  puts("");

  free(list2->data);
  free(list2);

  puts("Here we have correctly freed our heap allocated data. We de-allocated\n"
       "data in the correct order that we needed so that we did not leak our\n"
       "data. So, always be sure to be careful when allocating and de-\n"
       "allocating structs. A good way to handle allocating and de-allocating\n"
       "structs is to have constructor and destructor functions. A\n"
       "constructor function would take in any parameters it needs in order\n"
       "to construct the struct, and would then return a pointer to the\n"
       "struct it allocated. In our case the function signature would look\n"
       "something like this:\n\n"
       "\t\tlist_t *create_list_t(void);\n\n"
       "A destructor function is a function that is responsible for taking a\n"
       "pointer to a heap allocated struct, freeing any of the heap allocated\n"
       "memory that is a part of that struct, and then freeing the struct\n"
       "itself. In our case the function signature would look\n"
       "something like this:\n\n"
       "\t\tvoid destroy_list_t(list_t *list);\n\n"
       "Now you know how you would handle this in a real program. You change\n"
       "ownership of these pointers and delegate tasks to these functions in\n"
       "order to keep certain ideas together; and so you don't have to keep\n"
       "writing the exact same code over and over again.\n");
}

// -----------------------------------------------------------------------------
void understanding_dangling_pointers() {
  puts("-----------------------------------------------------");
  puts("\tUnderstanding Dangling Pointers.");
  puts("-----------------------------------------------------\n");

  puts("This is yet another potential bug that can occur when dealing with\n"
       "heap allocated memory. This bug is related to the other free bugs,\n"
       "but is not about losing data: it is about keeping data! A dangling\n"
       "pointer is a pointer to memory that has been freed. Remember, the\n"
       "free function does not clear the memory that it is freeing, nor does\n"
       "it set the de-allocated pointer to NULL to invalidate the pointer.\n"
       "These 2 things are the heart of the issue. A dangling pointer is a\n"
       "de-allocated memory address that we can still reference: the bug\n"
       "REALLY starts to show itself when when start reading or writing to\n"
       "this address. If we were to read from this address it is not\n"
       "guaranteed to be any kind of data that we care about because the\n"
       "address(es) can be written to by allocated memory from some other\n"
       "allocation: we would be reading garbage data leading to undefined\n"
       "behavior. If we wrote to this address(es) then we would potentially\n"
       "be overwriting data owned by some other allocated pointer: doing\n"
       "this would corrupt the data at that address(es). Let's see what this\n"
       "looks like in practice.\n");

  int *dangling_pointer = (int *)malloc(sizeof(int));
  if (!dangling_pointer) {
    fprintf(stderr, "Could not allocate dangling_pointer.\n\n");
    exit(EXIT_FAILURE);
  }

  *dangling_pointer = 200;
  printf("\t\tdangling_pointer before free\n"
         "\t\t| %p | %i\n\n",
         dangling_pointer, *dangling_pointer);
  free(dangling_pointer);
  printf("\t\tdangling_pointer after free\n"
         "\t\t| %p | %i\n\n",
         dangling_pointer, *dangling_pointer);

  puts("There we go, we now have a dangling pointer. This pointer gives us\n"
       "access to memory that is no longer owned by that pointer. The\n"
       "question is; how do we prevent a dangling pointer from occuring? Well\n"
       "after a free call we need to make sure to set our pointer to NULL.\n"
       "Let's do this correctly now.\n");

  int *pointer = (int *)malloc(sizeof(int));
  if (!pointer) {
    fprintf(stderr, "Could not allocate pointer.\n\n");
    exit(EXIT_FAILURE);
  }

  *pointer = 1000;
  printf("\t\tpointer before free\n"
         "\t\t| %p | %i\n\n",
         pointer, *pointer);
  free(pointer);
  pointer = NULL;
  printf("\t\tpointer after free\n"
         "\t\t| %p | N/A\n\n",
         pointer);

  puts("As you can see, we have now invalidated our pointer by pointing to\n"
       "NULL. This is a great pro because now we can't reference data that we\n"
       "don't own by accident; but, there is a con: we can not dereference\n"
       "that pointer without creating a segmentation fault and crashing the\n"
       "entire program. While this is bad, it is much better than reading\n"
       "garbage data or corrupting unowned data: so, it's a pick your poison\n"
       "kind of a deal. This is also a good practice because most functions\n"
       "will defensively check for a NULL pointer before trying to do work:\n"
       "you should also try to do this. Another thing to note is that you\n"
       "don't neccessarily need to assign NULL to a pointer after freeing if\n"
       "you are de-allocating heap allocated memory at the end of a function\n"
       "and NOT returning that pointer--which would be erroneous anyway\n"
       "because you'd be returning a dangling pointer since it is freed. We\n"
       "don't need to assign NULL in this case because when we return our\n"
       "stack frame will be destroyed: so, the pointer to freed memory will\n"
       "be lost along with everything else in the stack frame.\n");
}

// -----------------------------------------------------------------------------
void understanding_freeing_freed_memory() {
  puts("-----------------------------------------------------");
  puts("\tUnderstanding Freeing Freed Memory.");
  puts("-----------------------------------------------------\n");

  puts("This bug has to do with the free function. If we pass the free\n"
       "function a pointer to freed memory--a dangling pointer--then we will\n"
       "have some issues. Let's see what this looks like.\n");

  int *integer = (int *)malloc(sizeof(int));
  if (!integer) {
    fprintf(stderr, "Could not allocate integer.\n\n");
    exit(EXIT_FAILURE);
  }
  free(integer);
  // free(integer);

  puts("If we were to free integer again then our program would crash.\n"
       "Obviously not great. This is why it is so important to set our freed\n"
       "memory to NULL so that we don't have a dangling pointer. Let's see\n"
       "what that looks like.\n");

  integer = NULL;
  free(integer);

  puts("As you can see here, our program doesn't crash. Yet another reason to\n"
       "set our pointers to NULL when they are freed. Why is this? According\n"
       "to the documentation for free(), the function does nothing when\n"
       "passed a NULL pointer.\n");
}

// -----------------------------------------------------------------------------
void understanding_realloc_security_vulnerability() {
  puts("-----------------------------------------------------");
  puts("    Understanding realloc() Security Vulnerabilty.");
  puts("-----------------------------------------------------\n");

  puts("This bug is really only a bug in certain cases. We will only have a\n"
       "security vulnerability if we are storing sensitive data--like a\n"
       "password--on the heap; and only if realloc() frees our data in order\n"
       "to copy it into a new region. This bug can occur if we simply freed\n"
       "the data as well; but it is more problematic with realloc(). Now,\n"
       "with that being said, we will go over this bug for re-allocating\n"
       "sensitive data.\n");

  const size_t LEN = 7;
  char *password1 = (char *)malloc(sizeof(char) * LEN);
  if (!password1) {
    fprintf(stderr, "Could not allocate password1.\n\n");
    exit(EXIT_FAILURE);
  }
  char *password2 = (char *)malloc(sizeof(char) * LEN);
  if (!password2) {
    fprintf(stderr, "Could not allocate password2.\n\n");
    free(password1);
    exit(EXIT_FAILURE);
  }

  strncpy(password1, "abc123", LEN);
  strncpy(password2, "xyz789", LEN);
  printf("\t\tpassword1 @ %li\n", (long)password1);
  printf("\t\tpassword2 @ %li\n\n", (long)password2);
  printf("\t\tpassword1 = %s\n", password1);
  printf("\t\tpassword2 = %s\n\n", password2);

  puts("We have allocated onto the heap 2 strings and we then store our super\n"
       "secure passwords--no one could possibly guess them. Let's see how\n"
       "close these 2 pieces of data are in memory by printing out 100\n"
       "characters starting at password1.\n");

  for (int i = 0; i < 100; i++)
    printf("%c", password1[i]);
  puts("\n");

  puts("Let's now get the bug to occur by having realloc() move our data to a\n"
       "new region in memory.\n");

  const char *const password1_save = password1;
  char *tmp = (char *)realloc(password1, sizeof(char) * LEN * 3);
  if (!tmp) {
    fprintf(stderr, "Could not realloc password1.\n\n");
    free(password1);
    free(password2);
    exit(EXIT_FAILURE);
  } else {
    password1 = tmp;
  }

  printf("\t\tpassword1 @ %li\n", (long)password1);
  printf("\t\tpassword2 @ %li\n\n", (long)password2);
  printf("\t\tpassword1 = %s\n", password1);
  printf("\t\tpassword2 = %s\n\n", password2);

  puts("Our data is in a new memory region--at least it should be; if not re-\n"
       "execute the program--and as you can see the password was copied into\n"
       "the new memory location. What's up with the old block of memory\n"
       "though? We saved the pointer to it, so let's see.\n");

  printf("\t\tpassword1_save @ %li\n", (long)password1_save);
  printf("\t\tpassword1_save = \"%s\"\n", password1_save);

  for (int i = 0; i < 100; i++)
    printf("%c", password1_save[i]);
  puts("\n");

  puts("You may notice that save is a dangling pointer as that memory address\n"
       "is not owned by the program anymore. That isn't the issue though: I\n"
       "am simply using this dangling pointer to demonstrate that our\n"
       "password is still in the old block of memory. This is the crux of the\n"
       "issue! If an attacker created a memory dump of our program, the\n"
       "attacker would see the password: it's just hanging out there. That is\n"
       "obviously not great. This makes our program less secure.\n");
  puts("Solving this problem with realloc() is not ideal, nor exactly\n"
       "trivial, when storing sensitive data on the heap. The solution, funny\n"
       "enough, is to not use realloc() when managing sensitive data. We can\n"
       "use stack memory--which has its limitations and I still think we\n"
       "need to zero the memory anyway--or we make our own sensitive data\n"
       "realloc() function. There are probably many ways to go about this,\n"
       "and I'm not a security expert so I defer to a page I found from a\n"
       "University: I have referenced it below. I will demonstrate and\n"
       "explain their solution here.\n");

  char *secret = (char *)calloc(LEN, sizeof(char));
  if (!secret) {
    fprintf(stderr, "Could not allocate secret.\n\n");
    free(password1);
    free(password2);
    exit(EXIT_FAILURE);
  }
  strncpy(secret, "def456", LEN);

  puts("Here a block of memory has been allocated for a secret char*. We then\n"
       "check the returned pointer and handle any error that was encountered.\n"
       "Then, we initialize our block of memory with our password. Next, we\n"
       "start getting ready to re-allocate our memory.\n");

  size_t secret_size = strlen(secret);
  if (secret_size > SIZE_MAX / 2) {
    fprintf(stderr, "The secret is way too long.\n\n");
    free(secret);
    free(password1);
    free(password2);
    exit(EXIT_FAILURE);
  }

  char *temp_buff = (char *)calloc(secret_size * 2, sizeof(char));
  if (!temp_buff) {
    fprintf(stderr, "Could not allocate temp_buff.\n\n");
    free(secret);
    free(password1);
    free(password2);
    exit(EXIT_FAILURE);
  }

  puts("Here we start to re-allocate our new memory block. We first check the\n"
       "length of the string to make sure it isn't going to be too big after\n"
       "the re-allocation. Then, barring that has passed, we allocate a\n"
       "temporary buffer that is twice as big as our old secret's length. We\n"
       "create this pointer so that we can zero the old memory. We also use\n"
       "calloc() in this case in order to guarantee zeroed memory. Next,\n"
       "let's get to the memory copy, zeroing, and freeing of our old\n"
       "memory.\n");

  memcpy(temp_buff, secret, secret_size);

  memset((void *)(volatile char *)secret, '\0', secret_size);

  free(secret);
  secret = temp_buff;
  temp_buff = NULL;

  puts("First, we copy the data inside the secret into the temporary buffer.\n"
       "We don't free quite yet. First, we zero the memory inside the heap\n"
       "allocated block inside of secret. Now, what is up with the weird\n"
       "casts? First, we cast secret to a volatile string. What does that\n"
       "mean? The volatile keyword tells the compiler that this block of\n"
       "memory can be changed at any time and forces the compiler to not\n"
       "optimize the line. In this case, that is what we want. The line could\n"
       "be moved by compiler optimizations. We then cast to void in order to\n"
       "not get any compiler warnings when passing to memset(). Next, after\n"
       "zeroeing the memory, we free the old block of memory held by secret.\n"
       "Now, the only memory is the temporary buffer. We assign that address\n"
       "to secret for later use and assign NULL to the temporary buffer\n"
       "pointer so that we don't have 2 pointers to the same block of\n"
       "memory.\n");

  puts("Reference to the solution:");
  puts("https://wiki.sei.cmu.edu/confluence/display/c/"
       "MEM03-C.+Clear+sensitive+information+stored+in+reusable+resources\n");

  puts("The problem for the realloc() memory sensitivity issue is a strange\n"
       "one. It cannot be handled very simply and the ultimate fix is to\n"
       "essentially make a secure implementation of a new realloc().\n");

  free(secret);
  free(password1);
  free(password2);
}
