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

#ifndef MDC_C_OBJECT_INTERNAL_CHARACTER_OBJECT_CHARACTER_OBJECT_NAME_MACROS_H_
#define MDC_C_OBJECT_INTERNAL_CHARACTER_OBJECT_CHARACTER_OBJECT_NAME_MACROS_H_

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../object_name_macros.h"

/**
 * Initialize / Deinitialize
 */

#define Mdc_Character_InitDefault(T_CharacterT) \
    Mdc_Object_InitDefault(T_CharacterT)

#define Mdc_Character_InitFromValue(T_CharacterT) \
    Mdc_Object_InitFrom(T_CharacterT, MDC_T(T_CharacterT))

#define Mdc_Character_InitCopy(T_CharacterT) \
    Mdc_Object_InitCopy(T_CharacterT)

#define Mdc_Character_InitMove(T_CharacterT) \
    Mdc_Object_InitMove(T_CharacterT)

#define Mdc_Character_Deinit(T_CharacterT) \
    Mdc_Object_Deinit(T_CharacterT)

/**
 * Assignment
 */

#define Mdc_Character_AssignCopy(T_CharacterT) \
    Mdc_Object_AssignCopy(T_CharacterT)

#define Mdc_Character_AssignMove(T_CharacterT) \
    Mdc_Object_AssignMove(T_CharacterT)

/**
 * Logical
 */

#define Mdc_Character_LogicalNot(T_CharacterT) \
    Mdc_Object_LogicalNot(T_CharacterT)

#define Mdc_Character_LogicalNotConst(T_CharacterT) \
    Mdc_Object_LogicalNotConst(T_CharacterT)

#define Mdc_Character_LogicalAnd(T_CharacterT) \
    Mdc_Object_DefaultLogicalAnd(T_CharacterT, T_CharacterT)

#define Mdc_Character_LogicalOr(T_CharacterT) \
    Mdc_Object_DefaultLogicalOr(T_CharacterT, T_CharacterT)

/**
 * Comparison
 */

#define Mdc_Character_Equal(T_CharacterT) \
    Mdc_Object_DefaultEqual(T_CharacterT, T_CharacterT)

#define Mdc_Character_Compare(T_CharacterT) \
    Mdc_Object_DefaultCompare(T_CharacterT, T_CharacterT)

/**
 * General Functions
 */

#define Mdc_Character_Swap(T_CharacterT) \
    Mdc_Object_Swap(T_CharacterT)

#endif /* MDC_C_OBJECT_INTERNAL_CHARACTER_OBJECT_CHARACTER_OBJECT_NAME_MACROS_H_ */
