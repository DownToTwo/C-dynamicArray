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
    pushback(vector, i);
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
  i = 0;
  removeAt(NULL, 1);
  removeAt(vector, 12);
  printf("size=%zu\n", vector->size);

  removeAt(vector, 4);
  printf("size=%zu\n", vector->size);

  VECTOR_FOREACH(vector, it) {
    printf("[%i]=%d\n", i, *it);
    i++;
  }
  resize(vector);
  Vector a = (Vector){.elements = NULL};
  DynamicArrayDectructor(&a);
  DynamicArrayDectructor(vector);

  return 0;
}
