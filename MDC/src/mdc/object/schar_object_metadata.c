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

#include "../../../include/mdc/object/schar_object.h"

#include "../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Object initialization/deinitialization
 */

static void* Mdc_SChar_InitDefaultAsVoid(void* ch) {
  return Mdc_SChar_InitDefault(ch);
}

static void* Mdc_SChar_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_SChar_InitCopy(dest, src);
}

static void* Mdc_SChar_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_SChar_InitMove(dest, src);
}

static void Mdc_SChar_DeinitAsVoid(void* ch) {
  Mdc_SChar_Deinit(ch);
}

/**
 * Object assignment functions
 */

static void* Mdc_SChar_AssignCopyAsVoid(void* dest, const void* src) {
  return Mdc_SChar_AssignCopy(dest, src);
}

static void* Mdc_SChar_AssignMoveAsVoid(void* dest, void* src) {
  return Mdc_SChar_AssignMove(dest, src);
}

/**
 * Object increment/decrement operators
 */

static void* Mdc_SChar_PreIncrementAsVoid(void* ch) {
  return Mdc_SChar_PreIncrement(ch);
}

static void* Mdc_SChar_PreDecrementAsVoid(void* ch) {
  return Mdc_SChar_PreDecrement(ch);
}

static void* Mdc_SChar_PostIncrementAsVoid(void* out, void* in) {
  return Mdc_SChar_PostIncrement(out, in);
}

static void* Mdc_SChar_PostDecrementAsVoid(void* out, void* in) {
  return Mdc_SChar_PostDecrement(out, in);
}

/**
 * Object arithmetic operators
 */

static void* Mdc_SChar_AddAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_SChar_Add(out, op1, op2);
}

static void* Mdc_SChar_SubtractAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_SChar_Subtract(out, op1, op2);
}

static void* Mdc_SChar_MultiplyAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_SChar_Multiply(out, op1, op2);
}

static void* Mdc_SChar_DivideAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_SChar_Divide(out, op1, op2);
}

static void* Mdc_SChar_ModuloAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_SChar_Modulo(out, op1, op2);
}

static void* Mdc_SChar_BitwiseNotAsVoid(
    void* out,
    const void* in
) {
  return Mdc_SChar_BitwiseNot(out, in);
}

static void* Mdc_SChar_BitwiseAndAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_SChar_BitwiseAnd(out, op1, op2);
}

static void* Mdc_SChar_BitwiseOrAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_SChar_BitwiseOr(out, op1, op2);
}

static void* Mdc_SChar_BitwiseXorAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_SChar_BitwiseXor(out, op1, op2);
}

static void* Mdc_SChar_BitwiseLeftShiftAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_SChar_BitwiseLeftShift(out, op1, op2);
}

static void* Mdc_SChar_BitwiseRightShiftAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_SChar_BitwiseRightShift(out, op1, op2);
}

/**
 * Object comparison operators
 */

static bool Mdc_SChar_EqualAsVoid(
    const void* ch1,
    const void* ch2
) {
  return Mdc_SChar_Equal(ch1, ch2);
}

static int Mdc_SChar_CompareAsVoid(
    const void* ch1,
    const void* ch2
) {
  return Mdc_SChar_Compare(ch1, ch2);
}

/**
 * Object etc. functions
 */

static size_t Mdc_SChar_HashAsVoid(
    const void* ch
) {
  return Mdc_SChar_Hash(ch);
}

static void Mdc_SChar_SwapAsVoid(
    void* ch1,
    void* ch2
) {
  Mdc_SChar_Swap(ch1, ch2);
}

/**
 * Metadata
 */

static struct Mdc_ObjectMetadata global_metadata =
    MDC_OBJECT_METADATA_UNINIT;
static once_flag global_metadata_once_flag = ONCE_FLAG_INIT;

static struct Mdc_ObjectMetadata* Mdc_SChar_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(signed char);

  metadata->functions.init_default = &Mdc_SChar_InitDefaultAsVoid;
  metadata->functions.init_copy = &Mdc_SChar_InitCopyAsVoid;
  metadata->functions.init_move = &Mdc_SChar_InitMoveAsVoid;
  metadata->functions.deinit = &Mdc_SChar_DeinitAsVoid;

  metadata->functions.assign_copy = &Mdc_SChar_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mdc_SChar_AssignMoveAsVoid;

  metadata->functions.pre_increment = &Mdc_SChar_PreIncrementAsVoid;
  metadata->functions.pre_decrement = &Mdc_SChar_PreDecrementAsVoid;
  metadata->functions.post_increment = &Mdc_SChar_PostIncrementAsVoid;
  metadata->functions.post_decrement = &Mdc_SChar_PostDecrementAsVoid;

  metadata->functions.add = &Mdc_SChar_AddAsVoid;
  metadata->functions.subtract = &Mdc_SChar_SubtractAsVoid;
  metadata->functions.multiply = &Mdc_SChar_MultiplyAsVoid;
  metadata->functions.divide = &Mdc_SChar_DivideAsVoid;
  metadata->functions.modulo = &Mdc_SChar_ModuloAsVoid;

  metadata->functions.bitwise_not = &Mdc_SChar_BitwiseNotAsVoid;
  metadata->functions.bitwise_and = &Mdc_SChar_BitwiseAndAsVoid;
  metadata->functions.bitwise_or = &Mdc_SChar_BitwiseOrAsVoid;
  metadata->functions.bitwise_xor = &Mdc_SChar_BitwiseXorAsVoid;
  metadata->functions.bitwise_left_shift =
      &Mdc_SChar_BitwiseLeftShiftAsVoid;
  metadata->functions.bitwise_right_shift =
      &Mdc_SChar_BitwiseRightShiftAsVoid;

  metadata->functions.equal = &Mdc_SChar_EqualAsVoid;
  metadata->functions.compare = &Mdc_SChar_CompareAsVoid;

  metadata->functions.hash = &Mdc_SChar_HashAsVoid;
  metadata->functions.swap = &Mdc_SChar_SwapAsVoid;

  return metadata;
}

static void Mdc_SChar_InitGlobalObjectMetadata(void) {
  Mdc_SChar_InitObjectMetadata(&global_metadata);
}

/**
 * Metadata
 */

const struct Mdc_ObjectMetadata* Mdc_SChar_GetObjectMetadata(void) {
  call_once(
      &global_metadata_once_flag,
      &Mdc_SChar_InitGlobalObjectMetadata
  );

  return &global_metadata;
}
