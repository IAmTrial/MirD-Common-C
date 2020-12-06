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

#ifndef MDC_C_CONTAINER_INTERNAL_RED_BLACK_NODE_RED_BLACK_NODE_DECLARE_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_RED_BLACK_NODE_RED_BLACK_NODE_DECLARE_MACRO_H_

#include <stddef.h>

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../../../std/stdbool.h"
#include "../../pair.h"
#include "red_black_node_name_macro.h"

/**
 * Prerequisites
 */

enum Mdc_Internal_RedBlackColor {
  Mdc_Internal_RedBlackColor_kRed = 1,
  Mdc_Internal_RedBlackColor_kBlack = 2,
};

/**
 * Struct
 */

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_STRUCT(T_DataT, F_CompareFunc) \
    struct Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc) { \
      enum Mdc_Internal_RedBlackColor color_; \
      MDC_T_P(T_DataT) data_; \
\
      struct Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)* parent_; \
      struct Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)* left_; \
      struct Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)* right_; \
    }; \
    MDC_T_DECLARE_DATA_TYPE_TYPEDEFS( \
        struct, \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc) \
    )

/**
 * Initialize / Deinitialize
 */

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_INIT_FROM_DATA( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_InitFromData(T_DataT, F_CompareFunc)( \
        MDC_T_P(T_DataT) data \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_INIT_FROM_DATA_COPY( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_InitFromDataCopy(T_DataT, F_CompareFunc)( \
        MDC_T_PC(T_DataT) data \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_DEINIT(T_DataT, F_CompareFunc) \
    MDC_DECLARE_OBJECT_DEINIT( \
        Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc) \
    )

/**
 * General Functions
 */

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_BACK_NODE( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_BackNode(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_BACK_NODE_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_BackNodeConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_DATA( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(T_DataT) \
    Mdc_Internal_RedBlackNode_Data(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_DATA_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(T_DataT) \
    Mdc_Internal_RedBlackNode_DataConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_ERASE_NODE( \
    T_DataT, \
    F_CompareFunc \
) \
    void Mdc_Internal_RedBlackNode_Erase(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node, \
        MDC_T_PC(T_DataT) data \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_FRONT_NODE( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_FrontNode(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_FRONT_NODE_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_FrontNodeConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_GRANDPARENT( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Grandparent(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_GRANDPARENT_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_GrandparentConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_INSERT( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Insert(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) root, \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) data \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_LOOKUP( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Lookup(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node, \
        MDC_T_PC(T_DataT) data \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_LOOKUP_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_LookupConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node, \
        MDC_T_PC(T_DataT) data \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_NEXT_NODE( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_NextNode(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_NEXT_NODE_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_NextNodeConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_PARENT( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Parent(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_PARENT_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_ParentConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_PREDECESSOR( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Predecessor(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_PREDECESSOR_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_PredecessorConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_PREVIOUS_NODE( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_PreviousNode(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_PREVIOUS_NODE_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_PreviousNodeConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_ROTATE_LEFT( \
    T_DataT, \
    F_CompareFunc \
) \
    void Mdc_Internal_RedBlackNode_RotateLeft(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_ROTATE_RIGHT( \
    T_DataT, \
    F_CompareFunc \
) \
    void Mdc_Internal_RedBlackNode_RotateRight(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_SIBLING( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Sibling(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_SIBLING_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_SiblingConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_SUCCESSOR( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Successor(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_SUCCESSOR_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_SuccessorConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_UNCLE( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Uncle(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_UNCLE_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_UncleConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    );

#define MDC_INTERNAL_DECLARE_RED_BLACK_NODE_FUNCTIONS( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_INIT_FROM_DATA( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_INIT_FROM_DATA_COPY( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_DEINIT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_BACK_NODE(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_BACK_NODE_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_DATA(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_DATA_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_ERASE_NODE(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_FRONT_NODE( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_FRONT_NODE_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_GRANDPARENT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_GRANDPARENT_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_INSERT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_LOOKUP(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_LOOKUP_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_NEXT_NODE(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_NEXT_NODE_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_PARENT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_PARENT_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_PREDECESSOR(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_PREDECESSOR_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_ROTATE_LEFT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_ROTATE_RIGHT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_SIBLING(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_SIBLING_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_SUCCESSOR(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_SUCCESSOR_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_UNCLE(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE_UNCLE_CONST( \
        T_DataT, \
        F_CompareFunc \
    )

#endif /* MDC_C_CONTAINER_INTERNAL_RED_BLACK_NODE_RED_BLACK_NODE_DECLARE_MACRO_H_ */
