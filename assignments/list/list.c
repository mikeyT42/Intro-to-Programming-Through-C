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
  l->length = 0;
  l->capacity = GROWTH_FACTOR;

  return l;
}

// -----------------------------------------------------------------------------
void destroy(list *l) {
  free(l->data);
  l->data = NULL;
  l->length = 0;
  l->capacity = 0;
  free(l);
  l = NULL;
}

// -----------------------------------------------------------------------------
void put(list *l, const int i) {
  printf("length = %zu ; capacity = %zu\n", l->length, l->capacity);

  if (l->length >= l->capacity) {
    // TODO: Maybe, I could make this body into a function to share with
    // shrink_to_fit() and give it a function pointer to calculate the
    // new_array_size.
    printf("Reallocationg.\n");
    const size_t new_array_size = (GROWTH_FACTOR + l->capacity) * sizeof(int);
    printf("new_array_size = %ld\n", new_array_size);

    int *tmp = realloc(l->data, new_array_size);
    if (tmp == NULL) {
      fprintf(stderr, "Could not realloc data in List.");
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
int pop(list *const l) {
  int i = l->data[l->length - 1];
  l->length--;

  return i;
}

// -----------------------------------------------------------------------------
void shrink_to_fit(list *l) {
  const size_t diff = l->capacity - l->length;
  const bool can_reduce_size = diff > 0;
  printf("diff = %zu\n", diff);
  printf("can_reduce_size = %d\n", can_reduce_size);
  printf("length = %zu ; capacity = %zu\n", l->length, l->capacity);

  if (can_reduce_size) {
    const size_t new_array_size = l->length * sizeof(int);
    printf("new_array_size = %ld\n", new_array_size);
    int *tmp = realloc(l->data, new_array_size);
    if (tmp == NULL) {
      fprintf(stderr, "Could not realloc data in List.");
      destroy(l);
      exit(EXIT_FAILURE);
    }

    l->data = tmp;
    l->capacity = l->length;
    printf("length = %zu ; capacity = %zu\n", l->length, l->capacity);
  }
}
