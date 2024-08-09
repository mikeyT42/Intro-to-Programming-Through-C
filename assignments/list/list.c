#include "list.h"

// -----------------------------------------------------------------------------
list *create_list() {
  list *l = (list *)malloc(sizeof(list));
  if (!l) {
    fprintf(stderr, "Could not malloc List.");
    return NULL;
  }

  l->data = calloc(GROWTH_FACTOR, sizeof(int));
  if (!l->data) {
    fprintf(stderr, "Could not calloc data in List.");
    free(l);
    return NULL;
  }

  printf("List created.\n");
  l->size = 0;
  l->capacity = GROWTH_FACTOR;

  return l;
}

// -----------------------------------------------------------------------------
void destroy(list *l) {
  free(l->data);
  l->data = NULL;
  l->size = 0;
  l->capacity = 0;
  free(l);
}

// -----------------------------------------------------------------------------
void put(list *l, int i) {
  printf("length = %zu ; capacity = %zu\n", l->size, l->capacity);

  if (l->size >= l->capacity) {
    printf("Reallocationg.\n");
    size_t new_array_size = (GROWTH_FACTOR + l->capacity) * sizeof(int);
    printf("new_array_size = %ld\n", new_array_size);
    int *tmp = l->data;
    l->data = realloc(l->data, new_array_size);
    if (l->data == NULL) {
      fprintf(stderr, "Could not realloc data in List.");
      l->data = tmp;
      destroy(l);
      exit(EXIT_FAILURE);
    }

    l->capacity += GROWTH_FACTOR;
  }

  l->size++;
  l->data[l->size - 1] = i;
}

// -----------------------------------------------------------------------------
int pop(list *l) {
  int i = l->data[l->size - 1];
  l->size--;

  int diff = l->capacity - l->size;
  bool can_reduce_size = diff == GROWTH_FACTOR;
  printf("diff = %d\n", diff);
  printf("can_reduce_size = %d\n", can_reduce_size);
  printf("length = %zu ; capacity = %zu\n", l->size, l->capacity);

  if (can_reduce_size) {
    size_t new_array_size = (l->capacity - GROWTH_FACTOR) * sizeof(int);
    printf("new_array_size = %ld\n", new_array_size);
    int *tmp = l->data;
    l->data = realloc(l->data, new_array_size);
    if (l->data == NULL) {
      fprintf(stderr, "Could not realloc data in List.");
      l->data = tmp;
      destroy(l);
      exit(EXIT_FAILURE);
    }
    l->capacity -= GROWTH_FACTOR;
    printf("length = %zu ; capacity = %zu\n", l->size, l->capacity);
  }

  return i;
}
