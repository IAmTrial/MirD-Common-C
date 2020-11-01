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

#include "../../../include/mdc/object/arithmetic_object.h"

#include "../../../include/mdc/std/threads.h"

#define MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(name, type) \
\
/**
 * Object initialization/deinitialization
 */ \
\
static void* name##_InitDefaultAsVoid(void* obj) { \
  return name##_InitDefault(obj); \
} \
\
static void* name##_InitCopyAsVoid(void* dest, const void* src) { \
  return name##_InitCopy(dest, src); \
} \
\
static void* name##_InitMoveAsVoid(void* dest, void* src) { \
  return name##_InitMove(dest, src); \
} \
\
static void name##_DeinitAsVoid(void* obj) { \
  name##_Deinit(obj); \
} \
\
/**
 * Object assignment functions
 */ \
\
static void* name##_AssignCopyAsVoid(void* dest, const void* src) { \
  return name##_AssignCopy(dest, src); \
} \
\
static void* name##_AssignMoveAsVoid(void* dest, void* src) { \
  return name##_AssignMove(dest, src); \
} \
\
/**
 * Object increment/decrement operators
 */ \
\
static void* name##_PreIncrementAsVoid(void* obj) { \
  return name##_PreIncrement(obj); \
} \
\
static void* name##_PreDecrementAsVoid(void* obj) { \
  return name##_PreDecrement(obj); \
} \
\
static void* name##_PostIncrementAsVoid(void* out, void* in) { \
  return name##_PostIncrement(out, in); \
} \
\
static void* name##_PostDecrementAsVoid(void* out, void* in) { \
  return name##_PostDecrement(out, in); \
} \
\
/**
 * Object arithmetic operators
 */ \
\
static void* name##_AddAsVoid( \
    void* out, \
    const void* op1, \
    const void* op2 \
) { \
  return name##_Add(out, op1, op2); \
} \
\
static void* name##_SubtractAsVoid( \
    void* out, \
    const void* op1, \
    const void* op2 \
) { \
  return name##_Subtract(out, op1, op2); \
} \
\
static void* name##_MultiplyAsVoid( \
    void* out, \
    const void* op1, \
    const void* op2 \
) { \
  return name##_Multiply(out, op1, op2); \
} \
\
static void* name##_DivideAsVoid( \
    void* out, \
    const void* op1, \
    const void* op2 \
) { \
  return name##_Divide(out, op1, op2); \
} \
\
static void* name##_ModuloAsVoid( \
    void* out, \
    const void* op1, \
    const void* op2 \
) { \
  return name##_Modulo(out, op1, op2); \
} \
\
static void* name##_BitwiseNotAsVoid( \
    void* out, \
    const void* in \
) { \
  return name##_BitwiseNot(out, in); \
} \
\
static void* name##_BitwiseAndAsVoid( \
    void* out, \
    const void* op1, \
    const void* op2 \
) { \
  return name##_BitwiseAnd(out, op1, op2); \
} \
\
static void* name##_BitwiseOrAsVoid( \
    void* out, \
    const void* op1, \
    const void* op2 \
) { \
  return name##_BitwiseOr(out, op1, op2); \
} \
\
static void* name##_BitwiseXorAsVoid( \
    void* out, \
    const void* op1, \
    const void* op2 \
) { \
  return name##_BitwiseXor(out, op1, op2); \
} \
\
static void* name##_BitwiseLeftShiftAsVoid( \
    void* out, \
    const void* op1, \
    const void* op2 \
) { \
  return name##_BitwiseLeftShift(out, op1, op2); \
} \
\
static void* name##_BitwiseRightShiftAsVoid( \
    void* out, \
    const void* op1, \
    const void* op2 \
) { \
  return name##_BitwiseRightShift(out, op1, op2); \
} \
\
/**
 * Object comparison operators
 */ \
\
static bool name##_EqualAsVoid(const void* op1, const void* op2) { \
  return name##_Equal(op1, op2); \
} \
\
static int name##_CompareAsVoid(const void* op1, const void* op2) { \
  return name##_Compare(op1, op2); \
} \
\
/**
 * Object etc. functions
 */ \
\
static size_t name##_HashAsVoid(const void* obj) { \
  return name##_Hash(obj); \
} \
\
static void name##_SwapAsVoid(void* obj1, void* obj2) { \
  name##_Swap(obj1, obj2); \
} \
\
/**
 * Metadata
 */ \
