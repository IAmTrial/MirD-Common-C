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

#ifndef MDC_C_STRING_INTERNAL_CHAR_TRAITS_CHAR_TRAITS_NAME_MACROS_H_
#define MDC_C_STRING_INTERNAL_CHAR_TRAITS_CHAR_TRAITS_NAME_MACROS_H_

#include "../../../macro/concat_macro.h"

#define Mdc_CharTraits(CharT) \
    Mdc_CharTraits__##CharT

/**
 * Types
 */

#define Mdc_CharTraits_CharType(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __CharType)

#define Mdc_CharTraits_IntType(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __IntType)

/**
 * Functions
 */

#define Mdc_CharTraits_AssignChar(CharT, r, a) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __AssignChar(r, a))

#define Mdc_CharTraits_AssignCStr(CharT, p, count, a) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __AssignCStr(p, count, a))

#define Mdc_CharTraits_EqualChar(CharT, a, b) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __EqualChar(a, b))

#define Mdc_CharTraits_LessThanChar(CharT, a, b) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __LessThanChar(a, b))

#define Mdc_CharTraits_CopyOverlapCStr(CharT, dest, src, count) \
    MDC_MACRO_CONCAT( \
        Mdc_CharTraits(CharT), \
        __CopyOverlapCStr(dest, src, count) \
    )

#define Mdc_CharTraits_CopyNonoverlapCStr(CharT, dest, src, count) \
    MDC_MACRO_CONCAT( \
        Mdc_CharTraits(CharT), \
        __CopyNonoverlapCStr(dest, src, count) \
    )

#define Mdc_CharTraits_CompareCStr(CharT, s1, s2, count) \
    MDC_MACRO_CONCAT( \
        Mdc_CharTraits(CharT), \
        __CompareCStr(s1, s2, count) \
    )

#define Mdc_CharTraits_LengthCStr(CharT, s) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __LengthCStr(s))

#define Mdc_CharTraits_FindCStr(CharT, p, count, ch) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __FindCStr(p, count, ch))

#define Mdc_CharTraits_ToCharType(CharT, c) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __ToCharType(c))

#define Mdc_CharTraits_ToIntType(CharT, c) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __ToIntType(c))

#define Mdc_CharTraits_EqualIntType(CharT, c1, c2) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __EqualIntType(c1, c2))

#define Mdc_CharTraits_Eof(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __Eof())

#define Mdc_CharTraits_NotEof(CharT, e) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __NotEof(e))

#endif /* MDC_C_STRING_INTERNAL_CHAR_TRAITS_CHAR_TRAITS_NAME_MACROS_H_ */
