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
#include "../../sample_types/char_cstring.h"

static const struct CharCString kBasicExampleText[] = {
    "The", "quick", "brown", "fox", "jumped", "over", "the", "lazy",
    "dog."
};

enum FILE_SCOPE_CONSTANTS_02 {
  kBasicExampleTextCount = sizeof(kBasicExampleText)
      / sizeof(kBasicExampleText[0])
};

static void* Mdc_CharCString_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_CharCString_InitCopy(dest, src);
}

static void* Mdc_CharCString_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_CharCString_InitMove(dest, src);
}

static void Mdc_CharCString_DeinitAsVoid(void* str) {
  Mdc_CharCString_Deinit(str);
}

static int Mdc_CharCString_CompareAsVoid(const void* str1, const void* str2) {
  return Mdc_CharCString_Compare(str1, str2);
}

static struct Mdc_VectorMetadata* Mdc_VectorCharCStringMetadata_Init(
    struct Mdc_VectorMetadata* metadata
) {
  metadata->size.size = sizeof(struct CharCString);

  metadata->functions.init_copy = &Mdc_CharCString_InitCopyAsVoid;
  metadata->functions.init_move = &Mdc_CharCString_InitMoveAsVoid;
  metadata->functions.deinit = &Mdc_CharCString_DeinitAsVoid;
  metadata->functions.compare = &Mdc_CharCString_CompareAsVoid;

  return metadata;
}

static void Mdc_Vector_AssertInitDeinit(void) {
  struct Mdc_Vector vector = MDC_VECTOR_UNINIT;
  struct Mdc_VectorMetadata metadata;

  struct Mdc_Vector* init_vector;

  Mdc_VectorCharCStringMetadata_Init(&metadata);

  init_vector = Mdc_Vector_Init(&vector, &metadata);

  assert(init_vector == &vector);
  assert(memcmp(vector.metadata, &metadata, sizeof(vector.metadata)) == 0);
  assert(Mdc_Vector_Size(&vector) == 0);
  assert(Mdc_Vector_Empty(&vector));

  Mdc_Vector_Deinit(&vector);
}

static void Mdc_Vector_AssertPushAndPopBack(void) {
  struct Mdc_Vector vector = MDC_VECTOR_UNINIT;
  struct Mdc_VectorMetadata metadata;

  size_t i;
  struct CharCString str_src;
  struct CharCString* at_result;

  Mdc_VectorCharCStringMetadata_Init(&metadata);
  Mdc_Vector_Init(&vector, &metadata);

  Mdc_CharCString_InitCopy(&str_src, &kBasicExampleText[0]);
  Mdc_Vector_PushBack(&vector, &str_src);
  Mdc_CharCString_Deinit(&str_src);

  Mdc_CharCString_InitCopy(&str_src, &kBasicExampleText[1]);
  Mdc_Vector_PushBack(&vector, &str_src);
  Mdc_CharCString_Deinit(&str_src);

  assert(Mdc_Vector_Size(&vector) == 2);
  assert(Mdc_Vector_Capacity(&vector) >= 2);

  at_result = Mdc_Vector_At(&vector, 0);
  assert(Mdc_CharCString_Compare(at_result, &kBasicExampleText[0]) == 0);

  at_result = Mdc_Vector_At(&vector, 1);
  assert(Mdc_CharCString_Compare(at_result, &kBasicExampleText[1]) == 0);

  Mdc_Vector_PopBack(&vector);

  at_result = Mdc_Vector_At(&vector, 0);
  assert(Mdc_CharCString_Compare(at_result, &kBasicExampleText[0]) == 0);

  for (i = 2; i < kBasicExampleTextCount; i += 1) {
    Mdc_CharCString_InitCopy(&str_src, &kBasicExampleText[i]);
    Mdc_Vector_PushBack(&vector, &str_src);
    Mdc_CharCString_Deinit(&str_src);

    at_result = Mdc_Vector_At(&vector, i - 1);
    assert(Mdc_CharCString_Compare(at_result, &kBasicExampleText[i]) == 0);
  }

  while (Mdc_Vector_Size(&vector) > 0) {
    Mdc_Vector_PopBack(&vector);
  }

  assert(Mdc_Vector_Empty(&vector));

  Mdc_Vector_Deinit(&vector);
}

static void Mdc_Vector_AssertPushAndPopBackCopy(void) {
  struct Mdc_Vector vector = MDC_VECTOR_UNINIT;
  struct Mdc_VectorMetadata metadata;

  size_t i;
  struct CharCString* at_result;

  Mdc_VectorCharCStringMetadata_Init(&metadata);
  Mdc_Vector_Init(&vector, &metadata);

  Mdc_Vector_PushBackCopy(&vector, &kBasicExampleText[0]);
  Mdc_Vector_PushBackCopy(&vector, &kBasicExampleText[1]);

  assert(Mdc_Vector_Size(&vector) == 2);
  assert(Mdc_Vector_Capacity(&vector) >= 2);

  at_result = Mdc_Vector_At(&vector, 0);
  assert(Mdc_CharCString_Compare(at_result, &kBasicExampleText[0]) == 0);

  at_result = Mdc_Vector_At(&vector, 1);
  assert(Mdc_CharCString_Compare(at_result, &kBasicExampleText[1]) == 0);

  Mdc_Vector_PopBack(&vector);

  at_result = Mdc_Vector_At(&vector, 0);
  assert(Mdc_CharCString_Compare(at_result, &kBasicExampleText[0]) == 0);

  for (i = 2; i < kBasicExampleTextCount; i += 1) {
    Mdc_Vector_PushBackCopy(&vector, &kBasicExampleText[i]);

    at_result = Mdc_Vector_At(&vector, i - 1);
    assert(Mdc_CharCString_Compare(at_result, &kBasicExampleText[i]) == 0);
  }

  while (Mdc_Vector_Size(&vector) > 0) {
    Mdc_Vector_PopBack(&vector);
  }

  assert(Mdc_Vector_Empty(&vector));

  Mdc_Vector_Deinit(&vector);
}

static void Mdc_Vector_AssertClear(void) {
  struct Mdc_Vector vector = MDC_VECTOR_UNINIT;
  struct Mdc_VectorMetadata metadata;

  size_t i;
  struct CharCString* at_result;

  Mdc_VectorCharCStringMetadata_Init(&metadata);
  Mdc_Vector_Init(&vector, &metadata);

  for (i = 0; i < kBasicExampleTextCount; i += 1) {
    Mdc_Vector_PushBackCopy(&vector, &kBasicExampleText[i]);

    at_result = Mdc_Vector_At(&vector, i);
    assert(Mdc_CharCString_Compare(at_result, &kBasicExampleText[i]) == 0);
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