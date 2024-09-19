#include <stdio.h>
#include <stdlib.h>

const char *genre_to_string(const genre genre);

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  puts("---------------------------------------------------------------------");
  puts("\t\t\tWelcome");
  puts("---------------------------------------------------------------------"
       "\n");

  puts("---------------------------------------------------------------------");
  puts("\t\t\tThank you.");
  puts("---------------------------------------------------------------------"
       "\n");

  return EXIT_SUCCESS;
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
