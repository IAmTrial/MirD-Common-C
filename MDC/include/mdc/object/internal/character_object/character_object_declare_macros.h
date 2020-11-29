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

#ifndef MDC_C_OBJECT_INTERNAL_CHARACTER_OBJECT_CHARACTER_OBJECT_DECLARE_MACROS_H_
#define MDC_C_OBJECT_INTERNAL_CHARACTER_OBJECT_CHARACTER_OBJECT_DECLARE_MACROS_H_

#include "../../../macro/template_macro.h"
#include "../object_declare_macros.h"
#include "character_object_name_macros.h"

/**
 * Initialize / Deinitialize
 */

#define MDC_DECLARE_CHARACTER_INIT_DEFAULT(T_CharacterT) \
    MDC_DECLARE_OBJECT_INIT_DEFAULT(T_CharacterT)

#define MDC_DECLARE_CHARACTER_INIT_FROM_VALUE(T_CharacterT) \
    MDC_DECLARE_OBJECT_INIT_FROM(T_CharacterT, MDC_T(T_CharacterT))

#define MDC_DECLARE_CHARACTER_INIT_COPY(T_CharacterT) \
    MDC_DECLARE_OBJECT_INIT_COPY(T_CharacterT)

#define MDC_DECLARE_CHARACTER_INIT_MOVE(T_CharacterT) \
    MDC_DECLARE_OBJECT_INIT_MOVE(T_CharacterT)

#define MDC_DECLARE_CHARACTER_DEINIT(T_CharacterT) \
    MDC_DECLARE_OBJECT_DEINIT(T_CharacterT)

/**
 * Assignment
 */

#define MDC_DECLARE_CHARACTER_ASSIGN_COPY(T_CharacterT) \
    MDC_DECLARE_OBJECT_ASSIGN_COPY(T_CharacterT)

#define MDC_DECLARE_CHARACTER_ASSIGN_MOVE(T_CharacterT) \
    MDC_DECLARE_OBJECT_ASSIGN_MOVE(T_CharacterT)

/**
 * Logical
 */

#define MDC_DECLARE_CHARACTER_LOGICAL_NOT(T_CharacterT) \
    MDC_DECLARE_OBJECT_LOGICAL_NOT(bool, T_CharacterT)

#define MDC_DECLARE_CHARACTER_LOGICAL_NOT_CONST(T_CharacterT) \
    MDC_DECLARE_OBJECT_DEFAULT_LOGICAL_NOT_CONST(T_CharacterT)

#define MDC_DECLARE_CHARACTER_LOGICAL_AND(T_CharacterT) \
    MDC_DECLARE_OBJECT_DEFAULT_LOGICAL_AND(T_CharacterT, T_CharacterT)

#define MDC_DECLARE_CHARACTER_LOGICAL_OR(T_CharacterT) \
    MDC_DECLARE_OBJECT_DEFAULT_LOGICAL_OR(T_CharacterT, T_CharacterT)

/**
 * Comparison
 */

#define MDC_DECLARE_CHARACTER_EQUAL(T_CharacterT) \
    MDC_DECLARE_OBJECT_DEFAULT_EQUAL(T_CharacterT, T_CharacterT)

#define MDC_DECLARE_CHARACTER_COMPARE(T_CharacterT) \
    MDC_DECLARE_OBJECT_DEFAULT_COMPARE(T_CharacterT, T_CharacterT)

/**
 * General Functions
 */

#define MDC_DECLARE_CHARACTER_SWAP(T_CharacterT) \
    MDC_DECLARE_OBJECT_SWAP(T_CharacterT)

#define MDC_INTERNAL_DECLARE_CHARACTER_FUNCTIONS(T_CharacterT) \
    MDC_DECLARE_CHARACTER_INIT_DEFAULT(T_CharacterT) \
    MDC_DECLARE_CHARACTER_INIT_FROM_VALUE(T_CharacterT) \
    MDC_DECLARE_CHARACTER_INIT_COPY(T_CharacterT) \
    MDC_DECLARE_CHARACTER_INIT_MOVE(T_CharacterT) \
    MDC_DECLARE_CHARACTER_DEINIT(T_CharacterT) \
    MDC_DECLARE_CHARACTER_ASSIGN_COPY(T_CharacterT) \
    MDC_DECLARE_CHARACTER_ASSIGN_MOVE(T_CharacterT) \
    MDC_DECLARE_CHARACTER_LOGICAL_NOT(T_CharacterT) \
    MDC_DECLARE_CHARACTER_LOGICAL_NOT_CONST(T_CharacterT) \
    MDC_DECLARE_CHARACTER_LOGICAL_AND(T_CharacterT) \
    MDC_DECLARE_CHARACTER_LOGICAL_OR(T_CharacterT) \
    MDC_DECLARE_CHARACTER_EQUAL(T_CharacterT) \
    MDC_DECLARE_CHARACTER_COMPARE(T_CharacterT) \
    MDC_DECLARE_OBJECT_SWAP(T_CharacterT)

#define MDC_INTERNAL_DECLARE_DLLEXPORT_CHARACTER_FUNCTIONS(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_CHARACTER_INIT_DEFAULT(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_CHARACTER_INIT_FROM_VALUE(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_CHARACTER_INIT_COPY(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_CHARACTER_INIT_MOVE(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_CHARACTER_DEINIT(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_CHARACTER_ASSIGN_COPY(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_CHARACTER_ASSIGN_MOVE(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_CHARACTER_LOGICAL_NOT(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_CHARACTER_LOGICAL_NOT_CONST(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_CHARACTER_LOGICAL_AND(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_CHARACTER_LOGICAL_OR(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_CHARACTER_EQUAL(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_CHARACTER_COMPARE(T_CharacterT) \
    DLLEXPORT MDC_DECLARE_OBJECT_SWAP(T_CharacterT)

#define MDC_INTERNAL_DECLARE_CHARACTER(T_CharacterT) \
    MDC_T_DECLARE_TYPEDEFS(T_CharacterT) \
    MDC_INTERNAL_DECLARE_CHARACTER_FUNCTIONS(T_CharacterT)

#define MDC_INTERNAL_DECLARE_DLLEXPORT_CHARACTER(T_CharacterT) \
    MDC_T_DECLARE_TYPEDEFS(T_CharacterT) \
    MDC_INTERNAL_DECLARE_DLLEXPORT_CHARACTER_FUNCTIONS(T_CharacterT)

#endif /* MDC_C_OBJECT_INTERNAL_CHARACTER_OBJECT_CHARACTER_OBJECT_DECLARE_MACROS_H_ */
