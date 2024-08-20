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
void dangling_pointer(void);
void security_vulnerability_with_realloc(void);
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
    puts("Was not able to allocate memory for integer.");
    exit(EXIT_FAILURE);
  }

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

  const unsigned int LEN = 10;
  int *integers = (int *)malloc(sizeof(int) * LEN);
  if (!integers) {
    puts("Was not able to allocate memory for integers.");
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
       "in more detail in a second, but just know a memory leak is data on\n"
       "the heap that is still allocated, and therefore not able to be\n"
       "allocated by another call to one of the allocation function, but is\n"
       "not freed up when we are done with it for whatever reason. So, always\n"
       "be careful to FREE YOUR MEMORY when it is done being used. Anyway,\n"
       "what does it look like to actually free some dynamically allocated\n"
       "memory? Let's see that in action.\n");

  double *number = (double *)malloc(sizeof(double));
  if (!number) {
    puts("Was not able to allocate memory for number.");
    exit(EXIT_FAILURE);
  }
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
  if (!numbers) {
    puts("Was not able to allocate memory for numbers.");
    exit(EXIT_FAILURE);
  }
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
    puts("Was not able to allocate memory for number.");
    exit(EXIT_FAILURE);
  }
  printf("\tnumber before = %f\n", *number);
  *number = 2.0;
  printf("\tnumber after = %f\n\n", *number);

  puts(
      "As you can see, this guarantees that the value at the address we have\n"
      "allocated is going to be a zero value. This function, just like malloc\n"
      "can fail if the memory we asked for in the call to calloc() is not\n"
      "able to be allocated: in this case we get NULL. We need to make sure\n"
      "to check for that with every call. Now, we can also use this function\n"
      "to allocate arrays, which is what it is usually used for.\n");

  float *numbers = (float *)calloc(10, sizeof(float));
  if (!numbers) {
    puts("Was not able to allocate memory for numbers.");
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

  free(number);
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
  for (int i = 0; i < LEN; i++) {
    array[i] = i + 1;
    printf("\tarray[%i] = %i\n", i, array[i]);
  }
  puts("");

  const int NEW_LEN = LEN + 3;
  printf("We then give that array to realloc() and ask for that array to be\n"
         "resized into an array of length %i. What would that look like?\n\n",
         NEW_LEN);
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
  printf("array2 = %li\n", (long)array2);

  const int NEW_LEN2 = NEW_LEN + 100;
  printf("array before = %li\n", (long)array);
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
       "the reason being how the stack is automatically managed for us? Well,\n"
       "we now finally get to overcome this limitation! We can use a heap\n"
       "(dynamically allocated) array whose lifetime we get to manage\n"
       "ourselves. This allows us to return a pointer not to stack allocated\n"
       "memory but heap allocated memory. Let's define an array and fill it\n"
       "with some data.\n");

  const int LEN = 3;
  int *array = (int *)malloc(sizeof(int) * LEN);
  for (int i = 0; i < LEN; i++)
    array[i] = i + 1;

  printf("Here we have defined an int array and allocated it on the heap with\n"
         "a length of %i. We then initialized each element in the array. We\n"
         "can now return this array because it will not be freed when we exit\n"
         "the function like in stack (automatic) memory; but, now that we\n"
         "will return the pointer to this array, we are actually giving\n"
         "ownership of this array to the calling function. That now means the\n"
         "calling function is responsible to free this data, not this\n"
         "function.\n\n",
         LEN);

  return array;
}

// -----------------------------------------------------------------------------
char *returning_a_built_string() {
  puts("-----------------------------------------------------");
  puts("\t\tReturning A Locally Built String.");
  puts("-----------------------------------------------------\n");

  puts("Returning strings is basically the same problem as with arrays,\n"
       "though there are some caveats with strings. We have to use string\n"
       "manipulation functions to achieve our goals. We'll go over only one\n"
       "of these functions: strncpy() and strcpy(). One thing to note is that\n"
       "these function will work on any kind of string, even stack allocated\n"
       "strings.\n");
  puts("Let's first go over a simple way of creating a string using a string\n"
       "literal. The first function we will go over is strcpy().\n");

  const int STRING_LEN = 8;
  char *string = (char *)malloc(sizeof(char) * STRING_LEN);
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
      "not protections for a source string length that is bigger than the\n"
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
       "previous functions outcome that overwrites memory it doesn't own! So,\n"
       "still make sure that the length provided is still greater than or\n"
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
}

// -----------------------------------------------------------------------------
void memory_leak_no_free() {
  puts("----------------------------------------");
  puts("    Memory Leak From Not Freeing.");
  puts("----------------------------------------\n");

  puts("");
}

// -----------------------------------------------------------------------------
void memory_leak_lost_pointer() {
  puts("----------------------------------------");
  puts("  Memory Leak From Losing a Pointer.");
  puts("----------------------------------------\n");
}

// -----------------------------------------------------------------------------
void memory_leak_realloc_failure() {
  puts("----------------------------------------");
  puts("  Memory Leak From realloc() Failure.");
  puts("----------------------------------------\n");
}
