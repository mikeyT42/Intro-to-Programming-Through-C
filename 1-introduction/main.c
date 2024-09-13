#include <stdio.h>
#include <stdlib.h>

#define CONSTANT 500

void goals_of_this_course(void);

void what_is_a_program(void);
void compilation(void);
void how_does_a_program_execute(void);

void what_is_syntax(void);
void general_syntax(void);

void arithmetic_operators(void);
void addition(void);
void subtraction(void);
void multiplication(void);
void division(void);
void modulus(void);

void declaring_and_defining_variables(void);
void declaring_defining_and_calling_functions(void);
void function_a(void);
int function_b(int x);
double function_c(double x, double y);

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  puts("---------------------------------------------------------------------");
  puts("\t\tThis is the \"Whiteboard\" for today.");
  puts("---------------------------------------------------------------------"
       "\n");

  goals_of_this_course();
  what_is_a_program();
  compilation();
  how_does_a_program_execute();
  what_is_syntax();
  general_syntax();

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
void goals_of_this_course() {
  puts("----------------------------------------------------");
  puts("\tGoals of This Course.");
  puts("----------------------------------------------------");

  puts("The goals of this course is to introduce software engineering. I have\n"
       "chosen to do this through the language C because it forces us to\n"
       "understand certain aspects of the computer. The language itself is\n"
       "also pretty simple; other languages have more complex syntax that\n"
       "make writing programs a bit confusing.\n");
  puts("We will learn good coding habits, like proper and clear formatting,\n"
       "ways to structure simple programs. We will go over the various memory\n"
       "mechanisms available to us; we will go over stack vs. heap memory. We\n"
       "will also go over the kind of data that we can define and use. We\n"
       "will go over various things to lay a great foundation of\n"
       "understanding for you to build on.\n");
  puts("This course will adhere to some standards held in the C language\n"
       "community. We will be using snake case to define our variable,\n"
       "function, and type names. Snake case is a particular writing method\n"
       "to give split our multi-word names while making them one symbol.\n"
       "Snake case looks like this: my_variable_name. There are different\n"
       "ways to do this--like camelCase--but we will be using what others use\n"
       "in C. I will also be formatting a strict way of formatting our code.\n"
       "All function definitions will be split with a separator. Look at this\n"
       "whiteboard file to see what I mean. I expect this formatting to be\n"
       "adhered to because it allows better writing habits I believe.\n");
}

// -----------------------------------------------------------------------------
void what_is_a_program() {
  puts("----------------------------------------------------");
  puts("\tWhat Is A Program?");
  puts("----------------------------------------------------");

  puts("A simply question, but a very good starting point. A program is a set\n"
       "of instructions for a computer to execute. In the most basic sense,\n"
       "that is all. Programs can do anything that we want them to, as long\n"
       "as long as we can actually write them. A programm, though, is not\n"
       "just for the computer.\n");
  puts("We use a programming language to write these instructions. There are\n"
       "various languages that we can use; some are more difficult to write,\n"
       "some are more terse, some are more verbose, some are esoteric, and\n"
       "some are simple. These languages are not just a way to interact with\n"
       "the computer, but are also a way to interact with other developers.\n"
       "These instructions that we write are not just read by the computer,\n"
       "but they are read by other developers; these programs are altered by\n"
       "other developers; these programs need to be able to be understood by\n"
       "developers. This is why we have programming languages. We could just\n"
       "write programs in machine code, but we choose to write programs using\n"
       "language so that it is more ergonomic and easily understood by both\n"
       "ourselves and others. This is why we have Assembly, C, Java, and the\n"
       "hundreds of other languages. So, a program is a set of instructions\n"
       "for the computer and for humans.\n");
}

