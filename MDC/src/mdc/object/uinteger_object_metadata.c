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

#include "../../../include/mdc/object/uinteger_object.h"

#include "../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Object initialization/deinitialization
 */

static void* Mdc_UInteger_InitDefaultAsVoid(void* integer) {
  return Mdc_UInteger_InitDefault(integer);
}

static void* Mdc_UInteger_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_UInteger_InitCopy(dest, src);
}

static void* Mdc_UInteger_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_UInteger_InitMove(dest, src);
}

static void Mdc_UInteger_DeinitAsVoid(void* integer) {
  Mdc_UInteger_Deinit(integer);
}

/**
 * Object assignment functions
 */

static void* Mdc_UInteger_AssignCopyAsVoid(void* dest, const void* src) {
  return Mdc_UInteger_AssignCopy(dest, src);
}

static void* Mdc_UInteger_AssignMoveAsVoid(void* dest, void* src) {
  return Mdc_UInteger_AssignMove(dest, src);
}

/**
 * Object increment/decrement operators
 */

static void* Mdc_UInteger_PreIncrementAsVoid(void* integer) {
  return Mdc_UInteger_PreIncrement(integer);
}

static void* Mdc_UInteger_PreDecrementAsVoid(void* integer) {
  return Mdc_UInteger_PreDecrement(integer);
}

static void* Mdc_UInteger_PostIncrementAsVoid(void* out, void* in) {
  return Mdc_UInteger_PostIncrement(out, in);
}

static void* Mdc_UInteger_PostDecrementAsVoid(void* out, void* in) {
  return Mdc_UInteger_PostDecrement(out, in);
}

/**
 * Object arithmetic operators
 */

static void* Mdc_UInteger_AddAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UInteger_Add(out, op1, op2);
}

static void* Mdc_UInteger_SubtractAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UInteger_Subtract(out, op1, op2);
}

static void* Mdc_UInteger_MultiplyAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UInteger_Multiply(out, op1, op2);
}

static void* Mdc_UInteger_DivideAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UInteger_Divide(out, op1, op2);
}

static void* Mdc_UInteger_ModuloAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UInteger_Modulo(out, op1, op2);
}

static void* Mdc_UInteger_BitwiseNotAsVoid(
    void* out,
    const void* in
) {
  return Mdc_UInteger_BitwiseNot(out, in);
}

static void* Mdc_UInteger_BitwiseAndAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UInteger_BitwiseAnd(out, op1, op2);
}

static void* Mdc_UInteger_BitwiseOrAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UInteger_BitwiseOr(out, op1, op2);
}

static void* Mdc_UInteger_BitwiseXorAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UInteger_BitwiseXor(out, op1, op2);
}

static void* Mdc_UInteger_BitwiseLeftShiftAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UInteger_BitwiseLeftShift(out, op1, op2);
}

static void* Mdc_UInteger_BitwiseRightShiftAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UInteger_BitwiseRightShift(out, op1, op2);
}

/**
 * Object comparison operators
 */

static bool Mdc_UInteger_EqualAsVoid(
    const void* integer1,
    const void* integer2
) {
  return Mdc_UInteger_Equal(integer1, integer2);
}

static int Mdc_UInteger_CompareAsVoid(
    const void* integer1,
    const void* integer2
) {
  return Mdc_UInteger_Compare(integer1, integer2);
}

/**
 * Object etc. functions
 */

static size_t Mdc_UInteger_HashAsVoid(
    const void* integer
) {
  return Mdc_UInteger_Hash(integer);
}

static void Mdc_UInteger_SwapAsVoid(
    void* integer1,
    void* integer2
) {
  Mdc_UInteger_Swap(integer1, integer2);
}

/**
 * Metadata
 */

static struct Mdc_ObjectMetadata global_metadata =
    MDC_OBJECT_METADATA_UNINIT;
static once_flag global_metadata_once_flag = ONCE_FLAG_INIT;

static struct Mdc_ObjectMetadata* Mdc_UInteger_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(int);

  metadata->functions.init_default = &Mdc_UInteger_InitDefaultAsVoid;
  metadata->functions.init_copy = &Mdc_UInteger_InitCopyAsVoid;
  metadata->functions.init_move = &Mdc_UInteger_InitMoveAsVoid;
  metadata->functions.deinit = &Mdc_UInteger_DeinitAsVoid;

  metadata->functions.assign_copy = &Mdc_UInteger_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mdc_UInteger_AssignMoveAsVoid;

  metadata->functions.pre_increment = &Mdc_UInteger_PreIncrementAsVoid;
  metadata->functions.pre_decrement = &Mdc_UInteger_PreDecrementAsVoid;
  metadata->functions.post_increment = &Mdc_UInteger_PostIncrementAsVoid;
  metadata->functions.post_decrement = &Mdc_UInteger_PostDecrementAsVoid;

  metadata->functions.add = &Mdc_UInteger_AddAsVoid;
  metadata->functions.subtract = &Mdc_UInteger_SubtractAsVoid;
  metadata->functions.multiply = &Mdc_UInteger_MultiplyAsVoid;
  metadata->functions.divide = &Mdc_UInteger_DivideAsVoid;
  metadata->functions.modulo = &Mdc_UInteger_ModuloAsVoid;

  metadata->functions.bitwise_not = &Mdc_UInteger_BitwiseNotAsVoid;
  metadata->functions.bitwise_and = &Mdc_UInteger_BitwiseAndAsVoid;
  metadata->functions.bitwise_or = &Mdc_UInteger_BitwiseOrAsVoid;
  metadata->functions.bitwise_xor = &Mdc_UInteger_BitwiseXorAsVoid;
  metadata->functions.bitwise_left_shift =
      &Mdc_UInteger_BitwiseLeftShiftAsVoid;
  metadata->functions.bitwise_right_shift =
      &Mdc_UInteger_BitwiseRightShiftAsVoid;

  metadata->functions.equal = &Mdc_UInteger_EqualAsVoid;
  metadata->functions.compare = &Mdc_UInteger_CompareAsVoid;

  metadata->functions.hash = &Mdc_UInteger_HashAsVoid;
  metadata->functions.swap = &Mdc_UInteger_SwapAsVoid;

  return metadata;
}

static void Mdc_UInteger_InitGlobalObjectMetadata(void) {
  Mdc_UInteger_InitObjectMetadata(&global_metadata);
}

/**
 * Metadata
 */

const struct Mdc_ObjectMetadata* Mdc_UInteger_GetObjectMetadata(void) {
  call_once(
      &global_metadata_once_flag,
      &Mdc_UInteger_InitGlobalObjectMetadata
  );

  return &global_metadata;
}
