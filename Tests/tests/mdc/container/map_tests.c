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
#include <mdc/container/pair.h>
#include "string_int_pair/string_int_pair.h"

static const char* const kBasicExampleText[] = {
    "The", "quick", "brown", "fox", "jumped", "over", "the", "lazy",
    "dog."
};

static const char* const kRepeatingText[] = {
    "sort", "the", "sort", "map", "the", "way", "to", "sort",
    "what", "the", "sort", "said"
};

static const char* kRepeatingTextWords[] = {
  "map", "said", "sort", "the", "to", "way", "what"
};

static int kRepeatingTextCounts[] = {
  1, 1, 4, 3, 1, 1, 1
};

enum FILE_SCOPE_CONSTANTS_03 {
  kBasicExampleTextCount = sizeof(kBasicExampleText)
      / sizeof(kBasicExampleText[0]),
  kRepeatingTextCount = sizeof(kRepeatingText)
      / sizeof(kRepeatingText[0]),
  kRepeatingWordCountPairsCount = sizeof(kRepeatingTextWords)
      / sizeof(kRepeatingTextWords[0])
};

static struct Mdc_MapMetadata* Mdc_WordCountMapMetadata_Init(
    struct Mdc_MapMetadata* metadata
) {
  Mdc_PairStringIntMetadata_Init(&metadata->pair_metadata);

  return metadata;
}

static void Mdc_Map_AssertInitDeinit(void) {
  struct Mdc_Map map;
  struct Mdc_MapMetadata metadata_src;

  int memcmp_result;

  Mdc_WordCountMapMetadata_Init(&metadata_src);
  Mdc_Map_Init(&map, &metadata_src);

  assert(map.metadata != NULL);

  memcmp_result = memcmp(
      map.metadata,
      &metadata_src,
      sizeof(*map.metadata)
  );
  assert(memcmp_result == 0);

  assert(Mdc_Map_Size(&map) == 0);

  Mdc_Map_Deinit(&map);
}

static void Mdc_Map_AssertEmplace(void) {
  const int kZero = 0;

  struct Mdc_Map map;
  struct Mdc_MapMetadata metadata_src;

  const struct Mdc_PairMetadata* const pair_metadata =
      &metadata_src.pair_metadata;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const value_functions =
      &pair_metadata->functions.second_functions;

  int* actual_pair_value;
  const int* actual_pair_value_const;

  size_t i;
  int value_compare_result;

  char* key_copy;
  int zero_copy;

  const char** init_key_copy;

  Mdc_WordCountMapMetadata_Init(&metadata_src);
  Mdc_Map_Init(&map, &metadata_src);

  assert(map.metadata != NULL);

  /* Insert the elements. */
  for (i = 0; i < kRepeatingTextCount; i += 1) {
    if (!Mdc_Map_Contains(&map, &kRepeatingText[i])) {
      init_key_copy = Mdc_CharCString_InitCopy(&key_copy, &kRepeatingText[i]);
      assert(init_key_copy == &key_copy);

      zero_copy = kZero;

      Mdc_Map_Emplace(
          &map,
          &key_copy,
          &Mdc_Int_InitCopy,
          &zero_copy
      );

      Mdc_CharCString_Deinit(&key_copy);
    }

    actual_pair_value = Mdc_Map_At(&map, &kRepeatingText[i]);

    (*actual_pair_value) += 1;
  }

  /* Check all of the elements. */
  for (i = 0; i < kRepeatingWordCountPairsCount; i += 1) {
    assert(Mdc_Map_Contains(&map, &kRepeatingTextWords[i]));

    actual_pair_value_const = Mdc_Map_AtConst(&map, &kRepeatingTextWords[i]);
    assert(actual_pair_value_const != NULL);

    value_compare_result = value_functions->compare(
        actual_pair_value_const,
        &kRepeatingTextCounts[i]
    );
    assert(value_compare_result == 0);
  }

  Mdc_Map_Deinit(&map);
}

