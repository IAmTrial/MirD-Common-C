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

#include "../../../include/mdc/object/short_object.h"

#include "../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Object initialization/deinitialization
 */

#define MDC_SHORT_UNINIT { 0 }

static const struct Mdc_Short Mdc_Short_kUninit = MDC_SHORT_UNINIT;

static void* Mdc_Short_InitAsVoid(void* shrt) {
  return Mdc_Short_Init(shrt);
}

static void Mdc_Short_DeinitAsVoid(void* shrt) {
  Mdc_Short_Deinit(shrt);
}

/**
 * Object assignment functions
 */

static void* Mdc_Short_AssignDefaultAsVoid(void* shrt) {
  return Mdc_Short_AssignDefault(shrt);
}

static void* Mdc_Short_AssignCopyAsVoid(void* dest, const void* src) {
  return Mdc_Short_AssignCopy(dest, src);
}

static void* Mdc_Short_AssignMoveAsVoid(void* dest, void* src) {
  return Mdc_Short_AssignMove(dest, src);
}

/**
 * Object increment/decrement operators
 */

static void* Mdc_Short_PreIncrementAsVoid(void* shrt) {
  return Mdc_Short_PreIncrement(shrt);
}

static void* Mdc_Short_PreDecrementAsVoid(void* shrt) {
  return Mdc_Short_PreDecrement(shrt);
}

static void* Mdc_Short_PostIncrementAsVoid(
    void* short_out,
    void* short_in
) {
  return Mdc_Short_PostIncrement(short_out, short_in);
}

static void* Mdc_Short_PostDecrementAsVoid(
    void* short_out,
    void* short_in
) {
  return Mdc_Short_PostDecrement(short_out, short_in);
}

/**
 * Object arithmetic operators
 */

static void* Mdc_Short_AddAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_Short_Add(short_out, short_in1, short_in2);
}

static void* Mdc_Short_SubtractAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_Short_Subtract(short_out, short_in1, short_in2);
}

static void* Mdc_Short_MultiplyAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_Short_Multiply(short_out, short_in1, short_in2);
}

static void* Mdc_Short_DivideAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_Short_Divide(short_out, short_in1, short_in2);
}

static void* Mdc_Short_ModuloAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_Short_Modulo(short_out, short_in1, short_in2);
}

static void* Mdc_Short_BitwiseNotAsVoid(
    void* short_out,
    const void* short_in
) {
  return Mdc_Short_BitwiseNot(short_out, short_in);
}

static void* Mdc_Short_BitwiseAndAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_Short_BitwiseAnd(short_out, short_in1, short_in2);
}

static void* Mdc_Short_BitwiseOrAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_Short_BitwiseOr(short_out, short_in1, short_in2);
}

static void* Mdc_Short_BitwiseXorAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_Short_BitwiseXor(short_out, short_in1, short_in2);
}

static void* Mdc_Short_BitwiseLeftShiftAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_Short_BitwiseLeftShift(short_out, short_in1, short_in2);
}

static void* Mdc_Short_BitwiseRightShiftAsVoid(
    void* short_out,
    const void* short_in1,
    const void* short_in2
) {
  return Mdc_Short_BitwiseRightShift(short_out, short_in1, short_in2);
}

/**
 * Object comparison operators
 */

static bool Mdc_Short_EqualAsVoid(
    const void* short1,
    const void* short2
) {
  return Mdc_Short_Equal(short1, short2);
}

static int Mdc_Short_CompareAsVoid(
    const void* short1,
    const void* short2
) {
  return Mdc_Short_Compare(short1, short2);
}

/**
 * Object etc. functions
 */

static size_t Mdc_Short_HashAsVoid(
    const struct Mdc_Short* shrt
) {
  return Mdc_Short_Hash(shrt);
}

static void Mdc_Short_SwapAsVoid(
    void* short1,
    void* short2
) {
  Mdc_Short_Swap(short1, short2);
}

/**
 * Metadata
 */

static struct Mdc_ObjectMetadata global_metadata;
static once_flag global_metadata_once_flag = ONCE_FLAG_INIT;

static struct Mdc_ObjectMetadata* Mdc_Short_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(struct Mdc_Short);

  metadata->functions.init = &Mdc_Short_InitAsVoid;
  metadata->functions.deinit = &Mdc_Short_DeinitAsVoid;

  metadata->functions.assign_default = &Mdc_Short_AssignDefaultAsVoid;
  metadata->functions.assign_copy = &Mdc_Short_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mdc_Short_AssignMoveAsVoid;

  metadata->functions.pre_increment = &Mdc_Short_PreIncrementAsVoid;
  metadata->functions.pre_decrement = &Mdc_Short_PreDecrementAsVoid;
  metadata->functions.post_increment = &Mdc_Short_PostIncrementAsVoid;
  metadata->functions.post_decrement = &Mdc_Short_PostDecrementAsVoid;

  metadata->functions.add = &Mdc_Short_AddAsVoid;
  metadata->functions.subtract = &Mdc_Short_SubtractAsVoid;
  metadata->functions.multiply = &Mdc_Short_MultiplyAsVoid;
  metadata->functions.divide = &Mdc_Short_DivideAsVoid;
  metadata->functions.modulo = &Mdc_Short_ModuloAsVoid;

  metadata->functions.bitwise_not = &Mdc_Short_BitwiseNotAsVoid;
  metadata->functions.bitwise_and = &Mdc_Short_BitwiseAndAsVoid;
  metadata->functions.bitwise_or = &Mdc_Short_BitwiseOrAsVoid;
  metadata->functions.bitwise_xor = &Mdc_Short_BitwiseXorAsVoid;
  metadata->functions.bitwise_left_shift =
      &Mdc_Short_BitwiseLeftShiftAsVoid;
  metadata->functions.bitwise_right_shift =
      &Mdc_Short_BitwiseRightShiftAsVoid;

  metadata->functions.equal = &Mdc_Short_EqualAsVoid;
  metadata->functions.compare = &Mdc_Short_CompareAsVoid;

  metadata->functions.hash = &Mdc_Short_HashAsVoid;
  metadata->functions.swap = &Mdc_Short_SwapAsVoid;

  return metadata;
}

