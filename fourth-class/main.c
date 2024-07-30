#include <stdio.h>
#include <stdlib.h>

#define SIZE_B 10

void understanding_arrays(void);
void declaring_arrays(void);
void out_of_bounds_array_access(void);
void passing_primitive_types_to_functions(int i);
void passing_arrays_to_functions(double array[], const int array2[],
                                 const int LEN);
void arrays_decay_to_pointers(int *array);
int *can_we_return_arrays();

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  puts("---------------------------------------------------------------------");
  puts("\t\tThis is the \"Whiteboard\" for today.");
  puts("---------------------------------------------------------------------"
       "\n");

  understanding_arrays();
  declaring_arrays();
  out_of_bounds_array_access();

  int x = 10;
  passing_primitive_types_to_functions(x);
  printf("\nHere is x's value:\n\n"
         "\t%i\n\n"
         "As you can see we have not changed the value of x outside of the\n"
         "function even though we added one to the variable (parameter)\n"
         "\"i\". This will be different than when we pass an array to a\n"
         "function. This is because the value of \"x\" was COPIED into the\n"
         "parameter \"i\" and therefore \"x\" was never changed!\n\n",
         x);

  const int LEN = 5;
  double a[] = {1, 2, 3, 4, 5};
  int b[] = {6, 7, 8, 9, 10};
  passing_arrays_to_functions(a, b, LEN);
  puts("\nLet's now see what is inside the array we changed.\n");
  for (int i = 0; i < LEN; i++)
    printf("a[%i] = %f\n", i, a[i]);
  puts("\nAs you can see we have changed the last value in the array! This\n"
       "can be useful when we want it to be, but it can introduce bugs if we\n"
       "don't realize this behavior.\n");

  arrays_decay_to_pointers(b);

  int *returned_array = can_we_return_arrays();
  printf("\nreturned_array = %p\n\n", returned_array);

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
void understanding_arrays() {
  puts("-----------------------------------------------------");
  puts("\t\tUnderstanding Arrays.");
  puts("-----------------------------------------------------\n");

  puts(
      "Arrays are a special kind of type in \"C\" because they aren't exactly\n"
      "a type, they are a data structure, and a basic one at that. They are\n"
      "contiguous blocks of memory that are allocated for your program. Let's\n"
      "say we have an array of integers with a size of 3 that stores 0, 1,\n"
      "and 2.\n");

  int a[3] = {1, 2, 3};
  puts("\tA Representation of an Array:\n");
  printf("%s", "Memory Addresses (first row)");
  printf("\n%s\n\n\t", "Values At Those Addresses (second row)");
  for (int i = 0; i < 3; i++)
    printf("%s%li%-2s", "|", (long)(a + i), "|");
  printf("\n\t");
  for (int i = 0; i < 3; i++)
    printf("%-8s%i%8s ", "|", a[i], "|");

  printf(
      "\n\nLook at the end of the addresses; you'll see that they go up by\n"
      "%lu which is the size of an int. That means each array element is\n"
      "right next to each other in memory. This is great because now we can\n"
      "easily iterate over a chunk of memory--or an array of memory. All the\n"
      "program has to do to get the location of the value you want is\n"
      "multiply the size of the thing you want (%lu in our case) by the index\n"
      "that you want, and then add it to the starting address of the array.\n"
      "Doing that gives the program access to each element in an array!\n",
      sizeof(int), sizeof(int));

  puts("\nKnowing this, we can calculate our own address to the third\n"
       "element and then get the value at that element.\n");
  long starting_address_of_a = (long)a;
  int index = 2;
  long element_size = sizeof(int);
  long index_offset = (long)(element_size * index);
  printf("\t%li -> %i\n", starting_address_of_a + index_offset,
         *(int *)(starting_address_of_a + index_offset));

  puts("\nUltimately though, the compiler can just do this for us:\n");
  printf("\ta[%i] -> %i\n", index, a[index]);

  puts(
      "\nNow, every element in the array needs a block of memory that is big\n"
      "enough to hold it. Then you need the number of elements you have\n"
      "defined to equal the total chunk of memory that is needed. This is why\n"
      "you need to define the size of the array; otherwise how would the\n"
      "program know how big of a chunk of memory to allocate? It wouldn't!\n");
}

