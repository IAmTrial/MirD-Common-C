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

#ifndef MDC_C_OBJECT_WINDOWS_INTEGER_OBJECT_H_
#define MDC_C_OBJECT_WINDOWS_INTEGER_OBJECT_H_

#if defined(_WIN32) || defined(_WIN64)

#include <windows.h>

#include "../object_metadata/object_metadata.h"
#include "../std/stdbool.h"

#include "../../../dllexport_define.inc"

#define MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(name, type) \
\
/**
 * Initialization/deinitialization
 */ \
\
DLLEXPORT type* name##_InitDefault(type* obj); \
\
DLLEXPORT type* name##_InitFromValue(type* obj, type value); \
\
DLLEXPORT type* name##_InitCopy(type* dest, const type* src); \
\
DLLEXPORT type* name##_InitMove(type* dest, type* src); \
\
DLLEXPORT void name##_Deinit(type* obj); \
\
/**
 * Metadata
 */ \
\
DLLEXPORT const struct Mdc_ObjectMetadata* \
name##_GetObjectMetadata(void); \
\
/**
 * Assignment functions
 */ \
\
DLLEXPORT type* name##_AssignCopy(type* dest, const type* src); \
\
DLLEXPORT type* name##_AssignMove(type* dest, type* src); \
\
/**
 * Increment/decrement operators
 */ \
\
DLLEXPORT type* name##_PreIncrement(type* obj); \
\
DLLEXPORT type name##_PreIncrementValue(type op); \
\
DLLEXPORT type* name##_PreDecrement(type* obj); \
\
DLLEXPORT type name##_PreDecrementValue(type op); \
\
DLLEXPORT type* name##_PostIncrement(type* out, type* in); \
\
DLLEXPORT type name##_PostIncrementValue(type* op); \
\
DLLEXPORT type* name##_PostDecrement(type* out, type* in); \
\
DLLEXPORT type name##_PostDecrementValue(type* op); \
\
/**
 * Arithmetic operators
 */ \
\
DLLEXPORT type* name##_Add( \
    type* out, \
    const type* op1, \
    const type* op2 \
); \
\
DLLEXPORT type name##_AddValue(type op1, type op2); \
\
DLLEXPORT type* name##_Subtract( \
    type* out, \
    const type* op1, \
    const type* op2 \
); \
\
DLLEXPORT type name##_SubtractValue(type op1, type op2); \
\
DLLEXPORT type* name##_Multiply( \
    type* out, \
    const type* op1, \
    const type* op2 \
); \
\
DLLEXPORT type name##_MultiplyValue(type op1, type op2); \
\
DLLEXPORT type* name##_Divide( \
    type* out, \
    const type* op1, \
    const type* op2 \
); \
\
DLLEXPORT type name##_DivideValue(type op1, type op2); \
\
DLLEXPORT type* name##_Modulo( \
    type* out, \
    const type* op1, \
    const type* op2 \
); \
\
DLLEXPORT type name##_ModuloValue(type op1, type op2); \
\
DLLEXPORT type* name##_BitwiseNot( \
    type* out, \
    const type* in \
); \
\
DLLEXPORT type name##_BitwiseNotValue(type op); \
\
DLLEXPORT type* name##_BitwiseAnd( \
    type* out, \
    const type* op1, \
    const type* op2 \
); \
\
DLLEXPORT type name##_BitwiseAndValue(type op1, type op2); \
\
DLLEXPORT type* name##_BitwiseOr( \
    type* out, \
    const type* op1, \
    const type* op2 \
); \
\
DLLEXPORT type name##_BitwiseOrValue(type op1, type op2); \
\
DLLEXPORT type* name##_BitwiseXor( \
    type* out, \
    const type* op1, \
    const type* op2 \
); \
\
DLLEXPORT type name##_BitwiseXorValue(type op1, type op2); \
\
DLLEXPORT type* name##_BitwiseLeftShift( \
    type* out, \
    const type* op1, \
    const type* op2 \
); \
\
DLLEXPORT type name##_BitwiseLeftShiftValue(type op1, type op2); \
\
DLLEXPORT type* name##_BitwiseRightShift( \
    type* out, \
    const type* op1, \
    const type* op2 \
); \
\
DLLEXPORT type name##_BitwiseRightShiftValue(type op1, type op2); \
\
/**
 * Comparison operators
 */ \
\
DLLEXPORT bool name##_Equal(const type* op1, const type* op2); \
\
DLLEXPORT bool name##_EqualValue(type value1, type value2); \
\
DLLEXPORT int name##_Compare(const type* op1, const type* op2); \
\
DLLEXPORT int name##_CompareValue(type value1, type value2); \
\
/**
 * Etc. functions
 */ \
\
DLLEXPORT size_t name##_Hash(const type* obj); \
\
DLLEXPORT size_t name##_HashValue(type obj); \
\
DLLEXPORT void name##_Swap(type* obj1, type* obj2);

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_BOOL, BOOL);

MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_CHAR, CHAR);
MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_UCHAR, UCHAR);

MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_SHORT, SHORT);
MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_INT, INT);
MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_LONG, LONG);
MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_LONGLONG, LONGLONG);

MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_USHORT, USHORT);
MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_UINT, UINT);
MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_ULONG, ULONG);
MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_ULONGLONG, ULONGLONG);

MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_BYTE, BYTE);
MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_WORD, WORD);
MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_DWORD, DWORD);
MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_DWORDLONG, DWORDLONG);

MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_DWORD32, DWORD32);
MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS(Mdc_DWORD64, DWORD64);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#undef MDC_DECLARE_WINDOWS_INTEGER_OBJECT_FUNCS

#include "../../../dllexport_undefine.inc"

#endif /* defined(_WIN32) || defined(_WIN64) */
#endif /* MDC_C_OBJECT_WINDOWS_INTEGER_OBJECT_H_ */
