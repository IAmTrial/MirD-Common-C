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

#ifndef MDC_C_CONTAINER_INTERNAL_MAP_MAP_NODE_NAME_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_MAP_MAP_NODE_NAME_MACRO_H_

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../../../object/object.h"
#include "../red_black_node/red_black_node_name_macro.h"

#define Mdc_Internal_MapNode(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

/**
 * Initialize / Deinitialize
 */

#define Mdc_Internal_MapNode_InitFromData(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_InitFromData( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_InitFromDataCopy(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_InitFromDataCopy( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_Deinit(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_Deinit( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

/**
 * General Functions
 */

#define Mdc_Internal_MapNode_BackNode(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_BackNode( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_BackNodeConst(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_BackNodeConst( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_Data(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_Data( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_DataConst(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_DataConst( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_EraseNode(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_EraseNode( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_FrontNode(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_FrontNode( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_FrontNodeConst(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_FrontNodeConst( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_Grandparent(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_Grandparent( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_GrandparentConst(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_GrandparentConst( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_InsertNode(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_InsertNode( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_LookupNode(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_LookupNode( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_LookupNodeConst(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_LookupNodeConst( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_NextNode(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_NextNode( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_NextNodeConst(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_NextNodeConst( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_Parent(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_Parent( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_ParentConst(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_ParentConst( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_PreviousNode(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_PreviousNode( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_PreviousNodeConst(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_PreviousNodeConst( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_RotateLeft(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_RotateLeft( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_RotateRight(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_RotateRight( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_Sibling(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_Sibling( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_SiblingConst(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_SiblingConst( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_Uncle(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_Uncle( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#define Mdc_Internal_MapNode_UncleConst(T_KeyT, T_ValueT) \
    Mdc_Internal_RedBlackNode_UncleConst( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

#endif /* MDC_C_CONTAINER_INTERNAL_MAP_MAP_NODE_NAME_MACRO_H_ */
