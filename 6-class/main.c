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

  puts("There are 3 regions of memory for our use in a computer system. There\n"
       "is stack, static, and heap memory. Each of these has different\n"
       "characteristics and use cases for us as the developer. They all have\n"
       "different data \"lifetimes,\" new vocabulary word there, and\n"
       "different managers of that data. This, together, is what leads to\n"
       "the various use cases.\n");

  understanding_stack_memory();
  understanding_static_memory();
  understanding_heap_memory();

  puts("---------------------------------------------------------------------");
  puts("\t\t\tConclusion.");
  puts("---------------------------------------------------------------------"
       "\n");

  puts("There is a lot going on in the background while using our various\n"
       "memory systems. Keep this in mind while you write your programs in\n"
       "this course and in the future. We can have well running programs if\n"
       "we understand how our memory is being created and destroyed. We can\n"
       "use the stack for automatic management of our memory, we can use\n"
       "static memory to store variables for the life of the program, or we\n"
       "can use dynamic heap memory to store variables that are unknown until\n"
       "we run the programming and can change with execution. These systems\n"
       "allow us to create all of the programs we will ever write and is\n"
       "foundational to your futher understanding of software engineering.");

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
void understanding_stack_memory() {
  puts("-----------------------------------------------------");
  puts("\t\tUnderstanding Stack Memory.");
  puts("-----------------------------------------------------\n");

  puts("This region of memory, called the stack, is one that we have been\n"
       "exclusively using so far. This kind of memory is also called\n"
       "\"automatic memory\" because when we enter a function and leave it,\n"
       "the memory is created and destroyed for us, respectively.\n");
  puts("The stack can be thought of, as... well, a stack of boxes. A stack is\n"
       "a first-in-last-out structure: this means that the first box on a\n"
       "stack of boxes (the bottom box) is the last one to be removed from\n"
       "the stack; and since it is a stack, we can only remove from the top\n"
       "of the stack. Each \"box\" in our stack is a function call. Every\n"
       "new function call gets added to the top of the stack: this \"box\" is\n"
       "called a \"stack frame\" and it holds the address to the function\n"
       "along with all of the memory needed for this function call--a.k.a.\n"
       "all of your variables for the function. Our program then uses a\n"
       "\"stack pointer\" to know what function it is on in the stack. When a\n"
       "function returns, the stack pointer is moved back up to the previous\n"
       "function in the stack and starts to execute from where it last left\n"
       "off. If any data is returned, then that data is copied from the\n"
       "function and moved into the previous stack frame, ready to be used.\n"
       "When the function returns and the stack pointer is moved, then the\n"
       "data is freed for further writing, invalidating it. This effectively\n"
       "destroys the function and removes it from the top of the stack; the\n"
       "stack pointer then moves down the stack to the previous function.\n");
  puts("The memory in this region is automatically managed by the system.\n"
       "Therefore, this memory region is much easier for us to use. We don't\n"
       "need to worry about destroying our memory created for every function:\n"
       "the system does it for us. This though, limits the lifetime of our\n"
       "data that we declare in each function: it is only able to be used by\n"
       "that function unless we return that data, or write over data given to\n"
       "the function through a pointer argument. The lifetime, or scope, of\n"
       "data is limited to only the function that creates that data: we would\n"
       "say the function \"owns\" that data. This is why we have problems\n"
       "returning addresses to data created in a function: the lifetime of\n"
       "that data is limited to the scope of the function that created it.\n");
  puts("Memory in most--or maybe even all--computer systems is layed out from\n"
       "the lowest to the highest addresses. The stack, though, starts at the\n"
       "highest address that the system gives our program access to. The\n"
       "stack then allocates from the highest address and works its way\n"
       "towards the lowest address. This effectively makes the stack an\n"
       "upside-down stack.\n");
}

// -----------------------------------------------------------------------------
void understanding_static_memory() {
  puts("-----------------------------------------------------");
  puts("\t\tUnderstanding Static Memory.");
  puts("-----------------------------------------------------\n");

  puts("Static memory is another region in memory that is not managed\n"
       "directly by the developer. So far we have not used this memory, and\n"
       "we won't during this course; but, for completion's sake I will\n"
       "mention it here. It isn't managed by the program, like the stack, but\n"
       "the region of memory is created when the program runs. It is known at\n"
       "compile time and is \"baked\" into the program's executable file.\n");
  puts("Static memory is known at compilation time. What does this mean? When\n"
       "a program's source files are made into an executable via the\n"
       "compiler, it reads for certain variables: it looks for static\n"
       "variables. Static variables are created using the \"static\" keyword;\n"
       "and they can be created anywhere, in functions and outside functions\n"
       "in the \"global\" scope. The global scope is outside of functions,\n"
       "like where you declare functions and make #define constants: anything\n"
       "in this area is viewable by the rest of your program. This has pros-\n"
       "and-cons: the pro being these variables live forever, and the con\n"
       "that anyone can mess with them. This is why static variables--either\n"
       "declared globally or with the static keyword inside of a function--\n"
       "need to be handled with care. This is also why static variables are\n"
       "not used very often. They have their uses though.\n");
  puts("One thing to know, is that since static variables can be known at\n"
       "compile time, they have a lifetime of the entire program: they live\n"
       "as long as the program does. Therefore, these variables are never\n"
       "freed until the program itself is exited. This is useful if we have\n"
       "special constants we need to keep track of that will never change for\n"
       "the life of the program. It will never be destroyed when a function\n"
       "is destroyed and then have to be recreated. Or, if we have some\n"
       "constant in relation to a structure we can utilize it there. It's\n"
       "just we need to be careful in static variable declarations in order\n"
       "to make them constant. This is the usual use case. It is frowned upon\n"
       "to make a mutable variable static. This can introduce some strange\n"
       "bugs that would be hard to trace because you don't know what function\n"
       "is changing the data at any given time. This is called a race\n"
       "condition.\n");
  puts("The static memory region lies at the lowest address allocated to the\n"
       "program when it executes. This means it is as far away as possible\n"
       "from the stack. Also, since it is known at compile time, it never\n"
       "shrinks nor does it grow throughout the life of the program. The\n"
       "variables allocatted here live for the duration of the program.\n");
}

