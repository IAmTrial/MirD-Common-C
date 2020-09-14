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

#ifndef MDC_C_OBJECT_METADATA_OBJECT_METADATA_H_
#define MDC_C_OBJECT_METADATA_OBJECT_METADATA_H_

#include <stddef.h>

#include "../std/stdbool.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Mdc_ObjectFunctions {
  void* (*init_default)(void*);

  /**
   * Initializes the destination object by copying the source object.
   */
  void* (*init_copy)(void*, const void*);

  /**
   * Initializes the destination object by moving the source object.
   */
  void* (*init_move)(void*, void*);

  /**
   * Deinitializes the specified object.
   */
  void (*deinit)(void*);

  void* (*assign_copy)(void*, const void*);
  void* (*assign_move)(void*, void*);

  void* (*pre_increment)(void*);
  void* (*pre_decrement)(void*);
  void* (*post_increment)(void* out, void* in);
  void* (*post_decrement)(void* out, void* in);

  void* (*add)(void* out, const void* in1, const void* in2);
  void* (*subtract)(void* out, const void* in1, const void* in2);
  void* (*multiply)(void* out, const void* in1, const void* in2);
  void* (*divide)(void* out, const void* in1, const void* in2);
  void* (*modulo)(void* out, const void* in1, const void* in2);

  void* (*bitwise_not)(void* out, const void* in);
  void* (*bitwise_and)(void* out, const void* in1, const void* in2);
  void* (*bitwise_or)(void* out, const void* in1, const void* in2);
  void* (*bitwise_xor)(void* out, const void* in1, const void* in2);
  void* (*bitwise_left_shift)(void* out, const void* in1, const void* in2);
  void* (*bitwise_right_shift)(void* out, const void* in1, const void* in2);

  bool (*equal)(const void*, const void*);

  /**
   * Compares two objects. Returns 0 if they are the same, a negative
   * value if the first object is "less" than the second object, and a
   * positive value if the first object is "greater" than the second
   * object.
   */
  int (*compare)(const void*, const void*);

  size_t (*hash)(const void*);
  void (*swap)(void*, void*);
};


/*
* All sizes and init functions (except copy and move) in template
* object metadata need to be manually specialized.
*/

struct Mdc_ObjectMetadata {
  size_t size;
  struct Mdc_ObjectFunctions functions;
};

#define MDC_OBJECT_METADATA_UNINIT { 0 }

const struct Mdc_ObjectMetadata Mdc_ObjectMetadata_kUninit;

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_OBJECT_METADATA_OBJECT_METADATA_H_ */
