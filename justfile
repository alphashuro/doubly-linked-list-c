build:
  gcc main.c ./doubly_linked_list/*.c -o build/main -Wall

build-test:
  gcc ./doubly_linked_list/*.c test/*.c ./unity/src/unity.c -o build/test_doubly_linked_list -Wall

test: build-test
  ./build/test_doubly_linked_list

run: build
  ./build/main