// -----------------------------------------------------------------------------
void declaring_arrays(void) {
  puts("-----------------------------------------------------");
  puts("\t\tDeclaring Arrays.");
  puts("-----------------------------------------------------\n");

  puts("The array declaration syntax is very similar to the various string\n"
       "declaration syntaxes that we went over. You can do it in a few ways.\n"
       "The first way is with declaring the array and then initializing it at\n"
       "the same time.\n");

  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (int i = 0, len = 10; i < len; i++)
    printf("a[%i] = %i\n", i, a[i]);

  puts("\nWe can declare an array without giving it the size in this case\n"
       "because the compiler can figure out the size directly from the\n"
       "initialization.\n\n"
       "Most of the time, we are not working with arrays in this way; usually\n"
       "we are filling them in with data somehow and have to then iterate\n"
       "over them, so most of the time we will give the array size in the\n"
       "declaration. This is usually a good use of #define to make a constant\n"
       "that we can then use; but a local constant variable is fine as well.\n"
       "It just depends on the case.\n");

  float b[SIZE_B];
  for (int i = 0; i < SIZE_B; i++)
    b[i] = i + 1;

  for (int i = 0; i < SIZE_B; i++)
    printf("b[%i] = %f\n", i, b[i]);

  puts("\nBy using a constant, we can then iterate and end the array\n"
       "iteration easily without having to worry about going outside the\n"
       "bounds of the array.\n");
}

// -----------------------------------------------------------------------------
void out_of_bounds_array_access() {
  puts("-----------------------------------------------------");
  puts("\tOut of Bounds Array Access.");
  puts("-----------------------------------------------------\n");

  puts("There are some pretty unintuitive ways to mess up the usage of\n"
       "arrays. For one, we can exit the bounds of an array. When you exit\n"
       "the bounds of an array, \"C\" won't stop you; as the developer you\n"
       "need to be safe when accessing arrays and be sure to end when the\n"
       "array does as well. If you don't you access the memory outside of the\n"
       "array directly. This causes undefined behavior; you could access\n"
       "other values in your program or another program's memory! Let's\n"
       "demonstrate this by declaring 2 arrays that will be close in memory;\n"
       "they are declared one after the other, and will therefore be\n"
       "allocated by your program one after the other.\n");

  const int iteration_len = 20;
  int a[] = {1, 2, 3, 4, 5};
  int b[] = {6, 7, 8, 9, 10};
  for (int i = 0; i < iteration_len; i++)
    printf("a[%i] = %i\n", i, a[i]);
  puts("------------");
  for (int i = 0; i < iteration_len; i++)
    printf("b[%i] = %i\n", i, b[i]);

  puts("\nAs you can see, we eventually hit memory that is out of bounds of\n"
       "our arrays and we actually run into each array, even though we are\n"
       "trying to only access each array individually.\n");
}

// -----------------------------------------------------------------------------
void passing_primitive_types_to_functions(int i) {
  puts("-----------------------------------------------------");
  puts("\tPassing Primitive Types to Functions.");
  puts("-----------------------------------------------------\n");

  printf(
      "We are going to take a small detour and talk about primitive types.\n"
      "These types are things like int, double, char, etc. These data types\n"
      "are passed to functions by value; i.e. the value is copied into a\n"
      "variable that is only for the function. This is called \"pass-by\n"
      "-value.\" We defined a variable outside of this function called \"x\"\n"
      "with a value of %i. We passed \"x\" to our function and now call it\n"
      "\"i\" and its value is %i. Let's check it out:\n\n",
      i, i);
  printf("\ti = %i\n\n", i);

  puts("What happens here when we add 1 to \"i\".\n");
  i = i + 1;
  printf("\ti = %i\n\n", i);

  puts("Now, because we passed \"x\" by value we made a copy of the value of\n"
       "\"x\" and gave it to our function and made it \"i\". We still have\n"
       "\"x\" outside of our function. \"x\" will remain unchanged because we\n"
       "made a copy of \"x\". Let's see what is up with \"x\".");
}

