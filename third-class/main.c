#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef unsigned char boolean;

void logical_operators();
void the_or_operator();
void the_and_operator();
void the_equals_operator();
void the_not_operator();
void the_not_equals_operator();
void the_relational_operators();

void control_structures();
void if_statements();
void switch_statements();
void while_loops();
void for_loops();
void do_while_loops();

void strings();
void string_declarations();
void string_to_functions(char string[]);

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  puts("---------------------------------------------------------------------");
  puts("\t\tThis is the \"Whiteboard\" for today.");
  puts("---------------------------------------------------------------------"
       "\n");

  logical_operators();
  control_structures();
  strings();

  return EXIT_SUCCESS;
}

// =============================================================================
//                              The Logical Operators
// =============================================================================
void logical_operators() {
  puts("============================================================");
  puts("\tThe Logical Operators");
  puts("============================================================\n");
  puts("The logical false value is 0 in \"C\" while the logical true value is\n"
       "simply \"not\" 0; so 1, 2, 3, etc. For simplicity sake though, we\n"
       "will say true is 1.\n");

  the_or_operator();
  the_and_operator();
  the_equals_operator();
  the_not_operator();
  the_not_equals_operator();
  the_relational_operators();

  puts("\n");
}

// -----------------------------------------------------------------------------
/* The Logical OR's Truth Table.
| A     | B     | A || B |
|-------|-------|--------|
| false | false | false  |
| false | true  | true   |
| true  | false | true   |
| true  | true  | true   |
*/
void the_or_operator() {
  puts("----------------------------------------------------");
  puts("\tThe OR (||) Operator");
  puts("----------------------------------------------------");

  puts("The OR operator can be thought of as the binary addition of 2\n"
       "numbers.\n"
       "Let's consider A = 1 and B = 0; if we add them together A + B, we get\n"
       "1 because 0 + 1 = 1. Now, let's consider 1 + 1. When we add those\n"
       "together we would get a binary representation of 10 (not to be\n"
       "confused with ten but literally one-zero); we can get rid of the 0\n"
       "and now we simply have 1. So, 1 + 1 = 1. What if both A and B were\n"
       "0? 0 + 0 = 0, so we have false. This is more-or-less how the\n"
       "operator works; we add the 2 boolean representations to get a new\n"
       "boolean.\n");
  puts("\tThe Logical OR's Truth Table.\n"
       "\t| A     | B     | A || B |\n"
       "\t|-------|-------|--------|\n"
       "\t| false | false | false  |\n"
       "\t| false | true  | true   |\n"
       "\t| true  | false | true   |\n"
       "\t| true  | true  | true   |\n");

  boolean a = FALSE;
  boolean b = FALSE;
  boolean a_or_b = a || b;
  printf("false || false = %i\n", a_or_b);

  boolean c = FALSE;
  boolean d = TRUE;
  boolean c_or_d = c || d;
  printf("false || true = %i\n", c_or_d);

  boolean e = TRUE;
  boolean f = TRUE;
  boolean e_or_f = e || f;
  printf("true || true = %i\n", e_or_f);
}

