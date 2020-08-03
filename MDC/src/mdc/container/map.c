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

#include "../../../include/mdc/container/map.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

enum FILE_SCOPE_CONSTANTS_01 {
  kInitialCapacity = 2
};

/**
 * Static functions
 */

/**
 * Increases or decreases the capacity of this map. If the map's
 * pairs count is larger than the new capacity, the function does
 * nothing.
 */
static void Mdc_Map_SetCapacity(
    struct Mdc_Map* map,
    size_t new_capacity
) {
  struct Mdc_Pair** realloc_pairs_result;
  size_t realloc_pairs_size;

  if (new_capacity == map->capacity) {
    return;
  }

  if (new_capacity < map->count) {
    return;
  }

  realloc_pairs_size = new_capacity * sizeof(map->pairs[0]);

  realloc_pairs_result = realloc(
      map->pairs,
      realloc_pairs_size
  );

  map->pairs = realloc_pairs_result;
  map->capacity = new_capacity;
}

/**
 * Doubles the capacity when the elements count reaches the capacity,
 * and halves the capacity when the elements count reaches a quarter
 * of the capacity.
 */
static void Mdc_Map_SetCapacityOnPolicy(
    struct Mdc_Map* map
) {
  assert(map->count <= map->capacity);

  while (map->count == map->capacity) {
    Mdc_Map_SetCapacity(
        map,
        map->capacity * 2
    );
  }

  while (map->count < map->capacity / 4
      && map->capacity > kInitialCapacity) {
    Mdc_Map_SetCapacity(
        map,
        map->capacity / 2
    );
  }
}

static bool Mdc_Map_IsPairMetadataEqual(
    const struct Mdc_Map* map,
    const struct Mdc_Pair* pair
) {
  const struct Mdc_MapMetadata* const map_metadata = map->metadata;
  const struct Mdc_PairMetadata* const pair_metadata =
      &map_metadata->pair_metadata;

  int metadata_compare_result;

  if (pair_metadata == NULL) {
    return false;
  }

  metadata_compare_result = memcmp(
      pair_metadata,
      pair->metadata,
      sizeof(*pair_metadata)
  );

  return (metadata_compare_result == 0);
}

static int Mdc_Map_KeyCompare(
    const struct Mdc_Pair** pair1,
    const struct Mdc_Pair** pair2
) {
  const struct Mdc_PairMetadata* const pair_metadata =
      (*pair1)->metadata;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_metadata->functions.first_functions;

  return key_functions->compare((*pair1)->first, (*pair2)->first);
}

static int Mdc_Map_KeyCompareAsVoid(
    const void* pair1,
    const void* pair2
) {
  return Mdc_Map_KeyCompare(pair1, pair2);
}

static void Mdc_Map_InsertPair(
    struct Mdc_Map* map,
    struct Mdc_Pair* new_pair
) {
  const struct Mdc_Pair* init_pair_move;

  Mdc_Map_SetCapacityOnPolicy(map);

  map->pairs[map->count] = malloc(sizeof(*new_pair));

  if (map->pairs[map->count] == NULL) {
    goto return_bad;
  }

  init_pair_move = Mdc_Pair_InitMove(map->pairs[map->count], new_pair);

  if (init_pair_move != map->pairs[map->count]) {
    goto free_pair_move;
  }

  qsort(
      map->pairs,
      map->count + 1,
      sizeof(map->pairs[0]),
      &Mdc_Map_KeyCompareAsVoid
  );

  map->count += 1;
  return;

free_pair_move:
  free(map->pairs[map->count]);
  map->pairs[map->count] = NULL;

return_bad:
  return;
}

static void Mdc_Map_InsertPairCopy(
    struct Mdc_Map* map,
    const struct Mdc_Pair* new_pair
) {
  const struct Mdc_Pair* init_pair_copy;

  Mdc_Map_SetCapacityOnPolicy(map);

  map->pairs[map->count] = malloc(sizeof(*new_pair));

  if (map->pairs[map->count] == NULL) {
    goto return_bad;
  }

  init_pair_copy = Mdc_Pair_InitCopy(map->pairs[map->count], new_pair);

  if (init_pair_copy != map->pairs[map->count]) {
    goto free_pair_copy;
  }

  qsort(
      map->pairs,
      map->count + 1,
      sizeof(map->pairs[0]),
      &Mdc_Map_KeyCompareAsVoid
  );

  map->count += 1;
  return;

free_pair_copy:
  free(map->pairs[map->count]);
  map->pairs[map->count] = NULL;

return_bad:
  return;
}

