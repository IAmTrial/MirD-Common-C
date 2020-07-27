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

#ifndef MDC_C_CONTAINER_PAIR_H_
#define MDC_C_CONTAINER_PAIR_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Mdc_PairFirstFunctions {
  /**
   * Initializes the destination object by copying the source object.
   */
  void* (*init_copy)(void* dest, const void* src);

  /**
   * Deinitializes the specified object.
   */
  void (*deinit)(void* obj);

  /**
   * Compares two objects. Returns 0 if they are the same, a negative
   * value if the first object is "less" than the second object, and a
   * positive value if the first object is "greater" than the second
   * object.
   */
  int (*compare)(const void*, const void*);
};

struct Mdc_PairSecondFunctions {
  /**
   * Initializes the destination object by copying the source object.
   */
  void* (*init_copy)(void*, const void*);

  /**
   * Deinitializes the specified object.
   */
  void (*deinit)(void*);

  /**
   * Compares two objects. Returns 0 if they are the same, a negative
   * value if the first object is "less" than the second object, and a
   * positive value if the first object is "greater" than the second
   * object.
   */
  int (*compare)(const void*, const void*);
};

struct Mdc_PairSize {
  size_t first_size;
  size_t second_size;
};

struct Mdc_PairFunctions {
  struct Mdc_PairFirstFunctions first_functions;
  struct Mdc_PairSecondFunctions second_functions;
};

struct Mdc_PairMetadata {
  struct Mdc_PairSize size;
  struct Mdc_PairFunctions functions;
};

struct Mdc_Pair {
  struct Mdc_PairMetadata* metadata;

  void* first;
  void* second;
};

/**
 * Initializes the pair using the specified metadata for the type
 * information. The first and second are move-assigned into the pair.
 * The first and second must be allocated outside of this function,
 * where after initialization, they will be managed by the pair.
 *
 * @param[in, out] pair this pair
 * @param[in] metadata the metadata to copy
 * @param[in] first the first to move-assign
 * @param[in] second the second to move-assign
 * @return this pair if successful, otherwise NULL
 */
struct Mdc_Pair* Mdc_Pair_InitFirstSecond(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    void* first,
    void* second
);

/**
 * Initializes the pair using the specified metadata for the type
 * information. The first is move-assigned into the pair. The second
 * is copy-assigned into the pair.
 *
 * Requires:
 * Mdc_PairSecondFunctions.init_copy
 *
 * @param[in, out] pair this pair
 * @param[in] metadata the metadata to copy
 * @param[in] first the first to move-assign
 * @param[in] second the second to copy-assign
 * @return this pair if successful, otherwise NULL
 */
struct Mdc_Pair* Mdc_Pair_InitFirstSecondCopy(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    void* first,
    const void* second
);

/**
 * Initializes the pair using the specified metadata for the type
 * information. The first is copy-assigned into the pair. The second
 * is move-assigned into the pair.
 *
 * Requires:
 * Mdc_PairFirstFunctions.init_copy
 *
 * @param[in, out] pair this pair
 * @param[in] metadata the metadata to copy
 * @param[in] first the first to copy-assign
 * @param[in] second the second to move-assign
 * @return this pair if successful, otherwise NULL
 */
struct Mdc_Pair* Mdc_Pair_InitFirstCopySecond(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    const void* first,
    void* second
);

/**
 * Initializes the pair using the specified metadata for the type
 * information. The first is copy-assigned into the pair. The second
 * is copy-assigned into the pair.
 *
 * Requires:
 * Mdc_PairFirstFunctions.init_copy
 * Mdc_PairSecondFunctions.init_copy
 *
 * @param[in, out] pair this pair
 * @param[in] metadata the metadata to copy
 * @param[in] first the first to copy-assign
 * @param[in] second the second to copy-assign
 * @return this pair if successful, otherwise NULL
 */
struct Mdc_Pair* Mdc_Pair_InitFirstCopySecondCopy(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    const void* first,
    const void* second
);

/**
 * Initializes the destination pair by copying the source pair.
 *
 * Requires:
 * Mdc_PairFirstFunctions.init_copy
 * Mdc_PairSecondFunctions.init_copy
 *
 * @param[in, out] dest destination pair
 * @param[in] src source pair
 * @return dest if successful, otherwise NULL
 */
struct Mdc_Pair* Mdc_Pair_InitCopy(
    struct Mdc_Pair* dest,
    const struct Mdc_Pair* src
);

/**
 * Deinitializes the pair.
 *
 * Requires:
 * Mdc_PairFirstFunctions.deinit
 * Mdc_PairSecondFunctions.deinit
 *
 * @param[in, out] pair this pair
 */
void Mdc_Pair_Deinit(struct Mdc_Pair* pair);

/**
 * Compares the two pairs by their first values, and returns a
 * non-zero value if they are different. Otherwise, return a value
 * resulting from comparing their second values. Returns 0 if they are
 * the same, a negative value if the first pair is "less" than the
 * second pair, and a positive value if the first pair is "greater"
 * than the second pair.
 *
 * Requires:
 * Mdc_PairFirstFunctions.compare
 * Mdc_PairSecondFunctions.compare
 *
 * @param[in] pair1 first pair to compare
 * @param[in] pair2 second pair to compare
 * @return 0 if equal, < 0 if pair1 < pair2, > 0 if pair1 > pair2
 */
int Mdc_Pair_Compare(
    const struct Mdc_Pair* pair1,
    const struct Mdc_Pair* pair2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* MDC_C_CONTAINER_PAIR_H_ */
