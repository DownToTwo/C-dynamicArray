/*! TODO: Make TODO
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector.h"

Iterator begin(const Vector *iter) { return &iter->elements[0]; }
void next(Iterator *iter) { ++(*iter); }
Iterator end(const Vector *iter) { return (iter->elements + iter->size); }
bool isVectorValid(const Vector *vec) {
  return vec != NULL && vec->elements != NULL;

  // return vec != NULL ? (vec->elements != NULL ? true : false) : false;
}
Vector DynamicArray(size_t capacity) {

  Vector ret;
  capacity = capacity == 0 ? 1 : capacity; // its nessecary? yes
  ret.elements = malloc(capacity * sizeof(*ret.elements));
  if (!ret.elements) {
    perror("Malloc");
    exit(EXIT_FAILURE);
  }
  ret.size = 0;
  ret.capacity = capacity;
  memset(ret.elements, 0, capacity * sizeof(*ret.elements));

  return ret;
}

void resize(Vector *vector) {
  if (vector == NULL) {
    return;
  }
  element *temp =
      (element *)realloc(vector->elements, vector->capacity * GROWFACTOR *
                                               sizeof(*vector->elements));
  if (!temp) {
    free(temp);
    perror("Realloc");
    exit(EXIT_FAILURE);
  }
  vector->capacity = vector->capacity * GROWFACTOR;
  vector->elements = temp;
}

void DynamicArrayDectructor(Vector *vector) {
  if (vector != NULL) {
    free(vector->elements);
    vector->elements = NULL;
  }
}
element at(Vector *vector, size_t idx) {
  if (!isVectorValid(vector)) {
    printf("Vector NULL\n");
    exit(EXIT_FAILURE);
  }
  if (idx < vector->size) {
    return vector->elements[idx];
  }
  printf("Out Of Range\nindex:%zu vector->size:%zu\n", idx, vector->size);
  DynamicArrayDectructor(vector);
  exit(EXIT_FAILURE);
}
void set(Vector *vector, size_t idx, element number) {
  if (!isVectorValid(vector)) {
    printf("Vector NULL\n");
    exit(EXIT_FAILURE);
  }

  if (idx < vector->size) {
    memcpy(&vector->elements[idx], &number, sizeof(element));
  }
  printf("Out Of Range\nindex:%zu vector->size:%zu\n", idx, vector->size);
  DynamicArrayDectructor(vector);
  exit(EXIT_FAILURE);
}
void pushback(Vector *vector, element elem) {
  if (vector->size == vector->capacity) {
    resize(vector);
  }
  if (!isVectorValid(vector)) {
    printf("Vector NULL\n");
    exit(EXIT_FAILURE);
  }
  memcpy(&vector->elements[vector->size], &elem, sizeof(element));
  // vector->elements[vector->size] = elem;
  vector->size++;
}
element popback(Vector *vector) {
  if (!isVectorValid(vector)) {
    printf("Vector NULL\n");
    exit(EXIT_FAILURE);
  }
  if (vector->size == 0) {
    printf("Vector size = 0\nexiting\n");
    exit(EXIT_FAILURE);
  }

  return vector->elements[--vector->size];
}
void removeAt(Vector *vector, size_t index) {
  if (!isVectorValid(vector)) {
    printf("Vector NULL\n");
    exit(EXIT_FAILURE);
  }

  memmove(&vector->elements[index], &vector->elements[index + 1],
          (vector->size - index - 1) * sizeof(element)); // WTF?!
  vector->size--;
}