// -----------------------------------------------------------------------------
/* The Logical AND's Truth Table.
| A     | B     | A && B |
|-------|-------|--------|
| false | false | false  |
| false | true  | false  |
| true  | false | false  |
| true  | true  | true   |
*/
void the_and_operator() {
  puts("----------------------------------------------------");
  puts("\tThe AND (&&) Operator");
  puts("----------------------------------------------------");

  puts("The AND operator can be thought of as the binary multiplication of 2\n"
       "numbers.\n"
       "Let's consider A = 1 and B = 0; if we multiply them together A * B,\n"
       "we get 0 because 1 * 0 = 0. Now, let's consider 1 * 1. When we\n"
       "multiply those together we would get 1; so, 1 * 1 = 1. What if both\n"
       "A and B were 0? 0 * 0 = 0, so we have false. This is more-or-less\n"
       "how the operator works; we multiply the 2 boolean representations to\n"
       "get a new boolean.\n");
  puts("\tThe Logical AND's Truth Table.\n"
       "\t|   A   |   B   | A && B |\n"
       "\t|-------|-------|--------|\n"
       "\t| false | false | false  |\n"
       "\t| false | true  | false  |\n"
       "\t| true  | false | false  |\n"
       "\t| true  | true  | true   |\n");

  boolean a = FALSE;
  boolean b = FALSE;
  boolean a_and_b = a && b;
  printf("false && false = %i\n", a_and_b);

  boolean c = FALSE;
  boolean d = TRUE;
  boolean c_and_d = c && d;
  printf("false && true = %i\n", c_and_d);

  boolean e = TRUE;
  boolean f = TRUE;
  boolean e_and_f = e && f;
  printf("true && true = %i\n", e_and_f);
}

// -----------------------------------------------------------------------------
/*
| A     | B     | A == B |
|-------|-------|--------|
| false | false | true   |
| false | true  | false  |
| true  | false | false  |
| true  | true  | true   |
*/
void the_equals_operator() {
  puts("----------------------------------------------------");
  puts("\tThe \"Is Equal To\" (==) Operator");
  puts("----------------------------------------------------");

  puts("The \"is equal to\" operator is quite simple; it simply asks a\n"
       "question and then provides the answer: \"is the left thing equal to\n"
       "the right thing?\" If the 2 things are equivalent, then true is\n"
       "returned from the operation, otherwise false is returned from the\n"
       "operation.\n"
       "An important note is that the == operator can only be used on\n"
       "primitive types (int, double, char, *, etc) and they have certain\n"
       "caveats. Floating point precision errors can mess up the comparison,\n"
       "so a \"close enough\" comparison should be utilized. When comparing\n"
       "pointer types only the address is compared, not the value at that\n"
       "address. Also, structures cannot utilize the == operator. Only its\n"
       "data members can be compared one at a time for over all structure\n"
       "equivalence; therefore, to compare structures you need to make a\n"
       "function to do it. Also, arrays cannot utilize the == operator to\n"
       "compare the whole array's contents.\n");
  puts("\t|   A   |   B   | A == B |\n"
       "\t|-------|-------|--------|\n"
       "\t| false | false |  true  |\n"
       "\t| false | true  |  false |\n"
       "\t| true  | false |  false |\n"
       "\t| true  | true  |  true  |\n");

  printf("false == false = %i\n", FALSE == FALSE);
  printf("true == false = %i\n", TRUE == FALSE);
  printf("2 == 5 = %i\n", 2 == 5);
  printf("10 == 10 = %i\n", 10 == 10);
}

// -----------------------------------------------------------------------------
/*
| A     | !A    |
|-------|-------|
| false | true  |
| true  | false |
*/
void the_not_operator() {
  puts("----------------------------------------------------");
  puts("\tThe NOT (!) Operator");
  puts("----------------------------------------------------");

  puts("The NOT operator is also pretty simple. All it does is flip the\n"
       "logical value. So, if something is true it is now false (not true)\n"
       "and something that is false is now true (not false).\n"
       "Like the == operator it will only work on primitive types, so it\n"
       "cannot be used for structures and can only be used on their data\n"
       "members. Using the ! operator on arrays (not the array element) will\n"
       "behave like a pointer. When using the ! operator on a pointer it\n"
       "checks to see if the pointer is a non-zero (non-false) value, which\n"
       "in this case checks if it is non-NULL. If the pointer is NULL, then\n"
       "the operation will return true, and false if the pointer has an\n"
       "address.\n");
  puts("\t|   A   |  !A   |\n"
       "\t|-------|-------|\n"
       "\t| false | true  |\n"
       "\t| true  | false |\n");

  printf("!true = %i\n", !TRUE);
  printf("!false = %i\n", !FALSE);
  printf("!(5 == 10) = %i\n", !(5 == 10));
  int x = 10;
  int *p = NULL;
  int *p2 = &x;
  printf("!p = %i\n", !p);
  printf("!p2 = %i\n", !p2);
}

