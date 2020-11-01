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

#include "../../../include/mdc/object/uchar_object.h"

#include "../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Object initialization/deinitialization
 */

static void* Mdc_UChar_InitDefaultAsVoid(void* ch) {
  return Mdc_UChar_InitDefault(ch);
}

static void* Mdc_UChar_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_UChar_InitCopy(dest, src);
}

static void* Mdc_UChar_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_UChar_InitMove(dest, src);
}

static void Mdc_UChar_DeinitAsVoid(void* ch) {
  Mdc_UChar_Deinit(ch);
}

/**
 * Object assignment functions
 */

static void* Mdc_UChar_AssignCopyAsVoid(void* dest, const void* src) {
  return Mdc_UChar_AssignCopy(dest, src);
}

static void* Mdc_UChar_AssignMoveAsVoid(void* dest, void* src) {
  return Mdc_UChar_AssignMove(dest, src);
}

/**
 * Object increment/decrement operators
 */

static void* Mdc_UChar_PreIncrementAsVoid(void* ch) {
  return Mdc_UChar_PreIncrement(ch);
}

static void* Mdc_UChar_PreDecrementAsVoid(void* ch) {
  return Mdc_UChar_PreDecrement(ch);
}

static void* Mdc_UChar_PostIncrementAsVoid(void* out, void* in) {
  return Mdc_UChar_PostIncrement(out, in);
}

static void* Mdc_UChar_PostDecrementAsVoid(void* out, void* in) {
  return Mdc_UChar_PostDecrement(out, in);
}

/**
 * Object arithmetic operators
 */

static void* Mdc_UChar_AddAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UChar_Add(out, op1, op2);
}

static void* Mdc_UChar_SubtractAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UChar_Subtract(out, op1, op2);
}

static void* Mdc_UChar_MultiplyAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UChar_Multiply(out, op1, op2);
}

static void* Mdc_UChar_DivideAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UChar_Divide(out, op1, op2);
}

static void* Mdc_UChar_ModuloAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UChar_Modulo(out, op1, op2);
}

static void* Mdc_UChar_BitwiseNotAsVoid(
    void* out,
    const void* in
) {
  return Mdc_UChar_BitwiseNot(out, in);
}

static void* Mdc_UChar_BitwiseAndAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UChar_BitwiseAnd(out, op1, op2);
}

static void* Mdc_UChar_BitwiseOrAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UChar_BitwiseOr(out, op1, op2);
}

static void* Mdc_UChar_BitwiseXorAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UChar_BitwiseXor(out, op1, op2);
}

static void* Mdc_UChar_BitwiseLeftShiftAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UChar_BitwiseLeftShift(out, op1, op2);
}

static void* Mdc_UChar_BitwiseRightShiftAsVoid(
    void* out,
    const void* op1,
    const void* op2
) {
  return Mdc_UChar_BitwiseRightShift(out, op1, op2);
}

/**
 * Object comparison operators
 */

static bool Mdc_UChar_EqualAsVoid(
    const void* ch1,
    const void* ch2
) {
  return Mdc_UChar_Equal(ch1, ch2);
}

static int Mdc_UChar_CompareAsVoid(
    const void* ch1,
    const void* ch2
) {
  return Mdc_UChar_Compare(ch1, ch2);
}

/**
 * Object etc. functions
 */

static size_t Mdc_UChar_HashAsVoid(
    const void* ch
) {
  return Mdc_UChar_Hash(ch);
}

static void Mdc_UChar_SwapAsVoid(
    void* ch1,
    void* ch2
) {
  Mdc_UChar_Swap(ch1, ch2);
}

/**
 * Metadata
 */

static struct Mdc_ObjectMetadata global_metadata =
    MDC_OBJECT_METADATA_UNINIT;
static once_flag global_metadata_once_flag = ONCE_FLAG_INIT;

static struct Mdc_ObjectMetadata* Mdc_UChar_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(unsigned char);

  metadata->functions.init_default = &Mdc_UChar_InitDefaultAsVoid;
  metadata->functions.init_copy = &Mdc_UChar_InitCopyAsVoid;
  metadata->functions.init_move = &Mdc_UChar_InitMoveAsVoid;
  metadata->functions.deinit = &Mdc_UChar_DeinitAsVoid;

  metadata->functions.assign_copy = &Mdc_UChar_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mdc_UChar_AssignMoveAsVoid;

  metadata->functions.pre_increment = &Mdc_UChar_PreIncrementAsVoid;
  metadata->functions.pre_decrement = &Mdc_UChar_PreDecrementAsVoid;
  metadata->functions.post_increment = &Mdc_UChar_PostIncrementAsVoid;
  metadata->functions.post_decrement = &Mdc_UChar_PostDecrementAsVoid;

  metadata->functions.add = &Mdc_UChar_AddAsVoid;
  metadata->functions.subtract = &Mdc_UChar_SubtractAsVoid;
  metadata->functions.multiply = &Mdc_UChar_MultiplyAsVoid;
  metadata->functions.divide = &Mdc_UChar_DivideAsVoid;
  metadata->functions.modulo = &Mdc_UChar_ModuloAsVoid;

  metadata->functions.bitwise_not = &Mdc_UChar_BitwiseNotAsVoid;
  metadata->functions.bitwise_and = &Mdc_UChar_BitwiseAndAsVoid;
  metadata->functions.bitwise_or = &Mdc_UChar_BitwiseOrAsVoid;
  metadata->functions.bitwise_xor = &Mdc_UChar_BitwiseXorAsVoid;
  metadata->functions.bitwise_left_shift =
      &Mdc_UChar_BitwiseLeftShiftAsVoid;
  metadata->functions.bitwise_right_shift =
      &Mdc_UChar_BitwiseRightShiftAsVoid;

  metadata->functions.equal = &Mdc_UChar_EqualAsVoid;
  metadata->functions.compare = &Mdc_UChar_CompareAsVoid;

  metadata->functions.hash = &Mdc_UChar_HashAsVoid;
  metadata->functions.swap = &Mdc_UChar_SwapAsVoid;

  return metadata;
}

static void Mdc_UChar_InitGlobalObjectMetadata(void) {
  Mdc_UChar_InitObjectMetadata(&global_metadata);
}

/**
 * Metadata
 */

const struct Mdc_ObjectMetadata* Mdc_UChar_GetObjectMetadata(void) {
  call_once(
      &global_metadata_once_flag,
      &Mdc_UChar_InitGlobalObjectMetadata
  );

  return &global_metadata;
}
