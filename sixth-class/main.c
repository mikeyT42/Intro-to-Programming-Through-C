#include <stdio.h>
#include <stdlib.h>

void understanding_stack_memory(void);
void understanding_static_memory(void);
void understanding_heap_memory(void);

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  puts("---------------------------------------------------------------------");
  puts("\t\tThis is the \"Whiteboard\" for today.");
  puts("---------------------------------------------------------------------"
       "\n");

  puts("There are 3 regions of memory for our use in the computer system.\n"
       "There is stack, static, and heap memory. Each of these has different\n"
       "characteristics and use cases for us as the developer. They all have\n"
       "different data \"lifetimes,\" new vocabulary word there, and\n"
       "different managers of that data. This, together, is what leads to\n"
       "the various use cases.");

  understanding_stack_memory();

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
void understanding_stack_memory() {
  puts("-----------------------------------------------------");
  puts("\t\tUnderstanding Stack Memory.");
  puts("-----------------------------------------------------\n");

  puts("This region of memory, called the stack, is one that we have been\n"
       "exclusively so far. This kind of memory is also called \"automatic\n"
       "memory\" because when we enter a function and leave it, the memory is\n"
       "created and destroyed for us.\n");
  puts("The stack can be thought of, as... well, a stack of boxes. A stack is\n"
       "a first-in-last-out structure: this means that the first box on a\n"
       "stack of boxes (the bottom box) is the last one to be removed from\n"
       "the stack; and since it is a stack, we can only remove from the top\n"
       "of the stack. Each \"box\" in our stack is a function call. Every\n"
       "new function call gets added to the top of the stack: this \"box\" is\n"
       "called a stack frame and it holds the address to the function along\n"
       "with all of the memory needed for this function call--a.k.a. all of\n"
       "your variables. Our program then uses a \"stack pointer\" to know\n"
       "what function is it in on the stack. When a function returns, the\n"
       "stack pointer is moved back up to the previous function in the stack\n"
       "and starts to execute from where it last left of. If any data is\n"
       "returned, then that data is copied from the function and moved into\n"
       "the previous stack frame, ready to be used. When the function returns\n"
       "and the stack pointer is moved, then the data is freed for further\n"
       "writing, invalidating it. This effectively destroyes the function and\n"
       "removes it from the top of the stack; the stack pointer then moves\n"
       "down the stack to the previous function.\n");
  puts("The memory in this region is automatically managed by the system.\n"
       "Therefore, this memory region is much easier for us to use. We don't\n"
       "to worry about destorying our memory called for every function: the\n"
       "system does it for us. This though, limits the lifetime of our data\n"
       "that we declare in each function: it is only able to be used by that\n"
       "function unless we return its own data, or write over data given to\n"
       "function through a pointer argument. The lifetime, or scope, of data\n"
       "is limited to only the function that creates that data: we would say\n"
       "it owns that data. This is why we have problems returning addresses\n"
       "to data created in a function: the lifetime of that data is limited\n"
       "to the scope of that function.\n");
  puts("Memory in most--or maybe even all--is layed out from the lowest to\n"
       "the highest addresses. The stack, though, starts at the highest\n"
       "address that the system gave our program access to. The stack then\n"
       "allocates from the highest address and works its way towards the\n"
       "lowest address. This effectively makes the stack and upside-down\n"
       "stack.");
}

// -----------------------------------------------------------------------------

