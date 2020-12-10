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

#ifndef MDC_C_CONTAINER_INTERNAL_RED_BLACK_TREE_RED_BLACK_TREE_NAME_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_RED_BLACK_TREE_RED_BLACK_TREE_NAME_MACRO_H_

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../../../object/object.h"

#define Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc) \
    MDC_MACRO_CONCAT( \
        Mdc_Internal_RedBlackTree, \
        MDC_MACRO_TEMPLATE_2(T_DataT, F_CompareFunc) \
    )

/**
 * Constants
 */

#define Mdc_Internal_RedBlackTree_kUninit(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc), \
        kUninit \
    )

/**
 * Initialize / Deinitialize
 */

#define Mdc_Internal_RedBlackTree_InitEmpty(T_DataT, F_CompareFunc) \
    Mdc_Object_InitDefault( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc) \
    )

#define Mdc_Internal_RedBlackTree_InitCopy(T_DataT, F_CompareFunc) \
    Mdc_Object_InitCopy( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc) \
    )

#define Mdc_Internal_RedBlackTree_InitMove(T_DataT, F_CompareFunc) \
    Mdc_Object_InitMove( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc) \
    )

#define Mdc_Internal_RedBlackTree_Deinit(T_DataT, F_CompareFunc) \
    Mdc_Object_Deinit(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc))

/**
 * General Functions
 */

#define Mdc_Internal_RedBlackTree_Back(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc), \
        Back \
    )

#define Mdc_Internal_RedBlackTree_BackConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc), \
        BackConst \
    )

#define Mdc_Internal_RedBlackTree_Erase(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc), \
        Erase \
    )

#define Mdc_Internal_RedBlackTree_Front(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc), \
        Front \
    )

#define Mdc_Internal_RedBlackTree_FrontConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc), \
        FrontConst \
    )

#define Mdc_Internal_RedBlackTree_Insert(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc), \
        Insert \
    )

#define Mdc_Internal_RedBlackTree_InsertCopy(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc), \
        InsertCopy \
    )

#define Mdc_Internal_RedBlackTree_Lookup(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc), \
        Lookup \
    )

#define Mdc_Internal_RedBlackTree_LookupConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc), \
        LookupConst \
    )

#endif /* MDC_C_CONTAINER_INTERNAL_RED_BLACK_TREE_RED_BLACK_TREE_NAME_MACRO_H_ */