// -----------------------------------------------------------------------------
void compilation() {
  puts("----------------------------------------------------");
  puts("\tCode Compilation.");
  puts("----------------------------------------------------");

  puts("How does our code that we write--in our case C--become something that\n"
       "the computer can understand? There is a program called a \"compiler\"\n"
       "that turns our C source code into what the computer understands. It\n"
       "either turns it first into Assembly code and then machine code, or\n"
       "directly into machine code. In either case, our source code becomes\n"
       "machine code, which is all the computer understands. The compiler\n"
       "understands C and translates it. There are a few steps of this\n"
       "process that we will go over--only in the broadest of strokes\n"
       "though.\n");
  puts("The first step that we will talk about is the pre-proccessing step.\n"
       "This is where certain pre-proccessor commands and macros will be\n"
       "executed. We will go over how we can utilize this step later.\n"
       "Essentially these macros and constansts will be copied directly into\n"
       "our source code so that we don't have to write it ourselves. It's\n"
       "basically a glorified copying machine.\n");
  puts("The next step that we will be talking about is when the source code\n"
       "is actually parsed by the compiler. It checks the syntax and symbols\n"
       "of our code, along with with if our functions are declared and\n"
       "defined. It also checks to see for our included source files. It also\n"
       "checks our data types.\n");
  puts("The compiler does a wide variety of other things, but we won't be\n"
       "going into it all.\n");
}

// -----------------------------------------------------------------------------
void how_does_a_program_execute() {
  puts("----------------------------------------------------");
  puts("\tHow Does A Program Execute?");
  puts("----------------------------------------------------");

  puts("Code executes one step at a time. This is most often one line at a\n"
       "time; there are certain exceptions--we'll get to them soon. The\n"
       "program starts executing in the \"main\" function; this is the\n"
       "function defined at the beginning of this file. The lines inside of\n"
       "the main function are then executed one line at a time. Any function\n"
       "calls, like the call to puts() prints out the line of text, are moved\n"
       "moved into. So, the program starts to execute the code inside of\n"
       "puts(). This function prints out text to the standard output--the\n"
       "terminal in our case. We then call the function\n"
       "goals_of_this_course(). Our program starts executing the code inside\n"
       "of goals_of_this_course(). At the end of each of these functions, we\n"
       "then return out of the function and go back into the main() function.\n"
       "Then the program starts to execute the function what_is_a_program().\n"
       "Then the code starts to be executed inside of that function. This\n"
       "continues onward until the main() function returns its exit code.");
}

// -----------------------------------------------------------------------------
void what_is_syntax() {
  puts("----------------------------------------------------");
  puts("\tWhat Is \"Syntax\"?");
  puts("----------------------------------------------------");

  puts("What does \"syntax\" mean? The word describes the words and symbols\n"
       "we use to write in our programming language. For example, we use the\n"
       "parentheses to say that a name is a function. We will go over a ton\n"
       "of syntax. These words we use of the building blocks of any\n"
       "language.\n");
}

// -----------------------------------------------------------------------------
void general_syntax() {
  puts("----------------------------------------------------");
  puts("\tSome General Syntax.");
  puts("----------------------------------------------------");

  puts("All programming statements end with a semicolon. This tells the\n"
       "compiler that we reached the end of a statement. Do NOT forget to put\n"
       "a semicolon. The program will not compile with out them. If you\n"
       "forget you will get some really strange compilation errors.\n");
  puts("Since code is meant not just for computers, but for humans, we need\n"
       "to be able to communicate to humans in a way that the computer will\n"
       "not execute. These are called comments. We have to ways to make\n"
       "comments: a single-line comment and a multiline block comment. I'll\n"
       "show you the first way.");

  // This is a single line comment. We make it with the forward slashes.

  puts("Single-line comments are meant to be only on one line. You can\n"
       "technically write a bunch of them on multiple lines. But, that is\n"
       "what the block comment is for. I'll show you what that looks like.\n");

  /*
   * This is a multiline block comment!
   * We define it with the forward slash and then the star symbol. Every new
   * line starts with a star symbol. It ends with a star and forward slash
   * adjacent to each other.
   */

  puts("Comments are a good way to communicate weird things that the code is\n"
       "doing. Comments should NOT explain the code. They should simply be\n"
       "used to document code for other readers, or they should be used to\n"
       "explain something unorthodox that is being done.\n");

  puts("At the top of this file you may notice this:\n\n"
       "\t\t#include <stdio.h>\n\n"
       "Let's go over this. The #include is a pre-proccessor command. It\n"
       "tells the pre-processor to copy into this file (include) the code\n"
       "from some other file. In this case, we are including the code from\n"
       "the stdio.h file that is a part of the C standard library. This\n"
       "collection of code holds many different files that we will go over.\n"
       "There are various types and functions made available to us by the\n"
       "standard library so that we don't need to implement them; we get to\n"
       "use the code provided to us. The file that we use from the standard\n"
       "library must be surrounded with the < and > characters.\n");

  declaring_and_defining_variables();
  declaring_defining_and_calling_functions();
}

