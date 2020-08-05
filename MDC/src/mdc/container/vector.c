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

#include "../../../include/mdc/container/vector.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

enum FILE_SCOPE_CONSTANTS_01 {
  kInitialCapacity = 4
};

const struct Mdc_Vector MDC_VECTOR_UNINIT = { 0 };

/**
 * Static functions
 */

/**
 * Returns a pointer to the vector element located at the specified
 * index. Safe to use in init and deinit functions.
 *
 * @param[in] elements the contiguous array containing the elements
 * @param[in] element_size the size of each element
 * @param[in] index the position of the element
 */
static void* Mdc_UnVector_Access(
    void* elements,
    size_t element_size,
    size_t index
) {
  unsigned char* const elements_as_bytes = elements;
  const size_t bytes_index = index * element_size;

  return &elements_as_bytes[bytes_index];
}

/**
 * Returns a pointer to the vector element located at the specified
 * index. Safe to use in init and deinit functions.
 *
 * @param[in] elements the contiguous array containing the elements
 * @param[in] element_size the size of each element
 * @param[in] index the position of the element
 */
static const void* Mdc_UnVector_AccessConst(
    const void* elements,
    size_t element_size,
    size_t index
) {
  const unsigned char* const elements_as_bytes = elements;
  const size_t bytes_index = index * element_size;

  return &elements_as_bytes[bytes_index];
}

/**
 * Returns the bytes index for the specified vector and element
 * index.
 */
static size_t Mdc_Vector_ElementIndexToByteIndex(
    const struct Mdc_Vector* vector,
    size_t index
) {
  return index * vector->metadata->size.size;
}

/**
 * Removes the specified range of elements in the vector, frees the
 * memory used for the individual elements, sets the pointer to NULL.
 * Sets the size after reordering the elements.
 *
 * @param[in, out] map this map
 * @param[in] i_start start index
 * @param[in] i_end end index (non-inclusive)
 */
static void Mdc_Vector_DeinitIndexElements(
    struct Mdc_Vector* vector,
    size_t i_start,
    size_t i_end
) {
  const struct Mdc_VectorElementFunctions* const functions =
      &vector->metadata->functions;
  const size_t element_size = vector->metadata->size.size;

  const size_t d_start_end = i_end - i_start;

  size_t i;
  void* dest_element;
  void* src_element;

  for (i = i_start; i < i_end; i += 1) {
    functions->deinit(
        Mdc_UnVector_Access(vector->elements, element_size, i)
    );
  }

  for (; i < vector->count; i += 1) {
    dest_element = Mdc_UnVector_Access(
        vector->elements,
        element_size,
        i - d_start_end
    );

    src_element = Mdc_UnVector_Access(
        vector->elements,
        element_size,
        i
    );

    functions->init_move(dest_element, src_element);
  }

  vector->count -= d_start_end;
}

/**
 * Increases or decreases the capacity of this vector. If the vector's
 * elements count is larger than the new capacity, then the function
 * does nothing.
 */
static void Mdc_Vector_SetCapacity(
    struct Mdc_Vector* vector,
    size_t new_capacity
) {
  void* realloc_elements_result;
  size_t realloc_elements_size;

  if (new_capacity == vector->capacity) {
    return;
  }

  if (new_capacity < vector->count) {
    return;
  }

  realloc_elements_size = Mdc_Vector_ElementIndexToByteIndex(
      vector,
      new_capacity
  );

  realloc_elements_result = realloc(
      vector->elements,
      realloc_elements_size
  );

  vector->elements = realloc_elements_result;
  vector->capacity = new_capacity;
}

/**
 * Doubles the capacity when the elements count reaches the capacity,
 * and halves the capacity when the elements count reaches a quarter
 * of the capacity.
 */
static void Mdc_Vector_SetCapacityOnPolicy(
    struct Mdc_Vector* vector
) {
  assert(vector->count <= vector->capacity);

  while (vector->count == vector->capacity) {
    Mdc_Vector_SetCapacity(vector, vector->capacity * 2);
  }

  while (vector->count < vector->capacity / 4
      && vector->capacity > kInitialCapacity) {
    Mdc_Vector_SetCapacity(vector, vector->capacity / 2);
  }
}

/**
 * External functions
 */

struct Mdc_Vector* Mdc_Vector_Init(
    struct Mdc_Vector* vector,
    const struct Mdc_VectorMetadata* metadata
) {
  const struct Mdc_VectorElementFunctions* const element_functions =
      &metadata->functions;

  size_t elements_size;

  /* Copy the metadata. */
  vector->metadata = malloc(sizeof(*vector->metadata));

  if (vector->metadata == NULL) {
    goto return_bad;
  }

  *vector->metadata = *metadata;

  /* Initialize the elements. */
  elements_size = kInitialCapacity * sizeof(vector->metadata->size.size);
  vector->elements = malloc(elements_size);

  if (vector->elements == NULL) {
    goto free_metadata_copy;
  }

  vector->count = 0;
  vector->capacity = kInitialCapacity;

  return vector;

free_metadata_copy:
  free(vector->metadata);
  vector->metadata = NULL;

return_bad:
  return NULL;
}

