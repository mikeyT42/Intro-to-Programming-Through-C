#include <stdio.h>
#include <stdlib.h>

typedef char *string;
typedef struct {
  unsigned int year;
  string country;
  string sport;
  string *team_members;
  const unsigned int how_many_members;
} olympic_team;

void understanding_pointers(void);
void pass_by_pointer(int *i, double *d);
void null_pointer(void);
void constants_and_pointers(void);
int *returning_pointers_to_local_variables(void);
void pointer_arithmetic(void);
void struct_pointers(const olympic_team team,
                     const olympic_team *const team_pointer);

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  puts("---------------------------------------------------------------------");
  puts("\t\tThis is the \"Whiteboard\" for today.");
  puts("---------------------------------------------------------------------"
       "\n");

  understanding_pointers();

  int x = 1;
  double y = 3.0;
  pass_by_pointer(&x, &y);
  printf("We have now returned out of the function; let's see our changes:\n\n"
         "\tx = %i\n"
         "\ty = %f\n\n"
         "As you can see, the values have been changed! That is because,\n"
         "through the pointer, we have gained direct access to the original\n"
         "integer and double values in memory, which allows us to change the\n"
         "ACTUAL value. This is very useful for when we want to have a\n"
         "function change more than one variable (have more than one\n"
         "\"return\" value). It is also useful to efficiently pass structures\n"
         "around in out programs. Instead of copying that data using pass-by\n"
         "-value, a single pointer will be passed which gives the function\n"
         "access to the structure. This is quite memory and CPU efficient! It\n"
         "will also play a pivotal role when using dynamic (heap) memory; but\n"
         "we are not quite there yet.\n\n",
         x, y);

  null_pointer();
  constants_and_pointers();
  int *p = returning_pointers_to_local_variables();
  printf("We would expect \"p\" to be a NULL pointer:\n\n"
         "\tp = %p -> %i\n\n"
         "This could--and VERY likely will--be an address. We run into\n"
         "undefined behavior because while the memory is \"freed\", we can\n"
         "still reference the address; but, there can be ANYTHING in this\n"
         "address after the function returns because the program can\n"
         "overwrite this memory later on. This memory address can be\n"
         "overwritten when a new stack frame is made, or it could be\n"
         "overwritten by the current function: we simply have no idea what\n"
         "will happen with this address because it is \"freed\" when the\n"
         "function returns. We don't own the memory anymore, even though we\n"
         "can reference it. The fact still holds though; we should not return\n"
         "this memory as it is undefined behavior if we were to access it.\n\n",
         p, *p);
  pointer_arithmetic();

  const unsigned int womens_gym_size = 16;
  string womens_gym_participants[] = {
      "Simone Biles",      "Sunisa Lee",    "Jade Carey",
      "Jordan Chiles",     "Hezly Rivera",  "Skye Blakely",
      "Dulcy Caylor",      "Kayla Dicello", "Shilese Jones",
      "Kaliya Lincoln",    "Evelynn Lowe",  "Zoey Molomo",
      "Joscelyn Roberson", "Simone Rose",   "Tiana Sumanasekera",
      "Leanne Wong"};
  olympic_team womens_gymnastics_team = {.year = 2024,
                                         .country = "United States",
                                         .sport = "Women's Gymnastics",
                                         .team_members =
                                             womens_gym_participants,
                                         .how_many_members = womens_gym_size};

  struct_pointers(womens_gymnastics_team, &womens_gymnastics_team);

  printf("&womens_gymnastics_team = %li\n", (long)&womens_gymnastics_team);
  printf("womens_gymnastics_team.country address = %li\n",
         (long)womens_gymnastics_team.country);
  printf("womens_gymnastics_team.country = %s\n",
         womens_gymnastics_team.country);
  printf("womens_gymnastics_team.year address = %li\n",
         (long)&womens_gymnastics_team.year);
  printf("womens_gymnastics_team.year = %i\n", womens_gymnastics_team.year);
  printf("womens_gymnastics_team.sport address = %li\n",
         (long)womens_gymnastics_team.sport);
  printf("womens_gymnastics_team.sport = %s\n", womens_gymnastics_team.sport);
  printf("womens_gymnastics_team.how_many_members address = %li\n",
         (long)&womens_gymnastics_team.how_many_members);
  printf("womens_gymnastics_team.how_many_members = %i\n",
         womens_gymnastics_team.how_many_members);
  printf("womens_gymnastics_team.team_members address = %li\n",
         (long)womens_gymnastics_team.team_members);
  printf("womens_gymnastics_team.team_members:\n");

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
void understanding_pointers() {
  puts("-----------------------------------------------------");
  puts("\t\tUnderstanding Pointers.");
  puts("-----------------------------------------------------\n");

  puts("Pointers are a simple concept that is challenging to grasp. You, as\n"
       "the developer, need to understand this fundamental concept as it is\n"
       "foundational to how all of the other languages perform many of their\n"
       "operations. It just so happens, though, that most languages abstract\n"
       "away this idea to make programming easier. It is the mechanism that\n"
       "is behind the scenes that makes all kinds of data structures just\n"
       "work; you'll see tools in other languages that you'll use and know\n"
       "how they are working. Now that there is an understanding to the grave\n"
       "importance of understanding pointers, let's begin on how these things\n"
       "work and what pointers are.\n");
  puts("A pointer variable is a location in memory--a box--that holds the\n"
       "address to another variable in memory--the location of another box.\n"
       "All variables have an address in memory assigned to them, so a\n"
       "pointer variable is able to hold that address. Then, because we have\n"
       "that address, we can \"travel\" to the address that we have stored.\n"
       "Let's see an example to make this a bit more concrete.\n");

  int x = 10;
  int *p = &x;
  puts("Let's say we have 2 variables, an integer x and a pointer p to an\n"
       "integer. \"p\" is going to point to \"x\". Let's go through the\n"
       "syntax here. The \"*\" character next to the variable name \"p\"\n"
       "declares that \"p\" is a pointer; and the \"int\" part means that the\n"
       "pointer points to an integer. We assign the address of \"x\" to \"p\"\n"
       "with the \"&\" operator (the \"reference\" operator). Now, \"p\"\n"
       "holds the address of \"x\" and we can then go to that address and\n"
       "grab the value stored in the address with the \"*\" operator (the\n"
       "\"de-reference\" operator); the value at that address being 10.\n\n"
       "Let's see this in action.\n");
  printf("%-8s%s%9s\n"
         "%-4s%li%4s\n"
         "%-4s%li%4s\n\n",
         "|", "int *p", "|", "|", (long)&p, "|", "|", (long)p, "|");
  printf("%-8s%s%10s\n"
         "%-4s%li%4s\n"
         "%-4s%i%17s\n\n",
         "|", "int x", "|", "|", (long)&x, "|", "|", x, "|");
  printf("p -> %i\n\n", *p);

  puts("The \"*\" symbol is used with 2 meanings here. When declaring a\n"
       "pointer variable the \"*\" symbol is used to signify the variable is\n"
       "a pointer; but, when we use that variable and want to access the\n"
       "thing our pointer variable points to, the \"*\" symbol is now the\n"
       "\"de-reference\" operator. Do not forget these 2 meanings of the\n"
       "\"*\" symbol. We would say this symbol is overloaded: though, that\n"
       "tangential fact is not particularly important to the discussion of\n"
       "pointers.\n");
}

