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

#ifndef MDC_C_CONTAINER_MAP_H_
#define MDC_C_CONTAINER_MAP_H_

#include <stddef.h>

#include "../std/stdbool.h"
#include "pair.h"

struct Mdc_MapMetadata {
  struct Mdc_PairMetadata pair_metadata;
};

struct Mdc_Map {
  struct Mdc_MapMetadata* metadata;

  struct Mdc_Pair** pairs;
  size_t count;
  size_t capacity;
};

/**
 * Initializes the map.
 *
 * @param[out] map this map
 * @param[in] metadata the map metadata
 * @return this map if successful, otherwise NULL
 */
struct Mdc_Map* Mdc_Map_Init(
    struct Mdc_Map* map,
    const struct Mdc_MapMetadata* metadata
);

/**
 * Initializes the destination map by copying the source map.
 *
 * @param[out] dest destination pair
 * @param[in] src source pair
 * @return dest if successful, otherwise NULL
 */
struct Mdc_Map* Mdc_Map_InitCopy(
    struct Mdc_Map* dest,
    const struct Mdc_Map* src
);

/**
 * Initializes the destination map by moving the source map.
 *
 * @param[out] dest destination pair
 * @param[in] src source pair
 * @return dest if successful, otherwise NULL
 */
struct Mdc_Map* Mdc_Map_InitMove(
    struct Mdc_Map* dest,
    struct Mdc_Map* src
);

/**
 * Deinitializes the map.
 *
 * @param[in, out] map this map
 */
void Mdc_Map_Deinit(struct Mdc_Map* map);

/**
 * Returns the value mapped to the specified key. If no such key
 * mapping found, then the null pointer is returned.
 *
 * @param[in] map this map
 * @param[in] key the key of the element to locate
 * @return the value mapped to the key, otherwise NULL
 */
void* Mdc_Map_At(struct Mdc_Map* map, const void* key);

/**
 * Returns the value mapped to the specified key. If no such key
 * mapping found, then the null pointer is returned.
 *
 * @param[in] map this map
 * @param[in] key the key of the element to locate
 * @return the value mapped to the key, otherwise NULL
 */
const void* Mdc_Map_AtConst(const struct Mdc_Map* map, const void* key);

/**
 * Clear all entries in the map.
 *
 * @param[in, out] map this map
 */
void Mdc_Map_Clear(struct Mdc_Map* map);

/**
 * Returns whether or not the map contains a mapping for the specified
 * key.
 *
 * @param[in] map this map
 * @param[in] key the key of the element to check
 */
bool Mdc_Map_Contains(const struct Mdc_Map* map, const void* key);

/**
 * Emplaces a pair into the map. The emplaced pair is allocated by
 * this function and its value is initialized by the specified
 * function. The key is move-assigned to the emplaced pair. If the
 * specified key is found in the map, this function does nothing.
 *
 * @param[in, out] map this map
 * @param[in] key the key to emplace into a new pair
 * @param[in] value_init_function the value initialization function
 * @param[in] params the parameters to pass into the value
 *    initialization function
 */
void Mdc_Map_Emplace(
    struct Mdc_Map* map,
    void* key,
    void* (*value_init_function)(void*, void*),
    void* params
);

/**
 * Emplaces a pair into the map. The emplaced pair is allocated by
 * this function and its value is initialized by the specified
 * function. The key is copy-assigned to the emplaced pair. If the
 * specified key is found in the map, this function does nothing.
 *
 * @param[in, out] map this map
 * @param[in] key the key to emplace into a new pair
 * @param[in] value_init_function the value initialization function
 * @param[in] params the parameters to pass into the value
 *    initialization function
 */
void Mdc_Map_EmplaceKeyCopy(
    struct Mdc_Map* map,
    const void* key,
    void* (*value_init_function)(void*, void*),
    void* params
);

/**
 * Returns whether the map contains any key-mappings.
 *
 * @param map this map
 * @return true if the map contains any key-mapping, otherwise false
 */
bool Mdc_Map_Empty(const struct Mdc_Map* map);

/**
 * Removes the pair that is mapped to the specified key.
 *
 * @param[in, out] map this map
 * @param[in] key the key of the element to remove
 * @return whether the element was erased or not
 */
bool Mdc_Map_Erase(struct Mdc_Map* map, const void* key);

/**
 * Returns a pointer-to-pointer-to-pair with the specified key. If
 * the key is not found, then the null pointer is returned.
 *
 * @param[in, out] map this map
 * @param[in] key the key of the element to find
 * @return the pointer-to-pointer-to-pair that contains the key,
 *      otherwise NULL
 */
struct Mdc_Pair** Mdc_Map_Find(struct Mdc_Map* map, const void* key);

/**
 * Returns a pointer-to-pointer-to-pair with the specified key. If
 * the key is not found, then the null pointer is returned.
 *
 * @param[in, out] map this map
 * @param[in] key the key of the element to find
 * @return the pointer-to-pointer-to-pair that contains the key,
 *      otherwise NULL
 */
const struct Mdc_Pair** Mdc_Map_FindConst(
    const struct Mdc_Map* map,
    const void* key
);

/**
 * Inserts the pair into the map via move-assignment if there is no
 * key-mapping for the pair's key. Otherwise, replaces the previous
 * mapping with the specified pair via move-assignment. Returns the
 * pair if successful, otherwise the null pointer is returned.
 *
 * @param[in, out] map this map
 * @param[in] pair the pair to insert or assign
 */
void Mdc_Map_InsertOrAssignPair(
    struct Mdc_Map* map,
    struct Mdc_Pair* pair
);

/**
 * Inserts the pair into the map via copy-assignment if there is no
 * key-mapping for the pair's key. Otherwise, replaces the previous
 * mapping with the specified pair via move-assignment. Returns the
 * pair if successful, otherwise the null pointer is returned.
 *
 * @param[in, out] map this map
 * @param[in] pair the pair to insert or assign
 */
void Mdc_Map_InsertOrAssignPairCopy(
    struct Mdc_Map* map,
    const struct Mdc_Pair* new_pair
);

/**
 * Returns the number of keys in the map.
 *
 * @param map this map
 * @return the number of keys in the map
 */
size_t Mdc_Map_Size(const struct Mdc_Map* map);

/**
 * Compares two map metadatas and returns whether they are equal.
 *
 * @param[in] metadata1 the first metadata to compare
 * @param[in] metadata2 the second metadata to compare
 */
bool Mdc_MapMetadata_Equal(
    const struct Mdc_MapMetadata* metadata1,
    const struct Mdc_MapMetadata* metadata2
);

#endif /* MDC_C_CONTAINER_MAP_H_ */
