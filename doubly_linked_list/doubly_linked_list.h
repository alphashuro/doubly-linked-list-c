#include "node.h"

typedef struct DoublyLinkedList {
  Node *first;
  Node *last;
} DoublyLinkedList;

DoublyLinkedList *dll_newList();

/**
 * Inserts a new node at the given index
 * Returns 1 if the insertion was successful
 * Otherwise returns 0
 */
int dll_insert(DoublyLinkedList *list, int index, char *value);

/**
 * Inserts a new node at the start of the list
 */
int dll_prepend(DoublyLinkedList *list, char *value);

/**
 * Inserts a new node at the end of the list
 */
int dll_append(DoublyLinkedList *list, char *value);

/**
 * Searches the list for a value
 * If it is found, returns the index
 * otherwise returns 0
 */
Node *dll_find(DoublyLinkedList *list, char *value);

/**
 * Removes the node at the given index
 */
void dll_remove_at(DoublyLinkedList *list, int index);

/**
 * Returns the number of items in the list
 */
int dll_length(DoublyLinkedList *list);

/**
 * Creates a printable string representation of the list
 */
char *dll_toString(DoublyLinkedList *list);

/**
 * Returns a pointer to the node at the given index
 */
Node *dll_get(DoublyLinkedList *list, int index);