// -----------------------------------------------------------------------------
void passing_arrays_to_functions(double array[], const int array2[],
                                 const int LEN) {
  puts("-----------------------------------------------------");
  puts("\tPassing Arrays to Functions.");
  puts("-----------------------------------------------------\n");

  puts("Passing arrays to functions are a bit different than with primitive\n"
       "types. Arrays are passed to functions by pointer; the pointer to the\n"
       "beginning of the array. So, that means we get a \"reference\" to the\n"
       "original array, and not a copy of it. So, that means if we change\n"
       "this function's version of the array then the array outside our\n"
       "function will change as well. Let's first show the array and then\n"
       "change the last element to 20.\n");

  for (int i = 0; i < LEN; i++)
    printf("array[%i] = %f\n", i, array[i]);

  array[LEN - 1] = 20;

  puts("\nWe have now changed the last element. We will see that the value\n"
       "outside our function has changed in the last element. Because of\n"
       "this, be careful when passing arrays to functions. You can make the\n"
       "parameter constant and then you won't be able to change any of the\n"
       "values inside the array.\n");

  // array2[0] = 20;
  puts("We have a constant array, array2; and since it is constant, that\n"
       "means we can't alter it--just like a constant variable. Trying to\n"
       "assign to array2 won't work and will provide a compilation error.");
}

// -----------------------------------------------------------------------------
void arrays_decay_to_pointers(int *array) {
  puts("-----------------------------------------------------");
  puts("\t\tArrays Decay to Pointers.");
  puts("-----------------------------------------------------\n");

  puts("In the previous section I mentioned how arrays when passed to\n"
       "functions are passed by a pointer, or \"reference.\" This allows us\n"
       "to pass arrays into functions. But, how does it become a pointer? We\n"
       "say the array has DECAYED to a pointer. It is implicitely changed to\n"
       "a pointer to the first address of the array. The calculation for our\n"
       "own indexes to array elements utilizes this fact. This mechanism is\n"
       "what even allows us to pass arrays to functions.\n");

  printf("This int pointer we have is really a pointer to the first element\n"
         "in the array it points to. Here is its address:\n\n"
         "\t\t%li\n\n"
         "We can even use array index syntax like before:\n\n"
         "\t\tarray[%i] = %i\n\n",
         (long)array, 0, array[0]);

  puts("One thing of note is the behavior of the array now in relation to the\n"
       "sizeof() function: we can't use this function to calculate the length\n"
       "of the array. Since we now strictly have a pointer, we cannot use the\n"
       "sizeof() function to get the bytes of the array, all we would get is\n"
       "the size of the pointer type.\n");

  int local_array[5] = {1, 2, 3, 4, 5};
  printf("Let me show you. Here is the sizeof(int*):\n\n"
         "\t\t%li\n\n"
         "and here is the sizeof(array):\n\n"
         "\t\t%li\n\n"
         "This is why in the passing_arrays_to_functions() declaration I\n"
         "included a length argument so that the function knows the length of\n"
         "the array passed to it. Otherwise, there would be no way to\n"
         "calculate its size and length like we normally would: like when the\n"
         "array we are using is declared and initialized in the same function\n"
         "it is used. Here is how we would normally calculate the length of\n"
         "the array:\n\n"
         "\tsizeof(local_array) / sizeof(int) = %li\n\n"
         "\t\t\tOR\n\n"
         "\tsizeof(local_array) / sizeof(local_array[0]) = %li\n\n"
         "The second option works because we are getting the size of the\n"
         "first thing in the local_array, which is an int. It's a bit more\n"
         "generic way to test the length of a local array.\n\n",
         sizeof(int *), sizeof(array), sizeof(local_array) / sizeof(int),
         sizeof(local_array) / sizeof(local_array[0]));
}

// -----------------------------------------------------------------------------
int *can_we_return_arrays() {
  puts("-----------------------------------------------------");
  puts("\tCan We Return Arrays From Functions?");
  puts("-----------------------------------------------------\n");

  puts("The answer to this question is not straightforward. One would think\n"
       "that, like other variables, we can return an array. But, we can't do\n"
       "this without doing some fancy stuff. We would need to use heap\n"
       "memory, a.k.a. dynamic memory. The reason for this is the way that\n"
       "stack memory behaves. The array, when this function returns, is\n"
       "deleted from the stack's memory because this whole stack frame for\n"
       "this function is removed from program memory when we return. So,\n"
       "since we know the array decays to a pointer, we return a destroyed\n"
       "memory address, and since it is destroyed the address will be NULL.\n\n"
       "Now, why doesn't \"C\" just copy the array? This is because arrays\n"
       "can be large, so it'd have to loop through the whole array and make\n"
       "a copy to return; the same reason we don't copy the array when\n"
       "passing it to a function; but we still run into the stack memory\n"
       "issue; where would all of these values go? Primitive values are much\n"
       "simpler, they are simply copied and then sent back up to the calling\n"
       "function's stack frame.\n\n"
       "Don't worry too much about all of this stack and heap talk; we're\n"
       "going to go over this soon.");

  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  return array;
}
