/**
 * Mir Drualga Common For C
 * Copyright (C) 2020  Mir Drualga
 *
 * This file is part of Mir Drualga Common For C.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Additional permissions under GNU Affero General Public License version 3
 *  section 7
 *
 *  If you modify this Program, or any covered work, by linking or combining
 *  it with any program (or a modified version of that program and its
 *  libraries), containing parts covered by the terms of an incompatible
 *  license, the licensors of this Program grant you additional permission
 *  to convey the resulting work.
 */

#ifndef MDC_C_CONTAINER_VECTOR_H_
#define MDC_C_CONTAINER_VECTOR_H_

#include <stddef.h>

#include "../std/stdbool.h"

struct Mdc_VectorElementSize {
  size_t size;
};

struct Mdc_VectorElementFunctions {
  /**
   * Initializes the destination object by copying the source object.
   */
  void* (*init_copy)(void* dest, const void* src);

  /**
   * Initializes the destination object by moving the source object.
   */
  void* (*init_move)(void* dest, void* src);

  /**
   * Deinitializes the specified object.
   */
  void (*deinit)(void* obj);

  /**
   * Compares two objects. Returns 0 if they are the same, a negative
   * value if the first object is "less" than the second object, and a
   * positive value if the first object is "greater" than the second
   * object.
   */
  int (*compare)(const void*, const void*);
};

struct Mdc_VectorMetadata {
  struct Mdc_VectorElementSize size;
  struct Mdc_VectorElementFunctions functions;
};

struct Mdc_Vector {
  struct Mdc_VectorMetadata* metadata;

  void* elements;
  size_t count;
  size_t capacity;
};

const struct Mdc_Vector MDC_VECTOR_UNINIT;

/**
 * Initializes the vector.
 *
 * @param[out] vector this vector
 * @param[in] metadata the vector metadata
 * @return this vector if successful, otherwise NULL
 */
struct Mdc_Vector* Mdc_Vector_Init(
    struct Mdc_Vector* vector,
    const struct Mdc_VectorMetadata* metadata
);

/**
 * Initializes the destination vector by copying the source vector.
 *
 * @param[out] dest destination pair
 * @param[in] src source pair
 * @return dest if successful, otherwise NULL
 */
struct Mdc_Vector* Mdc_Vector_InitCopy(
    struct Mdc_Vector* dest,
    const struct Mdc_Vector* src
);

/**
 * Initializes the destination vector by moving the source vector.
 *
 * @param[out] dest destination pair
 * @param[in] src source pair
 * @return dest if successful, otherwise NULL
 */
struct Mdc_Vector* Mdc_Vector_InitMove(
    struct Mdc_Vector* dest,
    struct Mdc_Vector* src
);

/**
 * Deinitializes the vector.
 *
 * @param[in, out] vector this vector
 */
void Mdc_Vector_Deinit(struct Mdc_Vector* vector);

/**
 * Returns the pointer to the element at the specified position. No
 * bounds checking is performed.
 *
 * @param[in] vector this vector
 * @param[in] pos the position of the element
 * @return the pointer to the element at the specified position
 */
void* Mdc_Vector_Access(struct Mdc_Vector* vector, size_t pos);

/**
 * Returns the pointer to the element at the specified position. No
 * bounds checking is performed.
 *
 * @param[in] vector this vector
 * @param[in] pos the position of the element
 * @return the pointer to the element at the specified position
 */
const void* Mdc_Vector_AccessConst(
    const struct Mdc_Vector* vector,
    size_t pos
);

/**
 * Returns the pointer to the element at the specified position. If an
 * out-of-bounds position is specified, then the null pointer is
 * returned.
 *
 * @param[in] vector this vector
 * @param[in] pos the position of the element
 * @return the pointer to the element at the specified position,
 *    otherwise NULL
 */
void* Mdc_Vector_At(struct Mdc_Vector* vector, size_t pos);

/**
 * Returns the pointer to the element at the specified position. If an
 * out-of-bounds position is specified, then the null pointer is
 * returned.
 *
 * @param[in] vector this vector
 * @param[in] pos the position of the element
 * @return the pointer to the element at the specified position,
 *    otherwise NULL
 */
const void* Mdc_Vector_AtConst(const struct Mdc_Vector* vector, size_t pos);

/**
 * Returns the pointer to the last element in the vector.
 *
 * @param[in] vector this vector
 * @return the last element in the vector
 */
void* Mdc_Vector_Back(struct Mdc_Vector* vector);

/**
 * Returns the pointer to the last element in the vector.
 *
 * @param[in] vector this vector
 * @return the last element in the vector
 */
const void* Mdc_Vector_BackConst(const struct Mdc_Vector* vector);

/**
 * Returns the number of allocated spaces for elements in the vector.
 *
 * @param[in] vector this vector
 * @return the number of allocated spaces in the vector
 */
size_t Mdc_Vector_Capacity(const struct Mdc_Vector* vector);

/**
 * Removes all elements from the vector. Invalidates pointers
 * and interators to elements.
 *
 * @param[in, out] vector this vector
 */
void Mdc_Vector_Clear(struct Mdc_Vector* vector);

/**
 * Returns whether the map contains any key-mappings.
 *
 * @param[in] vector this vector
 * @return true if the vector contains at least one element, otherwise false
 */
bool Mdc_Vector_Empty(const struct Mdc_Vector* vector);

/**
 * Returns the pointer to the first element in the vector.
 *
 * @param[in] vector this vector
 * @return the first element in the vector
 */
void* Mdc_Vector_Front(struct Mdc_Vector* vector);

/**
 * Returns the pointer to the first element in the vector.
 *
 * @param[in] vector this vector
 * @return the first element in the vector
 */
const void* Mdc_Vector_FrontConst(const struct Mdc_Vector* vector);

/**
 * Increases the capacity of this vector. If the vector's capacity is
 * larger than the specified new capacity, then the function does
 * nothing.
 *
 * @param[in] vector this vector
 * @param[in] new_capacity the desired new capacity for this vector
 */
void Mdc_Vector_Reserve(struct Mdc_Vector* vector, size_t new_capacity);

/**
 * Returns the number of elements in the vector.
 *
 * @param[in] vector this vector
 * @return the number of elements in the vector
 */
size_t Mdc_Vector_Size(const struct Mdc_Vector* vector);

/**
 * Swaps the contents of two vectors.
 *
 * @param[in, out] vector1 first vector
 * @param[in, out] vector2 second vector
 */
void Mdc_Vector_Swap(struct Mdc_Vector* vector1, struct Mdc_Vector* vector2);

/**
 * Compares two vector metadatas and returns whether they are equal.
 *
 * @param[in] metadata1 the first metadata to compare
 * @param[in] metadata2 the second metadata to compare
 */
bool Mdc_VectorMetadata_Equal(
    struct Mdc_VectorMetadata* metadata1,
    struct Mdc_VectorMetadata* metadata2
);

#endif /* MDC_C_CONTAINER_VECTOR_H_ */
