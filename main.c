#include "doubly_linked_list/doubly_linked_list.h"
#include <stdio.h>

int main() {
  DoublyLinkedList *list = dll_newList();

  dll_append(list, "second");
  dll_append(list, "third");
  dll_append(list, "fourth");
  dll_prepend(list, "first");
  dll_prepend(list, "SOMETHING");
  dll_append(list, "SOMETHING");
  dll_insert(list, 3, "another thing");

  printf("%s\n", dll_toString(list));

  dll_remove_at(list, 0);

  printf("%s\n", dll_toString(list));

  dll_remove_at(list, -1);

  printf("%s\n", dll_toString(list));

  Node *item = dll_get(list, 2);

  printf("%s\n", item->value);

  return 0;
}
