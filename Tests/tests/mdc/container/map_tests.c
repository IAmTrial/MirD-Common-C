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
#include <mdc/malloc/malloc.h>
#include <mdc/object/integer_object.h>
#include <mdc/string/basic_string.h>
#include "map_string_int/map_string_int.h"
#include "pair_string_int/pair_string_int.h"

static int malloc_diff_start;

static const char* const kBasicExampleText[] = {
    "The", "quick", "brown", "fox", "jumped", "over", "the", "lazy",
    "dog."
};

static const char* const kRepeatingText[] = {
    "sort", "the", "sort", "map", "the", "way", "to", "sort",
    "what", "the", "sort", "said"
};

static const char* const kRepeatingTextWords[] = {
  "map", "said", "sort", "the", "to", "way", "what"
};

static int kRepeatingTextCounts[] = {
  1, 1, 4, 3, 1, 1, 1
};

enum {
  kBasicExampleTextCount = sizeof(kBasicExampleText)
      / sizeof(kBasicExampleText[0]),
  kRepeatingTextCount = sizeof(kRepeatingText)
      / sizeof(kRepeatingText[0]),
  kRepeatingWordCountPairsCount = sizeof(kRepeatingTextWords)
      / sizeof(kRepeatingTextWords[0])
};

static struct Mdc_BasicString basic_example_text_str[kBasicExampleTextCount];
static struct Mdc_BasicString repeating_text_str[kRepeatingTextCount];
static struct Mdc_BasicString
repeating_text_words_str[kRepeatingWordCountPairsCount];
static int repeating_text_counts[kRepeatingWordCountPairsCount];

static void Mdc_Map_AssertInitDeinit(void) {
  const struct Mdc_MapMetadata* const map_metadata =
      Mdc_MapStringInt_GetGlobalMapMetadata();
  const struct Mdc_PairMetadata* const pair_metadata =
      map_metadata->pair_metadata;
  const struct Mdc_ObjectMetadata* const first_metadata =
      pair_metadata->first_metadata;
  const size_t first_size = first_metadata->size;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      pair_metadata->second_metadata;
  const size_t second_size = second_metadata->size;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  struct Mdc_Map map;
  struct Mdc_Map* init_map;

  init_map = Mdc_Map_InitEmpty(&map, map_metadata);
  assert(init_map == &map);
  assert(map.metadata != NULL);
  assert(map.metadata == map_metadata);

  assert(map.metadata != NULL);
  assert(map.metadata == map_metadata);

  assert(Mdc_Map_Size(&map) == 0);

  Mdc_Map_Deinit(&map);

  assert(Mdc_GetMallocDifference() == malloc_diff_start);
}

static void Mdc_Map_AssertEmplace(void) {
  const struct Mdc_MapMetadata* const map_metadata =
      Mdc_MapStringInt_GetGlobalMapMetadata();
  const struct Mdc_PairMetadata* const pair_metadata =
      map_metadata->pair_metadata;
  const struct Mdc_ObjectMetadata* const key_metadata =
      pair_metadata->first_metadata;
  const size_t key_size = key_metadata->size;
  const struct Mdc_ObjectFunctions* const key_functions =
      &key_metadata->functions;
  const struct Mdc_ObjectMetadata* const value_metadata =
      pair_metadata->second_metadata;
  const size_t value_size = value_metadata->size;
  const struct Mdc_ObjectFunctions* const value_functions =
      &value_metadata->functions;

  struct Mdc_Map map;
  struct Mdc_Map* init_map;

  struct Mdc_BasicString key_copy;
  struct Mdc_BasicString* init_key_copy;

  int value_copy;
  int* init_value_copy;

  int* actual_pair_value;
  const int* actual_pair_value_const;

  size_t i;
  int value_compare_result;

  init_map = Mdc_Map_InitEmpty(&map, map_metadata);
  assert(init_map == &map);
  assert(map.metadata != NULL);
  assert(map.metadata == map_metadata);

  /* Insert the elements. */
  for (i = 0; i < kRepeatingTextCount; i += 1) {
    init_key_copy = Mdc_BasicString_InitCopy(
        &key_copy,
        &repeating_text_str[i]
    );
    assert(init_key_copy == &key_copy);

    init_value_copy = Mdc_Integer_InitFromValue(&value_copy, 0);
    assert(init_value_copy == &value_copy);

    Mdc_Map_Emplace(
        &map,
        &key_copy,
        value_functions->init_move,
        &value_copy
    );

    actual_pair_value = Mdc_Map_At(&map, &repeating_text_str[i]);
    Mdc_Integer_PreIncrement(actual_pair_value);

    Mdc_Integer_Deinit(&value_copy);
    Mdc_BasicString_Deinit(&key_copy);
  }

  /* Check all of the elements. */
  for (i = 0; i < kRepeatingWordCountPairsCount; i += 1) {
    assert(Mdc_Map_Contains(&map, &repeating_text_words_str[i]));

    actual_pair_value_const = Mdc_Map_AtConst(
        &map,
        &repeating_text_words_str[i]
    );
    assert(actual_pair_value_const != NULL);

    value_compare_result = value_functions->compare(
        actual_pair_value_const,
        &repeating_text_counts[i]
    );
    assert(value_compare_result == 0);
  }

  Mdc_Map_Deinit(&map);

  assert(Mdc_GetMallocDifference() == malloc_diff_start);
}

