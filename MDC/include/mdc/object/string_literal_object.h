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

#ifndef MDC_C_OBJECT_STRING_LITERAL_OBJECT_H_
#define MDC_C_OBJECT_STRING_LITERAL_OBJECT_H_

#include "../object_metadata/object_metadata.h"
#include "../std/stdbool.h"
#include "../std/wchar.h"

#include "../../../dllexport_define.inc"

#define MDC_DECLARE_STRING_LITERAL_OBJECT_FUNCS(name, type) \
\
/**
 * Initialization/deinitialization
 */ \
\
DLLEXPORT const type** name##_InitDefault(const type** obj); \
\
DLLEXPORT const type** name##_InitCopy( \
    const type** dest, \
    const type* const* src \
); \
\
DLLEXPORT const type** name##_InitMove( \
    const type** dest, \
    const type** src \
); \
\
DLLEXPORT void name##_Deinit(const type** obj); \
\
/**
 * Assignment functions
 */ \
\
DLLEXPORT const type** name##_AssignCopy( \
    const type** dest, \
    const type* const* src \
); \
\
DLLEXPORT const type** name##_AssignMove( \
    const type** dest, \
    const type** src \
); \
\
/**
 * Metadata
 */ \
\
DLLEXPORT const struct Mdc_ObjectMetadata* \
name##_GetObjectMetadata(void); \
\
/**
 * Comparison operators
 */ \
\
DLLEXPORT bool name##_Equal( \
    const type* const* op1, \
    const type* const* op2 \
); \
\
DLLEXPORT int name##_Compare( \
    const type* const* op1, \
    const type* const* op2 \
);\
\
/**
 * Etc. functions
 */ \
\
DLLEXPORT void name##_Swap( \
    const type** obj1, \
    const type** obj2 \
);

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

MDC_DECLARE_STRING_LITERAL_OBJECT_FUNCS(Mdc_StringLiteral, char);
MDC_DECLARE_STRING_LITERAL_OBJECT_FUNCS(Mdc_WStringLiteral, wchar_t);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#undef MDC_DECLARE_STRING_LITERAL_OBJECT_FUNCS

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_OBJECT_STRING_LITERAL_OBJECT_H_ */
