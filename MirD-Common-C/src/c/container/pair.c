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

#include "../../../include/c/container/pair.h"

#include <stdlib.h>

struct Mdc_Pair* Mdc_Pair_InitFirstSecond(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    void* first,
    void* second
) {
  /* Copy the pair metadata. */
  pair->metadata = (struct Mdc_PairMetadata*) malloc(sizeof(*pair->metadata));

  if (pair->metadata == NULL) {
    goto return_bad;
  }

  *pair->metadata = *metadata;

  /* Move-assign the first and second. */
  pair->first = first;
  pair->second = second;

  return pair;

return_bad:
  return NULL;
}

struct Mdc_Pair* Mdc_Pair_InitFirstSecondCopy(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    void* first,
    const void* second
) {
  const struct Mdc_PairSecondFunctions* const second_functions =
      &metadata->functions.second_functions;

  /* Copy the pair metadata. */
  pair->metadata = (struct Mdc_PairMetadata*) malloc(sizeof(*pair->metadata));

  if (pair->metadata == NULL) {
    goto return_bad;
  }

  *pair->metadata = *metadata;

  /* Move-assign the first. */
  pair->first = first;

  /* Copy-assign the second. */
  pair->second = malloc(metadata->size.second_size);

  if (pair->second == NULL) {
    goto free_metadata;
  }

  second_functions->init_copy(pair->second, second);

  return pair;

free_metadata:
  free(metadata);

return_bad:
  return NULL;
}

struct Mdc_Pair* Mdc_Pair_InitFirstCopySecond(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    const void* first,
    void* second
) {
  const struct Mdc_PairFirstFunctions* const first_functions =
      &metadata->functions.first_functions;

  /* Copy the pair metadata. */
  pair->metadata = (struct Mdc_PairMetadata*) malloc(sizeof(*pair->metadata));

  if (pair->metadata == NULL) {
    goto return_bad;
  }

  *pair->metadata = *metadata;

  /* Copy-assign the first. */
  pair->first = malloc(metadata->size.first_size);

  if (pair->first == NULL) {
    goto free_metadata;
  }

  first_functions->init_copy(pair->first, first);

  /* Move-assign the second. */
  pair->second = second;

  return pair;

free_metadata:
  free(metadata);

return_bad:
  return NULL;
}

struct Mdc_Pair* Mdc_Pair_InitFirstCopySecondCopy(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    const void* first,
    const void* second
) {
  const struct Mdc_Pair src = {
    (struct Mdc_PairMetadata*) metadata,
    (void*) first,
    (void*) second
  };

  return Mdc_Pair_InitCopy(pair, &src);
}

struct Mdc_Pair* Mdc_Pair_InitCopy(
    struct Mdc_Pair* dest,
    const struct Mdc_Pair* src
) {
  const struct Mdc_PairFunctions* pair_functions;
  const struct Mdc_PairSize* pair_size;

  /* Copy the pair metadata. */
  dest->metadata = (struct Mdc_PairMetadata*) malloc(sizeof(*dest->metadata));

  if (dest->metadata == NULL) {
    goto return_bad;
  }

  *dest->metadata = *src->metadata;

  /* Set aliases for pair metadata. */
  pair_functions = &dest->metadata->functions;
  pair_size = &dest->metadata->size;

  /* Copy the first from the source pair. */
  dest->first = malloc(pair_size->first_size);

  if (dest->first == NULL) {
    goto free_metadata;
  }

  pair_functions->first_functions.init_copy(dest->first, src->first);

  /* Copy the second from the source pair. */
  dest->second = malloc(pair_size->second_size);

  if (dest->second == NULL) {
    goto deinit_first;
  }

  pair_functions->second_functions.init_copy(
      dest->second,
      src->second
  );

  return dest;

deinit_second:
  pair_functions->second_functions.deinit(dest->second);

free_second:
  free(dest->second);

deinit_first:
  pair_functions->first_functions.deinit(dest->first);

free_first:
  free(dest->first);

free_metadata:
  free(dest->metadata);

return_bad:
  return NULL;
}

void Mdc_Pair_Deinit(struct Mdc_Pair* pair) {
  pair->metadata->functions.second_functions.deinit(pair->second);
  free(pair->second);

  pair->metadata->functions.first_functions.deinit(pair->first);
  free(pair->first);

  free(pair->metadata);
}

int Mdc_Pair_Compare(
    const struct Mdc_Pair* pair1,
    const struct Mdc_Pair* pair2
) {
  struct Mdc_PairFirstFunctions* first_functions;
  struct Mdc_PairSecondFunctions* second_functions;

  int first_compare_result;
  int second_compare_result;

  first_functions = &pair1->metadata->functions.first_functions;
  second_functions = &pair1->metadata->functions.second_functions;

  first_compare_result = first_functions->compare(
      pair1->first,
      pair2->first
  );

  if (first_compare_result != 0) {
    return first_compare_result;
  }

  second_compare_result = second_functions->compare(
      pair1->second,
      pair2->second
  );

  return second_compare_result;
}
