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

#ifndef MDC_C_CONTAINER_INTERNAL_RED_BLACK_NODE_RED_BLACK_NODE_DEFINE_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_RED_BLACK_NODE_RED_BLACK_NODE_DEFINE_MACRO_H_

#include <stddef.h>

#include "../../../macro/template_macro.h"
#include "../../../malloc/malloc.h"
#include "../../../std/assert.h"
#include "../../../std/stdbool.h"
#include "red_black_node_name_macro.h"

#define MDC_INTERNAL_RED_BLACK_NODE_UNINIT { 0 }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_K_UNINIT( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_C(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_kUninit(T_DataT, F_CompareFunc) = \
        MDC_INTERNAL_RED_BLACK_NODE_UNINIT;

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_CONSTANTS( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_K_UNINIT(T_DataT, F_CompareFunc)

/**
 * Functions
 */

/**
 * Initialize / Deinitialize
 */

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_INIT_FROM_DATA( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_InitFromData(T_DataT, F_CompareFunc)( \
        MDC_T_P(T_DataT) data \
    ) { \
      MDC_T(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node; \
\
      node.data = Mdc_malloc(sizeof(*node.data)); \
      if (node.data == NULL) { \
        return Mdc_Internal_RedBlackNode_kUninit(T_DataT, F_CompareFunc); \
      } \
      *node.data = Mdc_Object_InitMove(T_DataT)(data); \
      node.color = Mdc_Internal_RedBlackColor_kRed; \
      node.parent = NULL; \
      node.left = NULL; \
      node.right = NULL; \
\
      return node; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_INIT_FROM_DATA_COPY( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_InitFromDataCopy(T_DataT, F_CompareFunc)( \
        MDC_T_PC(T_DataT) data \
    ) { \
      MDC_T(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node; \
\
      node.data = Mdc_malloc(sizeof(*node.data)); \
      if (node.data == NULL) { \
        return Mdc_Internal_RedBlackNode_kUninit(T_DataT, F_CompareFunc); \
      } \
      *node.data = Mdc_Object_InitCopy(T_DataT)(data); \
      node.color = Mdc_Internal_RedBlackColor_kRed; \
      node.parent = NULL; \
      node.left = NULL; \
      node.right = NULL; \
\
      return node; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_INIT_COPY( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_InitCopy(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) src \
    ) { \
      MDC_T(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node; \
\
      node.data = Mdc_malloc(sizeof(*node.data)); \
      if (node.data == NULL) { \
        return Mdc_Internal_RedBlackNode_kUninit(T_DataT, F_CompareFunc); \
      } \
\
      *node.data = Mdc_Object_InitCopy(T_DataT)(src->data); \
\
      node.color = src->color; \
\
      if (src->left != NULL) { \
        node.left = Mdc_malloc(sizeof(*node.left)); \
        if (node.left == NULL) { \
          Mdc_Object_Deinit(T_DataT)(node.data); \
          Mdc_free(node.data); \
\
          return Mdc_Internal_RedBlackNode_kUninit(T_DataT, F_CompareFunc); \
        } \
\
        *node.left = Mdc_Internal_RedBlackNode_InitCopy( \
            T_DataT, \
            F_CompareFunc \
        )(src->left); \
      } \
\
      if (src->right != NULL) { \
        node.right = Mdc_malloc(sizeof(*node.right)); \
        if (node.right == NULL) { \
          Mdc_Internal_RedBlackNode_Deinit(T_DataT, F_CompareFunc)( \
              node.left \
          ); \
\
          Mdc_Object_Deinit(T_DataT)(node.data); \
          Mdc_free(node.data); \
\
          return Mdc_Internal_RedBlackNode_kUninit(T_DataT, F_CompareFunc); \
        } \
\
        *node.right = Mdc_Internal_RedBlackNode_InitCopy( \
            T_DataT, \
            F_CompareFunc \
        )(src->right); \
      } \
\
      return node; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_INIT_MOVE( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_InitMove(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) src \
    ) { \
      MDC_T(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node;\
\
      node = *src; \
      *src = Mdc_Internal_RedBlackNode_kUninit(T_DataT, F_CompareFunc); \
\
      return node; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_DEINIT(T_DataT, F_CompareFunc) \
    void Mdc_Internal_RedBlackNode_Deinit(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      if (node->left != NULL) { \
        Mdc_Internal_RedBlackNode_Deinit(T_DataT, F_CompareFunc)( \
            node->left \
        ); \
        Mdc_free(node->left); \
\
        node->left = NULL; \
      } \
\
      if (node->right != NULL) { \
        Mdc_Internal_RedBlackNode_Deinit(T_DataT, F_CompareFunc)( \
            node->right \
        ); \
        Mdc_free(node->right); \
\
        node->right = NULL; \
      } \
\
      Mdc_Object_Deinit(T_DataT)(node->data); \
      Mdc_free(node->data); \
    }

/**
 * General Functions
 */

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_BACK_NODE( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_BackNode(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      return (MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))) \
          Mdc_Internal_RedBlackNode_BackNodeConst(T_DataT, F_CompareFunc)( \
              node \
          ); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_BACK_NODE_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_BackNodeConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      current_node; \
\
      if (node == NULL) { \
        return NULL; \
      } \
\
      current_node = node; \
\
      while (current_node->right != NULL) { \
        current_node = current_node->right; \
      } \
\
      return current_node; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_DATA( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(T_DataT) \
    Mdc_Internal_RedBlackNode_Data(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      return (MDC_T_P(T_DataT)) \
          Mdc_Internal_RedBlackNode_DataConst(T_DataT, F_CompareFunc)( \
              node \
          ); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_DATA_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(T_DataT) \
    Mdc_Internal_RedBlackNode_DataConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      return node->data; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_FRONT_NODE( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_FrontNode(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      return (MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))) \
          Mdc_Internal_RedBlackNode_FrontNodeConst(T_DataT, F_CompareFunc)( \
              node \
          ); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_FRONT_NODE_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_FrontNodeConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      current_node; \
\
      if (node == NULL) { \
        return NULL; \
      } \
\
      current_node = node; \
\
      while (current_node->left != NULL) { \
        current_node = current_node->left; \
      } \
\
      return current_node; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_GRANDPARENT( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Grandparent(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      return (MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))) \
          Mdc_Internal_RedBlackNode_GrandparentConst( \
              T_DataT, \
              F_CompareFunc \
          )(node);\
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_GRANDPARENT_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_GrandparentConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      if (node->parent == NULL) { \
        return NULL; \
      } \
\
      return node->parent->parent; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_INSERT( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Insert(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) root, \
        MDC_T_P(T_DataT) data \
    ) { \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_NEXT_NODE( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_NextNode(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      return (MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))) \
          Mdc_Internal_RedBlackNode_NextNodeConst(T_DataT, F_CompareFunc)( \
              node \
          ); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_NEXT_NODE_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_NextNodeConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      current_node; \
      MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      next_node; \
\
      /* Select the right, then go as far left as possible. */ \
      current_node = node; \
      if (current_node->right != NULL) { \
        next_node = current_node->right; \
        while (next_node->left != NULL) { \
          next_node = next_node->left; \
        } \
\
        return next_node; \
      } \
\
      /* Find the first greater ancestor. */ \
      next_node = current_node->parent; \
      while (next_node != NULL && next_node->right == current_node) { \
        current_node = next_node; \
        next_node = next_node->parent; \
      } \
\
      if (next_node == NULL) { \
        return NULL; \
      } \
\
      return next_node; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_PARENT( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Parent(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      return (MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))) \
          Mdc_Internal_RedBlackNode_ParentConst(T_DataT, F_CompareFunc)( \
              node \
          ); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_PARENT_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_ParentConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      return node->parent; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_PREDECESSOR( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Predecessor(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      return (MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))) \
          Mdc_Internal_RedBlackNode_PredecessorConst( \
              T_DataT, \
              F_CompareFunc \
          )(node); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_PREDECESSOR_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_PredecessorConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      predecessor; \
\
      predecessor = node->left; \
      if (predecessor == NULL) { \
        return NULL; \
      } \
\
      while (predecessor->right != NULL) { \
        predecessor = predecessor->right; \
      } \
\
      return predecessor; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_ROTATE_LEFT( \
    T_DataT, \
    F_CompareFunc \
) \
    void Mdc_Internal_RedBlackNode_RotateLeft(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      right_child; \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      parent; \
\
      parent = node->parent; \
      right_child = node->right; \
\
      if (right_child != NULL) { \
        node->parent = right_child; \
        node->right = right_child->left; \
        if (right_child->left != NULL) { \
          right_child->left->parent = node; \
        } \
\
        right_child->parent = parent; \
        right_child->left = node; \
      } \
\
      if (parent != NULL) { \
        if (parent->left == node) { \
          parent->left = right_child; \
        } else { \
          parent->right = right_child; \
        } \
      } \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_ROTATE_RIGHT( \
    T_DataT, \
    F_CompareFunc \
) \
    void Mdc_Internal_RedBlackNode_RotateRight(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      left_child; \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      parent; \
\
      parent = node->parent; \
      left_child = node->left; \
\
      if (left_child != NULL) { \
        node->parent = left_child; \
        node->left = left_child->right; \
        if (left_child->right != NULL) { \
          left_child->right->parent = node; \
        } \
\
        left_child->parent = parent; \
        left_child->right = node; \
      } \
\
      if (parent != NULL) { \
        if (parent->left == node) { \
          parent->left = left_child; \
        } else { \
          parent->right = left_child; \
        } \
      } \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_SIBLING( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Sibling(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      return (MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))) \
          Mdc_Internal_RedBlackNode_SiblingConst(T_DataT, F_CompareFunc)( \
              node \
          ); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_SIBLING_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_SiblingConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) parent; \
\
      parent = node->parent; \
      if (parent == NULL) { \
        return NULL; \
      } \
\
      if (parent->left == node) { \
        return parent->right; \
      } else /* if (parent->right == node) */ { \
        return parent->left; \
      } \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_SUCCESSOR( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Successor(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      return (MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))) \
          Mdc_Internal_RedBlackNode_SuccessorConst(T_DataT, F_CompareFunc)( \
              node \
          ); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_SUCCESSOR_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_SuccessorConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      successor; \
\
      successor = node->right; \
      if (successor == NULL) { \
        return NULL; \
      } \
\
      while (successor->left != NULL) { \
        successor = successor->left; \
      } \
\
      return successor; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_UNCLE( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Uncle(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      return (MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))) \
          Mdc_Internal_RedBlackNode_UncleConst(T_DataT, F_CompareFunc)( \
              node \
          ); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_UNCLE_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_UncleConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) parent; \
\
      parent = node->parent; \
      if (parent == NULL) { \
        return NULL; \
      } \
\
      return Mdc_Internal_RedBlackNode_SiblingConst( \
          T_DataT, \
          F_CompareFunc \
      )(parent); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_FUNCTIONS( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_INIT_FROM_DATA( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_INIT_FROM_DATA_COPY( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_INIT_COPY(T_DataT, F_CompareFunc) \
    /*MDC_INTERNAL_DEFINE_RED_BLACK_NODE_INIT_MOVE(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_DEINIT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_BACK_NODE(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_BACK_NODE_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_DATA(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_DATA_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_FRONT_NODE( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_FRONT_NODE_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_GRANDPARENT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_GRANDPARENT_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_INSERT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_INSERT_COPY(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_LOOKUP(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_LOOKUP_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_NEXT_NODE(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_NEXT_NODE_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_PARENT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_PARENT_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_PREDECESSOR(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_PREDECESSOR_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_ROTATE_LEFT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_ROTATE_RIGHT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_SIBLING(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_SIBLING_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_SUCCESSOR(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_SUCCESSOR_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_UNCLE(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_UNCLE_CONST( \
        T_DataT, \
        F_CompareFunc \
    )*/

#endif /* MDC_C_CONTAINER_INTERNAL_RED_BLACK_NODE_RED_BLACK_NODE_DEFINE_MACRO_H_ */
