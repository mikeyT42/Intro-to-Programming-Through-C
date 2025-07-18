#include "list_t.h"
#include <stdio.h>

int main(void) {
  puts("-------------------------------------------------------------------\n");
  puts("\tWelcome to List Program.\n");
  puts("-------------------------------------------------------------------\n");

  puts("-----------------------------------------------------");
  puts("\t\tCreating the List.");
  puts("-----------------------------------------------------\n");

  list_t *list = create_list();
  if (!list)
    return EXIT_FAILURE;
  printf("List length = %zu\n", list->length);

  puts("-----------------------------------------------------");
  puts("\t\tFilling the List.");
  puts("-----------------------------------------------------\n");

  put(list, 1);
  put(list, 2);
  put(list, 3);
  put(list, 4);
  put(list, 5);
  put(list, 6);
  put(list, 7);
  put(list, 8);
  put(list, 9);

  printf("List length = %zu\n", list->length);
  for (int i = 0; i < list->length; i++) {
    printf("item at %d = %d\n", i, list->data[i]);
  }

  put(list, 10);
  printf("List length = %zu\n", list->length);
  for (int i = 0; i < list->length; i++) {
    printf("item at %d = %d\n", i, list->data[i]);
  }
  shrink_to_fit(list);

  puts("-----------------------------------------------------");
  puts("\t\tFirst Reallocation.");
  puts("-----------------------------------------------------\n");
  put(list, 11);
  printf("List length = %zu\n", list->length);
  for (int i = 0; i < list->length; i++) {
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

  puts("-----------------------------------------------------");
  puts("\t\tSecond Reallocation.");
  puts("-----------------------------------------------------\n");

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

  puts("-----------------------------------------------------");
  puts("\t\tThird Reallocation.");
  puts("-----------------------------------------------------\n");

  put(list, 31);
  put(list, 32);
  put(list, 33);

  printf("List length = %zu\n", list->length);
  for (int i = 0; i < list->length; i++) {
    printf("item at %d = %d\n", i, list->data[i]);
  }

  puts("-----------------------------------------------------");
  puts("\t\tRemoving and Shrinking.");
  puts("-----------------------------------------------------\n");

  const int popped = pop(list);
  printf("Popped = %d\n", popped);
  pop(list);
  pop(list);
  shrink_to_fit(list);

  puts("-----------------------------------------------------");
  puts("\t\tDestroying.");
  puts("-----------------------------------------------------\n");

  printf("list address before destruction = %p\n", list);
  list = destroy(list);
  printf("list address after destruction = %p\n", list);

  printf("-----------------------------------------------------------------\n");
  printf("\t\tThank you, come again.\n");
  printf("-----------------------------------------------------------------\n");

  return EXIT_SUCCESS;
}
