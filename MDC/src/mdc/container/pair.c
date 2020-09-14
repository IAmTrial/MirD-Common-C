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
#include <string.h>

/**
 * Static
 */

#define MDC_PAIR_UNINIT { 0 }

static const struct Mdc_Pair Mdc_Pair_kUninit = MDC_PAIR_UNINIT;

/**
 * External
 */

/**
 * Initialization/deinitialization
 */

struct Mdc_Pair* Mdc_Pair_InitDefault(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata
) {
  const struct Mdc_ObjectMetadata* const first_metadata =
      metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  const void* init_first;
  const void* init_second;

  pair->metadata = metadata;

  /* Allocate and init the first. */
  pair->first = malloc(first_metadata->size);
  if (pair->first == NULL) {
    goto return_bad;
  }

  init_first = first_functions->init_default(pair->first);
  if (init_first != pair->first) {
    goto free_first;
  }

  /* Allocate and init the second. */
  pair->second = malloc(second_metadata->size);
  if (pair->second == NULL) {
    goto deinit_first;
  }

  init_second = second_functions->init_default(pair->second);
  if (init_second != pair->second) {
    goto free_second;
  }

  return pair;

free_second:
  free(pair->second);

deinit_first:
  first_functions->deinit(pair->first);

free_first:
  free(pair->first);

return_bad:
  *pair = Mdc_Pair_kUninit;

  return NULL;
}

struct Mdc_Pair* Mdc_Pair_InitFromFirstSecond(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    void* first,
    void* second
) {
  const struct Mdc_ObjectMetadata* const first_metadata =
      metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  const void* init_first;
  const void* init_second;

  pair->metadata = metadata;

  /* Allocate and init the first. */
  pair->first = malloc(first_metadata->size);
  if (pair->first == NULL) {
    goto return_bad;
  }

  init_first = first_functions->init_move(pair->first, first);
  if (init_first != pair->first) {
    goto free_first;
  }

  /* Allocate and init the second. */
  pair->second = malloc(second_metadata->size);
  if (pair->second == NULL) {
    goto deinit_first;
  }

  init_second = second_functions->init_move(pair->second, second);
  if (init_second != pair->second) {
    goto free_second;
  }

  return pair;

free_second:
  free(pair->second);

deinit_first:
  first_functions->deinit(pair->first);

free_first:
  free(pair->first);

return_bad:
  *pair = Mdc_Pair_kUninit;

  return NULL;
}

struct Mdc_Pair* Mdc_Pair_InitFromFirstSecondCopy(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    void* first,
    const void* second
) {
  const struct Mdc_ObjectMetadata* const first_metadata =
      metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  const void* init_first;
  const void* init_second;

  pair->metadata = metadata;

  /* Allocate and init the first. */
  pair->first = malloc(first_metadata->size);
  if (pair->first == NULL) {
    goto return_bad;
  }

  init_first = first_functions->init_move(pair->first, first);
  if (init_first != pair->first) {
    goto free_first;
  }

  /* Allocate and init the second. */
  pair->second = malloc(second_metadata->size);
  if (pair->second == NULL) {
    goto deinit_first;
  }

  init_second = second_functions->init_copy(pair->second, second);
  if (init_second != pair->second) {
    goto free_second;
  }

  return pair;

free_second:
  free(pair->second);

deinit_first:
  first_functions->deinit(pair->first);

free_first:
  free(pair->first);

return_bad:
  *pair = Mdc_Pair_kUninit;

  return NULL;
}

struct Mdc_Pair* Mdc_Pair_InitFromFirstCopySecond(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    const void* first,
    void* second
) {
  const struct Mdc_ObjectMetadata* const first_metadata =
      metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  const void* init_first;
  const void* init_second;

  pair->metadata = metadata;

  /* Allocate and init the first. */
  pair->first = malloc(first_metadata->size);
  if (pair->first == NULL) {
    goto return_bad;
  }

  init_first = first_functions->init_copy(pair->first, first);
  if (init_first != pair->first) {
    goto free_first;
  }

  /* Allocate and init the second. */
  pair->second = malloc(second_metadata->size);
  if (pair->second == NULL) {
    goto deinit_first;
  }

  init_second = second_functions->init_move(pair->second, second);
  if (init_second != pair->second) {
    goto free_second;
  }

  return pair;

free_second:
  free(pair->second);

deinit_first:
  first_functions->deinit(pair->first);

free_first:
  free(pair->first);

return_bad:
  *pair = Mdc_Pair_kUninit;

  return NULL;
}

struct Mdc_Pair* Mdc_Pair_InitFromFirstCopySecondCopy(
    struct Mdc_Pair* pair,
    const struct Mdc_PairMetadata* metadata,
    const void* first,
    const void* second
) {
  const struct Mdc_ObjectMetadata* const first_metadata =
      metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  const void* init_first;
  const void* init_second;

  pair->metadata = metadata;

  /* Allocate and init the first. */
  pair->first = malloc(first_metadata->size);
  if (pair->first == NULL) {
    goto return_bad;
  }

  init_first = first_functions->init_copy(pair->first, first);
  if (init_first != pair->first) {
    goto free_first;
  }

  /* Allocate and init the second. */
  pair->second = malloc(second_metadata->size);
  if (pair->second == NULL) {
    goto deinit_first;
  }

  init_second = second_functions->init_copy(pair->second, second);
  if (init_second != pair->second) {
    goto free_second;
  }

  return pair;

free_second:
  free(pair->second);

deinit_first:
  first_functions->deinit(pair->first);

free_first:
  free(pair->first);

return_bad:
  *pair = Mdc_Pair_kUninit;

  return NULL;
}

