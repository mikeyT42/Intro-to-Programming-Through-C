#include <stdio.h>
#include <stdlib.h>

#define STRING_LEN 100

typedef enum {
  FICTION,
  NON_FICTION,
  SCIENCE_FICTION,
  MYSTERY,
  BIOGRAPHY,
} genre;

typedef struct {
  char title[STRING_LEN];
  char author[STRING_LEN];
  unsigned int year;
  genre genre;
} book;

const char *genre_to_string(const genre genre);
void print_book(const book book);

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  puts("---------------------------------------------------------------------");
  puts("\t\t\tWelcome");
  puts("---------------------------------------------------------------------"
       "\n");

  book library[] = {{.title = "The Great Gatsby",
                     .author = "F. Scott Fitzgerald",
                     .year = 1925,
                     .genre = FICTION},
                    {.title = "Harry Potter and the Sorcer's Stone",
                     .author = "J. K. Rowling",
                     .year = 1997,
                     .genre = FICTION},
                    {.title = "The War of the Worlds",
                     .author = "H. G. Wells",
                     .year = 1898,
                     .genre = SCIENCE_FICTION},
                    {.title = "Sherlock Holmes",
                     .author = "Arthur Conan Doyle",
                     .year = 1892,
                     .genre = MYSTERY},
                    {.title = "Steve Jobs",
                     .author = "Arthur Isaacson",
                     .year = 2011,
                     .genre = BIOGRAPHY},
                    {.title = "Philosophiae Naturalis Principia Mathematica",
                     .author = "Sir Isaac Newton",
                     .year = 1687,
                     .genre = NON_FICTION}};

  printf("Our library has %lu book(s).\n\n",
         sizeof(library) / sizeof(library[0]));

  print_book(library[0]);
  print_book(library[1]);
  print_book(library[2]);
  print_book(library[3]);
  print_book(library[4]);
  print_book(library[5]);

  puts("---------------------------------------------------------------------");
  puts("\t\t\tThank you.");
  puts("---------------------------------------------------------------------"
       "\n");
}

// -----------------------------------------------------------------------------
const char *genre_to_string(const genre genre) {
  switch (genre) {
  case FICTION:
    return "Fiction";
  case NON_FICTION:
    return "Non-fiction";
  case SCIENCE_FICTION:
    return "Science Fiction";
  case MYSTERY:
    return "Mystery";
  case BIOGRAPHY:
    return "Biography";
  }
}

// -----------------------------------------------------------------------------
void print_book(const book book) {
  printf("book {\n"
         "  %s = %s\n"
         "  %s = %s\n"
         "  %s = %u\n"
         "  %s = %s\n"
         "}\n\n",
         "title", book.title, "author", book.author, "year", book.year, "genre",
         genre_to_string(book.genre));
}
