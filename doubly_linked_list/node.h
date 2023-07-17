#ifndef NODE_H_
#define NODE_H_

typedef struct Node {
  struct Node *prev;
  struct Node *next;
  char *value;
} Node;

Node *dll_newNode(char *value);
void dll_add_after(Node *n, Node *new);
void dll_add_before(Node *n, Node *new);
void dll_remove_node(Node *n);

#endif // NODE_H_