// -----------------------------------------------------------------------------
void declaring_and_defining_variables() {
  puts("--------------------------------------------");
  puts("     Declaring and Defining Variables.");
  puts("--------------------------------------------");

  puts("Let's go over in this section how to define variables. Variable\n"
       "definitions start with an optional qualifier--we'll go over one in a\n"
       "second--a type, and then finally a name for the variable. Let's\n"
       "define one now:\n");

  int my_integer;

  puts("Above we have defined a variable with the name of \"my_integer.\" It\n"
       "has a type of \"int,\" which as you may guess is an integer. This\n"
       "variable though, has no data: it is not initialized to anything.\n"
       "Let's assign a value to \"my_integer.\"");

  my_integer = 10;
  printf("my_integer = %i", my_integer);

  puts("Here we have used the \"assignment operator\" (=) to assign the value\n"
       "of 10 to our variable name \"my_integer.\" We can declare a variable\n"
       "and assign to it in one statement. Assigning to the variable in this\n"
       "way is called \"initializing\" the variable. Let's see what that\n"
       "looks like.\n");

  int my_integer2 = 20;
  printf("my_integer2 = %i", my_integer2);

  puts("We now declared \"my_integer2\" and initialized it with a value of\n"
       "20. Let's now get to that optional qualifier business. We can make\n"
       "our variable a constant by using the \"const\" qualifier when we\n"
       "declare our variable. In this declaration, we must also initialize\n"
       "the variable because we cannot assign to our constant variable later\n"
       "on in the code; otherwise, it wouldn't be a constant! So, let's see\n"
       "how we do this.\n");

  const int MY_CONSTANT = 5;
  // my_constant = 10; This would produce a compilation error if we uncommented
  // the above line out.
  printf("MY_CONSTANT = %i\n\n", MY_CONSTANT);

  puts("We can now not assign to this variable after declaring it, if we\n"
       "tried to we would get a compilation error. Sometimes, this is\n"
       "desirable because this prevents us from assignming to a variable\n"
       "that shouldn't be altered by ourselves or any other developer: using\n"
       "this qualifier signifies our intent for this variable; and the\n"
       "compiler is able to enforce this for us. You may also notice the name\n"
       "is capitalized. This is the standard practice for variables that are\n"
       "contants. It helps to further communicate that this variable is a\n"
       "constant.\n");

  puts("We can make constants in another way. We can make a constant by using\n"
       "the \"#define\" keyword at the top of our file--a best practice--and\n"
       "that symbol a value. This way is nice because it utilizes the\n"
       "pre-processor to copy and paste this value directly into any code\n"
       "that uses this symbol. It it a pre-processor command. This is\n"
       "particularly nice because it is very efficient for the program when\n"
       "it is executing. The value is not stored into a variable, but is a\n"
       "\"literal value\" that is copied into the code itself before it is\n"
       "finally compiled. Let's see what that looks like exactly.\n");

  printf("CONSTANT = %i\n\n", CONSTANT);
}