static void Mdc_Map_AssertEmplaceKeyCopy(void) {
  const int kZero = 0;

  struct Mdc_Map map;
  struct Mdc_MapMetadata metadata_src;

  const struct Mdc_PairMetadata* const pair_metadata =
      &metadata_src.pair_metadata;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const value_functions =
      &pair_metadata->functions.second_functions;

  int* actual_pair_value;
  const int* actual_pair_value_const;

  size_t i;
  int value_compare_result;

  int zero_copy;

  Mdc_WordCountMapMetadata_Init(&metadata_src);
  Mdc_Map_Init(&map, &metadata_src);

  assert(map.metadata != NULL);

  /* Insert the elements. */
  for (i = 0; i < kRepeatingTextCount; i += 1) {
    if (!Mdc_Map_Contains(&map, &kRepeatingText[i])) {
      zero_copy = kZero;

      Mdc_Map_EmplaceKeyCopy(
          &map,
          &kRepeatingText[i],
          &Mdc_Int_InitCopy,
          &zero_copy
      );
    }

    actual_pair_value = Mdc_Map_At(&map, &kRepeatingText[i]);

    (*actual_pair_value) += 1;
  }

  /* Check all of the elements. */
  for (i = 0; i < kRepeatingWordCountPairsCount; i += 1) {
    assert(Mdc_Map_Contains(&map, &kRepeatingTextWords[i]));

    actual_pair_value_const = Mdc_Map_AtConst(&map, &kRepeatingTextWords[i]);
    assert(actual_pair_value_const != NULL);

    value_compare_result = value_functions->compare(
        actual_pair_value_const,
        &kRepeatingTextCounts[i]
    );
    assert(value_compare_result == 0);
  }

  Mdc_Map_Deinit(&map);
}

static void Mdc_Map_AssertInsertOrAssignPair(void) {
  const int kZero = 0;

  struct Mdc_Map map;
  struct Mdc_MapMetadata metadata_src;

  const struct Mdc_PairMetadata* const pair_metadata =
      &metadata_src.pair_metadata;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const value_functions =
      &pair_metadata->functions.second_functions;

  struct Mdc_Pair pair;
  int* actual_pair_value;
  const int* actual_pair_value_const;

  size_t i;
  int value_compare_result;

  const struct Mdc_Pair* init_pair;

  Mdc_WordCountMapMetadata_Init(&metadata_src);
  Mdc_Map_Init(&map, &metadata_src);

  assert(map.metadata != NULL);

  /* Insert the elements. */
  for (i = 0; i < kRepeatingTextCount; i += 1) {
    if (!Mdc_Map_Contains(&map, &kRepeatingText[i])) {
      init_pair = Mdc_Pair_InitFirstCopySecondCopy(
          &pair,
          &map.metadata->pair_metadata,
          &kRepeatingText[i],
          &kZero
      );
      assert(init_pair == &pair);

      Mdc_Map_InsertOrAssignPair(&map, &pair);

      Mdc_Pair_Deinit(&pair);
    }

    actual_pair_value = Mdc_Map_At(&map, &kRepeatingText[i]);

    (*actual_pair_value) += 1;
  }

  /* Check all of the elements. */
  for (i = 0; i < kRepeatingWordCountPairsCount; i += 1) {
    assert(Mdc_Map_Contains(&map, &kRepeatingTextWords[i]));

    actual_pair_value_const = Mdc_Map_AtConst(&map, &kRepeatingTextWords[i]);
    assert(actual_pair_value != NULL);

    value_compare_result = value_functions->compare(
        actual_pair_value_const,
        &kRepeatingTextCounts[i]
    );
    assert(value_compare_result == 0);
  }

  Mdc_Map_Deinit(&map);
}

static void Mdc_Map_AssertInsertOrAssignPairCopy(void) {
  const int kZero = 0;

  struct Mdc_Map map;
  struct Mdc_MapMetadata metadata_src;

  const struct Mdc_PairMetadata* const pair_metadata =
      &metadata_src.pair_metadata;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const value_functions =
      &pair_metadata->functions.second_functions;

  struct Mdc_Pair pair;
  int* actual_pair_value;
  const int* actual_pair_value_const;

  size_t i;
  int value_compare_result;

  const struct Mdc_Pair* init_pair;

  Mdc_WordCountMapMetadata_Init(&metadata_src);
  Mdc_Map_Init(&map, &metadata_src);

  assert(map.metadata != NULL);

  /* Insert the elements. */
  for (i = 0; i < kRepeatingTextCount; i += 1) {
    if (!Mdc_Map_Contains(&map, &kRepeatingText[i])) {
      init_pair = Mdc_Pair_InitFirstCopySecondCopy(
          &pair,
          &map.metadata->pair_metadata,
          &kRepeatingText[i],
          &kZero
      );
      assert(init_pair == &pair);

      Mdc_Map_InsertOrAssignPairCopy(&map, &pair);

      Mdc_Pair_Deinit(&pair);
    }

    actual_pair_value = Mdc_Map_At(&map, &kRepeatingText[i]);

    (*actual_pair_value) += 1;
  }

  /* Check all of the elements. */
  for (i = 0; i < kRepeatingWordCountPairsCount; i += 1) {
    assert(Mdc_Map_Contains(&map, &kRepeatingTextWords[i]));

    actual_pair_value_const = Mdc_Map_AtConst(&map, &kRepeatingTextWords[i]);
    assert(actual_pair_value_const != NULL);

    value_compare_result = value_functions->compare(
        actual_pair_value_const,
        &kRepeatingTextCounts[i]
    );
    assert(value_compare_result == 0);
  }

  Mdc_Map_Deinit(&map);
}

