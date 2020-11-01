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

#include "../../../include/mdc/object/ulong_object.h"

#include "../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Object initialization/deinitialization
 */

static void* Mdc_ULong_InitDefaultAsVoid(void* lng) {
  return Mdc_ULong_InitDefault(lng);
}

static void* Mdc_ULong_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_ULong_InitCopy(dest, src);
}

static void* Mdc_ULong_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_ULong_InitMove(dest, src);
}

static void Mdc_ULong_DeinitAsVoid(void* lng) {
  Mdc_ULong_Deinit(lng);
}

/**
 * Object assignment functions
 */

static void* Mdc_ULong_AssignCopyAsVoid(void* dest, const void* src) {
  return Mdc_ULong_AssignCopy(dest, src);
}

static void* Mdc_ULong_AssignMoveAsVoid(void* dest, void* src) {
  return Mdc_ULong_AssignMove(dest, src);
}

/**
 * Object increment/decrement operators
 */

static void* Mdc_ULong_PreIncrementAsVoid(void* lng) {
  return Mdc_ULong_PreIncrement(lng);
}

static void* Mdc_ULong_PreDecrementAsVoid(void* lng) {
  return Mdc_ULong_PreDecrement(lng);
}

static void* Mdc_ULong_PostIncrementAsVoid(void* out, void* in) {
  return Mdc_ULong_PostIncrement(out, in);
}

static void* Mdc_ULong_PostDecrementAsVoid(void* out, void* in) {
  return Mdc_ULong_PostDecrement(out, in);
}

/**
 * Object arithmetic operators
 */

static void* Mdc_ULong_AddAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_ULong_Add(out, op1, op2);
}

static void* Mdc_ULong_SubtractAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_ULong_Subtract(out, op1, op2);
}

static void* Mdc_ULong_MultiplyAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_ULong_Multiply(out, op1, op2);
}

static void* Mdc_ULong_DivideAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_ULong_Divide(out, op1, op2);
}

static void* Mdc_ULong_ModuloAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_ULong_Modulo(out, op1, op2);
}

static void* Mdc_ULong_BitwiseNotAsVoid(
    void* out,
    const void* in
) {
  return Mdc_ULong_BitwiseNot(out, in);
}

static void* Mdc_ULong_BitwiseAndAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_ULong_BitwiseAnd(out, op1, op2);
}

static void* Mdc_ULong_BitwiseOrAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_ULong_BitwiseOr(out, op1, op2);
}

static void* Mdc_ULong_BitwiseXorAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_ULong_BitwiseXor(out, op1, op2);
}

static void* Mdc_ULong_BitwiseLeftShiftAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_ULong_BitwiseLeftShift(out, op1, op2);
}

static void* Mdc_ULong_BitwiseRightShiftAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_ULong_BitwiseRightShift(out, op1, op2);
}

/**
 * Object comparison operators
 */

static bool Mdc_ULong_EqualAsVoid(
    const void* long1,
    const void* long2
) {
  return Mdc_ULong_Equal(long1, long2);
}

static int Mdc_ULong_CompareAsVoid(
    const void* long1,
    const void* long2
) {
  return Mdc_ULong_Compare(long1, long2);
}

/**
 * Object etc. functions
 */

static size_t Mdc_ULong_HashAsVoid(
    const void* lng
) {
  return Mdc_ULong_Hash(lng);
}

static void Mdc_ULong_SwapAsVoid(
    void* long1,
    void* long2
) {
  Mdc_ULong_Swap(long1, long2);
}

/**
 * Metadata
 */

static struct Mdc_ObjectMetadata global_metadata =
    MDC_OBJECT_METADATA_UNINIT;
static once_flag global_metadata_once_flag = ONCE_FLAG_INIT;

static struct Mdc_ObjectMetadata* Mdc_ULong_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(unsigned long);

  metadata->functions.init_default = &Mdc_ULong_InitDefaultAsVoid;
  metadata->functions.init_copy = &Mdc_ULong_InitCopyAsVoid;
  metadata->functions.init_move = &Mdc_ULong_InitMoveAsVoid;
  metadata->functions.deinit = &Mdc_ULong_DeinitAsVoid;

  metadata->functions.assign_copy = &Mdc_ULong_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mdc_ULong_AssignMoveAsVoid;

  metadata->functions.pre_increment = &Mdc_ULong_PreIncrementAsVoid;
  metadata->functions.pre_decrement = &Mdc_ULong_PreDecrementAsVoid;
  metadata->functions.post_increment = &Mdc_ULong_PostIncrementAsVoid;
  metadata->functions.post_decrement = &Mdc_ULong_PostDecrementAsVoid;

  metadata->functions.add = &Mdc_ULong_AddAsVoid;
  metadata->functions.subtract = &Mdc_ULong_SubtractAsVoid;
  metadata->functions.multiply = &Mdc_ULong_MultiplyAsVoid;
  metadata->functions.divide = &Mdc_ULong_DivideAsVoid;
  metadata->functions.modulo = &Mdc_ULong_ModuloAsVoid;

  metadata->functions.bitwise_not = &Mdc_ULong_BitwiseNotAsVoid;
  metadata->functions.bitwise_and = &Mdc_ULong_BitwiseAndAsVoid;
  metadata->functions.bitwise_or = &Mdc_ULong_BitwiseOrAsVoid;
  metadata->functions.bitwise_xor = &Mdc_ULong_BitwiseXorAsVoid;
  metadata->functions.bitwise_left_shift =
      &Mdc_ULong_BitwiseLeftShiftAsVoid;
  metadata->functions.bitwise_right_shift =
      &Mdc_ULong_BitwiseRightShiftAsVoid;

  metadata->functions.equal = &Mdc_ULong_EqualAsVoid;
  metadata->functions.compare = &Mdc_ULong_CompareAsVoid;

  metadata->functions.hash = &Mdc_ULong_HashAsVoid;
  metadata->functions.swap = &Mdc_ULong_SwapAsVoid;

  return metadata;
}

static void Mdc_ULong_InitGlobalObjectMetadata(void) {
  Mdc_ULong_InitObjectMetadata(&global_metadata);
}

/**
 * Metadata
 */

const struct Mdc_ObjectMetadata* Mdc_ULong_GetObjectMetadata(void) {
  call_once(
      &global_metadata_once_flag,
      &Mdc_ULong_InitGlobalObjectMetadata
  );

  return &global_metadata;
}
