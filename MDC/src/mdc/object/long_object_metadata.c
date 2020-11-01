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

#include "../../../include/mdc/object/long_object.h"

#include "../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Object initialization/deinitialization
 */

static void* Mdc_Long_InitDefaultAsVoid(void* lng) {
  return Mdc_Long_InitDefault(lng);
}

static void* Mdc_Long_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_Long_InitCopy(dest, src);
}

static void* Mdc_Long_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_Long_InitMove(dest, src);
}

static void Mdc_Long_DeinitAsVoid(void* lng) {
  Mdc_Long_Deinit(lng);
}

/**
 * Object assignment functions
 */

static void* Mdc_Long_AssignCopyAsVoid(void* dest, const void* src) {
  return Mdc_Long_AssignCopy(dest, src);
}

static void* Mdc_Long_AssignMoveAsVoid(void* dest, void* src) {
  return Mdc_Long_AssignMove(dest, src);
}

/**
 * Object increment/decrement operators
 */

static void* Mdc_Long_PreIncrementAsVoid(void* lng) {
  return Mdc_Long_PreIncrement(lng);
}

static void* Mdc_Long_PreDecrementAsVoid(void* lng) {
  return Mdc_Long_PreDecrement(lng);
}

static void* Mdc_Long_PostIncrementAsVoid(void* out, void* in) {
  return Mdc_Long_PostIncrement(out, in);
}

static void* Mdc_Long_PostDecrementAsVoid(void* out, void* in) {
  return Mdc_Long_PostDecrement(out, in);
}

/**
 * Object arithmetic operators
 */

static void* Mdc_Long_AddAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Long_Add(out, op1, op2);
}

static void* Mdc_Long_SubtractAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Long_Subtract(out, op1, op2);
}

static void* Mdc_Long_MultiplyAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Long_Multiply(out, op1, op2);
}

static void* Mdc_Long_DivideAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Long_Divide(out, op1, op2);
}

static void* Mdc_Long_ModuloAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Long_Modulo(out, op1, op2);
}

static void* Mdc_Long_BitwiseNotAsVoid(
    void* out,
    const void* in
) {
  return Mdc_Long_BitwiseNot(out, in);
}

static void* Mdc_Long_BitwiseAndAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Long_BitwiseAnd(out, op1, op2);
}

static void* Mdc_Long_BitwiseOrAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Long_BitwiseOr(out, op1, op2);
}

static void* Mdc_Long_BitwiseXorAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Long_BitwiseXor(out, op1, op2);
}

static void* Mdc_Long_BitwiseLeftShiftAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Long_BitwiseLeftShift(out, op1, op2);
}

static void* Mdc_Long_BitwiseRightShiftAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_Long_BitwiseRightShift(out, op1, op2);
}

/**
 * Object comparison operators
 */

static bool Mdc_Long_EqualAsVoid(
    const void* long1,
    const void* long2
) {
  return Mdc_Long_Equal(long1, long2);
}

static int Mdc_Long_CompareAsVoid(
    const void* long1,
    const void* long2
) {
  return Mdc_Long_Compare(long1, long2);
}

/**
 * Object etc. functions
 */

static size_t Mdc_Long_HashAsVoid(
    const void* lng
) {
  return Mdc_Long_Hash(lng);
}

static void Mdc_Long_SwapAsVoid(
    void* long1,
    void* long2
) {
  Mdc_Long_Swap(long1, long2);
}

/**
 * Metadata
 */

static struct Mdc_ObjectMetadata global_metadata =
    MDC_OBJECT_METADATA_UNINIT;
static once_flag global_metadata_once_flag = ONCE_FLAG_INIT;

static struct Mdc_ObjectMetadata* Mdc_Long_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(long);

  metadata->functions.init_default = &Mdc_Long_InitDefaultAsVoid;
  metadata->functions.init_copy = &Mdc_Long_InitCopyAsVoid;
  metadata->functions.init_move = &Mdc_Long_InitMoveAsVoid;
  metadata->functions.deinit = &Mdc_Long_DeinitAsVoid;

  metadata->functions.assign_copy = &Mdc_Long_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mdc_Long_AssignMoveAsVoid;

  metadata->functions.pre_increment = &Mdc_Long_PreIncrementAsVoid;
  metadata->functions.pre_decrement = &Mdc_Long_PreDecrementAsVoid;
  metadata->functions.post_increment = &Mdc_Long_PostIncrementAsVoid;
  metadata->functions.post_decrement = &Mdc_Long_PostDecrementAsVoid;

  metadata->functions.add = &Mdc_Long_AddAsVoid;
  metadata->functions.subtract = &Mdc_Long_SubtractAsVoid;
  metadata->functions.multiply = &Mdc_Long_MultiplyAsVoid;
  metadata->functions.divide = &Mdc_Long_DivideAsVoid;
  metadata->functions.modulo = &Mdc_Long_ModuloAsVoid;

  metadata->functions.bitwise_not = &Mdc_Long_BitwiseNotAsVoid;
  metadata->functions.bitwise_and = &Mdc_Long_BitwiseAndAsVoid;
  metadata->functions.bitwise_or = &Mdc_Long_BitwiseOrAsVoid;
  metadata->functions.bitwise_xor = &Mdc_Long_BitwiseXorAsVoid;
  metadata->functions.bitwise_left_shift =
      &Mdc_Long_BitwiseLeftShiftAsVoid;
  metadata->functions.bitwise_right_shift =
      &Mdc_Long_BitwiseRightShiftAsVoid;

  metadata->functions.equal = &Mdc_Long_EqualAsVoid;
  metadata->functions.compare = &Mdc_Long_CompareAsVoid;

  metadata->functions.hash = &Mdc_Long_HashAsVoid;
  metadata->functions.swap = &Mdc_Long_SwapAsVoid;

  return metadata;
}

static void Mdc_Long_InitGlobalObjectMetadata(void) {
  Mdc_Long_InitObjectMetadata(&global_metadata);
}

/**
 * Metadata
 */

const struct Mdc_ObjectMetadata* Mdc_Long_GetObjectMetadata(void) {
  call_once(
      &global_metadata_once_flag,
      &Mdc_Long_InitGlobalObjectMetadata
  );

  return &global_metadata;
}
