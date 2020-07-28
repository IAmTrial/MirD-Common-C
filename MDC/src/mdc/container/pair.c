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

#include "../../../include/mdc/container/pair.h"

#include <stdlib.h>

struct Mdc_Pair* Mdc_Pair_InitFirstSecond(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    void* first,
    void* second
) {
  const struct Mdc_PairFirstFunctions* const first_functions =
      &metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const second_functions =
      &metadata->functions.second_functions;

  const void* init_first_move;
  const void* init_second_move;

  /* Copy the pair metadata. */
  pair->metadata = malloc(sizeof(*pair->metadata));

  if (pair->metadata == NULL) {
    goto return_bad;
  }

  *pair->metadata = *metadata;

  /* Move-assign the first. */
  pair->first = malloc(metadata->size.first_size);

  if (pair->first == NULL) {
    goto free_metadata_copy;
  }

  init_first_move = first_functions->init_move(pair->first, first);

  if (init_first_move != pair->first) {
    goto free_first_move;
  }

  /* Move-assign the second. */
  pair->second = malloc(metadata->size.second_size);

  if (pair->second == NULL) {
    goto deinit_first_move;
  }

  init_second_move = second_functions->init_move(pair->second, second);

  if (init_second_move != pair->second) {
    goto free_second_move;
  }

  return pair;

free_second_move:
  free(pair->second);
  pair->second = NULL;

deinit_first_move:
  first_functions->deinit(pair->first);

free_first_move:
  free(pair->first);
  pair->first = NULL;

free_metadata_copy:
  free(pair->metadata);
  pair->metadata = NULL;

return_bad:
  return NULL;
}

struct Mdc_Pair* Mdc_Pair_InitFirstSecondCopy(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    void* first,
    const void* second
) {
  const struct Mdc_PairFirstFunctions* const first_functions =
      &metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const second_functions =
      &metadata->functions.second_functions;

  const void* init_first_move;
  const void* init_second_copy;

  /* Copy the pair metadata. */
  pair->metadata = malloc(sizeof(*pair->metadata));

  if (pair->metadata == NULL) {
    goto return_bad;
  }

  *pair->metadata = *metadata;

  /* Move-assign the first. */
  pair->first = malloc(metadata->size.first_size);

  if (pair->first == NULL) {
    goto free_metadata_copy;
  }

  init_first_move = first_functions->init_move(pair->first, first);

  if (init_first_move != pair->first) {
    goto free_first_move;
  }

  /* Copy-assign the second. */
  pair->second = malloc(metadata->size.second_size);

  if (pair->second == NULL) {
    goto deinit_first_move;
  }

  init_second_copy = second_functions->init_copy(pair->second, second);

  if (init_second_copy != pair->second) {
    goto free_second_copy;
  }

  return pair;

free_second_copy:
  free(pair->second);
  pair->second = NULL;

deinit_first_move:
  first_functions->deinit(pair->first);

free_first_move:
  free(pair->first);
  pair->first = NULL;

free_metadata_copy:
  free(pair->metadata);
  pair->metadata = NULL;

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
  const struct Mdc_PairSecondFunctions* const second_functions =
      &metadata->functions.second_functions;

  const void* init_first_copy;
  const void* init_second_move;

  /* Copy the pair metadata. */
  pair->metadata = malloc(sizeof(*pair->metadata));

  if (pair->metadata == NULL) {
    goto return_bad;
  }

  *pair->metadata = *metadata;

  /* Copy-assign the first. */
  pair->first = malloc(metadata->size.first_size);

  if (pair->first == NULL) {
    goto free_metadata_copy;
  }

  init_first_copy = first_functions->init_copy(pair->first, first);

  if (init_first_copy != pair->first) {
    goto free_first_copy;
  }

  /* Move-assign the second. */
  pair->second = malloc(metadata->size.second_size);

  if (pair->second == NULL) {
    goto deinit_first_copy;
  }

  init_second_move = second_functions->init_move(pair->second, second);

  if (init_second_move != pair->second) {
    goto free_second_move;
  }

  return pair;

free_second_move:
  free(pair->second);
  pair->second = NULL;

deinit_first_copy:
  first_functions->deinit(pair->first);

free_first_copy:
  free(pair->first);
  pair->first = NULL;

free_metadata_copy:
  free(pair->metadata);
  pair->metadata = NULL;

return_bad:
  return NULL;
}

struct Mdc_Pair* Mdc_Pair_InitFirstCopySecondCopy(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    const void* first,
    const void* second
) {
  const struct Mdc_PairFirstFunctions* const first_functions =
      &metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const second_functions =
      &metadata->functions.second_functions;

  const void* init_first_copy;
  const void* init_second_copy;

  /* Copy the pair metadata. */
  pair->metadata = malloc(sizeof(*pair->metadata));

  if (pair->metadata == NULL) {
    goto return_bad;
  }

  *pair->metadata = *metadata;

  /* Copy-assign the first. */
  pair->first = malloc(metadata->size.first_size);

  if (pair->first == NULL) {
    goto free_metadata_copy;
  }

  init_first_copy = first_functions->init_copy(pair->first, first);

  if (init_first_copy != pair->first) {
    goto free_first_copy;
  }

  /* Copy-assign the second. */
  pair->second = malloc(metadata->size.second_size);

  if (pair->second == NULL) {
    goto deinit_first_copy;
  }

  init_second_copy = second_functions->init_copy(pair->second, second);

  if (init_second_copy != pair->second) {
    goto free_second_copy;
  }

  return pair;

free_second_copy:
  free(pair->second);
  pair->second = NULL;

deinit_first_copy:
  first_functions->deinit(pair->first);

free_first_copy:
  free(pair->first);
  pair->first = NULL;

free_metadata_copy:
  free(pair->metadata);
  pair->metadata = NULL;

return_bad:
  return NULL;
}

struct Mdc_Pair* Mdc_Pair_InitCopy(
    struct Mdc_Pair* dest,
    const struct Mdc_Pair* src
) {
  return Mdc_Pair_InitFirstCopySecondCopy(
      dest,
      src->metadata,
      src->first,
      src->second
  );
}

struct Mdc_Pair* Mdc_Pair_InitMove(
    struct Mdc_Pair* dest,
    struct Mdc_Pair* src
) {
  return Mdc_Pair_InitFirstSecond(
      dest,
      src->metadata,
      src->first,
      src->second
  );
}

void Mdc_Pair_Deinit(struct Mdc_Pair* pair) {
  const struct Mdc_PairMetadata* const metadata = pair->metadata;
  const struct Mdc_PairFirstFunctions* const first_functions =
      &metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const second_functions =
      &metadata->functions.second_functions;

  second_functions->deinit(pair->second);
  free(pair->second);
  pair->second = NULL;

  first_functions->deinit(pair->first);
  free(pair->first);
  pair->first = NULL;

  free(pair->metadata);
  pair->metadata = NULL;
}

int Mdc_Pair_Compare(
    const struct Mdc_Pair* pair1,
    const struct Mdc_Pair* pair2
) {
  const struct Mdc_PairFirstFunctions* const first_functions =
      &pair1->metadata->functions.first_functions;
  const struct Mdc_PairSecondFunctions* const second_functions =
      &pair1->metadata->functions.second_functions;

  int first_compare_result;
  int second_compare_result;

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