// -----------------------------------------------------------------------------
void pass_by_pointer(int *i, double *d) {
  puts("-----------------------------------------------------");
  puts("\t\tPass By Pointer.");
  puts("-----------------------------------------------------\n");

  puts("We walked through this idea in the lesson on how arrays are passed to\n"
       "functions, but we are going to walk through it again here for\n"
       "posterity. Passing by pointer passes a pointer to a thing. So, it's\n"
       "an address to the original thing, which gives the function access to\n"
       "the original thing. This is particularly useful. We can change the\n"
       "variable directly in a function; it's not a copy of the variable.\n"
       "Because of this, we can have the changes from the function be shown\n"
       "in the calling function's body.\n");
  printf("We have passed 2 parameters to this function; a pointer to an\n"
         "integer (an integer pointer), and a pointer to a double (a double\n"
         "pointer). We now have access to the original integer and double\n"
         "variables that we gave to this function. Here are their values:\n\n"
         "\tint *i = %li\n"
         "\tdouble *d = %li\n"
         "\t*i = %i\n"
         "\t*d = %f\n\n"
         "Funny enough, we have passed the values of the addresses by value;\n"
         "but I digress.\n\n",
         (long)i, (long)d, *i, *d);
  puts("Because we have access to the original integer x and double y, when\n"
       "we change the values that i and d point to, they will be reflected\n"
       "outside of this function. Let's do that now.\n");

  *i = 20;
  *d = 50.0;
}

