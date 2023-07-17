#include "doubly_linked_list.h"
#include "node.h"
#include <stdlib.h>
#include <string.h>

DoublyLinkedList *dll_newList() {
  DoublyLinkedList *list =
      (DoublyLinkedList *)calloc(1, sizeof(DoublyLinkedList));

  return list;
}

int dll_insert(DoublyLinkedList *list, int index, char *value) {
  int list_length = dll_length(list);

  if (index != 0 && (abs(index) > list_length)) {
    return 0;
  }

  if (index == 0) {
    dll_prepend(list, value);
    return 1;
  }

  if (index == list_length) {
    dll_append(list, value);
    return 1;
  }

  Node *new = dll_newNode(value);
  Node *current = list->first;

  for (; index > 0; index--) {
    current = current->next;
  };

  dll_add_before(current, new);
  return 1;
}

/**
 * Inserts a new node at the start of the list
 */
int dll_prepend(DoublyLinkedList *list, char *value) {
  Node *new = dll_newNode(value);

  if (list->first == NULL) {
    list->first = new;
    list->last = new;
  } else {
    dll_add_before(list->first, new);
    list->first = new;
  }

  return 1;
}

/**
 * Inserts a new node at the end of the list
 */
int dll_append(DoublyLinkedList *list, char *value) {
  Node *new = dll_newNode(value);

  if (list->first == NULL) {
    list->first = new;
    list->last = new;
  } else {
    dll_add_after(list->last, new);
    list->last = new;
  }

  return 1;
};

Node *dll_find(DoublyLinkedList *list, char *value) {
  Node *current = list->first;

  while (current != NULL) {
    if (strcmp(current->value, value) == 0) {
      return current;
    } else {
      current = current->next;
    }
  }

  return NULL;
}

Node *dll_get(DoublyLinkedList *list, int index) {
  if (abs(index) > dll_length(list)) {
    return NULL;
  }

  Node *current;

  if (index >= 0) {
    current = list->first;

    for (; index > 0; index--) {
      current = current->next;
    };
  } else {
    current = list->last;

    for (; index < -1; index++) {
      current = current->prev;
    }
  }

  return current;
}

void dll_remove_at(DoublyLinkedList *list, int index) {
  int len = dll_length(list);

  if (abs(index) >= len) {
    return;
  }

  Node *node = dll_get(list, index);

  if (index == 0 || index == -len) {
    list->first = node->next;
  }

  if (index == len - 1 || index == -1) {
    list->last = node->prev;
  }

  dll_remove_node(node);
}

int dll_length(DoublyLinkedList *list) {
  if (list->first == NULL) {
    return 0;
  };

  int count = 1;

  for (Node *current = list->first; current->next != NULL;
       current = current->next) {
    count++;
  }

  return count;
};

char *dll_toString(DoublyLinkedList *list) {
  if (list->first == NULL) {
    return "";
  }

  char *string = calloc(1, sizeof(char *));

  for (Node *current = list->first; current != NULL; current = current->next) {
    string = realloc(string, (strlen(string) + strlen(current->value) + 2));

    if (current->prev) {
      strcat(string, ", ");
    }

    strcat(string, current->value);
  }

  return string;
}
