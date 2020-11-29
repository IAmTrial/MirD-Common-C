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

#include "map_tests.h"

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <mdc/container/map.h>
#include <mdc/malloc/malloc.h>
#include <mdc/object/integer_object.h>
#include <mdc/string/string.h>
#include "pair_string_int/pair_string_int.h"

/**
 * External functions
 */

const char* kFirstSrc1 = "Hello world";
const int kSecondSrc1 = 42;

const char* kFirstSrc2 = "Hello world!";
const int kSecondSrc2 = 43;

static void Mdc_Pair_AssertInitDefaultAndDeinit(void) {
  struct Mdc_Pair(Mdc_String, Mdc_Int) pair;

  pair = Mdc_Pair_InitDefault(Mdc_String, Mdc_Int)();

  assert(Mdc_String_EqualCStr(&pair.first, ""));

  Mdc_Pair_Deinit(Mdc_String, Mdc_Int)(&pair);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Pair_AssertInitFromFirstCopySecondCopyAndDeinit(void) {
  struct Mdc_String first;
  int second;

  struct Mdc_Pair(Mdc_String, Mdc_Int) pair;

  first = Mdc_String_InitFromCStr(kFirstSrc1);
  assert(Mdc_String_EqualCStr(&first, kFirstSrc1));

  second = kSecondSrc1;
  assert(second == kSecondSrc1);

  pair = Mdc_Pair_InitFromFirstCopySecondCopy(Mdc_String, Mdc_Int)(
      &first,
      &second
  );

  /* Check that the initialization completed correctly. */
  assert(Mdc_String_EqualCStr(&pair.first, kFirstSrc1));
  assert(pair.second == kSecondSrc1);

  Mdc_Pair_Deinit(Mdc_String, Mdc_Int)(&pair);
  Mdc_String_Deinit(&first);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Pair_AssertInitCopyAndDeinit(void) {
  struct Mdc_String first;
  int second;

  struct Mdc_Pair(Mdc_String, Mdc_Int) pair1;
  struct Mdc_Pair(Mdc_String, Mdc_Int) pair2;

  first = Mdc_String_InitFromCStr(kFirstSrc1);
  assert(Mdc_String_EqualCStr(&first, kFirstSrc1));

  second = kSecondSrc1;
  assert(second == kSecondSrc1);

  pair1 = Mdc_Pair_InitFromFirstCopySecondCopy(Mdc_String, Mdc_Int)(
      &first,
      &second
  );

  pair2 = Mdc_Pair_InitCopy(Mdc_String, Mdc_Int)(&pair2);

  /* Check that the initialization completed correctly. */
  assert(Mdc_String_EqualCStr(&pair1.first, kFirstSrc1));
  assert(pair1.second == kSecondSrc1);

  assert(Mdc_Pair_Equal(Mdc_String, Mdc_Int)(&pair1, &pair2));

  Mdc_Pair_Deinit(Mdc_String, Mdc_Int)(&pair2);
  Mdc_Pair_Deinit(Mdc_String, Mdc_Int)(&pair1);
  Mdc_String_Deinit(&first);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Pair_AssertCompareFirst(void) {
  struct Mdc_String first1;
  struct Mdc_String first2;

  int second;

  struct Mdc_Pair(Mdc_String, Mdc_Int) pair1;
  struct Mdc_Pair(Mdc_String, Mdc_Int) pair2;

  first1 = Mdc_String_InitFromCStr(kFirstSrc1);
  first2 = Mdc_String_InitFromCStr(kFirstSrc2);

  second = kSecondSrc1;

  pair1 = Mdc_Pair_InitFromFirstCopySecondCopy(Mdc_String, Mdc_Int)(
      &first1,
      &second
  );

  pair2 = Mdc_Pair_InitFromFirstCopySecondCopy(Mdc_String, Mdc_Int)(
      &first2,
      &second
  );

  assert(Mdc_Pair_Compare(Mdc_String, Mdc_Int)(&pair1, &pair2) < 0);
  assert(Mdc_Pair_Compare(Mdc_String, Mdc_Int)(&pair2, &pair1) > 0);
  assert(Mdc_Pair_Compare(Mdc_String, Mdc_Int)(&pair1, &pair1) == 0);
  assert(pair1.second == pair2.second);

  /* Check that the initialization completed correctly. */
  assert(Mdc_String_EqualCStr(&pair1.first, kFirstSrc1));
  assert(pair1.second == kSecondSrc1);
  assert(Mdc_String_EqualCStr(&pair2.first, kFirstSrc2));
  assert(pair2.second == kSecondSrc1);

  Mdc_Pair_Deinit(Mdc_String, Mdc_Int)(&pair2);
  Mdc_Pair_Deinit(Mdc_String, Mdc_Int)(&pair1);

  Mdc_String_Deinit(&first2);
  Mdc_String_Deinit(&first1);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Pair_AssertCompareSecond(void) {
  struct Mdc_Pair(Mdc_String, Mdc_Int) pair1;
  struct Mdc_Pair(Mdc_String, Mdc_Int) pair2;

  struct Mdc_String first;

  int second1;
  int second2;

  first = Mdc_String_InitFromCStr(kFirstSrc1);

  second1 = kSecondSrc1;
  second2 = kSecondSrc2;

  pair1 = Mdc_Pair_InitFromFirstCopySecondCopy(Mdc_String, Mdc_Int)(
      &first,
      &second1
  );

  pair2 = Mdc_Pair_InitFromFirstCopySecondCopy(Mdc_String, Mdc_Int)(
      &first,
      &second2
  );

  assert(Mdc_Pair_Compare(Mdc_String, Mdc_Int)(&pair1, &pair2) < 0);
  assert(Mdc_Pair_Compare(Mdc_String, Mdc_Int)(&pair2, &pair1) > 0);
  assert(Mdc_Pair_Compare(Mdc_String, Mdc_Int)(&pair1, &pair1) == 0);
  assert(Mdc_String_CompareStr(&pair1.first, &pair2.first) == 0);

  /* Check that the initialization completed correctly. */
  assert(Mdc_String_EqualCStr(&pair1.first, kFirstSrc1));
  assert(pair1.second == kSecondSrc1);
  assert(Mdc_String_EqualCStr(&pair2.first, kFirstSrc1));
  assert(pair2.second == kSecondSrc2);

  Mdc_Pair_Deinit(Mdc_String, Mdc_Int)(&pair2);
  Mdc_Pair_Deinit(Mdc_String, Mdc_Int)(&pair1);

  Mdc_String_Deinit(&first);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Pair_AssertSwap() {
  struct Mdc_Pair(Mdc_String, Mdc_Int) pair1;
  struct Mdc_Pair(Mdc_String, Mdc_Int) pair2;

  struct Mdc_String first1;
  struct Mdc_String first2;

  int second1;
  int second2;

  first1 = Mdc_String_InitFromCStr(kFirstSrc1);
  first2 = Mdc_String_InitFromCStr(kFirstSrc2);

  second1 = kSecondSrc1;
  second2 = kSecondSrc2;

  pair1 = Mdc_Pair_InitFromFirstCopySecondCopy(Mdc_String, Mdc_Int)(
      &first1,
      &second1
  );

  pair2 = Mdc_Pair_InitFromFirstCopySecondCopy(Mdc_String, Mdc_Int)(
      &first2,
      &second2
  );

  Mdc_Pair_Swap(Mdc_String, Mdc_Int)(&pair1, &pair2);

  /* Check that the initialization completed correctly. */
  assert(Mdc_String_EqualCStr(&pair1.first, kFirstSrc2));
  assert(pair1.second == kSecondSrc2);
  assert(Mdc_String_EqualCStr(&pair2.first, kFirstSrc1));
  assert(pair2.second == kSecondSrc1);

  Mdc_Pair_Deinit(Mdc_String, Mdc_Int)(&pair2);
  Mdc_Pair_Deinit(Mdc_String, Mdc_Int)(&pair1);

  Mdc_String_Deinit(&first2);
  Mdc_String_Deinit(&first1);

  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_Pair_RunTests(void) {
  Mdc_Pair_AssertInitDefaultAndDeinit();
  Mdc_Pair_AssertInitFromFirstCopySecondCopyAndDeinit();
  Mdc_Pair_AssertInitCopyAndDeinit();
  Mdc_Pair_AssertCompareFirst();
  Mdc_Pair_AssertCompareSecond();
  Mdc_Pair_AssertSwap();
}
