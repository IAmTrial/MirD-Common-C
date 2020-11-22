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
    MDC_MACRO_CONCAT(Mdc_CharTraits__, CharT)

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

#define Mdc_CharTraits_AssignChar(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __AssignChar)

#define Mdc_CharTraits_AssignCStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __AssignCStr)

#define Mdc_CharTraits_EqualChar(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __EqualChar)

#define Mdc_CharTraits_LessThanChar(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __LessThanChar)

#define Mdc_CharTraits_CopyOverlapCStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __CopyOverlapCStr)

#define Mdc_CharTraits_CopyNonoverlapCStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __CopyNonoverlapCStr)

#define Mdc_CharTraits_CompareCStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __CompareCStr)

#define Mdc_CharTraits_LengthCStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __LengthCStr)

#define Mdc_CharTraits_FindCStr(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __FindCStr)

#define Mdc_CharTraits_ToCharType(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __ToCharType)

#define Mdc_CharTraits_ToIntType(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __ToIntType)

#define Mdc_CharTraits_EqualIntType(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __EqualIntType)

#define Mdc_CharTraits_Eof(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __Eof)

#define Mdc_CharTraits_NotEof(CharT) \
    MDC_MACRO_CONCAT(Mdc_CharTraits(CharT), __NotEof)

#endif /* MDC_C_STRING_INTERNAL_CHAR_TRAITS_CHAR_TRAITS_NAME_MACROS_H_ */