// -----------------------------------------------------------------------------
void null_pointer() {
  puts("-----------------------------------------------------");
  puts("\t\tNULL Pointer.");
  puts("-----------------------------------------------------\n");

  puts("It is finally time to talk about the null pointer and what it means.\n"
       "The null pointer is a special value defined by the hardware and C\n"
       "language implementation. It is a zero value; or at the very least\n"
       "according to the C11 standard, \"guaranteed to compare unequal to any\n"
       "object or function.\" What this allows us to do is make a pointer\n"
       "point to nothing, which at times is quite useful. One instance it is\n"
       "useful is for returning an error case for pointers. This is used a\n"
       "lot in dynamic memory allocation functions. So, if something\n"
       "went wrong, a returned pointer would be NULL and we could check for\n"
       "that. If we were to de-reference that pointer then we would get a\n"
       "segmentation fault. We want to make sure to never do that.\n");

  puts("Let's see how we can use a NULL pointer. We can initalize a pointer\n"
       "to NULL before using it in complex code.");
  int *p = NULL;

  printf("p = %p\n\n", p);

  if (p == NULL)
    puts("Here we can see how to utilize the null pointer check.\n");

  if (!p)
    puts("Since NULL is a \"zero\" value, we can use the pointer value\n"
         "directly in the \"if\" statement and test for \"!p\".\n");

  /*
  printf("Un-commenting this would cause a segmentation fault and the program\n"
         "would crash. We cannot de-reference a null pointer. How can we get\n"
         "the value of something that exists at nothing?"
         "*p = %d\n\n",
         *p);
  */
}

