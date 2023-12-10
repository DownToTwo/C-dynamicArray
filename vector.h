#ifndef _VECTOR_
#define _VECTOR_
#include <stdbool.h> //for bool type
#include <stddef.h>  //for size_t
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
// Remove element at index from vector
void removeAt(Vector *vector, size_t index);
// Return and remove last element
element popback(Vector *vector);
// Insert element at the end of the vector
void pushback(Vector *vector, element elem);
// Set element at index in vector
void set(Vector *vector, size_t idx, element elem);
// Get element from vector at index with bounds checking
element at(Vector *vector, size_t idx);
// Free up memory for vector
void DynamicArrayDectructor(Vector *vector);
// Resize vector by GROWFACTOR
void resize(Vector *vector);
// Allocate memory for `capacity` elements
Vector DynamicArray(size_t capacity);
// Check whether vector is valid
bool isVectorValid(const Vector *vec);
// Dummy Iterator implementation
Iterator end(const Vector *iter);
void next(Iterator *iter);
Iterator begin(const Vector *iter);
#endif
