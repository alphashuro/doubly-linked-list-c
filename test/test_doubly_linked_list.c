#include "../doubly_linked_list/doubly_linked_list.h"
#include "../unity/src/unity.h"

void test_dll(DoublyLinkedList *list, char *values[], size_t nodes) {
  if (nodes == 0) {
    TEST_ASSERT_NULL(list->first);
    TEST_ASSERT_NULL(list->last);
    return;
  }

  TEST_ASSERT_NOT_NULL(list->first);
  TEST_ASSERT_NOT_NULL(list->last);
  TEST_ASSERT_NULL(list->first->prev);
  TEST_ASSERT_NULL(list->last->next);

  if (nodes == 1) {
    TEST_ASSERT_EQUAL(list->first, list->last);
  } else {
    int count = 0;
    Node *node = list->first;

    for (node = list->first, count = 0; count < nodes;
         count++, node = node->next) {
      TEST_ASSERT_EQUAL_STRING(values[count], node->value);
    }
  }
}

void test_newList(void) {
  DoublyLinkedList *list = dll_newList();

  TEST_ASSERT_EQUAL_INT(0, dll_length(list));
  TEST_ASSERT_NULL(list->first);
  TEST_ASSERT_NULL(list->last);
}

void test_newNode(void) {
  Node *node = dll_newNode("value");

  TEST_ASSERT_EQUAL_STRING("value", node->value);
  TEST_ASSERT_NULL(node->next);
  TEST_ASSERT_NULL(node->prev);
}

void test_length(void) {
  DoublyLinkedList *list = dll_newList();

  TEST_ASSERT_EQUAL_INT(0, dll_length(list));

  list->first = dll_newNode("one");
  list->last = list->first;

  TEST_ASSERT_EQUAL_INT(1, dll_length(list));

  list->last->next = dll_newNode("two");
  list->last = list->last->next;

  TEST_ASSERT_EQUAL_INT(2, dll_length(list));

  list->last->next = dll_newNode("three");
  list->last = list->last->next;

  TEST_ASSERT_EQUAL_INT(3, dll_length(list));
}

void test_append(void) {
  DoublyLinkedList *list = dll_newList();

  dll_append(list, "one");

  char *expected_values_1[] = {"one"};
  test_dll(list, expected_values_1, 1);

  dll_append(list, "two");
  dll_append(list, "three");

  char *expected_values_2[] = {"one", "two", "three"};
  test_dll(list, expected_values_2, 3);
}

void test_prepend(void) {
  DoublyLinkedList *list = dll_newList();

  dll_prepend(list, "three");

  char *expected_values_1[] = {"three"};
  test_dll(list, expected_values_1, 1);

  dll_prepend(list, "two");
  dll_prepend(list, "one");

  char *expected_values_2[] = {"one", "two", "three"};
  test_dll(list, expected_values_2, 3);
}

void test_insert(void) {
  DoublyLinkedList *list = dll_newList();

  dll_insert(list, 0, "one");

  char *expected_values_1[] = {"one"};
  test_dll(list, expected_values_1, 1);

  dll_insert(list, 1, "three");
  dll_insert(list, 1, "two");

  char *expected_values_2[] = {"one", "two", "three"};
  test_dll(list, expected_values_2, 3);
}

void test_find(void) {
  DoublyLinkedList *list = dll_newList();

  dll_append(list, "one");
  dll_append(list, "two");
  dll_append(list, "three");
  dll_append(list, "four");

  Node *found = dll_find(list, "two");

  TEST_ASSERT_EQUAL(list->first->next, found);
}

void test_get(void) {
  DoublyLinkedList *list = dll_newList();

  dll_append(list, "one");
  dll_append(list, "two");
  dll_append(list, "three");
  dll_append(list, "four");

  Node *got_1 = dll_get(list, 2);
  TEST_ASSERT_EQUAL(list->first->next->next, got_1);

  Node *got_2 = dll_get(list, -1);
  TEST_ASSERT_EQUAL(list->last, got_2);

  Node *got_3 = dll_get(list, -2);
  TEST_ASSERT_EQUAL(list->last->prev, got_3);
}

void test_remove_at(void) {
  DoublyLinkedList *list = dll_newList();

  dll_append(list, "one");
  dll_append(list, "two");
  dll_append(list, "three");
  dll_append(list, "four");

  dll_remove_at(list, 2);

  char *expected_values_1[] = {"one", "two", "four"};
  test_dll(list, expected_values_1, 3);

  dll_remove_at(list, 0);
  char *expected_values_2[] = {"two", "four"};
  test_dll(list, expected_values_2, 2);

  dll_append(list, "five");
  dll_append(list, "six");

  dll_remove_at(list, -1);
  char *expected_values_3[] = {"two", "four", "five"};
  test_dll(list, expected_values_3, 3);
}

void test_toString(void) {
  DoublyLinkedList *list = dll_newList();

  dll_append(list, "one");
  dll_append(list, "two");
  dll_append(list, "three");
  dll_append(list, "four");

  char *actual = dll_toString(list);

  TEST_ASSERT_EQUAL_STRING("one, two, three, four", actual);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_newList);
  RUN_TEST(test_newNode);
  RUN_TEST(test_length);
  RUN_TEST(test_append);
  RUN_TEST(test_prepend);
  RUN_TEST(test_insert);
  RUN_TEST(test_find);
  RUN_TEST(test_get);
  RUN_TEST(test_remove_at);
  RUN_TEST(test_toString);

  return UNITY_END();
}

void setUp(void){};
void tearDown(void){};
