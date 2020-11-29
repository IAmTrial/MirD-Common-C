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

#ifndef MDC_C_STRING_INTERNAL_CHAR_TRAITS_CHAR_TRAITS__CHAR_H_
#define MDC_C_STRING_INTERNAL_CHAR_TRAITS_CHAR_TRAITS__CHAR_H_

#include "../../../object/character_object.h"
#include "../../../object/integer_object.h"
#include "char_traits_declare_macros.h"
#include "char_traits_name_macros.h"

#include "../../../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

MDC_INTERNAL_DECLARE_CHAR_TRAITS_MEMBER_TYPES(Mdc_Char, Mdc_Int)
MDC_INTERNAL_DECLARE_DLLEXPORT_CHAR_TRAITS_FUNCTIONS(Mdc_Char)

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../../../dllexport_undefine.inc"
#endif /* MDC_C_STRING_INTERNAL_CHAR_TRAITS_CHAR_TRAITS__CHAR_H_ */
