#include "vector.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
inline static int randRange(int from, int to) {
  srand(time(NULL));
  return (rand() % (to + 1 - from) + from);
}
void test_DynamicArray(void) {
  Vector v = DynamicArray(10);
  assert(v.size == 0);
  assert(v.capacity == 10);
  DynamicArrayDectructor(&v);
}

void test_resize(void) {
  size_t a;
  Vector v = DynamicArray(10);
  resize(&v);
  assert(v.capacity == 20);
  DynamicArrayDectructor(&v);
}

void test_at(void) {
  Vector v = DynamicArray(10);
  for (int i = 0; i < 10; i++) {
    pushback(&v, i);
  }
  for (int i = 0; i < 10; i++) {
    assert(at(&v, i) == i);
  }

  DynamicArrayDectructor(&v);
}

void test_pushback(void) {
  Vector v = DynamicArray(10);
  for (int i = 0; i < 15; i++) {
    pushback(&v, i);
  }
  assert(v.size == 15);
  assert(v.capacity == 20);
  DynamicArrayDectructor(&v);
}

void test_popback(void) {
  Vector v = DynamicArray(10);
  for (int i = 0; i < 10; i++) {
    pushback(&v, i);
  }
  for (int i = 0; i < 5; i++) {
    assert(popback(&v) == 9 - i);
  }
  assert(v.size == 5);
  DynamicArrayDectructor(&v);
}

void test_DynamicArrayDectructor(void) {
  Vector v = DynamicArray(10);
  DynamicArrayDectructor(&v);
  assert(v.elements == NULL);
}
void test_removeAt(void) {
  srand(time(NULL));
  Vector v = DynamicArray(6);
  for (int i = 0; i < v.capacity; ++i) {
    pushback(&v, i);
  }
  removeAt(&v, 5);
  VECTOR_FOREACH(&v, it) { printf("%d ", *it); }
  putchar('\n');
  for (size_t i = 0; i < v.capacity; ++i) {
    printf("%zu\t%zu\n", i, v.size);
    VECTOR_FOREACH(&v, it) { printf("%d ", *it); }
    putchar('\n');
    removeAt(&v, 0);
  }
  removeAt(&v, 0);

  printf("%zu\n", v.size);
  assert(v.size == 0);
  DynamicArrayDectructor(&v);
}
int main(void) {
  printf("test_DynamicArray()\n");
  test_DynamicArray();
  printf("test_resize()\n");

  test_resize();
  printf("test_at()\n");

  test_at();
  printf("test_pushback()\n");

  test_pushback();
  printf("test_popback()\n");

  test_popback();
  printf("test_DynamicArrayDectructor()\n");

  test_DynamicArrayDectructor();
  printf("test_removeAt()\n");
  test_removeAt();
  return 0;
}
