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

#ifndef MDC_C_CONTAINER_INTERNAL_RED_BLACK_NODE_RED_BLACK_NODE_NAME_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_RED_BLACK_NODE_RED_BLACK_NODE_NAME_MACRO_H_

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../../../object/object.h"

#define Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc) \
    MDC_MACRO_CONCAT( \
        Mdc_Internal_RedBlackNode, \
        MDC_MACRO_TEMPLATE_2(T_DataT, F_CompareFunc) \
    )

/**
 * Constants
 */

#define Mdc_Internal_RedBlackNode_kUninit(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        kUninit \
    )

/**
 * Initialize / Deinitialize
 */

#define Mdc_Internal_RedBlackNode_InitFromData(T_DataT, F_CompareFunc) \
    Mdc_Object_InitFrom_1( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        MDC_T_P(T_DataT) \
    )

#define Mdc_Internal_RedBlackNode_InitFromDataCopy(T_DataT, F_CompareFunc) \
    Mdc_Object_InitFrom_1( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        MDC_T_PC(T_DataT) \
    )

#define Mdc_Internal_RedBlackNode_InitCopy(T_DataT, F_CompareFunc) \
    Mdc_Object_InitCopy(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))

#define Mdc_Internal_RedBlackNode_InitMove(T_DataT, F_CompareFunc) \
    Mdc_Object_InitCopy(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))

#define Mdc_Internal_RedBlackNode_Deinit(T_DataT, F_CompareFunc) \
    Mdc_Object_Deinit(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))

/**
 * General Functions
 */

#define Mdc_Internal_RedBlackNode_BackNode(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        BackNode \
    )

#define Mdc_Internal_RedBlackNode_BackNodeConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        BackNodeConst \
    )

#define Mdc_Internal_RedBlackNode_Data(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        Data \
    )

#define Mdc_Internal_RedBlackNode_DataConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        DataConst \
    )

#define Mdc_Internal_RedBlackNode_FrontNode(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        FrontNode \
    )

#define Mdc_Internal_RedBlackNode_FrontNodeConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        FrontNodeConst \
    )

#define Mdc_Internal_RedBlackNode_Grandparent(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        Grandparent \
    )

#define Mdc_Internal_RedBlackNode_GrandparentConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        GrandparentConst \
    )

#define Mdc_Internal_RedBlackNode_Left(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        Left \
    )

#define Mdc_Internal_RedBlackNode_LeftConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        LeftConst \
    )

#define Mdc_Internal_RedBlackNode_NextNode(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        NextNode \
    )

#define Mdc_Internal_RedBlackNode_NextNodeConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        NextNodeConst \
    )

#define Mdc_Internal_RedBlackNode_Parent(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        Parent \
    )

#define Mdc_Internal_RedBlackNode_ParentConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        ParentConst \
    )

#define Mdc_Internal_RedBlackNode_Predecessor(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        Predecessor \
    )

#define Mdc_Internal_RedBlackNode_PredecessorConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        PredecessorConst \
    )

#define Mdc_Internal_RedBlackNode_PreviousNode(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        PreviousNode \
    )

#define Mdc_Internal_RedBlackNode_PreviousNodeConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        PreviousNodeConst \
    )

#define Mdc_Internal_RedBlackNode_Right(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        Right \
    )

#define Mdc_Internal_RedBlackNode_RightConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        RightConst \
    )

#define Mdc_Internal_RedBlackNode_RotateLeft(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        RotateLeft \
    )

#define Mdc_Internal_RedBlackNode_RotateRight(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        RotateRight \
    )

#define Mdc_Internal_RedBlackNode_Sibling(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        Sibling \
    )

#define Mdc_Internal_RedBlackNode_SiblingConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        SiblingConst \
    )

#define Mdc_Internal_RedBlackNode_Successor(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        Successor \
    )

#define Mdc_Internal_RedBlackNode_SuccessorConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        SuccessorConst \
    )

#define Mdc_Internal_RedBlackNode_Uncle(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        Uncle \
    )

#define Mdc_Internal_RedBlackNode_UncleConst(T_DataT, F_CompareFunc) \
    Mdc_Object_Member( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc), \
        UncleConst \
    )

#endif /* MDC_C_CONTAINER_INTERNAL_RED_BLACK_NODE_RED_BLACK_NODE_NAME_MACRO_H_ */