static void Mdc_Map_AssertEmplaceKeyCopy(void) {
  const struct Mdc_MapMetadata* const map_metadata =
      Mdc_MapStringInt_GetGlobalMapMetadata();
  const struct Mdc_PairMetadata* const pair_metadata =
      map_metadata->pair_metadata;
  const struct Mdc_ObjectMetadata* const key_metadata =
      pair_metadata->first_metadata;
  const size_t key_size = key_metadata->size;
  const struct Mdc_ObjectFunctions* const key_functions =
      &key_metadata->functions;
  const struct Mdc_ObjectMetadata* const value_metadata =
      pair_metadata->second_metadata;
  const size_t value_size = value_metadata->size;
  const struct Mdc_ObjectFunctions* const value_functions =
      &value_metadata->functions;

  struct Mdc_Map map;
  struct Mdc_Map* init_map;

  int value_copy;
  int* init_value_copy;

  int* actual_pair_value;
  const int* actual_pair_value_const;

  size_t i;
  int value_compare_result;

  init_map = Mdc_Map_InitEmpty(&map, map_metadata);
  assert(init_map == &map);
  assert(map.metadata != NULL);
  assert(map.metadata == map_metadata);

  /* Insert the elements. */
  for (i = 0; i < kRepeatingTextCount; i += 1) {
    init_value_copy = Mdc_Integer_InitFromValue(&value_copy, 0);
    assert(init_value_copy == &value_copy);

    Mdc_Map_EmplaceKeyCopy(
        &map,
        &repeating_text_str[i],
        value_functions->init_copy,
        &value_copy
    );

    actual_pair_value = Mdc_Map_At(&map, &repeating_text_str[i]);
    Mdc_Integer_PreIncrement(actual_pair_value);

    Mdc_Integer_Deinit(&value_copy);
  }

  /* Check all of the elements. */
  for (i = 0; i < kRepeatingWordCountPairsCount; i += 1) {
    assert(Mdc_Map_Contains(&map, &repeating_text_words_str[i]));

    actual_pair_value_const = Mdc_Map_AtConst(
        &map,
        &repeating_text_words_str[i]
    );
    assert(actual_pair_value_const != NULL);

    value_compare_result = value_functions->compare(
        actual_pair_value_const,
        &repeating_text_counts[i]
    );
    assert(value_compare_result == 0);
  }

  Mdc_Map_Deinit(&map);

  assert(Mdc_GetMallocDifference() == malloc_diff_start);
}

