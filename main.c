/*! TODO: Make TODO
 *
 */
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {

  const size_t size = 12;
  Vector svector = DynamicArray(size);

  Vector *vector = &svector;
  for (int i = 0; i < vector->capacity; i++) {
    pushback(vector, i + (i % 3));
  }
  printf("%d\n", isVectorValid(vector));
  printf("%d\n", isVectorValid((Vector *){NULL, 1, 1}));
  printf("%d\n", isVectorValid(NULL));

  int i = 0;

  VECTOR_FOREACH(vector, it) {
    printf("[%i]=%d\n", i, *it);
    i++;
  }
  putchar('\n');
  removeAt(vector, 11);
  i = 0;

  VECTOR_FOREACH(vector, it) {
    printf("%d\n", at(vector, i));
    i++;
  }
  for (int i = 0; i < vector->size; ++i) {
    at(vector, i);
  }
  resize(vector);
  Vector a = (Vector){.elements = NULL};
  DynamicArrayDectructor(&a);
  DynamicArrayDectructor(vector);

  return 0;
}