/**
 * Deinits all elements in the map.
 *
 * @param[in, out] this map
 */
static void Mdc_Map_DeinitAllElements(struct Mdc_Map* map) {
  const size_t elements_count = Mdc_Map_Size(map);

  size_t i;

  for (i = 0; i < elements_count; i += 1) {
    Mdc_Pair_Deinit(map->pairs[i]);
  }
}

/**
 * Deinits the specified range of elements in the map, frees the
 * memory used for the individual elements, sets the pointer to NULL.
 * Sets the size after reordering the elements.
 *
 * @param[in, out] map this map
 * @param[in] i_start start index
 * @param[in] i_end end index (non-inclusive)
 */
static void Mdc_Map_DeinitAndFreeElements(
    struct Mdc_Map* map,
    size_t i_start,
    size_t i_end
) {
  const size_t old_map_count = Mdc_Map_Size(map);
  const size_t remove_count = i_end - i_start;

  size_t i;

  for (i = i_start; i < i_end; i += 1) {
    Mdc_Pair_Deinit(map->pairs[i]);
    free(map->pairs[i]);
    map->pairs[i] = NULL;
  }

  assert(i == i_end);

  for (; i < old_map_count; i += 1) {
    map->pairs[i - remove_count] = map->pairs[i];
    map->pairs[i] = NULL;
  }

  map->count = old_map_count - remove_count;
}

/**
 * External functions
 */

struct Mdc_Map* Mdc_Map_Init(
    struct Mdc_Map* map,
    const struct Mdc_MapMetadata* metadata
) {
  size_t pairs_size;

  /* Copy the metadata. */
  map->metadata = malloc(sizeof(*map->metadata));

  if (map->metadata == NULL) {
    goto return_bad;
  }

  *map->metadata = *metadata;

  /* Initialize the table. */
  pairs_size = kInitialCapacity * sizeof(map->pairs[0]);
  map->pairs = malloc(pairs_size);

  if (map->pairs == NULL) {
    goto free_metadata;
  }

  map->count = 0;
  map->capacity = kInitialCapacity;

  return map;

free_metadata:
  free(map->metadata);
  map->metadata = NULL;

return_bad:
  return NULL;
}

struct Mdc_Map* Mdc_Map_InitCopy(
    struct Mdc_Map* dest,
    const struct Mdc_Map* src
) {
  const struct Mdc_MapMetadata* const map_metadata = src->metadata;
  const struct Mdc_PairMetadata* const pair_metadata =
      &map_metadata->pair_metadata;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const value_functions =
      &pair_metadata->functions.second_functions;

  size_t i;

  const struct Mdc_Pair* init_pair_copy;

  /* Copy the metadata. */
  dest->metadata = malloc(sizeof(*dest->metadata));

  if (dest->metadata == NULL) {
    goto return_bad;
  }

  *dest->metadata = *map_metadata;

  /* Copy the pairs. */
  dest->pairs = malloc(src->capacity * sizeof(*dest->pairs));

  if (dest->pairs == NULL) {
    goto free_metadata_copy;
  }

  dest->capacity = src->capacity;

  for (i = 0; i < src->count; i += 1, dest->count += 1) {
    dest->pairs[i] = malloc(sizeof(*dest->pairs[i]));

    if (dest->pairs[i] == NULL) {
      goto deinit_and_free_pairs;
    }

    init_pair_copy = Mdc_Pair_InitCopy(dest->pairs[i], src->pairs[i]);

    if (init_pair_copy != dest->pairs[i]) {
      goto free_last_pair;
    }
  }

  return dest;

free_last_pair:
  free(dest->pairs[dest->count]);
  dest->pairs[dest->count] = NULL;

deinit_and_free_pairs:
  for (i = 0; (i + 1) < dest->count; i += 1) {
    Mdc_Pair_Deinit(dest->pairs[i]);
    free(dest->pairs[i]);
    dest->pairs[i] = NULL;
  }

  dest->count = 0;

  free(dest->pairs);
  dest->pairs = NULL;
  dest->capacity = 0;

free_metadata_copy:
  free(dest->metadata);
  dest->metadata = NULL;

return_bad:
  return NULL;
}

struct Mdc_Map* Mdc_Map_InitMove(
    struct Mdc_Map* dest,
    struct Mdc_Map* src
) {
  dest->metadata = malloc(sizeof(*dest->metadata));

  if (dest->metadata == NULL) {
    goto return_bad;
  }

  dest->pairs = src->pairs;
  dest->count = src->count;
  dest->capacity = src->capacity;

  src->pairs = NULL;
  src->count = 0;
  src->capacity = 0;

  return dest;

return_bad:
  return NULL;
}

