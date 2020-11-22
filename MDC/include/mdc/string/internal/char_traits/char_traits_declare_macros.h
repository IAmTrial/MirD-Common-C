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

#ifndef MDC_C_STRING_INTERNAL_CHAR_TRAITS_CHAR_TRAITS_DECLARE_MACROS_H_
#define MDC_C_STRING_INTERNAL_CHAR_TRAITS_CHAR_TRAITS_DECLARE_MACROS_H_

#include <stddef.h>

#include "../../../macro/concat_macro.h"
#include "../../../std/stdbool.h"
#include "char_traits_name_macros.h"

/**
 * Types
 */

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_CHAR_TYPE(CharT) \
    typedef CharT Mdc_CharTraits_CharType(CharT);

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_INT_TYPE(CharT, int_type) \
    typedef int_type Mdc_CharTraits_IntType(CharT);

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_MEMBER_TYPES( \
    CharT, \
    int_type \
) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_CHAR_TYPE(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_INT_TYPE(CharT, int_type)

/**
 * Functions
 */

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_ASSIGN_CHAR(CharT) \
    void Mdc_CharTraits_AssignChar(CharT)( \
        Mdc_CharTraits_CharType(CharT)* r, \
        const Mdc_CharTraits_CharType(CharT)* a \
    );

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_ASSIGN_CSTR(CharT) \
    CharT* Mdc_CharTraits_AssignCStr(CharT)( \
        CharT* p, \
        size_t count, \
        CharT a \
    );

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_EQUAL_CHAR(CharT) \
    bool Mdc_CharTraits_EqualChar(CharT)(CharT a, CharT b);

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_LESS_THAN_CHAR(CharT) \
    bool Mdc_CharTraits_LessThanChar(CharT)(CharT a, CharT b);

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_COPY_OVERLAP_CSTR(CharT) \
    CharT* Mdc_CharTraits_CopyOverlapCStr(CharT)( \
        CharT* dest, \
        const CharT* src, \
        size_t count \
    );

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_COPY_NONOVERLAP_CSTR(CharT) \
    CharT* Mdc_CharTraits_CopyNonoverlapCStr(CharT)( \
        CharT* dest, \
        const CharT* src, \
        size_t count \
    );

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_COMPARE_CSTR(CharT) \
    int Mdc_CharTraits_CompareCStr(CharT)( \
        const CharT* s1, \
        const CharT* s2, \
        size_t count \
    );

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_LENGTH_CSTR(CharT) \
    size_t Mdc_CharTraits_LengthCStr(CharT)( \
        const CharT* s \
    );

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_FIND_CSTR(CharT) \
    const CharT* Mdc_CharTraits_FindCStr(CharT)( \
        const CharT* p, \
        size_t count, \
        CharT ch \
    );

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_TO_CHAR_TYPE(CharT) \
    CharT Mdc_CharTraits_ToCharType(CharT)( \
        Mdc_CharTraits_IntType(CharT) c \
    );

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_TO_INT_TYPE(CharT) \
    Mdc_CharTraits_IntType(CharT) Mdc_CharTraits_ToIntType(CharT)( \
        CharT c \
    );

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_EQUAL_INT_TYPE(CharT) \
    bool Mdc_CharTraits_EqualIntType(CharT)( \
        Mdc_CharTraits_IntType(CharT) c1, \
        Mdc_CharTraits_IntType(CharT) c2 \
    );

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_EOF(CharT) \
    Mdc_CharTraits_IntType(CharT) Mdc_CharTraits_Eof(CharT)(void);

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_NOT_EOF(CharT) \
    Mdc_CharTraits_IntType(CharT) Mdc_CharTraits_NotEof(CharT)( \
        Mdc_CharTraits_IntType(CharT) e \
    );

#define MDC_INTERNAL_DECLARE_CHAR_TRAITS_FUNCTIONS( \
    CharT \
) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_ASSIGN_CHAR(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_ASSIGN_CSTR(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_EQUAL_CHAR(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_LESS_THAN_CHAR(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_COPY_OVERLAP_CSTR(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_COPY_NONOVERLAP_CSTR(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_COMPARE_CSTR(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_LENGTH_CSTR(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_FIND_CSTR(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_TO_CHAR_TYPE(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_TO_INT_TYPE(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_EQUAL_INT_TYPE(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_EOF(CharT) \
    MDC_INTERNAL_DECLARE_CHAR_TRAITS_NOT_EOF(CharT)

#define MDC_INTERNAL_DECLARE_DLLEXPORT_CHAR_TRAITS_FUNCTIONS( \
    CharT \
) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_ASSIGN_CHAR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_ASSIGN_CSTR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_EQUAL_CHAR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_LESS_THAN_CHAR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_COPY_OVERLAP_CSTR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_COPY_NONOVERLAP_CSTR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_COMPARE_CSTR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_LENGTH_CSTR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_FIND_CSTR(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_TO_CHAR_TYPE(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_TO_INT_TYPE(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_EQUAL_INT_TYPE(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_EOF(CharT) \
    DLLEXPORT MDC_INTERNAL_DECLARE_CHAR_TRAITS_NOT_EOF(CharT)

#endif /* MDC_C_STRING_INTERNAL_CHAR_TRAITS_CHAR_TRAITS_DECLARE_MACROS_H_ */