// -----------------------------------------------------------------------------
/*
| A     | B     | A != B |
|-------|-------|--------|
| false | false | false  |
| false | true  | true   |
| true  | false | true   |
| true  | true  | false  |
*/
void the_not_equals_operator() {
  puts("----------------------------------------------------");
  puts("\tThe \"Is Not Equal To\" (!=) Operator");
  puts("----------------------------------------------------");

  puts("Comparing if something is not equal to something else is quite common\n"
       "in programming, so common that the \"C\" language desingers decided\n"
       "to make a shortcut for !(A == B). To do this, they introduced != to\n"
       "the logical operator list. All it simply does is invert the operation\n"
       "of the == operator.\n");
  puts("\t|   A   |   B   | A != B |\n"
       "\t|-------|-------|--------|\n"
       "\t| false | false | false  |\n"
       "\t| false | true  | true   |\n"
       "\t| true  | false | true   |\n"
       "\t| true  | true  | false  |\n");

  printf("false != false = %i\n", FALSE != FALSE);
  printf("true != false = %i\n", TRUE != FALSE);
  printf("2 != 5 = %i\n", 2 != 5);
  printf("10 != 10 = %i\n", 10 != 10);
}

// -----------------------------------------------------------------------------
void the_relational_operators() {
  puts("----------------------------------------------------");
  puts("\tThe \"Relational\" (<, >, <=, >=) Operators");
  puts("----------------------------------------------------");

  puts("These operators compare values to each other and don't really have\n"
       "truth tables associated to them. Basically, they do what is written\n"
       "on their respective boxes. The < operator asks if the left value is\n"
       "less than the right value; the > operator asks if the left value is\n"
       "greater than the right value; the <= operator asks if the left value\n"
       "is less than or equal to the right value; and the >= operator asks if\n"
       "the left value is greater than or equal to the right value. Depending\n"
       "on the relational comparison, true or false is output.\n");

  printf("false > true = %i\n", FALSE > TRUE);
  printf("1 > 2 = %i\n", 1 > 2);
  printf("1 < 2 = %i\n", 1 < 2);
  printf("1 <= 2 = %i\n", 1 <= 2);
  printf("1 >= 2 = %i\n", 1 >= 2);
  printf("3 >= 3 = %i\n", 3 >= 3);
}

// =============================================================================
//                              The Control Structures
// =============================================================================
void control_structures() {
  puts("============================================================");
  puts("\tThe Control Structures");
  puts("============================================================\n");

  puts("Control structures take advantage of logical operators to\n"
       "conditionally control the execution of certain code blocks.\n");

  if_statements();
  switch_statements();
  while_loops();
  for_loops();
  do_while_loops();
}

// -----------------------------------------------------------------------------
void if_statements() {
  puts("----------------------------------------------------");
  puts("\tThe \"if\" Statement");
  puts("----------------------------------------------------");

  puts("\"if\" statements control the flow of code execution. Depending on\n"
       "their resolution, certain blocks of code can execute. This allows\n"
       "you, the developer, to give conditional logic to your program; this\n"
       "allows your program to make decisions that you allow. Your program\n"
       "can \"think.\"\n");

  if (1)
    puts("I am true");

  if (0)
    puts("I won't execute because the if will resolve to false.");
  else
    puts("I will be executed because my brother \"if\" resolved to false\n"
         "and now I will execute.");

  if (0)
    puts("I won't execute because the if will resolve to false.");
  else if (1)
    puts("I will execute because I have my own \"if\" that resolves to true.");
  else
    puts("I won't execute because my brother \"if\" resolved to true.");

  if (0) {
    puts("I won't execute because the if will resolve to false.");
  } else if (0) {
    puts("I will not execute because my \"if\" resolved to false.");
  } else {
    puts("I will execute because all the other \"if\" statements failed to\n"
         "resolve to true; so, it defaults to me.");
  }
}