static void Mdc_Map_AssertInsertOrAssignPair(void) {
  const struct Mdc_MapMetadata* const map_metadata =
      Mdc_MapStringInt_GetGlobalMapMetadata();
  const struct Mdc_PairMetadata* const pair_metadata =
      map_metadata->pair_metadata;
  const struct Mdc_ObjectMetadata* const key_metadata =
      pair_metadata->first_metadata;
  const size_t key_size = key_metadata->size;
  const struct Mdc_ObjectFunctions* const key_functions =
      &key_metadata->functions;
  const struct Mdc_ObjectMetadata* const value_metadata =
      pair_metadata->second_metadata;
  const size_t value_size = value_metadata->size;
  const struct Mdc_ObjectFunctions* const value_functions =
      &value_metadata->functions;

  struct Mdc_Map map;
  struct Mdc_Map* init_map;

  int value_copy;
  int* init_value_copy;

  struct Mdc_Pair pair;
  int* actual_pair_value;
  const int* actual_pair_value_const;

  size_t i;
  int value_compare_result;

  const struct Mdc_Pair* init_pair;

  init_map = Mdc_Map_InitEmpty(&map, map_metadata);
  assert(init_map == &map);
  assert(map.metadata != NULL);
  assert(map.metadata == map_metadata);

  /* Insert the elements. */
  for (i = 0; i < kRepeatingTextCount; i += 1) {
    init_value_copy = Mdc_Integer_InitFromValue(&value_copy, 0);
    assert(init_value_copy == &value_copy);

    if (!Mdc_Map_Contains(&map, &repeating_text_str[i])) {
      init_pair = Mdc_Pair_InitFromFirstCopySecondCopy(
          &pair,
          pair_metadata,
          &repeating_text_str[i],
          &value_copy
      );
      assert(init_pair == &pair);

      Mdc_Map_InsertOrAssignPair(&map, &pair);

      Mdc_Pair_Deinit(&pair);
    }

    actual_pair_value = Mdc_Map_At(&map, &repeating_text_str[i]);
    Mdc_Integer_PreIncrement(actual_pair_value);

    Mdc_Integer_Deinit(&value_copy);
  }

  /* Check all of the elements. */
  for (i = 0; i < kRepeatingWordCountPairsCount; i += 1) {
    assert(Mdc_Map_Contains(&map, &repeating_text_words_str[i]));

    actual_pair_value_const = Mdc_Map_AtConst(
        &map,
        &repeating_text_words_str[i]
    );
    assert(actual_pair_value != NULL);

    value_compare_result = value_functions->compare(
        actual_pair_value_const,
        &repeating_text_counts[i]
    );
    assert(value_compare_result == 0);
  }

  Mdc_Map_Deinit(&map);

  assert(Mdc_GetMallocDifference() == malloc_diff_start);
}

static void Mdc_Map_AssertInsertOrAssignPairCopy(void) {
  const struct Mdc_MapMetadata* const map_metadata =
      Mdc_MapStringInt_GetGlobalMapMetadata();
  const struct Mdc_PairMetadata* const pair_metadata =
      map_metadata->pair_metadata;
  const struct Mdc_ObjectMetadata* const key_metadata =
      pair_metadata->first_metadata;
  const size_t key_size = key_metadata->size;
  const struct Mdc_ObjectFunctions* const key_functions =
      &key_metadata->functions;
  const struct Mdc_ObjectMetadata* const value_metadata =
      pair_metadata->second_metadata;
  const size_t value_size = value_metadata->size;
  const struct Mdc_ObjectFunctions* const value_functions =
      &value_metadata->functions;

  struct Mdc_Map map;
  struct Mdc_Map* init_map;

  int value_copy;
  int* init_value_copy;

  struct Mdc_Pair pair;
  const struct Mdc_Pair* init_pair;

  int* actual_pair_value;
  const int* actual_pair_value_const;

  size_t i;
  int value_compare_result;

  init_map = Mdc_Map_InitEmpty(&map, map_metadata);
  assert(init_map == &map);
  assert(map.metadata != NULL);
  assert(map.metadata == map_metadata);

  /* Insert the elements. */
  for (i = 0; i < kRepeatingTextCount; i += 1) {
    init_value_copy = Mdc_Integer_InitFromValue(&value_copy, 0);

    if (!Mdc_Map_Contains(&map, &repeating_text_str[i])) {
      init_pair = Mdc_Pair_InitFromFirstCopySecondCopy(
          &pair,
          pair_metadata,
          &repeating_text_str[i],
          &value_copy
      );
      assert(init_pair == &pair);

      Mdc_Map_InsertOrAssignPairCopy(&map, &pair);

      Mdc_Pair_Deinit(&pair);
    }

    actual_pair_value = Mdc_Map_At(&map, &repeating_text_str[i]);
    Mdc_Integer_PreIncrement(actual_pair_value);

    Mdc_Integer_Deinit(&value_copy);
  }

  /* Check all of the elements. */
  for (i = 0; i < kRepeatingWordCountPairsCount; i += 1) {
    assert(Mdc_Map_Contains(&map, &repeating_text_words_str[i]));

    actual_pair_value_const = Mdc_Map_AtConst(
        &map,
        &repeating_text_words_str[i]
    );
    assert(actual_pair_value_const != NULL);

    value_compare_result = value_functions->compare(
        actual_pair_value_const,
        &repeating_text_counts[i]
    );
    assert(value_compare_result == 0);
  }

  Mdc_Map_Deinit(&map);

  assert(Mdc_GetMallocDifference() == malloc_diff_start);
}

