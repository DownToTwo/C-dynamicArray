/*! TODO: Make TODO
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int element;
typedef struct vector {
  element *elements;
  size_t size;
  size_t capacity;
} Vector;
#define GROWFACTOR (2)
typedef element *Iterator;
Iterator begin(const Vector *iter) { return &iter->elements[0]; }
void next(Iterator *iter) { ++(*iter); }
Iterator end(const Vector *iter) { return (iter->elements + iter->size); }
#define VECTOR_FOREACH(vec, i)                                                 \
  for (Iterator(i) = begin((vec)), en = end((vec)); (i) != en; next(&(i)))

Vector DynamicArray(size_t capacity) {

  Vector ret;
  capacity = capacity == 0 ? 1 : capacity; // its nessecary? yes
  ret.elements = malloc(capacity * sizeof(*ret.elements));
  if (!ret.elements) {
    perror("Malloc");
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
  if (vector == NULL) {
    printf("Vector NULL\n");
    exit(EXIT_FAILURE);
  }
  if (idx <= vector->size) {
    return vector->elements[idx];
  }
  printf("Out Of Range\nindex:%zu vector->size:%zu\n", idx, vector->size);
  DynamicArrayDectructor(vector);
  exit(EXIT_FAILURE);
}
element get(Vector *vector, int idx) { return vector->elements[idx]; }
void set(Vector *vector, int idx, element number) {
  if (vector != NULL) {
    memcpy(&vector->elements[idx], &number, sizeof(element));
  }
}
void pushback(Vector *vector, element elem) {
  if (vector->size == vector->capacity) {
    resize(vector);
  }

  memcpy(&vector->elements[vector->size], &elem, sizeof(element));
  // vector->elements[vector->size] = elem;
  vector->size++;
}
element popback(Vector *vector) {
  if (vector->size == 0) {
    printf("Vector size = 0\nexiting\n");
    exit(EXIT_FAILURE);
  }

  return vector->elements[--vector->size];
}
void removeAt(Vector *vector, size_t index) {
  if (index >= vector->size) {
    printf("Index out of bounds\n");
    exit(EXIT_FAILURE);
  }
  memmove(vector->elements + index, vector->elements + index + 1,
          (vector->size - index - 1) * sizeof(element)); // WTF?!
  vector->size--;
}
int main(void) {

  const size_t size = 12;
  Vector svector = DynamicArray(size);

  Vector *vector = &svector;
  for (int i = 0; i < vector->capacity; i++) {
    pushback(vector, i + (i % 3));
  }
  int i = 0;

  VECTOR_FOREACH(vector, it) {
    printf("[%i]=%d\n", i, *it);
    i++;
  }
  putchar('\n');
  removeAt(vector, 11);
  i = 0;

  VECTOR_FOREACH(vector, it) {

    printf("[%i]=%i\n", i, *it);
    i++;
  }

  printf("%d\n", at(vector, 1));
  resize(vector);

  DynamicArrayDectructor(vector);

  return 0;
}