// -----------------------------------------------------------------------------
void switch_statements() {
  puts("----------------------------------------------------");
  puts("\tThe \"switch\" Statement");
  puts("----------------------------------------------------");

  puts("The \"switch\" statement is a simplified series of \"if\" statements.\n"
       "It will only work on numbers types and matches exactly on that\n"
       "number, so it is not exactly useful for floating point types. It will\n"
       "work on integers types and enums, and technically works on boolean\n"
       "types; though, it is not as useful for that. It also works on the\n"
       "char data type since characters are just numbers mapped to\n"
       "characters. Really, it's purpose is to test a series of things and\n"
       "then execute certain code.\n");

  int i = 1;
  switch (i) {
  case 1:
    puts("i is 1.");
    break;
  case 2:
    puts("i is 2; which won't happen in this case.");
    break;
  default:
    puts("The default case, we'll get to this in a second.");
    break;
  }

  puts("\nAs you can see, we use the \"break\" statement at the end of each\n"
       "\"case\" block. This is important. If we don't do this, then the next\n"
       "\"case\" block is executed until we hit a \"break\". Let me show\n"
       "that.\n");

  int d = 1;
  switch (d) {
  case 1:
    printf("case 1 :: d = %i\n", d);
  case 2:
    printf("case 2 :: d = %i\n", d);
    break;
  default:
    puts("The default case, we'll get to this in a second.");
    break;
  }

  puts("\nThe \"default\" case is there for when no other case can be\n"
       "executed because none of the \"case\" statements matched. It is\n"
       "particularly useful when handling errors.\n");

  char c = 'z';
  switch (c) {
  case 'a':
    puts("case a.");
    break;
  case 'b':
    puts("case b.");
    break;
  default:
    printf("default case :: c = %c\n", c);
    break;
  }

  puts("\nThe \"switch\" statement is especially useful when used with\n"
       "enums!\n");

  enum Color { RED, GREEN, BLUE };
  enum Color color = BLUE;
  switch (color) {
  case RED:
    puts("Execute RED code.");
    break;
  case GREEN:
    puts("Execute GREEN code.");
    break;
  case BLUE:
    puts("Execute BLUE code.");
    break;
  }
}

// -----------------------------------------------------------------------------
void while_loops() {
  puts("----------------------------------------------------");
  puts("\tThe \"while\" Loop");
  puts("----------------------------------------------------");

  puts("This is our first loop kind. Loops are used to iterate over sets of\n"
       "data and to gather input from a user until we decide to leave the\n"
       "loop. The way we express these loops in words is kind of like this:\n"
       "\t\"While 'x' is true, do 'y'.\"\n"
       "Loops, like \"while,\" need to be left and entered using some\n"
       "kind of condition. Here, again, we can use our conditional operators.\n"
       "Let's see how we can iterate and do some counting up to a number.\n");

  int i = 0;
  const int END = 10;
  while (i <= END) {
    printf("i = %i\n", i);
    i++;
  }

  puts("\nAs you can see, we counted until 10. We can write this same loop\n"
       "using the \"break\" statement. This word allows us to exit the loop\n"
       "from the body of the loop. It is very useful for input loops. We have\n"
       "to execute the infinite \"while\" loop using while(TRUE) which will\n"
       "run for infinity (or really until stack-overflow) because the\n"
       "condtional statement always evaluates to true. It is a best-practice\n"
       "to check the loop exit condtion at the beginning of the loop for\n"
       "\"while\" loops; they can technically be anywhere though and depends\n"
       "on the required logic.\n");

  int d = 0;
  const int SENTINEL = 10;
  while (TRUE) {
    if (d > SENTINEL)
      break;

    printf("d = %i\n", d);
    d++;
  }

  puts("\nSometimes, there are instances where we need to skip a loop\n"
       "iteration. This is done using the \"continue\" keyword. Let's use\n"
       "this keyword to skip the number 3 in a loop until 10.\n");

  int f = 0;
  while (f <= END) {
    if (f == 3) {
      f++;
      continue;
    }

    printf("f = %i\n", f);
    f++;
  }

  puts("\nI usually don't use \"while\" loops; the only reason being that I\n"
       "find the other loops to be more useful.");
}

