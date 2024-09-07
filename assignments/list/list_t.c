#include "list_t.h"

// -----------------------------------------------------------------------------
list_t *create_list() {
  list_t *l = (list_t *)malloc(sizeof(list_t));
  if (!l) {
    fprintf(stderr, "\n\nCould not malloc List.\n\n");
    return NULL;
  }

  l->data = calloc(GROWTH_FACTOR, sizeof(int));
  if (!l->data) {
    fprintf(stderr, "\n\nCould not calloc data in List.\n\n");
    free(l);
    return NULL;
  }

  printf("List created.\n");
  l->length = 0;
  l->capacity = GROWTH_FACTOR;

  return l;
}

// -----------------------------------------------------------------------------
void destroy(list_t *l) {
  free(l->data);
  l->data = NULL;
  l->length = 0;
  l->capacity = 0;
  free(l);
  l = NULL;
}

// -----------------------------------------------------------------------------
int pop(list_t *const l) {
  int i = l->data[l->length - 1];
  l->length--;

  return i;
}

// -----------------------------------------------------------------------------
void put(list_t *l, const int i) {
  printf("length = %zu ; capacity = %zu\n", l->length, l->capacity);

  if (l->length >= l->capacity) {
    printf("Reallocationg.\n");
    const size_t new_array_size = (GROWTH_FACTOR + l->capacity) * sizeof(int);
    printf("new_array_size = %ld\n", new_array_size);

    int *tmp = realloc(l->data, new_array_size);
    if (!tmp) {
      fprintf(stderr, "\n\nCould not realloc data in List.\n\n");
      destroy(l);
      exit(EXIT_FAILURE);
    }

    l->data = tmp;
    l->capacity += GROWTH_FACTOR;
  }

  l->length++;
  l->data[l->length - 1] = i;
}

// -----------------------------------------------------------------------------
void shrink_to_fit(list_t *l) {
  const size_t diff = l->capacity - l->length;
  const bool can_reduce_size = diff > 0;
  printf("diff = %zu\n", diff);
  printf("can_reduce_size = %d\n", can_reduce_size);
  printf("length = %zu ; capacity = %zu\n", l->length, l->capacity);

  if (can_reduce_size) {
    const size_t new_array_size = l->length * sizeof(int);
    printf("new_array_size = %ld\n", new_array_size);
    int *tmp = realloc(l->data, new_array_size);
    if (!tmp) {
      fprintf(stderr, "\n\nCould not realloc data in List.\n\n");
      destroy(l);
      exit(EXIT_FAILURE);
    }

    l->data = tmp;
    l->capacity = l->length;
    printf("length = %zu ; capacity = %zu\n", l->length, l->capacity);
  }
}
