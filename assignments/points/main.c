#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTINEL '\n'
#define INPUT_LEN 256

typedef struct {
  int x;
  int y;
} point;

typedef enum { CONTINUE, STOP } loop_control;

point *create_point(const int x, const int y);
char *to_string(const point *const point);
loop_control input_loop(void);

// -----------------------------------------------------------------------------
int main(void) {
  system("clear");
  printf("-----------------------------------------------------------------\n");
  printf("\tWelcome the Point Inputter\n");
  printf("-----------------------------------------------------------------\n");

  loop_control l;
  do {
    l = input_loop();
  } while (l == CONTINUE);

  printf("-----------------------------------------------------------------\n");
  printf("\t\tDhank you, come again.\n");
  printf("-----------------------------------------------------------------\n");

  return EXIT_SUCCESS;
}

// -----------------------------------------------------------------------------
loop_control input_loop(void) {
  char input[INPUT_LEN];
  puts("Please input 2 integers, an x and y value, for a point in space.\n");
  fgets(input, INPUT_LEN, stdin);
  if (input[0] == '\n')
    return STOP;

  int x, y;
  int num_matches = sscanf(input, "%i %i", &x, &y);
  if (num_matches < 2) {
    puts("You did not enter 2 valid integers to create a point. Try again.\n");
    return CONTINUE;
  }

  point *point = create_point(x, y);
  char *point_string = to_string(point);

  if (!point_string) {
    fprintf(stderr, "Could not allocate a string to print the point.");
    free(point);
    return CONTINUE;
  }
  printf("\n%s\n\n", point_string);

  free(point_string);
  free(point);

  return CONTINUE;
}

// -----------------------------------------------------------------------------
point *create_point(const int x, const int y) {
  point *new_point = (point *)malloc(sizeof(point));
  if (!new_point) {
    fprintf(stderr, "Could not malloc a point.");
    exit(EXIT_FAILURE);
  }

  new_point->x = x;
  new_point->y = y;

  return new_point;
}

// -----------------------------------------------------------------------------
char *to_string(const point *const point) {
  const int buffer_size = 512;
  char buffer[buffer_size];

  int was_successful = snprintf(buffer, buffer_size,
                                "point {\n"
                                "%4c = %i\n"
                                "%4c = %i\n"
                                "}",
                                'x', point->x, 'y', point->y);
  char *string_point;
  if (was_successful == -1)
    return NULL;

  const int string_len = was_successful + 1;
  string_point = (char *)malloc(sizeof(char) * string_len);
  strcpy(string_point, buffer);

  return string_point;
}