// -----------------------------------------------------------------------------
void for_loops() {
  puts("----------------------------------------------------");
  puts("\tThe \"for\" Loop");
  puts("----------------------------------------------------");

  puts("The \"for\" loop is very similar to the \"while\" loop, but it simply\n"
       "handles counting for us. Let's take an example loop that counts to\n"
       "10.\n");

  for (int x = 0; x <= 10; x++) {
    printf("x = %i\n", x);
  }

  puts("\nThis loop can be expressed in language as such:\n"
       "\t\"For integer 'x', while 'x' is less than or equal to 10, then do\n"
       "\tsomething, and then increment 'x'.\"\n");

  puts("\nThe \"for\" loop allows us to declare and initialize a loop\n"
       "counter, check some condition that usually uses the counter, and then\n"
       "something to execute at the end of the iteration, which usually\n"
       "consists of incrementing the loop counter by 1.\n"
       "We can also initialize more than 1 thing in the initialization\n"
       "section of the \"for\" loop.\n");

  for (int x = 0, END = 10; x <= END; x++) {
    printf("x = %i\n", x);
  }

  puts("\nWe can also make an infinite \"for\" loop. There used to be certain\n"
       "compiler optimizations that were in favor of the infinite \"for\"\n"
       "loop; but now-a-days they are the same performance wise.\n");

  const int SENTINEL = 10;
  int x = 0;
  for (;;) {
    if (x > SENTINEL)
      break;

    printf("x = %i\n", x);
    x++;
  }

  puts("\nAs you can see, we can use the \"break\" keyword in \"for\" loops.\n"
       "We can also use the \"continue\" keyword.\n");

  for (int x = 0, END = 10; x <= END; x++) {
    if (x == 3)
      continue;

    printf("x = %i\n", x);
  }
}

// -----------------------------------------------------------------------------
void do_while_loops() {
  puts("----------------------------------------------------");
  puts("\tThe \"do-while\" Loop");
  puts("----------------------------------------------------");

  puts("The \"do-while\" loop is nearly identical to the \"while\" loop. The\n"
       "difference is that the loop's conditional check happens after the\n"
       "first iteration, and not the beginning of the loop. Let's count to\n"
       "10 again:\n");

  int x = 0;
  const int END = 10;
  do {
    printf("x = %i\n", x);
    x++;
  } while (x <= END);

  puts("\nThis loop is particularly useful for user input loops. I'll model\n"
       "that up with strings.\n");

  char input[14] = "Hello, World!";
  int i = 0;
  char SENTINEL = '\n';
  do {
    /*
     * On the first iteration the user enters Hello, World!; and then on the
     * second iteration the user hits the commuincated exit character.
     */
    if (i == 1)
      input[0] = SENTINEL;
    else {
      printf("input = %s\n", input);
      i++;
    }
  } while (input[0] != SENTINEL);

  puts("\nThis loop allows the user to first enter input, and then we are\n"
       "able to check that input.\n"
       "We can also use \"break\" and \"continue\" in \"do-while\" loops.\n"
       "I won't show it here though.");
}

