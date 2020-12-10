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

#ifndef MDC_C_CONTAINER_INTERNAL_RED_BLACK_TREE_RED_BLACK_TREE_DECLARE_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_RED_BLACK_TREE_RED_BLACK_TREE_DECLARE_MACRO_H_

#include <stddef.h>

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../../../std/stdbool.h"
#include "../../pair.h"
#include "../red_black_node.h"
#include "red_black_tree_name_macro.h"

/**
 * Prerequisites
 */

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_PREREQUISITES( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE( \
        T_DataT, \
        F_CompareFunc \
    )

/**
 * Struct
 */

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_STRUCT(T_DataT, F_CompareFunc) \
    struct Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc); \
    MDC_T_DECLARE_DATA_TYPE_TYPEDEFS( \
        struct, \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc) \
    ) \
    struct Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc) { \
      MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) root_; \
    }; \

/**
 * Initialize / Deinitialize
 */

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_INIT_EMPTY( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_DECLARE_OBJECT_INIT_DEFAULT( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc) \
    )

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_INIT_COPY( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_DECLARE_OBJECT_INIT_COPY( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc) \
    )

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_INIT_MOVE( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_DECLARE_OBJECT_INIT_MOVE( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc) \
    )

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_DEINIT( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_DECLARE_OBJECT_DEINIT( \
        Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc) \
    )

/**
 * General Functions
 */

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_BACK( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_Back(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_BACK_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_BackConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_ERASE( \
    T_DataT, \
    F_CompareFunc \
) \
    void Mdc_Internal_RedBlackTree_Erase(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree, \
        MDC_T_PC(T_DataT) data \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_FRONT( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_Front(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_FRONT_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_FrontConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_INSERT(T_DataT, F_CompareFunc) \
    void Mdc_Internal_RedBlackTree_Insert(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree, \
        MDC_T_P(T_DataT) data \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_INSERT_COPY( \
    T_DataT, \
    F_CompareFunc \
) \
    void Mdc_Internal_RedBlackTree_InsertCopy(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree, \
        MDC_T_PC(T_DataT) data \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_LOOKUP(T_DataT, F_CompareFunc) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_Lookup(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree, \
        MDC_T_PC(T_DataT) data \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_LOOKUP_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_LookupConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree, \
        MDC_T_PC(T_DataT) data \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_TREE_FUNCTIONS( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_INTERNAL_DECLARE_RED_BLACK_TREE_INIT_EMPTY(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_TREE_INIT_COPY(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_TREE_INIT_MOVE(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_TREE_DEINIT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_TREE_BACK(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_TREE_BACK_CONST(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_TREE_ERASE(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_TREE_FRONT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_TREE_FRONT_CONST(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_TREE_INSERT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_TREE_INSERT_COPY(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_TREE_LOOKUP(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_TREE_LOOKUP_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \

#endif /* MDC_C_CONTAINER_INTERNAL_RED_BLACK_TREE_RED_BLACK_TREE_DECLARE_MACRO_H_ */
