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

#include "../object_metadata/object_metadata.h"
#include "../std/stdbool.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Mdc_VectorMetadata {
  const struct Mdc_ObjectMetadata* element_metadata;
};

struct Mdc_Vector {
  const struct Mdc_VectorMetadata* metadata;

  void* elements;
  size_t count;
  size_t capacity;
};

/**
 * Initializes the vector.
 *
 * @param[out] vector this vector
 * @param[in] metadata the vector metadata
 * @return this vector if successful, otherwise NULL
 */
DLLEXPORT struct Mdc_Vector* Mdc_Vector_InitEmpty(
    struct Mdc_Vector* vector,
    const struct Mdc_VectorMetadata* metadata
);

/**
 * Initializes the destination vector by copying the source vector.
 *
 * @param[out] dest destination vector
 * @param[in] src source vector
 * @return dest if successful, otherwise NULL
 */
DLLEXPORT struct Mdc_Vector* Mdc_Vector_InitCopy(
    struct Mdc_Vector* dest,
    const struct Mdc_Vector* src
);

/**
 * Initializes the destination vector by moving the source vector.
 *
 * @param[out] dest destination vector
 * @param[in] src source vector
 * @return dest if successful, otherwise NULL
 */
DLLEXPORT struct Mdc_Vector* Mdc_Vector_InitMove(
    struct Mdc_Vector* dest,
    struct Mdc_Vector* src
);

/**
 * Deinitializes the vector.
 *
 * @param[in, out] vector this vector
 */
DLLEXPORT void Mdc_Vector_Deinit(struct Mdc_Vector* vector);

/**
 * Returns the pointer to the element at the specified position. No
 * bounds checking is performed.
 *
 * @param[in] vector this vector
 * @param[in] pos the position of the element
 * @return the pointer to the element at the specified position
 */
DLLEXPORT void* Mdc_Vector_Access(struct Mdc_Vector* vector, size_t pos);

/**
 * Returns the pointer to the element at the specified position. No
 * bounds checking is performed.
 *
 * @param[in] vector this vector
 * @param[in] pos the position of the element
 * @return the pointer to the element at the specified position
 */