void Mdc_Map_Deinit(struct Mdc_Map* map) {
  if (map->pairs != NULL) {
    Mdc_Map_DeinitAndFreeElements(map, 0, Mdc_Map_Size(map));

    free(map->pairs);
    map->pairs = NULL;
  }

  map->capacity = 0;

  if (map->metadata != NULL) {
    free(map->metadata);
    map->metadata = NULL;
  }
}

struct Mdc_Map* Mdc_Map_ReinitCopy(
    struct Mdc_Map* dest,
    const struct Mdc_Map* src
) {
  const struct Mdc_MapMetadata* const map_metadata = dest->metadata;
  const struct Mdc_PairMetadata* const pair_metadata =
      &map_metadata->pair_metadata;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const value_function =
      &pair_metadata->functions.second_functions;

  const size_t old_count = Mdc_Map_Size(dest);
  const size_t src_count = Mdc_Map_Size(src);
  const size_t src_size = src->capacity * sizeof(src->pairs[0]);

  struct Mdc_Pair** realloc_pairs;
  const struct Mdc_Pair* reinit_pair_copy;

  if (dest == src) {
    return dest;
  }

  if (!Mdc_MapMetadata_Equal(dest->metadata, src->metadata)) {
    goto return_bad;
  }

  /* Deallocate unnecessary resources. */
  if (old_count > src_count) {
    Mdc_Map_DeinitAndFreeElements(dest, src_count, old_count);

    realloc_pairs = realloc(dest->pairs, src_size);

    if (realloc_pairs == NULL) {
      goto free_pairs;
    }

    dest->pairs = realloc_pairs;
  }

  /* Copy elements. */
  for (dest->count = 0; dest->count < src_count; dest->count += 1) {
    dest->pairs[dest->count] = malloc(sizeof(*dest->pairs[0]));

    if (dest->pairs[dest->count] == NULL) {
      goto deinit_and_free_elements;
    }

    reinit_pair_copy = Mdc_Pair_ReinitCopy(
        dest->pairs[dest->count],
        src->pairs[dest->count]
    );

    if (reinit_pair_copy != dest->pairs[dest->count]) {
      goto free_last_element;
    }
  }

  return dest;

free_last_element:
  free(dest->pairs[dest->count]);
  dest->pairs[dest->count] = NULL;

deinit_and_free_elements:
  Mdc_Map_DeinitAndFreeElements(dest, 0, Mdc_Map_Size(dest));

free_pairs:
  free(dest->pairs);
  dest->pairs = NULL;

  free(dest->metadata);
  dest->metadata = NULL;

return_bad:
  return NULL;
}

struct Mdc_Map* Mdc_Map_ReinitMove(
    struct Mdc_Map* dest,
    struct Mdc_Map* src
) {
  if (dest == src) {
    return dest;
  }

  if (!Mdc_MapMetadata_Equal(dest->metadata, src->metadata)) {
    goto return_bad;
  }

  Mdc_Map_DeinitAndFreeElements(dest, 0, dest->count);
  free(dest->pairs);

  dest->pairs = src->pairs;
  dest->count = src->count;
  dest->capacity = src->capacity;

  src->pairs = NULL;
  src->count = 0;
  src->capacity = 0;

  return dest;

return_bad:
  return NULL;
}

void* Mdc_Map_At(struct Mdc_Map* map, const void* key) {
  return (void*) Mdc_Map_AtConst(map, key);
}

const void* Mdc_Map_AtConst(
    const struct Mdc_Map* map,
    const void* key
) {
  const struct Mdc_Pair** search_result;

  search_result = Mdc_Map_FindConst(map, key);

  if (search_result == NULL) {
    return NULL;
  }

  return (*search_result)->second;
}

void Mdc_Map_Clear(struct Mdc_Map* map) {
  size_t new_pairs_size;
  struct Mdc_Pair** realloc_result;

  if (Mdc_Map_Empty(map)) {
    return;
  }

  /* Remove all the elements. */
  Mdc_Map_DeinitAndFreeElements(map, 0, Mdc_Map_Size(map));

  /* Skip resize on the smallest capacity. */
  if (map->capacity <= kInitialCapacity) {
    return;
  }

  new_pairs_size = kInitialCapacity * sizeof(map->pairs[0]);
  realloc_result = realloc(map->pairs, new_pairs_size);

  /* If the reallocation failed, the capacity won't have changed, but at least the map was cleared. */
  if (realloc_result == NULL) {
    return;
  }

  map->pairs = realloc_result;
  map->capacity = kInitialCapacity;
}

