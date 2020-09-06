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

const struct Mdc_Short Mdc_Short_kUninit = MDC_SHORT_UNINIT;

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

/**
 * Object arithmetic operators
 */

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

static struct Mdc_ObjectMetadata* Mdc_Short_InitObjectMetadata(
    struct Mdc_ObjectMetadata* metadata
) {
  metadata->size = sizeof(struct Mdc_Short);

  metadata->functions.init = &Mdc_Short_InitAsVoid;
  metadata->functions.deinit = &Mdc_Short_DeinitAsVoid;

  metadata->functions.assign_default = &Mdc_Short_AssignDefaultAsVoid;
  metadata->functions.assign_copy = &Mdc_Short_AssignCopyAsVoid;
  metadata->functions.assign_move = &Mdc_Short_AssignMoveAsVoid;

  metadata->functions.equal = &Mdc_Short_EqualAsVoid;
  metadata->functions.compare = &Mdc_Short_CompareAsVoid;

  metadata->functions.hash = &Mdc_Short_HashAsVoid;
  metadata->functions.swap = &Mdc_Short_SwapAsVoid;

  return metadata;
}

static struct Mdc_ObjectMetadata global_metadata;
static once_flag global_metadata_once_flag = ONCE_FLAG_INIT;

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

/**
 * Arithmetic operators
 */

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
    const struct Mdc_Short* short_,
    short value
) {
  return short_->value_ == value;
}

int Mdc_Short_Compare(
    const struct Mdc_Short* short1,
    const struct Mdc_Short* short2
) {
  return short1->value_ - short2->value_;
}

int Mdc_Short_CompareValue(
    const struct Mdc_Short* short_,
    short value
) {
  return short_->value_ - value;
}

/**
 * Etc. functions
 */

size_t Mdc_Short_Hash(const struct Mdc_Short* short_) {
  return short_->value_;
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

short Mdc_Short_GetValue(const struct Mdc_Short* short_) {
  return short_->value_;
}

void Mdc_Short_SetValue(struct Mdc_Short* short_, short value) {
  short_->value_ = value;
}