struct Mdc_Vector* Mdc_Vector_InitCopy(
    struct Mdc_Vector* dest,
    const struct Mdc_Vector* src
) {
  const struct Mdc_VectorElementFunctions* const element_functions =
      &src->metadata->functions;

  size_t i;
  size_t elements_size;

  const void* init_element_copy;

  unsigned char* dest_elements_as_bytes;
  unsigned char* src_elements_as_bytes;
  size_t i_bytes;

  /* Copy the metadata. */
  dest->metadata = malloc(sizeof(*dest->metadata));

  if (dest->metadata == NULL) {
    goto return_bad;
  }

  *dest->metadata = *src->metadata;

  /* Copy the elements. */
  elements_size = src->capacity * sizeof(dest->metadata->size.size);
  dest->elements = malloc(elements_size);

  if (dest->elements == NULL) {
    goto free_metadata_copy;
  }

  dest->capacity = src->capacity;

  dest_elements_as_bytes = dest->elements;
  src_elements_as_bytes = src->elements;

  for (dest->count = 0; dest->count < src->count; dest->count += 1) {
    i_bytes = Mdc_Vector_ElementIndexToByteIndex(dest, dest->count);

    init_element_copy = element_functions->init_copy(
        &dest_elements_as_bytes[i_bytes],
        &src_elements_as_bytes[i_bytes]
    );

    if (init_element_copy != &dest_elements_as_bytes[i_bytes]) {
      goto deinit_elements;
    }
  }

  return dest;

deinit_elements:
  for (i = 0; i < dest->count; i += 1) {
    i_bytes = Mdc_Vector_ElementIndexToByteIndex(dest, i);
    element_functions->deinit(&dest_elements_as_bytes[i_bytes]);
  }

  dest->count = 0;

  free(dest->elements);
  dest->elements = NULL;
  dest->capacity = 0;

free_metadata_copy:
  free(dest->metadata);
  dest->metadata = NULL;

return_bad:
  return NULL;
}

struct Mdc_Vector* Mdc_Vector_InitMove(
    struct Mdc_Vector* dest,
    struct Mdc_Vector* src
) {
  dest->metadata = malloc(sizeof(*dest->metadata));

  if (dest->metadata == NULL) {
    goto return_bad;
  }

  *dest->metadata = *src->metadata;

  dest->elements = src->elements;
  src->elements = NULL;

  dest->count = src->count;
  src->count = 0;

  dest->capacity = src->capacity;
  src->capacity = 0;

  return dest;

return_bad:
  return NULL;
}

void Mdc_Vector_Deinit(struct Mdc_Vector* vector) {
  const struct Mdc_VectorElementFunctions* const element_functions =
      &vector->metadata->functions;
  unsigned char* const elements_as_bytes = vector->elements;

  size_t i;
  size_t i_bytes;

  for (i = 0; i < vector->count; i += 1) {
    i_bytes = Mdc_Vector_ElementIndexToByteIndex(vector, i);
    element_functions->deinit(&elements_as_bytes[i_bytes]);
  }

  vector->count = 0;

  free(vector->elements);
  vector->elements = NULL;

  vector->capacity = 0;

  free(vector->metadata);
  vector->metadata = NULL;
}

void* Mdc_Vector_At(struct Mdc_Vector* vector, size_t pos) {
  return (void*) Mdc_Vector_AtConst(vector, pos);
}

const void* Mdc_Vector_AtConst(const struct Mdc_Vector* vector, size_t pos) {
  const unsigned char* const elements_as_bytes = vector->elements;

  size_t i_bytes;

  if (pos < 0 || pos >= vector->count) {
    goto return_bad;
  }

  i_bytes = Mdc_Vector_ElementIndexToByteIndex(vector, pos);

  return &elements_as_bytes[i_bytes];

return_bad:
  return NULL;
}

void* Mdc_Vector_Back(struct Mdc_Vector* vector) {
  return (void*) Mdc_Vector_BackConst(vector);
}

const void* Mdc_Vector_BackConst(const struct Mdc_Vector* vector) {
  return Mdc_Vector_AtConst(vector, vector->count - 1);
}

size_t Mdc_Vector_Capacity(const struct Mdc_Vector* vector) {
  return vector->capacity;
}

void Mdc_Vector_Clear(struct Mdc_Vector* vector) {
  Mdc_Vector_DeinitIndexElements(vector, 0, vector->count);
}

bool Mdc_Vector_Empty(const struct Mdc_Vector* vector) {
  return (Mdc_Vector_Size(vector) == 0);
}

void* Mdc_Vector_Front(struct Mdc_Vector* vector) {
  return (void*) Mdc_Vector_FrontConst(vector);
}

const void* Mdc_Vector_FrontConst(const struct Mdc_Vector* vector) {
  return Mdc_Vector_AtConst(vector, 0);
}

size_t Mdc_Vector_Size(const struct Mdc_Vector* vector) {
  return vector->count;
}

void Mdc_Vector_Swap(struct Mdc_Vector* vector1, struct Mdc_Vector* vector2) {
  struct Mdc_Vector temp;

  temp = *vector1;
  *vector1 = *vector2;
  *vector2 = temp;
}

bool Mdc_VectorMetadata_Equal(
    struct Mdc_VectorMetadata* metadata1,
    struct Mdc_VectorMetadata* metadata2
) {
  int memcmp_result;

  if (metadata1 == metadata2) {
    return true;
  }

  memcmp_result = memcmp(metadata1, metadata2, sizeof(*metadata1));

  return (memcmp == 0);
}