// -----------------------------------------------------------------------------
void declaring_defining_and_calling_functions() {
  puts("--------------------------------------------");
  puts(" Declaring, Defining, and Calling Functions.");
  puts("--------------------------------------------");

  puts("In this section, we will start explaining functions. Up to this point\n"
       "we have been using and making them; but I have simply not explained\n"
       "their syntax.\n");
  puts("Functions must be declared, just like variables. We declare functions\n"
       "at the top of our file. The first piece of a function is the return\n"
       "type. This tells the compiler what kind, if any data, the function\n"
       "will be giving back to the caller. We can use any data types. We can\n"
       "tell the compiler we are returning nothing by saying the return type\n"
       "is \"void.\" Then, after the return type is the function name. Here,\n"
       "we want to be descriptive. We don't want to be overly descriptive\n"
       "like I am being in certain instances in this program; but we do want\n"
       "to communicate purpose. Next comes the opening and closing\n"
       "parentheses. This is the section to hold any arguments (a.k.a.\n"
       "parameters) that this function will take as input. We would then have\n"
       "the variable declaration syntax that is separated by commas to define\n"
       "multiple arguments. We can say void in this section in order to\n"
       "define that this function takes no arguments. We then end our\n"
       "declaration with a semicolon. See the top of this file for an\n"
       "example.\n");
  puts("Next comes the definition, or implementation, of the function that\n"
       "was declared. This happens after the main function: it technically\n"
       "doesn't have to be after the main function, but it is a better\n"
       "practice to do so. The definition needs to match the declaration. The\n"
       "return type, function name, and argument list must match. The\n"
       "argument list doesn't need to have the same argument names as the\n"
       "declaration--it is a good practice to do so and I will enforce that--\n"
       "but the argument types must match.\n");
  puts("Then, we use the opening bracket (\"{\") to define the beginning of\n"
       "the function's code, and the closing bracket (\"}\") to define the\n"
       "end of the function's code: this is also known as the function's\n"
       "\"scope.\" The opening bracket should go on the same line as the\n"
       "function's definition, while the closing bracket will go on its own\n"
       "line after any of the function's code. Some C formatting standards\n"
       "will have the opening bracket on its own line as well: we will NOT be\n"
       "doing this--I simply don't like it. See this own function definiton\n"
       "along with the other function defintions to see what this looks\n"
       "like.\n");
  puts("now we move of the using, or \"calling,\" functions. Let's call a\n"
       "function that I have defined that takes no arguments and returns\n"
       "nothing.\n");

  function_a();

  puts("We call a function by typing its name, and then passing it any data\n"
       "that matches it argument list. In this particular case, since nothing\n"
       "is asked for by the function, we have empty parentheses; but, what\n"
       "does it look like if a function returns something and takes something\n"
       "in its argument list?");

  int i = 10;
  int j = function_b(i);

  puts("Here we have a variable, i, with a value of 10, that is given, or\n"
       "passed to our function. We then save the value return by function_b\n"
       "into an integer variable j. When we call a function, the execution of\n"
       "the program enters that function and then executes its code until it\n"
       "returns. A void reterning function does not need a retrun statement\n"
       "because it returns nothing; but a function that does return something\n"
       "requires at least one return statement and must return something if\n"
       "there are logical branches in the code--we won't get into logic and\n"
       "the syntax for the various control flow mechanisms until another\n"
       "class. We can see how the flow of execution is changed by the output\n"
       "of our program. Next, we can also call functions by using a literal\n"
       "value--a value itself--into a function: we can also not save the\n"
       "returned value into a variable if we choose to do so.\n");

  function_b(20);

  puts("Let's also look a a function that returns a double value (a floating\n"
       "point a.k.a. decimal type) and takes 2 double vales.\n");

  int h = function_c(20.5, 15.25);

  puts("The syntax is virtually the same. The only difference is that we\n"
       "separate our arguments with a comma. This allows us to give any\n"
       "number of data to a function as long as it accepts it.\n");
}

// -----------------------------------------------------------------------------
void function_a() {
  puts("I am function_a and I return nothing.");
  puts("I do perform something though, I print out this text!");
}

// -----------------------------------------------------------------------------
int function_b(int x) {
  printf("x = %i", x);
  return x + 10;
}

// -----------------------------------------------------------------------------
double function_c(double x, double y) {
  double j = x + y;
  puts("x + y = j");
  printf("%f + %f = %f", x, y, j);
  return j;
}