struct Mdc_Pair* Mdc_Pair_InitCopy(
    struct Mdc_Pair* dest,
    const struct Mdc_Pair* src
) {
  return Mdc_Pair_InitFromFirstCopySecondCopy(
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
  return Mdc_Pair_InitFromFirstSecond(
      dest,
      src->metadata,
      src->first,
      src->second
  );
}

void Mdc_Pair_Deinit(struct Mdc_Pair* pair) {
  const struct Mdc_PairMetadata* const metadata = pair->metadata;
  const struct Mdc_ObjectMetadata* const first_metadata =
      metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  if (pair->second != NULL) {
    second_functions->deinit(pair->second);
    free(pair->second);
  }

  if (pair->first != NULL) {
    first_functions->deinit(pair->first);
    free(pair->first);
  }

  *pair = Mdc_Pair_kUninit;
}

struct Mdc_Pair* Mdc_Pair_AssignCopy(
    struct Mdc_Pair* dest,
    const struct Mdc_Pair* src
) {
  struct Mdc_Pair temp_pair;
  const struct Mdc_Pair* init_temp_pair;

  const struct Mdc_Pair* assign_dest;

  if (dest == src) {
    return dest;
  }

  init_temp_pair = Mdc_Pair_InitCopy(&temp_pair, src);
  if (init_temp_pair != &temp_pair) {
    goto return_bad;
  }

  assign_dest = Mdc_Pair_AssignMove(dest, &temp_pair);
  if (assign_dest != dest) {
    goto deinit_temp_pair;
  }

  Mdc_Pair_Deinit(&temp_pair);

  return dest;

deinit_temp_pair:
  Mdc_Pair_Deinit(&temp_pair);

return_bad:
  return NULL;
}

struct Mdc_Pair* Mdc_Pair_AssignMove(
    struct Mdc_Pair* dest,
    struct Mdc_Pair* src
) {
  const struct Mdc_PairMetadata* const pair_metadata = src->metadata;
  const struct Mdc_ObjectMetadata* const first_metadata =
      pair_metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      pair_metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  const void* assign_first;
  const void* assign_second;

  if (dest == src) {
    return dest;
  }

  /* Assign the first. */
  assign_first = first_functions->assign_move(dest->first, src->first);
  if (assign_first != dest->first) {
    goto return_bad;
  }

  /* Assign the second. */
  assign_second = second_functions->assign_move(dest->second, src->second);
  if (assign_second != dest->second) {
    goto return_bad;
  }

  return dest;

return_bad:
  return NULL;
}

bool Mdc_Pair_Equal(
    const struct Mdc_Pair* pair1,
    const struct Mdc_Pair* pair2
) {
  const struct Mdc_PairMetadata* const metadata = pair1->metadata;
  const struct Mdc_ObjectMetadata* const first_metadata =
      metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  if (pair1 == pair2) {
    return false;
  }

  if (first_functions->equal(pair1->first, pair2->first)) {
    return true;
  }

  return second_functions->equal(pair1->second, pair2->second);
}

int Mdc_Pair_Compare(
    const struct Mdc_Pair* pair1,
    const struct Mdc_Pair* pair2
) {
  const struct Mdc_PairMetadata* const metadata = pair1->metadata;
  const struct Mdc_ObjectMetadata* const first_metadata =
      metadata->first_metadata;
  const struct Mdc_ObjectFunctions* const first_functions =
      &first_metadata->functions;
  const struct Mdc_ObjectMetadata* const second_metadata =
      metadata->second_metadata;
  const struct Mdc_ObjectFunctions* const second_functions =
      &second_metadata->functions;

  int first_compare_result;
  int second_compare_result;

  if (pair1 == pair2) {
    return 0;
  }

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

void Mdc_Pair_Swap(
    struct Mdc_Pair* pair1,
    struct Mdc_Pair* pair2
) {
  struct Mdc_Pair temp;
  const struct Mdc_Pair* init_temp;

  const struct Mdc_Pair* assign_pair1;
  const struct Mdc_Pair* assign_pair2;

  if (pair1 == pair2) {
    return;
  }

  init_temp = Mdc_Pair_InitMove(&temp, pair1);
  if (init_temp != &temp) {
    goto return_bad;
  }

  assign_pair1 = Mdc_Pair_AssignMove(pair1, pair2);
  if (assign_pair1 != pair1) {
    goto deinit_temp;
  }

  assign_pair2 = Mdc_Pair_AssignMove(pair2, &temp);
  if (assign_pair2 != pair2) {
    goto unassign_pair1;
  }

  return;

unassign_pair1:
  assign_pair2 = Mdc_Pair_AssignMove(pair2, pair1);

deinit_temp:
  assign_pair1 = Mdc_Pair_AssignMove(pair1, &temp);
  Mdc_Pair_Deinit(&temp);


return_bad:
  return;
}

bool Mdc_PairMetadata_Equal(
    const struct Mdc_PairMetadata* metadata1,
    const struct Mdc_PairMetadata* metadata2
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
