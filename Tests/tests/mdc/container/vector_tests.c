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

#include "vector_tests.h"

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <mdc/container/vector.h>
#include <mdc/malloc/malloc.h>
#include <mdc/object/integer_object.h>
#include "vector_int/vector_int.h"

static void Mdc_Vector_AssertInitDeinit(void) {
  const struct Mdc_VectorMetadata* const vector_metadata =
      Mdc_VectorInt_GetGlobalVectorMetadata();
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  struct Mdc_Vector vector;
  struct Mdc_Vector* init_vector;

  init_vector = Mdc_Vector_InitEmpty(&vector, vector_metadata);

  assert(init_vector == &vector);
  assert(vector.metadata == vector_metadata);
  assert(Mdc_Vector_Size(&vector) == 0);
  assert(Mdc_Vector_Empty(&vector));

  Mdc_Vector_Deinit(&vector);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Vector_AssertPushAndPopBack(void) {
  const struct Mdc_VectorMetadata* const vector_metadata =
      Mdc_VectorInt_GetGlobalVectorMetadata();
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  struct Mdc_Vector vector;
  struct Mdc_Vector* init_vector;

  int integer1;
  int integer2;
  int integer3;

  size_t i;
  int* at_result;

  init_vector = Mdc_Vector_InitEmpty(&vector, vector_metadata);
  assert(init_vector == &vector);

  Mdc_Integer_InitFromValue(&integer1, 1234);
  Mdc_Vector_PushBack(&vector, &integer1);

  Mdc_Integer_InitFromValue(&integer2, 4321);
  Mdc_Vector_PushBack(&vector, &integer2);

  assert(Mdc_Vector_Size(&vector) == 2);
  assert(Mdc_Vector_Capacity(&vector) >= 2);

  at_result = Mdc_Vector_At(&vector, 0);
  assert(Mdc_Integer_EqualValue(*at_result, 1234));

  at_result = Mdc_Vector_At(&vector, 1);
  assert(Mdc_Integer_CompareValue(*at_result, 4321) == 0);

  Mdc_Vector_PopBack(&vector);

  at_result = Mdc_Vector_At(&vector, 0);
  assert(Mdc_Integer_EqualValue(*at_result, 1234));

  for (i = 1; i < 5; i += 1) {
    Mdc_Integer_InitFromValue(&integer3, (int) i);

    Mdc_Vector_PushBack(&vector, &integer3);

    at_result = Mdc_Vector_At(&vector, i);
    assert(Mdc_Integer_EqualValue(*at_result, (int) i));

    Mdc_Integer_Deinit(&integer3);
  }

  while (Mdc_Vector_Size(&vector) > 0) {
    Mdc_Vector_PopBack(&vector);
  }

  assert(Mdc_Vector_Empty(&vector));

  Mdc_Integer_Deinit(&integer2);
  Mdc_Integer_Deinit(&integer1);
  Mdc_Vector_Deinit(&vector);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Vector_AssertPushAndPopBackCopy(void) {
  const struct Mdc_VectorMetadata* const vector_metadata =
      Mdc_VectorInt_GetGlobalVectorMetadata();
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  struct Mdc_Vector vector;
  struct Mdc_Vector* init_vector;

  int integer1;
  int integer2;
  int integer3;

  size_t i;
  int* at_result;

  init_vector = Mdc_Vector_InitEmpty(&vector, vector_metadata);
  assert(init_vector == &vector);

  Mdc_Integer_InitFromValue(&integer1, 1234);
  Mdc_Vector_PushBackCopy(&vector, &integer1);

  Mdc_Integer_InitFromValue(&integer2, 4321);
  Mdc_Vector_PushBackCopy(&vector, &integer2);

  assert(Mdc_Vector_Size(&vector) == 2);
  assert(Mdc_Vector_Capacity(&vector) >= 2);

  at_result = Mdc_Vector_At(&vector, 0);
  assert(Mdc_Integer_EqualValue(*at_result, 1234));

  at_result = Mdc_Vector_At(&vector, 1);
  assert(Mdc_Integer_CompareValue(*at_result, 4321) == 0);

  Mdc_Vector_PopBack(&vector);

  at_result = Mdc_Vector_At(&vector, 0);
  assert(Mdc_Integer_EqualValue(*at_result, 1234));

  for (i = 1; i < 5; i += 1) {
    Mdc_Integer_InitFromValue(&integer3, (int) i);

    Mdc_Vector_PushBackCopy(&vector, &integer3);

    at_result = Mdc_Vector_At(&vector, i);
    assert(Mdc_Integer_EqualValue(*at_result, (int) i));

    Mdc_Integer_Deinit(&integer3);
  }

  while (Mdc_Vector_Size(&vector) > 0) {
    Mdc_Vector_PopBack(&vector);
  }

  assert(Mdc_Vector_Empty(&vector));

  Mdc_Integer_Deinit(&integer2);
  Mdc_Integer_Deinit(&integer1);
  Mdc_Vector_Deinit(&vector);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Vector_AssertClear(void) {
  const struct Mdc_VectorMetadata* const vector_metadata =
      Mdc_VectorInt_GetGlobalVectorMetadata();
  const struct Mdc_ObjectMetadata* const element_metadata =
      vector_metadata->element_metadata;
  const size_t element_size = element_metadata->size;
  const struct Mdc_ObjectFunctions* const element_functions =
      &element_metadata->functions;

  struct Mdc_Vector vector;
  struct Mdc_Vector* init_vector;

  int integer;

  size_t i;
  int* at_result;

  init_vector = Mdc_Vector_InitEmpty(&vector, vector_metadata);
  assert(init_vector == &vector);

  for (i = 0; i < 32; i += 1) {
    Mdc_Integer_InitFromValue(&integer, (int) i);
    Mdc_Vector_PushBackCopy(&vector, &integer);

    at_result = Mdc_Vector_At(&vector, i);
    assert(Mdc_Integer_EqualValue(*at_result, (int) i));

    Mdc_Integer_Deinit(&integer);
  }

  Mdc_Vector_Clear(&vector);

  assert(Mdc_Vector_Empty(&vector));

  Mdc_Vector_Deinit(&vector);

  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_Vector_RunTests(void) {
  Mdc_Vector_AssertInitDeinit();
  Mdc_Vector_AssertPushAndPopBack();
  Mdc_Vector_AssertPushAndPopBackCopy();
  Mdc_Vector_AssertClear();
}
