#include <stdio.h>
#include <stdlib.h>

void goals_of_this_course(void);

void what_is_a_program(void);
void compilation(void);
void how_does_a_program_execute(void);

void general_syntax(void);
void what_is_syntax(void);
void declaring_and_defining_variables(void);
void declaring_defining_and_calling_functions(void);
int function_a(void);
int function_b(int x);
void comments(void);

void intro_to_arrays(void);
void calculate_array_length(void);
void enums(void);
void structs(void);

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
  puts("The next step that");
}
