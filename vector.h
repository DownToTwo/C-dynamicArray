/* This file was automatically generated.  Do not edit! */
#ifndef _VECTOR_
#define _VECTOR_
#include <stdbool.h>
#include <stddef.h>
typedef int element;
#define VECTOR_FOREACH(vec, i)                                                 \
  for (Iterator i = begin((vec)), en = end((vec)); (i) != en; next(&(i)))

typedef struct vector {
  element *elements;
  size_t size;
  size_t capacity;
} Vector;
#define GROWFACTOR (2)
typedef element *Iterator;
void removeAt(Vector *vector, size_t index);
element popback(Vector *vector);
void pushback(Vector *vector, element elem);
void set(Vector *vector, size_t idx, element number);
element at(Vector *vector, size_t idx);
void DynamicArrayDectructor(Vector *vector);
void resize(Vector *vector);
Vector DynamicArray(size_t capacity);
bool isVectorValid(const Vector *vec);
Iterator end(const Vector *iter);
void next(Iterator *iter);
Iterator begin(const Vector *iter);
#endif