// -----------------------------------------------------------------------------
void understanding_heap_memory() {
  puts("-----------------------------------------------------");
  puts("\t\tUnderstanding Heap Memory.");
  puts("-----------------------------------------------------\n");

  puts("This region of memory, called the heap, is a dynamic region of\n"
       "memory: this is dynamic memory. It is the memory the developer has\n"
       "direct control over. This means we can create and destroy data at our\n"
       "will. This is a great power that will be touched on in this course\n"
       "as it is pivotal to our understanding of writing programs and how\n"
       "languages other than C generally work.\n");
  puts("The heap, you can imagine, is a disorganized bin of boxes. It is not\n"
       "super structured like the stack or the static regions. This is\n"
       "because as we allocate and de-allocate, the memory can become\n"
       "fragmented. This is not really a problem for us; but, in HEAVILY\n"
       "constrained system, it could be. The heap holds the data we decide to\n"
       "control ourselves and we do this by calling the various allocation\n"
       "functions provided by C, along with the de-allocation function given\n"
       "to us. This allows us to have control over the life of the variables:\n"
       "no longer is our data constrained to only living as long as the\n"
       "function lives or to as long as the program. With this, we can now\n"
       "make data outlive a function, or create data structures that grow and\n"
       "shrink with our needs. Now that we have a controllable data lifetime,\n"
       "we need to introduce a concept known as \"data ownership.\" This\n"
       "essentially gets us thinking about what function owns any given data.\n"
       "We can give ownership of our data by returning our managed data to\n"
       "another function, or by passing our managed data to a function. We\n"
       "can also allow someone to \"borrow\" our data. We can do this by\n"
       "telling the function we are giving our data to that it should not\n"
       "modify this data being given to it: the function is not the owner of\n"
       "the data, but is simply borrowing it. The function could potentially\n"
       "change it as well in a different case, but it certainly shouldn't\n"
       "de-allocate it. The data isn't owned by it. The one who is\n"
       "responsible for de-allocation is effectively the owner of that data.\n"
       "Since we are directly managing who owns and borrows the data, there\n"
       "can be some serious bugs. We have to take the utmost care when using\n"
       "this data. We need to be sure to de-allocate all of our dynamic\n"
       "memory before the program is exited, and we have to be sure to not\n"
       "lose our memory in the heap. This is called a memory leak. This is a\n"
       "terrible bug and is extremely hard to catch in a complex system. A\n"
       "memory leak is when memory is not freed. It builds up, eating your\n"
       "system's resources, until there is no more memory left: this is when\n"
       "the program would then crash. Obviously, this is a terrible bug and\n"
       "should be avoided at all costs. While heap memory is a great and\n"
       "neccessary tool, it is also a dangerous one: \"With great power,\n"
       "comes great responsibility.\"\n");
  puts("The heap region of memory resides just above the static region: it is\n"
       "adjacent to it in memory. While it is not starting at the lowest\n"
       "address given to the program by the system, the heap resides in the\n"
       "lower addresses. The heap grows towards the stack: that is to say the\n"
       "heap grows from small addresses to large addresses. Unlike the stack,\n"
       "the only things in the heap are variable addresses--memory managed by\n"
       "the developer. Because data of various sizes are being allocatted and\n"
       "de-allocatted at our whim, fragmentation can occur. What that means\n"
       "is there are gaps in memory between variables that we can't write to\n"
       "unless we had a peg that could fit that particular hole. If nothing\n"
       "will fit, or the memory around the fragmentation is not freed, then\n"
       "we will have unusable memory. This is obviously not ideal and not\n"
       "something that is easily solvable. Also, allocating memory can be a\n"
       "\"slow\" affair. We have to reach farther out into memory than with\n"
       "the stack to create our data. Also, reading from this region can be\n"
       "slower; in particular when we are jumping around memory to iterate\n"
       "over data or access various things. CPU's have a cache (a small\n"
       "memory region close to the processor), and if we can't read all of\n"
       "our data into it in one shot, or the CPU doesn't ready our data\n"
       "because it is a region of the heap not close to our first read, then\n"
       "we have what is called a \"cache miss.\" This slows down our\n"
       "application. It is something we can not directly control, but\n"
       "certainly something we can help to not happen by using the heap\n"
       "smartly. Keep related data as together in allocations as possible;\n"
       "having contiguous data is especially helpful here.\n");
}