static void Mdc_Map_AssertClear(void) {
  const struct Mdc_MapMetadata* const map_metadata =
      Mdc_MapStringInt_GetGlobalMapMetadata();
  const struct Mdc_PairMetadata* const pair_metadata =
      map_metadata->pair_metadata;
  const struct Mdc_ObjectMetadata* const key_metadata =
      pair_metadata->first_metadata;
  const size_t key_size = key_metadata->size;
  const struct Mdc_ObjectFunctions* const key_functions =
      &key_metadata->functions;
  const struct Mdc_ObjectMetadata* const value_metadata =
      pair_metadata->second_metadata;
  const size_t value_size = value_metadata->size;
  const struct Mdc_ObjectFunctions* const value_functions =
      &value_metadata->functions;

  struct Mdc_Map map;
  struct Mdc_Map* init_map;

  int value_copy;
  int* init_value_copy;

  struct Mdc_Pair pair;
  const struct Mdc_Pair* init_pair;

  int* actual_pair_value;

  size_t i;

  init_map = Mdc_Map_InitEmpty(&map, map_metadata);
  assert(init_map == &map);
  assert(map.metadata != NULL);
  assert(map.metadata == map_metadata);

  /* Insert the elements. */
  for (i = 0; i < kRepeatingTextCount; i += 1) {
    init_value_copy = Mdc_Integer_InitFromValue(&value_copy, 0);

    if (!Mdc_Map_Contains(&map, &repeating_text_str[i])) {
      init_pair = Mdc_Pair_InitFromFirstCopySecondCopy(
          &pair,
          pair_metadata,
          &repeating_text_str[i],
          &value_copy
      );
      assert(init_pair == &pair);

      Mdc_Map_InsertOrAssignPairCopy(&map, &pair);

      Mdc_Pair_Deinit(&pair);
    }

    actual_pair_value = Mdc_Map_At(&map, &repeating_text_str[i]);
    Mdc_Integer_PreIncrement(actual_pair_value);

    Mdc_Integer_Deinit(&value_copy);
  }

  /* Clear all of the elements. */
  Mdc_Map_Clear(&map);

  assert(Mdc_Map_Empty(&map));

  Mdc_Map_Deinit(&map);

  assert(Mdc_GetMallocDifference() == malloc_diff_start);
}

static void Mdc_Map_AssertErase(void) {
  const struct Mdc_MapMetadata* const map_metadata =
      Mdc_MapStringInt_GetGlobalMapMetadata();
  const struct Mdc_PairMetadata* const pair_metadata =
      map_metadata->pair_metadata;
  const struct Mdc_ObjectMetadata* const key_metadata =
      pair_metadata->first_metadata;
  const size_t key_size = key_metadata->size;
  const struct Mdc_ObjectFunctions* const key_functions =
      &key_metadata->functions;
  const struct Mdc_ObjectMetadata* const value_metadata =
      pair_metadata->second_metadata;
  const size_t value_size = value_metadata->size;
  const struct Mdc_ObjectFunctions* const value_functions =
      &value_metadata->functions;

  struct Mdc_Map map;
  struct Mdc_Map* init_map;

  int value_copy;
  int* init_value_copy;

  struct Mdc_Pair pair;
  const struct Mdc_Pair* init_pair;
  int* actual_pair_value;

  size_t i;

  init_map = Mdc_Map_InitEmpty(&map, map_metadata);
  assert(init_map == &map);
  assert(map.metadata != NULL);
  assert(map.metadata == map_metadata);

  /* Insert the elements. */
  for (i = 0; i < kRepeatingTextCount; i += 1) {
    init_value_copy = Mdc_Integer_InitFromValue(&value_copy, 0);

    if (!Mdc_Map_Contains(&map, &repeating_text_str[i])) {
      init_pair = Mdc_Pair_InitFromFirstCopySecondCopy(
          &pair,
          pair_metadata,
          &repeating_text_str[i],
          &value_copy
      );
      assert(init_pair == &pair);

      Mdc_Map_InsertOrAssignPairCopy(&map, &pair);

      Mdc_Pair_Deinit(&pair);
    }

    actual_pair_value = Mdc_Map_At(&map, &repeating_text_str[i]);
    Mdc_Integer_PreIncrement(actual_pair_value);

    Mdc_Integer_Deinit(&value_copy);
  }

  /* Erase all of the elements. */
  for (i = 0; i < kRepeatingWordCountPairsCount; i += 1) {
    assert(Mdc_Map_Contains(&map, &repeating_text_words_str[i]));
    assert(Mdc_Map_Erase(&map, &repeating_text_words_str[i]));
    assert(!Mdc_Map_Contains(&map, &repeating_text_words_str[i]));
  }

  assert(Mdc_Map_Empty(&map));

  Mdc_Map_Deinit(&map);

  assert(Mdc_GetMallocDifference() == malloc_diff_start);
}

