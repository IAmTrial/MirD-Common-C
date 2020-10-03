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

enum {
  kInitialCapacity = 4
};

/**
 * Static
 */

#define MDC_VECTOR_UNINIT { 0 }

const struct Mdc_Vector Mdc_Vector_kUninit = MDC_VECTOR_UNINIT;

/**
 * Returns the bytes index for the specified vector and element
 * index. Safe to use in init and deinit functions.
 *
 * @param[in] element_size the size of an element, in bytes
 * @param[in] index the index of the element in the vector
 */
static size_t Mdc_UnVector_ElementIndexToByteIndex(
    size_t element_size,
    size_t index
) {
  return element_size * index;
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
  size_t bytes_index;

  bytes_index = Mdc_UnVector_ElementIndexToByteIndex(element_size, index);

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
static void* Mdc_UnVector_Access(
    void* elements,
    size_t element_size,
    size_t index
) {
  return (void*) Mdc_UnVector_AccessConst(elements, element_size, index);
}

/**
 * Returns the bytes index for the specified vector and element
 * index.
 *
 * @param[in] vector this vector
 * @param[in] index the index of the element in the vector
 */
static size_t Mdc_Vector_ElementIndexToByteIndex(
    const struct Mdc_Vector* vector,
    size_t index
) {
  const struct Mdc_VectorMetadata* const vector_metadata = vector->metadata;
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  return Mdc_UnVector_ElementIndexToByteIndex(
      element_metadata->size,
      index
  );
}

static void* Mdc_UnVector_InitMoveElements(
    void* dest_elements,
    const struct Mdc_VectorMetadata* vector_metadata,
    void* src_elements,
    size_t count
) {
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  size_t i;
  void* dest_element;
  void* src_element;

  const void* init_element;

  for (i = 0; i < count; i += 1) {
    dest_element = Mdc_UnVector_Access(dest_elements, element_size, i);
    src_element = Mdc_UnVector_Access(dest_elements, element_size, i);

    init_element = element_functions->init_move(
        dest_element,
        src_element
    );

    if (init_element != dest_element) {
      goto deinit_elements;
    }

    element_functions->deinit(src_element);
  }

  return dest_elements;

deinit_elements:
  for (; i > 0; i -= 1) {
    dest_element = Mdc_UnVector_Access(dest_elements, element_size, i - 1);
    element_functions->deinit(dest_element);
  }

  return NULL;
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
  const struct Mdc_VectorMetadata* const vector_metadata = vector->metadata;
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  const size_t d_start_end = i_end - i_start;

  size_t i;
  void* dest_element;
  void* src_element;

  for (i = i_start; i < i_end; i += 1) {
    element_functions->deinit(
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

    element_functions->init_move(dest_element, src_element);
    element_functions->deinit(src_element);
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
 * Doubles the capacity when the elements count reaches the capacity.
 *
 * @param vector this vector
 */
static void Mdc_Vector_ReserveOnPolicy(struct Mdc_Vector* vector) {
  size_t vector_count;
  size_t vector_capacity;

  vector_count = Mdc_Vector_Size(vector);
  vector_capacity = Mdc_Vector_Capacity(vector);

  assert(vector_count <= vector_capacity);

  if (vector_count != vector_capacity) {
    return;
  }

  Mdc_Vector_Reserve(vector, vector_capacity * 2);
}

/**
 * External functions
 */

struct Mdc_Vector* Mdc_Vector_InitEmpty(
    struct Mdc_Vector* vector,
    const struct Mdc_VectorMetadata* metadata
) {
  const struct Mdc_VectorMetadata* const vector_metadata = vector->metadata;
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  size_t elements_size;

  vector->metadata = metadata;

  /* Initialize the elements. */
  elements_size = kInitialCapacity * sizeof(element_size);
  vector->elements = malloc(elements_size);

  if (vector->elements == NULL) {
    goto return_bad;
  }

  vector->count = 0;
  vector->capacity = kInitialCapacity;

  return vector;

return_bad:
  *vector = Mdc_Vector_kUninit;

  return NULL;
}

struct Mdc_Vector* Mdc_Vector_InitCopy(
    struct Mdc_Vector* dest,
    const struct Mdc_Vector* src
) {
  const struct Mdc_VectorMetadata* const vector_metadata = src->metadata;
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  size_t i;
  size_t elements_size;

  const void* init_element_copy;

  void* dest_element;
  const void* src_element;

  dest->metadata = vector_metadata;

  /* Copy the elements. */
  elements_size = src->capacity * sizeof(element_size);
  dest->elements = malloc(elements_size);

  if (dest->elements == NULL) {
    goto return_bad;
  }

  dest->capacity = src->capacity;

  for (dest->count = 0; dest->count < src->count; dest->count += 1) {
    dest_element = Mdc_UnVector_Access(
        dest->elements,
        element_size,
        dest->count
    );

    src_element = Mdc_UnVector_AccessConst(
        src->elements,
        element_size,
        dest->count
    );

    init_element_copy = element_functions->init_copy(
        dest_element,
        src_element
    );

    if (init_element_copy != dest_element) {
      goto deinit_elements;
    }
  }

  return dest;

deinit_elements:
  for (i = 0; i < dest->count; i += 1) {
    dest_element = Mdc_UnVector_Access(
        dest->elements,
        element_size,
        dest->count
    );

    element_functions->deinit(dest_element);
  }

  dest->count = 0;

  free(dest->elements);
  dest->elements = NULL;
  dest->capacity = 0;

return_bad:
  *dest = Mdc_Vector_kUninit;

  return NULL;
}

struct Mdc_Vector* Mdc_Vector_InitMove(
    struct Mdc_Vector* dest,
    struct Mdc_Vector* src
) {
  dest->metadata = src->metadata;

  dest->elements = src->elements;
  src->elements = NULL;

  dest->count = src->count;
  src->count = 0;

  dest->capacity = src->capacity;
  src->capacity = 0;

  return dest;
}

void Mdc_Vector_Deinit(struct Mdc_Vector* vector) {
  const struct Mdc_VectorMetadata* const vector_metadata = vector->metadata;
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  void* dest_element;
  size_t i;

  if (vector->elements != NULL) {
    for (i = 0; i < vector->count; i += 1) {
      dest_element = Mdc_UnVector_Access(
          vector->elements,
          element_size,
          i
      );

      element_functions->deinit(dest_element);
    }

    vector->count = 0;

    free(vector->elements);
    vector->elements = NULL;

    vector->capacity = 0;
  }

  *vector = Mdc_Vector_kUninit;
}

void* Mdc_Vector_Access(struct Mdc_Vector* vector, size_t pos) {
  return (void*) Mdc_Vector_AccessConst(vector, pos);
}

const void* Mdc_Vector_AccessConst(
    const struct Mdc_Vector* vector,
    size_t pos
) {
  const struct Mdc_VectorMetadata* const vector_metadata = vector->metadata;
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  return Mdc_UnVector_AccessConst(
      vector->elements,
      element_size,
      pos
  );
}

void* Mdc_Vector_At(struct Mdc_Vector* vector, size_t pos) {
  return (void*) Mdc_Vector_AtConst(vector, pos);
}

const void* Mdc_Vector_AtConst(const struct Mdc_Vector* vector, size_t pos) {
  if (pos < 0 || pos >= vector->count) {
    goto return_bad;
  }

  return Mdc_Vector_AccessConst(vector, pos);

return_bad:
  return NULL;
}

void* Mdc_Vector_Back(struct Mdc_Vector* vector) {
  return (void*) Mdc_Vector_BackConst(vector);
}

const void* Mdc_Vector_BackConst(const struct Mdc_Vector* vector) {
  return Mdc_Vector_AccessConst(vector, vector->count - 1);
}

size_t Mdc_Vector_Capacity(const struct Mdc_Vector* vector) {
  return vector->capacity;
}

void Mdc_Vector_Clear(struct Mdc_Vector* vector) {
  Mdc_Vector_DeinitIndexElements(vector, 0, vector->count);
}

void* Mdc_Vector_Data(struct Mdc_Vector* vector) {
  return (void*) Mdc_Vector_DataConst(vector);
}

const void* Mdc_Vector_DataConst(const struct Mdc_Vector* vector) {
  return vector->elements;
}

bool Mdc_Vector_Empty(const struct Mdc_Vector* vector) {
  return (Mdc_Vector_Size(vector) == 0);
}

void* Mdc_Vector_Front(struct Mdc_Vector* vector) {
  return (void*) Mdc_Vector_FrontConst(vector);
}

const void* Mdc_Vector_FrontConst(const struct Mdc_Vector* vector) {
  return Mdc_Vector_AccessConst(vector, 0);
}

void Mdc_Vector_PopBack(struct Mdc_Vector* vector) {
  const struct Mdc_VectorMetadata* const vector_metadata = vector->metadata;
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  void* last_element;

  last_element = Mdc_Vector_Back(vector);
  element_functions->deinit(last_element);

  vector->count -= 1;
}

void Mdc_Vector_PushBack(struct Mdc_Vector* vector, void* value) {
  const struct Mdc_VectorMetadata* const vector_metadata = vector->metadata;
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  void* insertion_element;
  const void* init_insertion_element_move;

  Mdc_Vector_ReserveOnPolicy(vector);

  insertion_element = Mdc_UnVector_Access(
      vector->elements,
      element_size,
      vector->count
  );

  init_insertion_element_move = element_functions->init_move(
      insertion_element,
      value
  );

  if (init_insertion_element_move != insertion_element) {
    goto return_bad;
  }

  vector->count += 1;

  return;

return_bad:
  return;
}

void Mdc_Vector_PushBackCopy(struct Mdc_Vector* vector, const void* value) {
  const struct Mdc_VectorMetadata* const vector_metadata = vector->metadata;
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  void* insertion_element;
  const void* init_insertion_element_copy;

  Mdc_Vector_ReserveOnPolicy(vector);

  insertion_element = Mdc_UnVector_Access(
      vector->elements,
      element_size,
      vector->count
  );

  init_insertion_element_copy = element_functions->init_copy(
      insertion_element,
      value
  );

  if (init_insertion_element_copy != insertion_element) {
    goto return_bad;
  }

  vector->count += 1;

  return;

return_bad:
  return;
}

void Mdc_Vector_Resize(
    struct Mdc_Vector* vector,
    size_t count,
    const void* value
) {
  const struct Mdc_VectorMetadata* const vector_metadata = vector->metadata;
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  const size_t old_count = Mdc_Vector_Size(vector);

  void* element;
  const void* init_element_copy;

  if (vector->count == count) {
    return;
  }

  if (vector->capacity < count) {
    Mdc_Vector_Reserve(vector, count);
  }

  /* Init or deinit the additional elements in the vector. */
  for (; vector->count > count; vector->count -= 1) {
    element = Mdc_Vector_Access(vector, vector->count - 1);
    element_functions->deinit(element);
  }

  for (; vector->count < count; vector->count += 1) {
    element = Mdc_Vector_Access(vector, vector->count);
    init_element_copy = element_functions->init_copy(element, value);

    if (init_element_copy != element) {
      goto return_bad;
    }
  }

return_bad:
  for (; vector->count > old_count; vector->count -= 1) {
    element = Mdc_Vector_Access(vector, vector->count - 1);
    element_functions->deinit(element);
  }

  return;
}

void Mdc_Vector_Reserve(struct Mdc_Vector* vector, size_t new_capacity) {
  const struct Mdc_VectorMetadata* const vector_metadata = vector->metadata;
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  void* realloc_elements;
  size_t new_elements_size;
  const void* init_elements_move;

  if (vector->capacity >= new_capacity) {
    return;
  }

  new_elements_size = element_size * new_capacity;
  realloc_elements = malloc(new_elements_size);

  if (realloc_elements == NULL) {
    goto return_bad;
  }

  init_elements_move = Mdc_UnVector_InitMoveElements(
      realloc_elements,
      vector->metadata,
      vector->elements,
      vector->count
  );

  if (init_elements_move != realloc_elements) {
    goto free_realloc_elements;
  }

  free(vector->elements);
  vector->elements = realloc_elements;
  vector->capacity = new_capacity;

  return;

free_realloc_elements:
  free(realloc_elements);
  realloc_elements = NULL;

return_bad:
  return;
}

void Mdc_Vector_ShrinkToFit(struct Mdc_Vector* vector) {
  const struct Mdc_VectorMetadata* const vector_metadata = vector->metadata;
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  void* realloc_elements;
  size_t new_elements_size;

  const void* init_elements_move;

  if (vector->capacity == vector->count) {
    return;
  }

  new_elements_size = vector->count * element_size;
  realloc_elements = malloc(new_elements_size);

  if (realloc_elements == NULL) {
    goto return_bad;
  }

  init_elements_move = Mdc_UnVector_InitMoveElements(
      realloc_elements,
      vector->metadata,
      vector->elements,
      vector->count
  );

  if (init_elements_move != realloc_elements) {
    goto free_realloc_elements;
  }

  free(vector->elements);
  vector->elements = realloc_elements;
  vector->capacity = vector->count;

  return;

free_realloc_elements:
  free(realloc_elements);
  realloc_elements = NULL;

return_bad:
  return;
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

  return (memcmp_result == 0);
}