bool Mdc_Map_Contains(const struct Mdc_Map* map, const void* key) {
  const struct Mdc_Pair** search_result;

  search_result = Mdc_Map_FindConst(map, key);

  return (search_result != NULL);
}

struct Mdc_Pair** Mdc_Map_Find(
    struct Mdc_Map* map,
    const void* key
) {
  return (struct Mdc_Pair**) Mdc_Map_FindConst(map, key);
}

const struct Mdc_Pair** Mdc_Map_FindConst(
    const struct Mdc_Map* map,
    const void* key
) {
  const struct Mdc_PairMetadata* const pair_metadata =
      &map->metadata->pair_metadata;
  const struct Mdc_PairFunctions* const pair_functions =
      &pair_metadata->functions;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_functions->first_functions;

  struct Mdc_Pair** search_result;

  struct Mdc_Pair search_pair;
  struct Mdc_Pair* search_pair_ptr;

  search_pair.first = key;
  search_pair.metadata = pair_metadata;

  search_pair_ptr = &search_pair;

  search_result = bsearch(
      &search_pair_ptr,
      map->pairs,
      map->count,
      sizeof(map->pairs[0]),
      &Mdc_Map_KeyCompareAsVoid
  );

  if (search_result == NULL) {
    return NULL;
  }

  return search_result;
}

void Mdc_Map_Emplace(
    struct Mdc_Map* map,
    void* key,
    void* (*value_init_function)(void*, void*),
    void* params
) {
  const struct Mdc_MapMetadata* const map_metadata = map->metadata;
  const struct Mdc_PairMetadata* const pair_metadata =
      &map_metadata->pair_metadata;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const value_functions =
      &pair_metadata->functions.second_functions;

  struct Mdc_Pair new_pair;
  void* value;

  const struct Mdc_Pair* init_pair;
  const void* init_value;

  /* If the key exists, do nothing. */
  if (Mdc_Map_Contains(map, key)) {
    return;
  }

  /* In-place instantiate the value. */
  value = malloc(pair_metadata->size.second_size);

  if (value == NULL) {
    goto return_bad;
  }

  init_value = value_init_function(value, params);

  if (init_value != value) {
    goto free_value;
  }

  /* Initialize the pair. */
  init_pair = Mdc_Pair_InitFirstSecond(
      &new_pair,
      pair_metadata,
      key,
      value
  );

  if (init_pair != &new_pair) {
    goto deinit_value;
  }

  /* Move-insert the pair into the map. */
  Mdc_Map_InsertPair(map, &new_pair);

  free(value);

  return;

deinit_value:
  value_functions->deinit(value);

free_value:
  free(value);

return_bad:
  return;
}

void Mdc_Map_EmplaceKeyCopy(
    struct Mdc_Map* map,
    const void* key,
    void* (*value_init_function)(void*, void*),
    void* params
) {
  const struct Mdc_MapMetadata* const map_metadata = map->metadata;
  const struct Mdc_PairMetadata* const pair_metadata =
      &map_metadata->pair_metadata;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const value_functions =
      &pair_metadata->functions.second_functions;

  struct Mdc_Pair new_pair;
  void* value;

  const struct Mdc_Pair* init_pair;
  const void* init_value;

  /* If the key exists, do nothing. */
  if (Mdc_Map_Contains(map, key)) {
    return;
  }

  /* In-place instantiate the value. */
  value = malloc(pair_metadata->size.second_size);

  if (value == NULL) {
    goto return_bad;
  }

  init_value = value_init_function(value, params);

  if (init_value != value) {
    goto free_value;
  }

  /* Initialize the pair. */
  init_pair = Mdc_Pair_InitFirstCopySecond(
      &new_pair,
      pair_metadata,
      key,
      value
  );

  if (init_pair != &new_pair) {
    goto deinit_value;
  }

  /* Move-insert the pair into the map. */
  Mdc_Map_InsertPair(map, &new_pair);

  free(value);

  return;

deinit_value:
  value_functions->deinit(value);

free_value:
  free(value);

return_bad:
  return;
}

bool Mdc_Map_Empty(const struct Mdc_Map* map) {
  return Mdc_Map_Size(map) == 0;
}