DLLEXPORT const void* Mdc_Vector_AccessConst(
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
DLLEXPORT void* Mdc_Vector_At(struct Mdc_Vector* vector, size_t pos);

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
DLLEXPORT const void* Mdc_Vector_AtConst(
    const struct Mdc_Vector* vector,
    size_t pos
);

/**
 * Returns the pointer to the last element in the vector.
 *
 * @param[in] vector this vector
 * @return the pointer to the last element in the vector
 */
DLLEXPORT void* Mdc_Vector_Back(struct Mdc_Vector* vector);

/**
 * Returns the pointer to the last element in the vector.
 *
 * @param[in] vector this vector
 * @return the pointer to the last element in the vector
 */
DLLEXPORT const void* Mdc_Vector_BackConst(const struct Mdc_Vector* vector);

/**
 * Returns the number of allocated spaces for elements in the vector.
 *
 * @param[in] vector this vector
 * @return the number of allocated spaces in the vector
 */
DLLEXPORT size_t Mdc_Vector_Capacity(const struct Mdc_Vector* vector);

/**
 * Removes all elements from the vector. Invalidates pointers
 * and interators to elements.
 *
 * @param[in, out] vector this vector
 */
DLLEXPORT void Mdc_Vector_Clear(struct Mdc_Vector* vector);

/**
 * Returns the pointer to the array of contiguous elements that is
 * managed by this vector.
 *
 * @param[in] vector this vector
 * @return the pointer to the array managed by this vector
 */
DLLEXPORT void* Mdc_Vector_Data(struct Mdc_Vector* vector);

/**
 * Returns the pointer to the array of contiguous elements that is
 * managed by this vector.
 *
 * @param[in] vector this vector
 * @return the pointer to the array managed by this vector
 */
DLLEXPORT const void* Mdc_Vector_DataConst(const struct Mdc_Vector* vector);

/**
 * Returns whether the map contains any key-mappings.
 *
 * @param[in] vector this vector
 * @return true if the vector contains at least one element, otherwise false
 */
DLLEXPORT bool Mdc_Vector_Empty(const struct Mdc_Vector* vector);

/**
 * Returns the pointer to the first element in the vector.
 *
 * @param[in] vector this vector
 * @return the pointer to the first element in the vector
 */
DLLEXPORT void* Mdc_Vector_Front(struct Mdc_Vector* vector);

/**
 * Returns the pointer to the first element in the vector.
 *
 * @param[in] vector this vector
 * @return the pointer to the first element in the vector
 */
DLLEXPORT const void* Mdc_Vector_FrontConst(const struct Mdc_Vector* vector);

/**
 * Removes the last element in the vector. If the vector is empty,
 * then there is undefined behavior. Iterators and references to the
 * last element are invalidated.
 *
 * @param[in] vector this vector
 */
DLLEXPORT void Mdc_Vector_PopBack(struct Mdc_Vector* vector);

/**
 * Appends the value to the end of the vector via move-assignment. The
 * end iterator is invalidated. If the new size is greater than
 * capacity, then all iterators are invalidated.
 *
 * @param[in, out] vector this vector
 * @param[in] value the value to append
 */
DLLEXPORT void Mdc_Vector_PushBack(struct Mdc_Vector* vector, void* value);

/**
 * Appends the value to the end of the vector via copy-assignment. The
 * end iterator is invalidated. If the new size is greater than
 * capacity, then all iterators are invalidated.
 *
 * @param[in] vector this vector
 * @param[in] value the value append
 */
DLLEXPORT void Mdc_Vector_PushBackCopy(
    struct Mdc_Vector* vector,
    const void* value
);

/**
 * Resizes the vector to contain a new count of elements. If the new
 * count is greater, then multiple copies of the specified value are
 * appended. If the new count is less, then any additional elements
 * are removed from the vector.
 *
 * @param[in] vector this vector
 * @param[in] count the new count of elements
 * @param[in] value the value to copy into the vector if appended
 */
DLLEXPORT void Mdc_Vector_Resize(
    struct Mdc_Vector* vector,
    size_t count,
    const void* value
);

/**
 * Increases the capacity of this vector. If the vector's capacity is
 * larger than or equal to the specified new capacity, then the
 * function does nothing.
 *
 * @param[in] vector this vector
 * @param[in] new_capacity the desired new capacity for this vector
 */
DLLEXPORT void Mdc_Vector_Reserve(
    struct Mdc_Vector* vector,
    size_t new_capacity
);

/**
 * Requests for the vector's element capacity to shrink down to the
 * vector's element count.
 *
 * @param[in] vector this vector
 */
DLLEXPORT void Mdc_Vector_ShrinkToFit(struct Mdc_Vector* vector);

/**
 * Returns the number of elements in the vector.
 *
 * @param[in] vector this vector
 * @return the number of elements in the vector
 */
DLLEXPORT size_t Mdc_Vector_Size(const struct Mdc_Vector* vector);

/**
 * Swaps the contents of two vectors.
 *
 * @param[in, out] vector1 first vector
 * @param[in, out] vector2 second vector
 */
DLLEXPORT void Mdc_Vector_Swap(
    struct Mdc_Vector* vector1,
    struct Mdc_Vector* vector2
);

/**
 * Compares two vector metadatas and returns whether they are equal.
 *
 * @param[in] metadata1 the first metadata to compare
 * @param[in] metadata2 the second metadata to compare
 */
DLLEXPORT bool Mdc_VectorMetadata_Equal(
    struct Mdc_VectorMetadata* metadata1,
    struct Mdc_VectorMetadata* metadata2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_CONTAINER_VECTOR_H_ */
