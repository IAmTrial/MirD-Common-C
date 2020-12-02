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

#ifndef MDC_C_CONTAINER_INTERNAL_VECTOR_VECTOR_NAME_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_VECTOR_VECTOR_NAME_MACRO_H_

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../../../object/integer_object.h"
#include "../../../object/object.h"

#define Mdc_Vector(T_ValueT) \
    MDC_MACRO_CONCAT( \
        Mdc_Vector, \
        MDC_MACRO_TEMPLATE_1(T_ValueT) \
    )

/**
 * Initialize / Deinitialize
 */

#define Mdc_Vector_InitEmpty(T_ValueT) \
    Mdc_Object_InitDefault(Mdc_Vector(T_ValueT))

#define Mdc_Vector_InitCopy(T_ValueT) \
    Mdc_Object_InitCopy(Mdc_Vector(T_ValueT))

#define Mdc_Vector_InitMove(T_ValueT) \
    Mdc_Object_InitMove(Mdc_Vector(T_ValueT))

#define Mdc_Vector_Deinit(T_ValueT) \
    Mdc_Object_Deinit(Mdc_Vector(T_ValueT))

/**
 * Assignment
 */

#define Mdc_Vector_AssignCopy(T_ValueT) \
    Mdc_Object_AssignCopy(Mdc_Vector(T_ValueT))

#define Mdc_Vector_AssignMove(T_ValueT) \
    Mdc_Object_AssignMove(Mdc_Vector(T_ValueT))

/**
 * Comparison
 */

#define Mdc_Vector_Equal(T_ValueT) \
    Mdc_Object_DefaultEqual(Mdc_Vector(T_ValueT), Mdc_Vector(T_ValueT))

#define Mdc_Vector_Compare(T_ValueT) \
    Mdc_Object_DefaultCompare(Mdc_Vector(T_ValueT), Mdc_Vector(T_ValueT))

/**
 * Member access
 */

#define Mdc_Vector_Access(T_ValueT) \
    Mdc_Object_Subscript(Mdc_Vector(T_ValueT), MDC_T_PC(Mdc_Size))

#define Mdc_Vector_AccessConst(T_ValueT) \
    Mdc_Object_SubscriptConst(Mdc_Vector(T_ValueT), MDC_T_PC(Mdc_Size))

/**
 * General Functions
 */

#define Mdc_Vector_At(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), At)

#define Mdc_Vector_AtConst(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), AtConst)

#define Mdc_Vector_Back(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), Back)

#define Mdc_Vector_BackConst(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), BackConst)

#define Mdc_Vector_Capacity(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), Capacity)

#define Mdc_Vector_Clear(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), Clear)

#define Mdc_Vector_Data(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), Data)

#define Mdc_Vector_DataConst(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), DataConst)

#define Mdc_Vector_Empty(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), Empty)

#define Mdc_Vector_Front(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), Front)

#define Mdc_Vector_FrontConst(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), FrontConst)

#define Mdc_Vector_PopBack(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), PopBack)

#define Mdc_Vector_PushBack(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), PushBack)

#define Mdc_Vector_PushBackCopy(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), PushBackCopy)

#define Mdc_Vector_Resize(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), Resize)

#define Mdc_Vector_Reserve(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), Reserve)

#define Mdc_Vector_ShrinkToFit(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), ShrinkToFit)

#define Mdc_Vector_Size(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), Size)

#define Mdc_Vector_Swap(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), Swap)

#endif /* MDC_C_CONTAINER_INTERNAL_VECTOR_VECTOR_NAME_MACRO_H_ */
