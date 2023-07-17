#include "node.h"
#include <stdlib.h>
#include <string.h>

Node *dll_newNode(char *value) {
  Node *new = (Node *)calloc(1, sizeof(Node));
  new->value = (char *)calloc(strlen(value), sizeof(char));

  strcpy(new->value, value);

  return new;
}

void dll_add_after(Node *n, Node *new) {
  Node *prev_next = n->next;

  n->next = new;
  new->prev = n;

  if (prev_next) {
    prev_next->prev = new;
    new->next = prev_next;
  }
}

void dll_add_before(Node *n, Node *new) {
  Node *prev_prev = n->prev;

  n->prev = new;
  new->next = n;

  if (prev_prev) {
    prev_prev->next = new;
    new->prev = prev_prev;
  }
}

void dll_remove_node(Node *n) {
  if (!n) {
    return;
  }

  Node *before = n->prev;
  Node *after = n->next;

  if (before) {
    before->next = after;
  }

  if (after) {
    after->prev = before;
  }

  free(n);
}