// -----------------------------------------------------------------------------
void constants_and_pointers() {
  puts("-----------------------------------------------------");
  puts("\t\tConstants and Pointers.");
  puts("-----------------------------------------------------\n");

  puts("Using constants with pointers is kinda weird. Let me explain. You can\n"
       "have a constant pointer, a pointer to a constant, and a constant\n"
       "pointer to a constant. What is the difference between all of these?\n"
       "First, let's go over a pointer to a constant as it has the most\n"
       "familiar syntax.\n");

  int x = 10;
  int y = 20;
  const int *p = &x;
  puts("Here we have defined an int pointer that points to \"x\". We have\n"
       "also declared it to be a pointer to a constant: it has made the value\n"
       "it points to a constant value when being referenced through \"p\". If\n"
       "we tried to de-reference \"p\" and then reassign a value to \"*p\"\n"
       "then we would get a compilation error. This statement below would be\n"
       "illegal in our definition of \"p\" being a pointer to a constant:\n\n"
       "\t*p = y;\n");
  // *p = y; // This would give a compilation error.
  puts("We can, though, reassign what \"p\" points to like this:\n\n"
       "\tp = &y;\n\n"
       "We can do this because the pointer itself is not constant.\n");
  p = &y; // This is legal because p is a pointer TO a constant.

  int *const p2 = &x;
  puts("We now get to a contant pointer. We have defined a pointer \"p2\" as\n"
       "a constant pointer to an int. This is the opposite of our previous\n"
       "example. We can assign a value to what \"p2\" points to, but we\n"
       "cannot change what \"p2\" points to. This statement below would be\n"
       "illegal in our definition of \"p2\" because it is a constant pointer,\n"
       "therefore the pointer can't be changed:\n\n"
       "\tp2 = &y;\n");
  // p2 = &y; // This would give a compilation error.
  puts("We can, though, reassign the value that \"p2\" points to like this:\n\n"
       "\t*p2 = y;\n\n"
       "We can do this because we have declared the thing \"p2\" points to to\n"
       "not be constant.\n");
  *p2 = y;

  const int *const p3 = &x;
  puts("Now, what about our last option; a constant pointer to a constant?\n"
       "This option does not allow us to change WHAT the pointer points to,\n"
       "nor the VALUE that the pointer points to. A constant pointer to a\n"
       "constant is truly a combination of the former 2 options in one!\n"
       "Therefore, both of these would be illegal according to our definition\n"
       "of \"p3\":\n\n"
       "\tp3 = &y;\n"
       "\t*p3 = y;\n");
  // p3 = &y; // This would give a compilation error.
  // *p3 = y; // This would give a compilation error.

  puts("All of these options allow us to define how protected we want our\n"
       "data to be from being changed, a.k.a. mutated. Enforcing immutability\n"
       "(no change) allows our data to be safe from accidental change when\n"
       "being used in our code. This is a good habit we want to get into. By\n"
       "enforcing immutability we are communicating to other developers the\n"
       "intended purpose of our variables: the more intrinsic communication\n"
       "the better. By also being explicit in our immutability we are\n"
       "granting the compiler to enforce this for us, which stops developers\n"
       "from doing things that were not intended. As time goes on, and you\n"
       "learn more about software engineering, you will come to see the\n"
       "importance of immutability.\n");
}

// -----------------------------------------------------------------------------
int *returning_pointers_to_local_variables() {
  puts("-----------------------------------------------------");
  puts("\tReturning Pointers to Local Variables.");
  puts("-----------------------------------------------------\n");

  puts("This excursion will be very similar--nearly identical really--to the\n"
       "sub-lesson on returning pointers to local arrays. Long story short,\n"
       "we shouldn't do it; and for the same reasons at that! We can't return\n"
       "pointers to local variables because when we exit this function, this\n"
       "function's stack memory will become un-referable (we should not\n"
       "access \"freed\" memory). Let's try this now.\n");
  int x = 50;
  int *p = &x;
  return p;
}