bool Mdc_Map_Erase(struct Mdc_Map* map, const void* key) {
  const struct Mdc_PairMetadata* const pair_metadata =
      &map->metadata->pair_metadata;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const value_functions =
      &pair_metadata->functions.second_functions;

  struct Mdc_Pair** find_pair_ptr;

  /* Search for the pair with the matching key. */
  find_pair_ptr = Mdc_Map_Find(map, key);

  if (find_pair_ptr == NULL) {
    return false;
  }

  Mdc_Pair_Deinit(*find_pair_ptr);
  free(*find_pair_ptr);

  *find_pair_ptr = map->pairs[map->count - 1];
  map->pairs[map->count - 1] = NULL;

  map->count -= 1;

  qsort(
      map->pairs,
      map->count,
      sizeof(map->pairs[0]),
      &Mdc_Map_KeyCompareAsVoid
  );

  return true;
}

void Mdc_Map_InsertOrAssignPair(
    struct Mdc_Map* map,
    struct Mdc_Pair* new_pair
) {
  const struct Mdc_PairMetadata* const pair_metadata =
      &map->metadata->pair_metadata;
  const struct Mdc_PairFunctions* const pair_functions =
      &pair_metadata->functions;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_functions->first_functions;
  const struct Mdc_PairSecondFunctions* const value_functions =
      &pair_functions->second_functions;

  const struct Mdc_Pair* init_pair_move;
  struct Mdc_Pair** find_pair;

  if (!Mdc_Map_IsPairMetadataEqual(map, new_pair)) {
    return;
  }

  /* If element exists, move-assign value. Otherwise, insert into map. */
  find_pair = Mdc_Map_Find(map, new_pair->first);

  if (find_pair == NULL) {
    Mdc_Map_InsertPair(map, new_pair);
    return;
  }

  assert(*find_pair != NULL);

  Mdc_Pair_Deinit(*find_pair);
  init_pair_move = Mdc_Pair_InitMove(*find_pair, new_pair);

  if (init_pair_move != *find_pair) {
    goto return_bad;
  }

  return;

return_bad:
  return;
}

void Mdc_Map_InsertOrAssignPairCopy(
    struct Mdc_Map* map,
    const struct Mdc_Pair* new_pair
) {
  const struct Mdc_PairMetadata* const pair_metadata =
      &map->metadata->pair_metadata;
  const struct Mdc_PairFunctions* const pair_functions =
      &pair_metadata->functions;
  const struct Mdc_PairFirstFunctions* const key_functions =
      &pair_functions->first_functions;
  const struct Mdc_PairSecondFunctions* const value_functions =
      &pair_functions->second_functions;

  struct Mdc_Pair** find_pair_ptr;
  struct Mdc_Pair* init_pair_copy;

  if (!Mdc_Map_IsPairMetadataEqual(map, new_pair)) {
    goto return_bad;
  }

  /* If element exists, copy-assign value. Otherwise, insert into map. */
  find_pair_ptr = Mdc_Map_Find(map, new_pair->first);

  if (find_pair_ptr == NULL) {
    Mdc_Map_InsertPairCopy(map, new_pair);
    return;
  }

  assert(*find_pair_ptr != NULL);

  Mdc_Pair_Deinit(*find_pair_ptr);
  init_pair_copy = Mdc_Pair_InitCopy(*find_pair_ptr, new_pair);

  if (init_pair_copy != *find_pair_ptr) {
    goto return_bad;
  }

  return;

return_bad:
  return;
}

size_t Mdc_Map_MaxSize(const struct Mdc_Map* map) {
  const struct Mdc_MapMetadata* const map_metadata = map->metadata;
  const struct Mdc_PairMetadata* const pair_metadata =
      &map_metadata->pair_metadata;

  size_t non_elements_size;
  size_t element_size;

  non_elements_size = sizeof(map_metadata)
      + sizeof(*map_metadata)
      + sizeof(map->count)
      + sizeof(map->capacity)
      + sizeof(map->pairs);

  element_size = sizeof(map->pairs[0])
      + sizeof(*map->pairs[0])
      + pair_metadata->size.first_size
      + pair_metadata->size.second_size;

  return (((size_t) -1) - non_elements_size) / element_size;
}

size_t Mdc_Map_Size(const struct Mdc_Map* map) {
  return map->count;
}

void Mdc_Map_Swap(struct Mdc_Map* map1, struct Mdc_Map* map2) {
  struct Mdc_Map temp;

  temp = *map1;
  *map1 = *map2;
  *map2 = temp;
}

bool Mdc_MapMetadata_Equal(
    const struct Mdc_MapMetadata* metadata1,
    const struct Mdc_MapMetadata* metadata2
) {
  int metadata_compare_result;

  if (metadata1 == metadata2) {
    return true;
  }

  metadata_compare_result = memcmp(
      metadata1,
      metadata2,
      sizeof(*metadata1)
  );

  return (metadata_compare_result == 0);
}