// =============================================================================
//                             String Basics
// =============================================================================
void strings() {
  puts("\n\n============================================================");
  puts("\tString Basics");
  puts("============================================================\n");

  puts("Finally, we'll go over some string basics. Strings in 'C' are\n"
       "character arrays. Because they are arrays, they have a fixed size at\n"
       "declaration. If you accidentally iterate over that size, or try to\n"
       "put a string that is bigger than the declared size, you will have\n"
       "undefined behavior.");

  string_declarations();
  char string[] = "Foo bar";
  string_to_functions(string);
}

// -----------------------------------------------------------------------------
void string_declarations() {
  puts("----------------------------------------------------");
  puts("\tDeclaring String Variables");
  puts("----------------------------------------------------");

  puts("Strings are a special kind of array. They are a character array with\n"
       "a null-terminator character. It is not printable, so you won't see\n"
       "it, but it's there. This null-terminator allows 'C', and you, to stop\n"
       "at the end of the string. Let's see one way we can initialize a\n"
       "string.\n");

  char s[14] = {'H', 'e', 'l', 'l', 'o', ',', ' ',
                'W', 'o', 'r', 'l', 'd', '!', '\0'};
  printf("s = %s\n", s);

  puts("\nAs you can see, printf() stops when the null-terminator is reached.\n"
       "We can as well.\n");

  for (int i = 0; s[i] != '\0'; i++) {
    printf("%c", s[i]);
  }
  printf("\n");

  puts("\nMost of the time though, we iterate over a string with the length.\n"
       "We can get the length in a few ways. We know it when we declare a\n"
       "string but when getting input there is not guarantee that the whole\n"
       "array has been used by text. So, we can also use the strlen()\n"
       "function from string.h library.\n");

  const int len = strlen(s);
  printf("len = %i\n", len);

  puts("\nThe strlen() function does not include the null-terminator\n"
       "character for iteration. You do NOT want to put the strlen() function\n"
       "call in a \"for\" declaration because each iteration will\n"
       "re-calculate the length of the string. Since the strlen() basically\n"
       "just iterates over a string and counts until it reaches the\n"
       "null-terminator, you actually end up iterating the array a bunch of\n"
       "times! This is terrible for performance, so get the length of a\n"
       "string before you enter a loop.\n");
  puts("The most common way to create a string is with a string literal. We\n"
       "don't need to include the char array size when doing it like this\n"
       "(or even the way before but no one does it like that) because the\n"
       "compiler can easily figure it out.\n");

  char s2[] = "Foo";
  printf("%s\n", s2);

  puts("\nDeclaring and initializing in this way is far more common. The\n"
       "null-terminator character is automatically added using this method,\n"
       "which is nice. Really, all of these puts() and format strings for\n"
       "printf() are string literals. The only difference is they are not\n"
       "assigned to a variable.");
  char text[] =
      "\nReally, I can also write like this and then give it to puts().";
  puts(text);

  char format_string[] = "\nI can even do this! My favorite number is %i.\n";
  printf(format_string, 50);

  puts("\nStrings can also just be defined and then filled in later.");

  char string[10];
  char c = 'a';
  for (int i = 0; i < 10; i++, c++) {
    if (i == 10 - 1) {
      string[i] = '\0';
      continue;
    }
    string[i] = c;
  }
  printf("\n%s\n", string);

  puts("\nIf we don't add the null-terminator at the end of the string, there\n"
       "is no guarantee that garbage won't be printed from standard library\n"
       "functions; we'll go over why that is when we talk about arrays in\n"
       "general next week.");
}

// -----------------------------------------------------------------------------
void string_to_functions(char string[]) {
  puts("----------------------------------------------------");
  puts("\tPassing String Variables to Functions");
  puts("----------------------------------------------------");

  puts("We're going to do some very basic string passing to functions.\n");
  printf("\tLet's simply print string: %s\n", string);

  puts("\nAnd now, lets do a simpe loop.\n");
  for (int i = 0; string[i] != '\0'; i++)
    printf("%c", string[i]);

  puts("\n\nThat is it for now, we'll talk much more about arrays and strings\n"
       "another time.");
}