// -----------------------------------------------------------------------------
void pointer_arithmetic() {
  puts("-----------------------------------------------------");
  puts("\t\tPointer Arithmetic.");
  puts("-----------------------------------------------------\n");

  puts("In this section we come to a strange--and often unused--topic,\n"
       "pointer arithmetic. We can do basic mathematics with pointers, very\n"
       "simple things like addition and subtraction, that allows us to simply\n"
       "alter the address we are pointing at. Most of the examples you will\n"
       "come across for pointer arithmetic are for array iteration--a case I\n"
       "can imagine this idea only being useful for. I am not aware of any\n"
       "other use cases of pointer arithmetic. So, with that being said let's\n"
       "get to it.\n");
  puts("Ultimately, pointer arithmetic is what facilitates array indexing. I\n"
       "will copy from the previous lesson our calculation for array indexes\n"
       "to demonstrate and then go over the syntax in detail. This shows how\n"
       "both array indexing and pointer arithmetic essentially operate.\n");
  int a[3] = {1, 2, 3};
  long starting_address_of_a = (long)a;
  int index = 2;
  long element_size = sizeof(int);
  long index_offset = (long)(element_size * index);
  long address_at_i = starting_address_of_a + index_offset;
  printf("\t%p -> %i\n\n", (int *)address_at_i, *(int *)(address_at_i));

  puts("Ok, so first we declare an array, \"a\". It has a length of 3 items.\n"
       "We create a variable called, \"starting_address_of_a\", that uses the\n"
       "fact that arrays decay to pointers when just using it's name like we\n"
       "here. No, we have the beginning memory value of \"a\" to iterate\n"
       "over. We then decide what \"index\" we want, in this case 2. We then\n"
       "the size of our data that is being stored in the array, in our case\n"
       "ints, and save it into the \"element_size\". Thento calculate how far\n"
       "into the array we need to look we need to calculate the\n"
       "\"index_offset\". We multiply the \"element_size\" by the \"index\"\n"
       "to get the \"index_offset\". Now that we have how for to look into\n"
       "the array, we can then calculate the exact address of the item in the\n"
       "array. We do this by adding the \"index_offset\" to the\n"
       "\"starting_address_of_a\". All of this can be simplified to this\n"
       "equation:\n\n"
       "    address_at_i = first_address_in_array + (sizeof(type_in_a) * i)\n\n"
       "With this \"address_at_i\", we can then cast it to an int pointer and\n"
       "de-reference it like we would any other pointer to get its value.\n"
       "That is where this bit comes into play:\n\n"
       "\t*(int *)(address_at_i)\n\n"
       "We change \"address_at_i\" into an int pointer by surrounding\n"
       "\"address_at_i\" in parenthesis, casting, and then de-referencing the\n"
       "whole thing with the de-reference operator (\"*\").\n\n"
       "Now, where does pointer arithmetic play into this equation? By going\n"
       "over this equation we have also shown pointer arithmetic's inner\n"
       "workings. So, what would this look like using pointer arithmetic\n"
       "syntax?\n");

  int *p = a;
  int *p_at_index_2 = p + 2;
  printf("\t%p -> %i\n\n", p_at_index_2, *(p_at_index_2));

  puts("Here we see it's syntactic simplicity. We declare an int pointer to\n"
       "\"a\" which decays to a pointer to the first element in \"a\". Then,\n"
       "we add 2 to our pointer, \"p\", and save our new pointer into\n"
       "\"p_at_index_2\". Now, this variable does not simply hold the address\n"
       "of \"p\" plus literally 2; no, it is actually adding 2 multiplied by\n"
       "the sizeof what \"p\" is pointing to, in our case an int, and adding\n"
       "THAT to the address that \"p\" is pointing to. This is exactly what\n"
       "we showed above, which is already what is happening for array\n"
       "indexing.\n");

  puts("Let's see how, using pointer arithmetic, we can iterate and print\n"
       "from an array:\n");
  const int *const pointer = a;
  for (int i = 0; i < 3; i++)
    printf("\t%p -> %i\n", pointer + i, *(pointer + i));

  puts("\nThe first thing to note is that we have a constant pointer to a\n"
       "constant. Adding to pointer in this way does not change the value\n"
       "\"pointer\" is pointing at nor does a new address get assigned to\n"
       "\"pointer\". We just add to it and then utilize that addition. Next,\n"
       "we use our index counter, \"i\", to add to our \"pointer\" which then\n"
       "does all of the aforementioned behavior to get the address of the\n"
       "item.\n\n"
       "Now, most of the time pointer arithmetic is not recommended. It is\n"
       "not faster in the modern day of compiler optimizations, so therefore\n"
       "only the most niche use case for performance would occur. Second, it\n"
       "is an uncommon way to get access to items in an array. Most use array\n"
       "index syntax for this job. There could be an argument to utilize when\n"
       "working with multi-dimensional arrays, but I am not very familiar\n"
       "with those arguments; plus, we won't be covering multi-dimensional\n"
       "arrays anyway. Therefore, I don't want you to actually use pointer\n"
       "arithmetic in this course. I simply showed it here because it is a\n"
       "feature of the language that is very much a part of C and helps to\n"
       "demonstrate and reinforce what is going on with arrays.\n");
}

