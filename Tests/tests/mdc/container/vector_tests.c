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
#include <stdio.h>
#include <string.h>

#include <mdc/container/vector.h>
#include <mdc/object/integer.h>

static void* Mdc_Integer_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_Integer_InitCopy(dest, src);
}

static void* Mdc_Integer_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_Integer_InitMove(dest, src);
}

static void Mdc_Integer_DeinitAsVoid(void* str) {
  Mdc_Integer_Deinit(str);
}

static int Mdc_Integer_CompareAsVoid(const void* str1, const void* str2) {
  return Mdc_Integer_Compare(str1, str2);
}

static struct Mdc_VectorMetadata* Mdc_VectorIntegerMetadata_Init(
    struct Mdc_VectorMetadata* metadata
) {
  metadata->size.size = sizeof(struct Mdc_Integer);

  metadata->functions.init_copy = &Mdc_Integer_InitCopyAsVoid;
  metadata->functions.init_move = &Mdc_Integer_InitMoveAsVoid;
  metadata->functions.deinit = &Mdc_Integer_DeinitAsVoid;
  metadata->functions.compare = &Mdc_Integer_CompareAsVoid;

  return metadata;
}

static void Mdc_Vector_AssertInitDeinit(void) {
  struct Mdc_Vector vector = MDC_VECTOR_UNINIT;
  struct Mdc_VectorMetadata metadata;

  struct Mdc_Vector* init_vector;

  Mdc_VectorIntegerMetadata_Init(&metadata);

  init_vector = Mdc_Vector_Init(&vector, &metadata);

  assert(init_vector == &vector);
  assert(memcmp(vector.metadata, &metadata, sizeof(*vector.metadata)) == 0);
  assert(Mdc_Vector_Size(&vector) == 0);
  assert(Mdc_Vector_Empty(&vector));

  Mdc_Vector_Deinit(&vector);
}

static void Mdc_Vector_AssertPushAndPopBack(void) {
  struct Mdc_Vector vector = MDC_VECTOR_UNINIT;
  struct Mdc_VectorMetadata vector_metadata;

  struct Mdc_Integer integer1 = MDC_INTEGER_UNINIT;
  struct Mdc_Integer integer2 = MDC_INTEGER_UNINIT;
  struct Mdc_Integer integer3 = MDC_INTEGER_UNINIT;

  size_t i;
  struct Mdc_Integer* at_result;

  Mdc_VectorIntegerMetadata_Init(&vector_metadata);
  Mdc_Vector_Init(&vector, &vector_metadata);

  Mdc_Integer_InitFromValue(&integer1, 1234);
  Mdc_Vector_PushBack(&vector, &integer1);

  Mdc_Integer_InitFromValue(&integer2, 4321);
  Mdc_Vector_PushBack(&vector, &integer2);

  assert(Mdc_Vector_Size(&vector) == 2);
  assert(Mdc_Vector_Capacity(&vector) >= 2);

  at_result = Mdc_Vector_At(&vector, 0);
  assert(Mdc_Integer_EqualValue(at_result, 1234));

  at_result = Mdc_Vector_At(&vector, 1);
  assert(Mdc_Integer_CompareValue(at_result, 4321) == 0);

  Mdc_Vector_PopBack(&vector);

  at_result = Mdc_Vector_At(&vector, 0);
  assert(Mdc_Integer_EqualValue(at_result, 1234));

  for (i = 1; i < 5; i += 1) {
    Mdc_Integer_InitFromValue(&integer3, i);

    Mdc_Vector_PushBack(&vector, &integer3);

    at_result = Mdc_Vector_At(&vector, i);
    assert(Mdc_Integer_EqualValue(at_result, i));

    Mdc_Integer_Deinit(&integer3);
  }

  while (Mdc_Vector_Size(&vector) > 0) {
    Mdc_Vector_PopBack(&vector);
  }

  assert(Mdc_Vector_Empty(&vector));

  Mdc_Integer_Deinit(&integer2);
  Mdc_Integer_Deinit(&integer1);
  Mdc_Vector_Deinit(&vector);
}

static void Mdc_Vector_AssertPushAndPopBackCopy(void) {
  struct Mdc_Vector vector = MDC_VECTOR_UNINIT;
  struct Mdc_VectorMetadata vector_metadata;

  struct Mdc_Integer integer1 = MDC_INTEGER_UNINIT;
  struct Mdc_Integer integer2 = MDC_INTEGER_UNINIT;
  struct Mdc_Integer integer3 = MDC_INTEGER_UNINIT;

  size_t i;
  struct Mdc_Integer* at_result;

  Mdc_VectorIntegerMetadata_Init(&vector_metadata);

  Mdc_Vector_Init(&vector, &vector_metadata);

  Mdc_Integer_InitFromValue(&integer1, 1234);
  Mdc_Vector_PushBackCopy(&vector, &integer1);

  Mdc_Integer_InitFromValue(&integer2, 4321);
  Mdc_Vector_PushBackCopy(&vector, &integer2);

  assert(Mdc_Vector_Size(&vector) == 2);
  assert(Mdc_Vector_Capacity(&vector) >= 2);

  at_result = Mdc_Vector_At(&vector, 0);
  assert(Mdc_Integer_EqualValue(at_result, 1234));

  at_result = Mdc_Vector_At(&vector, 1);
  assert(Mdc_Integer_CompareValue(at_result, 4321) == 0);

  Mdc_Vector_PopBack(&vector);

  at_result = Mdc_Vector_At(&vector, 0);
  assert(Mdc_Integer_EqualValue(at_result, 1234));

  for (i = 1; i < 5; i += 1) {
    Mdc_Integer_InitFromValue(&integer3, i);

    Mdc_Vector_PushBackCopy(&vector, &integer3);

    at_result = Mdc_Vector_At(&vector, i);
    assert(Mdc_Integer_EqualValue(at_result, i));

    Mdc_Integer_Deinit(&integer3);
  }

  while (Mdc_Vector_Size(&vector) > 0) {
    Mdc_Vector_PopBack(&vector);
  }

  assert(Mdc_Vector_Empty(&vector));

  Mdc_Integer_Deinit(&integer2);
  Mdc_Integer_Deinit(&integer1);
  Mdc_Vector_Deinit(&vector);
}

static void Mdc_Vector_AssertClear(void) {
  struct Mdc_Vector vector = MDC_VECTOR_UNINIT;
  struct Mdc_VectorMetadata metadata;

  struct Mdc_Integer integer;

  size_t i;
  struct Mdc_Integer* at_result;

  Mdc_VectorIntegerMetadata_Init(&metadata);
  Mdc_Vector_Init(&vector, &metadata);

  for (i = 0; i < 32; i += 1) {
    Mdc_Integer_InitFromValue(&integer, i);
    Mdc_Vector_PushBackCopy(&vector, &integer);

    at_result = Mdc_Vector_At(&vector, i);
    assert(Mdc_Integer_EqualValue(at_result, i));

    Mdc_Integer_Deinit(&integer);
  }

  Mdc_Vector_Clear(&vector);

  assert(Mdc_Vector_Empty(&vector));

  Mdc_Vector_Deinit(&vector);
}

void Mdc_Vector_RunTests(void) {
  Mdc_Vector_AssertInitDeinit();
  Mdc_Vector_AssertPushAndPopBack();
  Mdc_Vector_AssertPushAndPopBackCopy();
  Mdc_Vector_AssertClear();
}
