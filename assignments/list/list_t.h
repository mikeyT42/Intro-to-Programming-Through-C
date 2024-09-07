#ifndef LIST_T_H
#define LIST_T_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define GROWTH_FACTOR 10

typedef struct {
  size_t capacity;
  size_t length;
  int *data;
} list_t;

list_t *create_list();
void put(list_t *l, const int i);
int pop(list_t *const l);
void shrink_to_fit(list_t *l);
void destroy(list_t *l);

#endif // !LIST_T_H