\
static struct Mdc_ObjectMetadata name##global_metadata = \
    MDC_OBJECT_METADATA_UNINIT; \
static once_flag name##global_metadata_once_flag = ONCE_FLAG_INIT; \
\
static struct Mdc_ObjectMetadata* name##_InitObjectMetadata( \
    struct Mdc_ObjectMetadata* metadata \
) { \
  metadata->size = sizeof(type); \
\
  metadata->functions.init_default = &name##_InitDefaultAsVoid; \
  metadata->functions.init_copy = &name##_InitCopyAsVoid; \
  metadata->functions.init_move = &name##_InitMoveAsVoid; \
  metadata->functions.deinit = &name##_DeinitAsVoid; \
\
  metadata->functions.assign_copy = &name##_AssignCopyAsVoid; \
  metadata->functions.assign_move = &name##_AssignMoveAsVoid; \
\
  metadata->functions.pre_increment = &name##_PreIncrementAsVoid; \
  metadata->functions.pre_decrement = &name##_PreDecrementAsVoid; \
  metadata->functions.post_increment = &name##_PostIncrementAsVoid; \
  metadata->functions.post_decrement = &name##_PostDecrementAsVoid; \
\
  metadata->functions.add = &name##_AddAsVoid; \
  metadata->functions.subtract = &name##_SubtractAsVoid; \
  metadata->functions.multiply = &name##_MultiplyAsVoid; \
  metadata->functions.divide = &name##_DivideAsVoid; \
  metadata->functions.modulo = &name##_ModuloAsVoid; \
\
  metadata->functions.bitwise_not = &name##_BitwiseNotAsVoid; \
  metadata->functions.bitwise_and = &name##_BitwiseAndAsVoid; \
  metadata->functions.bitwise_or = &name##_BitwiseOrAsVoid; \
  metadata->functions.bitwise_xor = &name##_BitwiseXorAsVoid; \
  metadata->functions.bitwise_left_shift = \
      &name##_BitwiseLeftShiftAsVoid; \
  metadata->functions.bitwise_right_shift = \
      &name##_BitwiseRightShiftAsVoid; \
\
  metadata->functions.equal = &name##_EqualAsVoid; \
  metadata->functions.compare = &name##_CompareAsVoid; \
\
  metadata->functions.hash = &name##_HashAsVoid; \
  metadata->functions.swap = &name##_SwapAsVoid; \
\
  return metadata; \
} \
\
static void name##_InitGlobalObjectMetadata(void) { \
  name##_InitObjectMetadata(&name##global_metadata); \
} \
\
/**
 * Metadata
 */ \
\
const struct Mdc_ObjectMetadata* name##_GetObjectMetadata(void) { \
  call_once( \
      &name##global_metadata_once_flag, \
      &name##_InitGlobalObjectMetadata \
  ); \
\
  return &name##global_metadata; \
}

MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_Boolean, bool);

MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_SChar, signed char);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_Short, short);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_Integer, int);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_Long, long);

MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_Int8, int8_t);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_Int16, int16_t);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_Int32, int32_t);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_Int64, int64_t);

MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_IntLeast8, int_least8_t);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_IntLeast16, int_least16_t);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_IntLeast32, int_least32_t);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_IntLeast64, int_least64_t);

MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_IntMax, intmax_t);

MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_UChar, unsigned char);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_UShort, unsigned short);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_UInteger, unsigned int);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_ULong, unsigned long);

MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_UInt8, uint8_t);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_UInt16, uint16_t);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_UInt32, uint32_t);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_UInt64, uint64_t);

MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_UIntLeast8, uint_least8_t);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_UIntLeast16, uint_least16_t);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_UIntLeast32, uint_least32_t);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_UIntLeast64, uint_least64_t);

MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_UIntMax, uintmax_t);

MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_Intptr, intptr_t);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_UIntptr, uintptr_t);

#if __cplusplus >= 201103L \
    || __STDC_VERSION__ >= 201112L \
    || _MSC_VER >= 1600

MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_LLong, long long);
MDC_DEFINE_ARITHMETIC_OBJECT_METADATA(Mdc_ULLong, unsigned long long);

#endif /* __cplusplus >= 201103L \
    || __STDC_VERSION__ >= 201112L \
    || _MSC_VER >= 1600 */

#undef MDC_DEFINE_ARITHMETIC_OBJECT_METADATA
