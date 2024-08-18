#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define GROWTH_FACTOR 10

typedef struct {
  size_t capacity;
  size_t length;
  int *data;
} list;

list *create_list();
void put(list *l, const int i);
int pop(list *const l);
void shrink_to_fit(list *l);
void destroy(list *l);

#endif // !LIST_H