static void Mdc_Map_AssertClear(void) {
  const int kZero = 0;

  struct Mdc_Map map;
  struct Mdc_MapMetadata metadata_src;

  const struct Mdc_PairMetadata* const pair_metadata =
      &metadata_src.pair_metadata;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const value_functions =
      &pair_metadata->functions.second_functions;

  struct Mdc_Pair pair;
  int* actual_pair_value;

  size_t i;

  const struct Mdc_Pair* init_pair;

  Mdc_WordCountMapMetadata_Init(&metadata_src);
  Mdc_Map_Init(&map, &metadata_src);

  assert(map.metadata != NULL);

  /* Insert the elements. */
  for (i = 0; i < kRepeatingTextCount; i += 1) {
    if (!Mdc_Map_Contains(&map, &kRepeatingText[i])) {
      init_pair = Mdc_Pair_InitFirstCopySecondCopy(
          &pair,
          &map.metadata->pair_metadata,
          &kRepeatingText[i],
          &kZero
      );
      assert(init_pair == &pair);

      Mdc_Map_InsertOrAssignPairCopy(&map, &pair);

      Mdc_Pair_Deinit(&pair);
    }

    actual_pair_value = Mdc_Map_At(&map, &kRepeatingText[i]);

    (*actual_pair_value) += 1;
  }

  /* Clear all of the elements. */
  Mdc_Map_Clear(&map);

  assert(Mdc_Map_Empty(&map));

  Mdc_Map_Deinit(&map);
}

static void Mdc_Map_AssertErase(void) {
  const int kZero = 0;

  struct Mdc_Map map;
  struct Mdc_MapMetadata metadata_src;

  const struct Mdc_PairMetadata* const pair_metadata =
      &metadata_src.pair_metadata;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const value_functions =
      &pair_metadata->functions.second_functions;

  struct Mdc_Pair pair;
  int* actual_pair_value;

  size_t i;

  const struct Mdc_Pair* init_pair;

  Mdc_WordCountMapMetadata_Init(&metadata_src);
  Mdc_Map_Init(&map, &metadata_src);

  assert(map.metadata != NULL);

  /* Insert the elements. */
  for (i = 0; i < kRepeatingTextCount; i += 1) {
    if (!Mdc_Map_Contains(&map, &kRepeatingText[i])) {
      init_pair = Mdc_Pair_InitFirstCopySecondCopy(
          &pair,
          &map.metadata->pair_metadata,
          &kRepeatingText[i],
          &kZero
      );
      assert(init_pair == &pair);

      Mdc_Map_InsertOrAssignPairCopy(&map, &pair);

      Mdc_Pair_Deinit(&pair);
    }

    actual_pair_value = Mdc_Map_At(&map, &kRepeatingText[i]);

    (*actual_pair_value) += 1;
  }

  /* Erase all of the elements. */
  for (i = 0; i < kRepeatingWordCountPairsCount; i += 1) {
    assert(Mdc_Map_Contains(&map, &kRepeatingTextWords[i]));
    assert(Mdc_Map_Erase(&map, &kRepeatingTextWords[i]));
    assert(!Mdc_Map_Contains(&map, &kRepeatingTextWords[i]));
  }

  assert(Mdc_Map_Empty(&map));

  Mdc_Map_Deinit(&map);
}

void Mdc_Map_RunTests(void) {
  Mdc_Map_AssertInitDeinit();
  Mdc_Map_AssertEmplace();
  Mdc_Map_AssertEmplaceKeyCopy();
  Mdc_Map_AssertInsertOrAssignPair();
  Mdc_Map_AssertInsertOrAssignPairCopy();
  Mdc_Map_AssertClear();
  Mdc_Map_AssertErase();
}