static void Mdc_Short_InitGlobalObjectMetadata(void) {
  Mdc_Short_InitObjectMetadata(&global_metadata);
}

/**
 * External
 */

/**
 * Initialization/deinitialization
 */

struct Mdc_Short* Mdc_Short_Init(struct Mdc_Short* shrt) {
  return shrt;
}

void Mdc_Short_Deinit(struct Mdc_Short* shrt) {
  *shrt = Mdc_Short_kUninit;
}

/**
 * Metadata
 */

const struct Mdc_ObjectMetadata* Mdc_Short_GetObjectMetadata(void) {
  call_once(
      &global_metadata_once_flag,
      &Mdc_Short_InitGlobalObjectMetadata
  );

  return &global_metadata;
}

/**
 * Assignment functions
 */

struct Mdc_Short* Mdc_Short_AssignDefault(
    struct Mdc_Short* shrt
) {
  shrt->value_ = 0;

  return shrt;
}

struct Mdc_Short* Mdc_Short_AssignFromValue(
    struct Mdc_Short* shrt,
    short value
) {
  shrt->value_ = value;

  return shrt;
}

struct Mdc_Short* Mdc_Short_AssignCopy(
    struct Mdc_Short* dest,
    const struct Mdc_Short* src
) {
  dest->value_ = src->value_;

  return dest;
}

struct Mdc_Short* Mdc_Short_AssignMove(
    struct Mdc_Short* dest,
    struct Mdc_Short* src
) {
  return Mdc_Short_AssignCopy(dest, src);
}

/**
 * Increment/decrement operators
 */

struct Mdc_Short* Mdc_Short_PreIncrement(
    struct Mdc_Short* shrt
) {
  shrt->value_ += 1;

  return shrt;
}

struct Mdc_Short* Mdc_Short_PreDecrement(
    struct Mdc_Short* shrt
) {
  shrt->value_ -= 1;

  return shrt;
}

struct Mdc_Short* Mdc_Short_PostIncrement(
    struct Mdc_Short* short_out,
    struct Mdc_Short* short_in
) {
  Mdc_Short_AssignCopy(short_out, short_in);
  short_in->value_ += 1;

  return short_out;
}

struct Mdc_Short* Mdc_Short_PostDecrement(
    struct Mdc_Short* short_out,
    struct Mdc_Short* short_in
) {
  Mdc_Short_AssignCopy(short_out, short_in);
  short_in->value_ -= 1;

  return short_out;
}

/**
 * Arithmetic operators
 */

struct Mdc_Short* Mdc_Short_Add(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ + short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_Subtract(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ - short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_Multiply(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ * short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_Divide(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ / short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_Modulo(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ % short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_BitwiseNot(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in
) {
  Mdc_Short_AssignFromValue(
      short_out,
      ~(short_in->value_)
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_BitwiseAnd(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ & short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_BitwiseOr(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ | short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_BitwiseXor(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ ^ short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_BitwiseLeftShift(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ << short_in2->value_
  );

  return short_out;
}

struct Mdc_Short* Mdc_Short_BitwiseRightShift(
    struct Mdc_Short* short_out,
    const struct Mdc_Short* short_in1,
    const struct Mdc_Short* short_in2
) {
  Mdc_Short_AssignFromValue(
      short_out,
      short_in1->value_ >> short_in2->value_
  );

  return short_out;
}

/**
 * Comparison operators
 */

bool Mdc_Short_Equal(
    const struct Mdc_Short* short1,
    const struct Mdc_Short* short2
) {
  return short1->value_ == short2->value_;
}

bool Mdc_Short_EqualValue(
    const struct Mdc_Short* shrt,
    short value
) {
  return shrt->value_ == value;
}

int Mdc_Short_Compare(
    const struct Mdc_Short* short1,
    const struct Mdc_Short* short2
) {
  return short1->value_ - short2->value_;
}

int Mdc_Short_CompareValue(
    const struct Mdc_Short* shrt,
    short value
) {
  return shrt->value_ - value;
}

/**
 * Etc. functions
 */

size_t Mdc_Short_Hash(const struct Mdc_Short* shrt) {
  return shrt->value_ % (size_t) -1;
}

void Mdc_Short_Swap(
    struct Mdc_Short* short1,
    struct Mdc_Short* short2
) {
  struct Mdc_Short temp;

  temp = *short1;
  *short1 = *short2;
  *short2 = temp;
}

short Mdc_Short_GetValue(const struct Mdc_Short* shrt) {
  return shrt->value_;
}

void Mdc_Short_SetValue(struct Mdc_Short* shrt, short value) {
  shrt->value_ = value;
}
