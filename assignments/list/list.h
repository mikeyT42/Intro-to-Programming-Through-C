#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define GROWTH_FACTOR 10

typedef struct {
  size_t capacity;
  size_t size;
  int *data;
} list;

list *create_list();
void put(list *l, int i);
int pop(list *l);
void destroy(list *l);

#endif // !LIST_H