// -----------------------------------------------------------------------------
void struct_pointers(const olympic_team team,
                     const olympic_team *const team_pointer) {
  puts("-----------------------------------------------------");
  puts("\t\tStruct Pointers.");
  puts("-----------------------------------------------------\n");

  puts("Struct pointers have their own special data member access syntax.\n"
       "This is done with the -> (arrow) operator. It looks like this:\n\n"
       "\tteam_point->year;\n\n"
       "This traverses the pointer and grabs the data member value. The\n"
       "value can then be used as usual. If the data member was an array\n"
       "then the access would be the same, and even the use would be the\n"
       "same as usual. Basically, this operator is a shorthand for first\n"
       "de-referencing the pointer and then using the dot-operator. This\n"
       "is what it'd look like if you didn't use the arrow operator:\n\n"
       "\t(*team_pointer).year;\n\n"
       "This is much longer to type and more confusing. Don't access struct\n"
       "pointer members like this.\n");

  puts("Passing structs to functions can have some strange quirks. Strings,\n"
       "and in general arrays, are a particular issue. Structs, when passed\n"
       "to functions by-value, have all of its data copied into the function.\n"
       "Any arrays decay to a pointer to the first item in the array (the\n"
       "pointer value is passed-by-value), so the array is actually the\n"
       "original array and not a copy. You can pass the struct by-pointer and\n"
       "skip past this quirk, because now everything in the original struct\n"
       "is able to be referenced. This of course leads to the potential to\n"
       "change the values of the original struct, or point to a new struct;\n"
       "if the calling function is not privy to this behavior then you can\n"
       "have a bad bug. So, using const when passing structs around by\n"
       "pointer is quite imperative when you want to guarantee the struct\n"
       "won't be changed.\n");

  puts("Let me demonstrate how the address of the string array is the same\n"
       "in the pointer to the same struct as the one copied in by-value.\n"
       "Notice how all of the primitive types have new addresses, but the\n"
       "array has the same address as the original.\n");

  printf("&team = %li\n", (long)&team);
  printf("team.country address = %li\n", (long)team.country);
  printf("team.country = %s\n", team.country);
  printf("team.year address = %li\n", (long)&team.year);
  printf("team.year = %i\n", team.year);
  printf("team.sport address = %li\n", (long)team.sport);
  printf("team.sport = %s\n", team.sport);
  printf("team.how_many_members address = %li\n", (long)&team.how_many_members);
  printf("team.how_many_members = %i\n", team.how_many_members);
  printf("team.team_members address = %li\n", (long)team.team_members);
  puts("");

  printf("team_pointer = %li\n", (long)team_pointer);
  printf("team_pointer->country address = %li\n", (long)team_pointer->country);
  printf("team_pointer->country = %s\n", team_pointer->country);
  printf("team_pointer->year address = %li\n", (long)&team_pointer->year);
  printf("team_pointer->year = %i\n", team_pointer->year);
  printf("team_pointer->sport address = %li\n", (long)team_pointer->sport);
  printf("team_pointer->sport = %s\n", team_pointer->sport);
  printf("team_pointer->how_many_members address = %li\n",
         (long)&team_pointer->how_many_members);
  printf("team_pointer->how_many_members = %i\n",
         team_pointer->how_many_members);
  printf("team_pointer->team_members address = %li\n",
         (long)team_pointer->team_members);
  puts("");

  puts("For completion's sake, let's also see the orignal variable,\n"
       "womens_gymnastics_team. This way, we can see all of the original\n"
       "addresses.\n");
}
