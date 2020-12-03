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

#include <mdc/malloc/malloc.h>
#include "vector_int/vector_int.h"

static void Mdc_Vector_AssertInitAndDeinit(void) {
  struct Mdc_Vector(Mdc_Int) vector;

  vector = Mdc_Vector_InitEmpty(Mdc_Int)();

  assert(Mdc_Vector_Size(Mdc_Int)(&vector) == 0);
  assert(Mdc_Vector_Empty(Mdc_Int)(&vector));

  Mdc_Vector_Deinit(Mdc_Int)(&vector);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Vector_AssertPushAndPopBack(void) {
  struct Mdc_Vector(Mdc_Int) vector;

  int integer1;
  int integer2;
  int integer3;

  size_t i;
  int* at_result;

  vector = Mdc_Vector_InitEmpty(Mdc_Int)();

  integer1 = 1234;
  Mdc_Vector_PushBack(Mdc_Int)(&vector, &integer1);

  integer2 = 4321;
  Mdc_Vector_PushBack(Mdc_Int)(&vector, &integer2);

  assert(Mdc_Vector_Size(Mdc_Int)(&vector) == 2);
  assert(Mdc_Vector_Capacity(Mdc_Int)(&vector) >= 2);

  at_result = Mdc_Vector_At(Mdc_Int)(&vector, 0);
  assert(*at_result == 1234);

  at_result = Mdc_Vector_At(Mdc_Int)(&vector, 1);
  assert(*at_result == 4321);

  Mdc_Vector_PopBack(Mdc_Int)(&vector);

  at_result = Mdc_Vector_At(Mdc_Int)(&vector, 0);
  assert(*at_result == 1234);

  for (i = 1; i < 5; i += 1) {
    integer3 = (int) i;

    Mdc_Vector_PushBack(Mdc_Int)(&vector, &integer3);

    at_result = Mdc_Vector_At(Mdc_Int)(&vector, i);
    assert(*at_result == (int) i);
  }

  while (Mdc_Vector_Size(Mdc_Int)(&vector) > 0) {
    Mdc_Vector_PopBack(Mdc_Int)(&vector);
  }

  assert(Mdc_Vector_Empty(Mdc_Int)(&vector));

  Mdc_Vector_Deinit(Mdc_Int)(&vector);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Vector_AssertPushAndPopBackCopy(void) {
  struct Mdc_Vector(Mdc_Int) vector;

  int integer1;
  int integer2;
  int integer3;

  size_t i;
  int* at_result;

  vector = Mdc_Vector_InitEmpty(Mdc_Int)();

  integer1 = 1234;
  Mdc_Vector_PushBackCopy(Mdc_Int)(&vector, &integer1);

  integer2 = 4321;
  Mdc_Vector_PushBackCopy(Mdc_Int)(&vector, &integer2);

  assert(Mdc_Vector_Size(Mdc_Int)(&vector) == 2);
  assert(Mdc_Vector_Capacity(Mdc_Int)(&vector) >= 2);

  at_result = Mdc_Vector_At(Mdc_Int)(&vector, 0);
  assert(*at_result == 1234);

  at_result = Mdc_Vector_At(Mdc_Int)(&vector, 1);
  assert(*at_result == 4321);

  Mdc_Vector_PopBack(Mdc_Int)(&vector);

  at_result = Mdc_Vector_At(Mdc_Int)(&vector, 0);
  assert(*at_result == 1234);

  for (i = 1; i < 5; i += 1) {
    integer3 = (int) i;

    Mdc_Vector_PushBackCopy(Mdc_Int)(&vector, &integer3);

    at_result = Mdc_Vector_At(Mdc_Int)(&vector, i);
    assert(*at_result == (int) i);
  }

  while (Mdc_Vector_Size(Mdc_Int)(&vector) > 0) {
    Mdc_Vector_PopBack(Mdc_Int)(&vector);
  }

  assert(Mdc_Vector_Empty(Mdc_Int)(&vector));

  Mdc_Vector_Deinit(Mdc_Int)(&vector);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Vector_AssertClear(void) {
  struct Mdc_Vector(Mdc_Int) vector;

  int integer;

  size_t i;
  int* at_result;

  vector = Mdc_Vector_InitEmpty(Mdc_Int)();

  for (i = 0; i < 32; i += 1) {
    integer = (int) i;
    Mdc_Vector_PushBackCopy(Mdc_Int)(&vector, &integer);

    at_result = Mdc_Vector_At(Mdc_Int)(&vector, i);
    assert(*at_result == (int) i);
  }

  Mdc_Vector_Clear(Mdc_Int)(&vector);

  assert(Mdc_Vector_Empty(Mdc_Int)(&vector));

  Mdc_Vector_Deinit(Mdc_Int)(&vector);

  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_Vector_RunTests(void) {
  Mdc_Vector_AssertInitAndDeinit();
  Mdc_Vector_AssertPushAndPopBack();
  Mdc_Vector_AssertPushAndPopBackCopy();
  Mdc_Vector_AssertClear();
}