static void Init(void) {
  size_t i;

  struct Mdc_BasicString* init_str;
  int* init_integer;

  for (i = 0; i < kBasicExampleTextCount; i += 1) {
    init_str = Mdc_BasicString_InitFromCStr(
        &basic_example_text_str[i],
        Mdc_CharTraitsChar_GetCharTraits(),
        kBasicExampleText[i]
    );
    assert(init_str == &basic_example_text_str[i]);
    assert(Mdc_BasicString_EqualCStr(
        &basic_example_text_str[i],
        kBasicExampleText[i]
    ));
  }

  for (i = 0; i < kRepeatingTextCount; i += 1) {
    init_str = Mdc_BasicString_InitFromCStr(
        &repeating_text_str[i],
        Mdc_CharTraitsChar_GetCharTraits(),
        kRepeatingText[i]
    );
    assert(init_str == &repeating_text_str[i]);
    assert(Mdc_BasicString_EqualCStr(
        &repeating_text_str[i],
        kRepeatingText[i]
    ));
  }

  for (i = 0; i < kRepeatingWordCountPairsCount; i += 1) {
    init_str = Mdc_BasicString_InitFromCStr(
        &repeating_text_words_str[i],
        Mdc_CharTraitsChar_GetCharTraits(),
        kRepeatingTextWords[i]
    );
    assert(init_str == &repeating_text_words_str[i]);
    assert(Mdc_BasicString_EqualCStr(
        &repeating_text_words_str[i],
        kRepeatingTextWords[i]
    ));

    init_integer = Mdc_Integer_InitFromValue(
        &repeating_text_counts[i],
        kRepeatingTextCounts[i]
    );
    assert(init_integer == &repeating_text_counts[i]);
    assert(Mdc_Integer_EqualValue(
        &repeating_text_counts[i],
        kRepeatingTextCounts[i]
    ));
  }

  malloc_diff_start = Mdc_GetMallocDifference();
  assert(Mdc_GetMallocDifference() == malloc_diff_start);
}

static void Deinit(void) {
  size_t i;

  for (i = 0; i < kRepeatingWordCountPairsCount; i += 1) {
    Mdc_Integer_Deinit(&repeating_text_counts[i]);
    Mdc_BasicString_Deinit(&repeating_text_words_str[i]);
  }

  for (i = 0; i < kRepeatingTextCount; i += 1) {
    Mdc_BasicString_Deinit(&repeating_text_str[i]);
  }

  for (i = 0; i < kBasicExampleTextCount; i += 1) {
    Mdc_BasicString_Deinit(&basic_example_text_str[i]);
  }

  malloc_diff_start = Mdc_GetMallocDifference();
  assert(Mdc_GetMallocDifference() == 0);
}

void Mdc_Map_RunTests(void) {
  Init();

  Mdc_Map_AssertInitDeinit();
  Mdc_Map_AssertEmplace();
  Mdc_Map_AssertEmplaceKeyCopy();
  Mdc_Map_AssertInsertOrAssignPair();
  Mdc_Map_AssertInsertOrAssignPairCopy();
  Mdc_Map_AssertClear();
  Mdc_Map_AssertErase();

  Deinit();
}
