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

#include "../../../include/mdc/object/ushort_object.h"

#include "../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Object initialization/deinitialization
 */

static void* Mdc_UShort_InitDefaultAsVoid(void* shrt) {
  return Mdc_UShort_InitDefault(shrt);
}

static void* Mdc_UShort_InitCopyAsVoid(void* dest, const void* src) {
  return Mdc_UShort_InitCopy(dest, src);
}

static void* Mdc_UShort_InitMoveAsVoid(void* dest, void* src) {
  return Mdc_UShort_InitMove(dest, src);
}

static void Mdc_UShort_DeinitAsVoid(void* shrt) {
  Mdc_UShort_Deinit(shrt);
}

/**
 * Object assignment functions
 */

static void* Mdc_UShort_AssignCopyAsVoid(void* dest, const void* src) {
  return Mdc_UShort_AssignCopy(dest, src);
}

static void* Mdc_UShort_AssignMoveAsVoid(void* dest, void* src) {
  return Mdc_UShort_AssignMove(dest, src);
}

/**
 * Object increment/decrement operators
 */

static void* Mdc_UShort_PreIncrementAsVoid(void* shrt) {
  return Mdc_UShort_PreIncrement(shrt);
}

static void* Mdc_UShort_PreDecrementAsVoid(void* shrt) {
  return Mdc_UShort_PreDecrement(shrt);
}

static void* Mdc_UShort_PostIncrementAsVoid(
    void* short_out,
    void* short_in
) {
  return Mdc_UShort_PostIncrement(short_out, short_in);
}

static void* Mdc_UShort_PostDecrementAsVoid(
    void* short_out,
    void* short_in
) {
  return Mdc_UShort_PostDecrement(short_out, short_in);
}

/**
 * Object arithmetic operators
 */

static void* Mdc_UShort_AddAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_UShort_Add(short_out, short_in1, short_in2);
}

static void* Mdc_UShort_SubtractAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_UShort_Subtract(short_out, short_in1, short_in2);
}

static void* Mdc_UShort_MultiplyAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_UShort_Multiply(short_out, short_in1, short_in2);
}

static void* Mdc_UShort_DivideAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_UShort_Divide(short_out, short_in1, short_in2);
}

static void* Mdc_UShort_ModuloAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_UShort_Modulo(short_out, short_in1, short_in2);
}

static void* Mdc_UShort_BitwiseNotAsVoid(
    void* short_out,
    const void* short_in
) {
  return Mdc_UShort_BitwiseNot(short_out, short_in);
}

static void* Mdc_UShort_BitwiseAndAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_UShort_BitwiseAnd(short_out, short_in1, short_in2);
}

static void* Mdc_UShort_BitwiseOrAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_UShort_BitwiseOr(short_out, short_in1, short_in2);
}

static void* Mdc_UShort_BitwiseXorAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_UShort_BitwiseXor(short_out, short_in1, short_in2);
}

static void* Mdc_UShort_BitwiseLeftShiftAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_UShort_BitwiseLeftShift(short_out, short_in1, short_in2);
}

static void* Mdc_UShort_BitwiseRightShiftAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_UShort_BitwiseRightShift(short_out, short_in1, short_in2);
}

/**
 * Object comparison operators
 */

static bool Mdc_UShort_EqualAsVoid(
    const void* short1,
    const void* short2
) {
  return Mdc_UShort_Equal(short1, short2);
}

static int Mdc_UShort_CompareAsVoid(
    const void* short1,
    const void* short2
) {
  return Mdc_UShort_Compare(short1, short2);
}

/**
 * Object etc. functions
 */

static size_t Mdc_UShort_HashAsVoid(
    const void* shrt
) {
  return Mdc_UShort_Hash(shrt);
}

static void Mdc_UShort_SwapAsVoid(
    void* short1,
    void* short2
) {
  Mdc_UShort_Swap(short1, short2);
}

/**
 * Metadata
 */

static struct Mdc_ObjectMetadata global_metadata =
    MDC_OBJECT_METADATA_UNINIT;
static once_flag global_metadata_once_flag = ONCE_FLAG_INIT;

static struct Mdc_ObjectMetadata* Mdc_UShort_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(unsigned short);

  metadata->functions.init_default = &Mdc_UShort_InitDefaultAsVoid;
  metadata->functions.init_copy = &Mdc_UShort_InitCopyAsVoid;
  metadata->functions.init_move = &Mdc_UShort_InitMoveAsVoid;
  metadata->functions.deinit = &Mdc_UShort_DeinitAsVoid;

  metadata->functions.assign_copy = &Mdc_UShort_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mdc_UShort_AssignMoveAsVoid;

  metadata->functions.pre_increment = &Mdc_UShort_PreIncrementAsVoid;
  metadata->functions.pre_decrement = &Mdc_UShort_PreDecrementAsVoid;
  metadata->functions.post_increment = &Mdc_UShort_PostIncrementAsVoid;
  metadata->functions.post_decrement = &Mdc_UShort_PostDecrementAsVoid;

  metadata->functions.add = &Mdc_UShort_AddAsVoid;
  metadata->functions.subtract = &Mdc_UShort_SubtractAsVoid;
  metadata->functions.multiply = &Mdc_UShort_MultiplyAsVoid;
  metadata->functions.divide = &Mdc_UShort_DivideAsVoid;
  metadata->functions.modulo = &Mdc_UShort_ModuloAsVoid;

  metadata->functions.bitwise_not = &Mdc_UShort_BitwiseNotAsVoid;
  metadata->functions.bitwise_and = &Mdc_UShort_BitwiseAndAsVoid;
  metadata->functions.bitwise_or = &Mdc_UShort_BitwiseOrAsVoid;
  metadata->functions.bitwise_xor = &Mdc_UShort_BitwiseXorAsVoid;
  metadata->functions.bitwise_left_shift =
      &Mdc_UShort_BitwiseLeftShiftAsVoid;
  metadata->functions.bitwise_right_shift =
      &Mdc_UShort_BitwiseRightShiftAsVoid;

  metadata->functions.equal = &Mdc_UShort_EqualAsVoid;
  metadata->functions.compare = &Mdc_UShort_CompareAsVoid;

  metadata->functions.hash = &Mdc_UShort_HashAsVoid;
  metadata->functions.swap = &Mdc_UShort_SwapAsVoid;

  return metadata;
}

static void Mdc_UShort_InitGlobalObjectMetadata(void) {
  Mdc_UShort_InitObjectMetadata(&global_metadata);
}

/**
 * External
 */

/**
 * Metadata
 */

const struct Mdc_ObjectMetadata* Mdc_UShort_GetObjectMetadata(void) {
  call_once(
      &global_metadata_once_flag,
      &Mdc_UShort_InitGlobalObjectMetadata
  );

  return &global_metadata;
}
