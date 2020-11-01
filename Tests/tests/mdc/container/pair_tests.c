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
#include <mdc/string/basic_string.h>
#include "pair_string_int/pair_string_int.h"

/**
 * External functions
 */

const char* kFirstSrc1 = "Hello world";
const int kSecondSrc1 = 42;

const char* kFirstSrc2 = "Hello world!";
const int kSecondSrc2 = 43;

static void Mdc_Pair_AssertInitDeinit(void) {
  const struct Mdc_PairMetadata* const pair_metadata =
      Mdc_PairStringInt_GetGlobalPairMetadata();
  const struct Mdc_ObjectMetadata* const first_metadata =
      pair_metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      pair_metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  struct Mdc_BasicString first;
  const struct Mdc_BasicString* init_first;

  int second;
  const int* init_second;

  struct Mdc_Pair pair;
  struct Mdc_Pair* init_pair;

  init_first = Mdc_BasicString_InitFromCStr(
      &first,
      Mdc_CharTraitsChar_GetCharTraits(),
      kFirstSrc1
  );

  assert(init_first == &first);
  assert(Mdc_BasicString_EqualCStr(&first, kFirstSrc1));

  init_second = Mdc_Integer_InitFromValue(&second, kSecondSrc1);
  assert(init_second == &second);
  assert(Mdc_Integer_EqualValue(&second, kSecondSrc1));

  init_pair = Mdc_Pair_InitFromFirstSecond(
      &pair,
      pair_metadata,
      &first,
      &second
  );
  assert(init_pair == &pair);

  /* Check that the initialization completed correctly. */
  assert(pair.metadata == Mdc_PairStringInt_GetGlobalPairMetadata());

  assert(pair.first != NULL);
  assert(Mdc_BasicString_EqualCStr(pair.first, kFirstSrc1));

  assert(pair.second != NULL);
  assert(Mdc_Integer_EqualValue(pair.second, kSecondSrc1));

  Mdc_Pair_Deinit(&pair);
  Mdc_Integer_Deinit(&second);
  Mdc_BasicString_Deinit(&first);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Pair_AssertInitCopyDeinit(void) {
  const struct Mdc_PairMetadata* const pair_metadata =
      Mdc_PairStringInt_GetGlobalPairMetadata();
  const struct Mdc_ObjectMetadata* const first_metadata =
      pair_metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      pair_metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  struct Mdc_Pair pair;
  struct Mdc_Pair* init_pair;

  struct Mdc_BasicString first;
  struct Mdc_BasicString* init_first;

  int second;
  int* init_second;

  init_first = Mdc_BasicString_InitFromCStr(
      &first,
      Mdc_CharTraitsChar_GetCharTraits(),
      kFirstSrc1
  );
  assert(init_first == &first);
  assert(Mdc_BasicString_EqualCStr(&first, kFirstSrc1));

  init_second = Mdc_Integer_InitFromValue(&second, kSecondSrc1);
  assert(init_second == &second);
  assert(Mdc_Integer_EqualValue(&second, kSecondSrc1));

  init_pair = Mdc_Pair_InitFromFirstCopySecondCopy(
      &pair,
      pair_metadata,
      &first,
      &second
  );
  assert(init_pair == &pair);

  /* Check that the initialization completed correctly. */
  assert(pair.metadata == pair_metadata);

  assert(pair.first != NULL);
  assert(Mdc_BasicString_EqualCStr(pair.first, kFirstSrc1));
  assert(first_functions->equal(pair.first, &first));

  assert(pair.second != NULL);
  assert(Mdc_Integer_EqualValue(pair.second, kSecondSrc1));
  assert(second_functions->equal(pair.second, &second));

  Mdc_Pair_Deinit(&pair);
  Mdc_Integer_Deinit(&second);
  Mdc_BasicString_Deinit(&first);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Pair_AssertCompareFirst(void) {
  const struct Mdc_PairMetadata* const pair_metadata =
      Mdc_PairStringInt_GetGlobalPairMetadata();
  const struct Mdc_ObjectMetadata* const first_metadata =
      pair_metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      pair_metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  struct Mdc_BasicString first1;
  struct Mdc_BasicString first2;

  int second;

  struct Mdc_Pair pair1;
  struct Mdc_Pair pair2;

  const struct Mdc_Pair* init_pair1;
  const struct Mdc_Pair* init_pair2;

  Mdc_BasicString_InitFromCStr(
      &first1,
      Mdc_CharTraitsChar_GetCharTraits(),
      kFirstSrc1
  );

  Mdc_BasicString_InitFromCStr(
      &first2,
      Mdc_CharTraitsChar_GetCharTraits(),
      kFirstSrc2
  );

  Mdc_Integer_InitFromValue(&second, kSecondSrc1);

  init_pair1 = Mdc_Pair_InitFromFirstCopySecondCopy(
      &pair1,
      pair_metadata,
      &first1,
      &second
  );
  assert(init_pair1 == &pair1);

  init_pair2 = Mdc_Pair_InitFromFirstCopySecondCopy(
      &pair2,
      pair_metadata,
      &first2,
      &second
  );
  assert(init_pair2 == &pair2);

  assert(Mdc_Pair_Compare(&pair1, &pair2) < 0);
  assert(Mdc_Pair_Compare(&pair2, &pair1) > 0);
  assert(Mdc_Pair_Compare(&pair1, &pair1) == 0);
  assert(second_functions->compare(pair1.second, pair2.second) == 0);

  /* Check that the initialization completed correctly. */
  assert(pair1.metadata == pair_metadata);

  assert(pair1.first != NULL);
  assert(Mdc_BasicString_EqualCStr(pair1.first, kFirstSrc1));

  assert(pair1.second != NULL);
  assert(Mdc_Integer_EqualValue(pair1.second, kSecondSrc1));

  assert(pair2.metadata == pair_metadata);

  assert(pair2.first != NULL);
  assert(Mdc_BasicString_EqualCStr(pair2.first, kFirstSrc2));

  assert(pair2.second != NULL);
  assert(Mdc_Integer_EqualValue(pair2.second, kSecondSrc1));

  Mdc_Pair_Deinit(&pair2);
  Mdc_Pair_Deinit(&pair1);

  Mdc_Integer_Deinit(&second);
  Mdc_BasicString_Deinit(&first2);
  Mdc_BasicString_Deinit(&first1);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Pair_AssertCompareSecond(void) {
  const struct Mdc_PairMetadata* const pair_metadata =
      Mdc_PairStringInt_GetGlobalPairMetadata();
  const struct Mdc_ObjectMetadata* const first_metadata =
      pair_metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      pair_metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  struct Mdc_Pair pair1;
  struct Mdc_Pair pair2;

  struct Mdc_BasicString first;

  int second1;
  int second2;

  const struct Mdc_Pair* init_pair1;
  const struct Mdc_Pair* init_pair2;

  Mdc_BasicString_InitFromCStr(
      &first,
      Mdc_CharTraitsChar_GetCharTraits(),
      kFirstSrc1
  );

  Mdc_Integer_InitFromValue(&second1, kSecondSrc1);
  Mdc_Integer_InitFromValue(&second2, kSecondSrc2);

  init_pair1 = Mdc_Pair_InitFromFirstCopySecondCopy(
      &pair1,
      pair_metadata,
      &first,
      &second1
  );
  assert(init_pair1 == &pair1);

  init_pair2 = Mdc_Pair_InitFromFirstCopySecondCopy(
      &pair2,
      pair_metadata,
      &first,
      &second2
  );
  assert(init_pair2 == &pair2);

  assert(Mdc_Pair_Compare(&pair1, &pair2) < 0);
  assert(Mdc_Pair_Compare(&pair2, &pair1) > 0);
  assert(Mdc_Pair_Compare(&pair1, &pair1) == 0);
  assert(first_functions->compare(pair1.first, pair2.first) == 0);

  /* Check that the initialization completed correctly. */
  assert(pair1.metadata == pair_metadata);

  assert(pair1.first != NULL);
  assert(Mdc_BasicString_EqualCStr(pair1.first, kFirstSrc1));

  assert(pair1.second != NULL);
  assert(Mdc_Integer_EqualValue(pair1.second, kSecondSrc1));

  assert(pair2.metadata == pair_metadata);

  assert(pair2.first != NULL);
  assert(Mdc_BasicString_EqualCStr(pair2.first, kFirstSrc1));

  assert(pair2.second != NULL);
  assert(Mdc_Integer_EqualValue(pair2.second, kSecondSrc2));

  Mdc_Pair_Deinit(&pair2);
  Mdc_Pair_Deinit(&pair1);

  Mdc_Integer_Deinit(&second2);
  Mdc_Integer_Deinit(&second1);
  Mdc_BasicString_Deinit(&first);

  assert(Mdc_GetMallocDifference() == 0);
}

static void Mdc_Pair_AssertSwap() {
  const struct Mdc_PairMetadata* const pair_metadata =
      Mdc_PairStringInt_GetGlobalPairMetadata();
  const struct Mdc_ObjectMetadata* const first_metadata =
      pair_metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      pair_metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  struct Mdc_Pair pair1;
  struct Mdc_Pair pair2;

  struct Mdc_BasicString first1;
  struct Mdc_BasicString first2;

  int second1;
  int second2;

  const struct Mdc_Pair* init_pair1;
  const struct Mdc_Pair* init_pair2;

  Mdc_BasicString_InitFromCStr(
      &first1,
      Mdc_CharTraitsChar_GetCharTraits(),
      kFirstSrc1
  );
  Mdc_BasicString_InitFromCStr(
      &first2,
      Mdc_CharTraitsChar_GetCharTraits(),
      kFirstSrc2
  );

  Mdc_Integer_InitFromValue(&second1, kSecondSrc1);
  Mdc_Integer_InitFromValue(&second2, kSecondSrc2);

  init_pair1 = Mdc_Pair_InitFromFirstCopySecondCopy(
      &pair1,
      pair_metadata,
      &first1,
      &second1
  );
  assert(init_pair1 == &pair1);

  init_pair2 = Mdc_Pair_InitFromFirstCopySecondCopy(
      &pair2,
      pair_metadata,
      &first2,
      &second2
  );
  assert(init_pair2 == &pair2);

  Mdc_Pair_Swap(&pair1, &pair2);

  /* Check that the initialization completed correctly. */
  assert(pair1.metadata == pair_metadata);

  assert(pair1.first != NULL);
  assert(Mdc_BasicString_EqualCStr(pair1.first, kFirstSrc2));

  assert(pair1.second != NULL);
  assert(Mdc_Integer_EqualValue(pair1.second, kSecondSrc2));

  assert(pair2.metadata == pair_metadata);

  assert(pair2.first != NULL);
  assert(Mdc_BasicString_EqualCStr(pair2.first, kFirstSrc1));

  assert(pair2.second != NULL);
  assert(Mdc_Integer_EqualValue(pair2.second, kSecondSrc1));

  Mdc_Pair_Deinit(&pair2);
  Mdc_Pair_Deinit(&pair1);

  Mdc_Integer_Deinit(&second2);
  Mdc_Integer_Deinit(&second1);
  Mdc_BasicString_Deinit(&first2);
  Mdc_BasicString_Deinit(&first1);

  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_Pair_RunTests(void) {
  Mdc_Pair_AssertInitDeinit();
  Mdc_Pair_AssertInitCopyDeinit();
  Mdc_Pair_AssertCompareFirst();
  Mdc_Pair_AssertCompareSecond();
  Mdc_Pair_AssertSwap();
}
