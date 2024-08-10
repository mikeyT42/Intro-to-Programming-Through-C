#include "list.h"
#include <stdio.h>

int main(void) {
  list *list = create_list();
  if (!list)
    return EXIT_FAILURE;

  printf("List size = %zu\n", list->size);
  printf("sizeof int = %ld\n", sizeof(int));

  put(list, 1);
  put(list, 2);
  put(list, 3);
  put(list, 4);
  put(list, 5);
  put(list, 6);
  put(list, 7);
  put(list, 8);
  put(list, 9);

  printf("List size = %zu\n", list->size);
  for (int i = 0; i < list->size; i++) {
    printf("item at %d = %d\n", i, list->data[i]);
  }

  put(list, 10);
  printf("List size = %zu\n", list->size);
  for (int i = 0; i < list->size; i++) {
    printf("item at %d = %d\n", i, list->data[i]);
  }
  shrink_to_fit(list);

  put(list, 11);
  printf("List size = %zu\n", list->size);
  for (int i = 0; i < list->size; i++) {
    printf("item at %d = %d\n", i, list->data[i]);
  }

  put(list, 12);
  put(list, 13);
  put(list, 14);
  put(list, 15);
  put(list, 16);
  put(list, 17);
  put(list, 18);
  put(list, 19);
  put(list, 20);
  put(list, 21);
  put(list, 22);
  put(list, 23);
  put(list, 24);
  put(list, 25);
  put(list, 26);
  put(list, 27);
  put(list, 28);
  put(list, 29);
  put(list, 30);
  put(list, 31);
  put(list, 32);
  put(list, 33);

  printf("List size = %zu\n", list->size);
  for (int i = 0; i < list->size; i++) {
    printf("item at %d = %d\n", i, list->data[i]);
  }

  pop(list);
  pop(list);
  pop(list);

  shrink_to_fit(list);

  destroy(list);

  return EXIT_SUCCESS;
}
