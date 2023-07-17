#include "doubly_linked_list.h"

int main() {
  DoublyLinkedList* list = dll_newList();

  append(list, "second");
  append(list, "third");
  append(list, "fourth");
  prepend(list, "first");
  prepend(list, "SOMETHING");
  append(list, "SOMETHING");

  print(list);

  remove_head(list);

  print(list);

  remove_tail(list);

  print(list);

  return 0;
}
