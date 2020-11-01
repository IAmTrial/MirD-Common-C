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

#include "../../../include/mdc/object/integer_object.h"

#include "../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Object initialization/deinitialization
 */

static void* Mdc_Integer_InitDefaultAsVoid(void* integer) {
  return Mdc_Integer_InitDefault(integer);
}

static void* Mdc_Integer_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_Integer_InitCopy(dest, src);
}

static void* Mdc_Integer_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_Integer_InitMove(dest, src);
}

static void Mdc_Integer_DeinitAsVoid(void* integer) {
  Mdc_Integer_Deinit(integer);
}

/**
 * Object assignment functions
 */

static void* Mdc_Integer_AssignCopyAsVoid(void* dest, const void* src) {
  return Mdc_Integer_AssignCopy(dest, src);
}

static void* Mdc_Integer_AssignMoveAsVoid(void* dest, void* src) {
  return Mdc_Integer_AssignMove(dest, src);
}

/**
 * Object increment/decrement operators
 */

static void* Mdc_Integer_PreIncrementAsVoid(void* integer) {
  return Mdc_Integer_PreIncrement(integer);
}

static void* Mdc_Integer_PreDecrementAsVoid(void* integer) {
  return Mdc_Integer_PreDecrement(integer);
}

static void* Mdc_Integer_PostIncrementAsVoid(void* out, void* in) {
  return Mdc_Integer_PostIncrement(out, in);
}

static void* Mdc_Integer_PostDecrementAsVoid(void* out, void* in) {
  return Mdc_Integer_PostDecrement(out, in);
}

/**
 * Object arithmetic operators
 */

static void* Mdc_Integer_AddAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Integer_Add(out, op1, op2);
}

static void* Mdc_Integer_SubtractAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Integer_Subtract(out, op1, op2);
}

static void* Mdc_Integer_MultiplyAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Integer_Multiply(out, op1, op2);
}

static void* Mdc_Integer_DivideAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Integer_Divide(out, op1, op2);
}

static void* Mdc_Integer_ModuloAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Integer_Modulo(out, op1, op2);
}

static void* Mdc_Integer_BitwiseNotAsVoid(
    void* out,
    const void* in
) {
  return Mdc_Integer_BitwiseNot(out, in);
}

static void* Mdc_Integer_BitwiseAndAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Integer_BitwiseAnd(out, op1, op2);
}

static void* Mdc_Integer_BitwiseOrAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Integer_BitwiseOr(out, op1, op2);
}

static void* Mdc_Integer_BitwiseXorAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Integer_BitwiseXor(out, op1, op2);
}

static void* Mdc_Integer_BitwiseLeftShiftAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Integer_BitwiseLeftShift(out, op1, op2);
}

static void* Mdc_Integer_BitwiseRightShiftAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Integer_BitwiseRightShift(out, op1, op2);
}

/**
 * Object comparison operators
 */

static bool Mdc_Integer_EqualAsVoid(
    const void* integer1,
    const void* integer2
) {
  return Mdc_Integer_Equal(integer1, integer2);
}

static int Mdc_Integer_CompareAsVoid(
    const void* integer1,
    const void* integer2
) {
  return Mdc_Integer_Compare(integer1, integer2);
}

/**
 * Object etc. functions
 */

static size_t Mdc_Integer_HashAsVoid(
    void* integer
) {
  return Mdc_Integer_Hash(integer);
}

static void Mdc_Integer_SwapAsVoid(
    void* integer1,
    void* integer2
) {
  Mdc_Integer_Swap(integer1, integer2);
}

/**
 * Metadata
 */

static struct Mdc_ObjectMetadata global_metadata =
    MDC_OBJECT_METADATA_UNINIT;
static once_flag global_metadata_once_flag = ONCE_FLAG_INIT;

static struct Mdc_ObjectMetadata* Mdc_Integer_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(int);

  metadata->functions.init_default = &Mdc_Integer_InitDefaultAsVoid;
  metadata->functions.init_copy = &Mdc_Integer_InitCopyAsVoid;
  metadata->functions.init_move = &Mdc_Integer_InitMoveAsVoid;
  metadata->functions.deinit = &Mdc_Integer_DeinitAsVoid;

  metadata->functions.assign_copy = &Mdc_Integer_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mdc_Integer_AssignMoveAsVoid;

  metadata->functions.pre_increment = &Mdc_Integer_PreIncrementAsVoid;
  metadata->functions.pre_decrement = &Mdc_Integer_PreDecrementAsVoid;
  metadata->functions.post_increment = &Mdc_Integer_PostIncrementAsVoid;
  metadata->functions.post_decrement = &Mdc_Integer_PostDecrementAsVoid;

  metadata->functions.add = &Mdc_Integer_AddAsVoid;
  metadata->functions.subtract = &Mdc_Integer_SubtractAsVoid;
  metadata->functions.multiply = &Mdc_Integer_MultiplyAsVoid;
  metadata->functions.divide = &Mdc_Integer_DivideAsVoid;
  metadata->functions.modulo = &Mdc_Integer_ModuloAsVoid;

  metadata->functions.bitwise_not = &Mdc_Integer_BitwiseNotAsVoid;
  metadata->functions.bitwise_and = &Mdc_Integer_BitwiseAndAsVoid;
  metadata->functions.bitwise_or = &Mdc_Integer_BitwiseOrAsVoid;
  metadata->functions.bitwise_xor = &Mdc_Integer_BitwiseXorAsVoid;
  metadata->functions.bitwise_left_shift =
      &Mdc_Integer_BitwiseLeftShiftAsVoid;
  metadata->functions.bitwise_right_shift =
      &Mdc_Integer_BitwiseRightShiftAsVoid;

  metadata->functions.equal = &Mdc_Integer_EqualAsVoid;
  metadata->functions.compare = &Mdc_Integer_CompareAsVoid;

  metadata->functions.hash = &Mdc_Integer_HashAsVoid;
  metadata->functions.swap = &Mdc_Integer_SwapAsVoid;

  return metadata;
}

static void Mdc_Integer_InitGlobalObjectMetadata(void) {
  Mdc_Integer_InitObjectMetadata(&global_metadata);
}

/**
 * Metadata
 */

const struct Mdc_ObjectMetadata* Mdc_Integer_GetObjectMetadata(void) {
  call_once(
      &global_metadata_once_flag,
      &Mdc_Integer_InitGlobalObjectMetadata
  );

  return &global_metadata;
}
