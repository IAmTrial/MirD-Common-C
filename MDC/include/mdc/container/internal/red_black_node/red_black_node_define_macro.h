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
#include "../../../std/stdbool.h"
#include "red_black_node_name_macro.h"

#define MDC_INTERNAL_RED_BLACK_NODE_UNINIT { 0 }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_K_UNINIT( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_C(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_kUninit(T_DataT, F_CompareFunc) = \
        MDC_INTERNAL_RED_BLACK_NODE_UNINIT

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
      node.data_ = Mdc_malloc(sizeof(*node.data_)); \
      if (node.data_ == NULL) { \
        return Mdc_Internal_RedBlackNode_kUninit(T_DataT, F_CompareFunc); \
      } \
      *node.data_ = Mdc_Object_InitMove(T_DataT)(data); \
      node.color_ = Mdc_Internal_RedBlackColor_kRed; \
      node.parent_ = NULL; \
      node.left_ = NULL; \
      node.right_ = NULL; \
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
      node.data_ = Mdc_malloc(sizeof(*node.data_)); \
      if (node.data_ == NULL) { \
        return Mdc_Internal_RedBlackNode_kUninit(T_DataT, F_CompareFunc); \
      } \
      *node.data_ = Mdc_Object_InitCopy(T_DataT)(data); \
      node.color_ = Mdc_Internal_RedBlackColor_kRed; \
      node.parent_ = NULL; \
      node.left_ = NULL; \
      node.right_ = NULL; \
\
      return node; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_DEINIT(T_DataT, F_CompareFunc) \
    void Mdc_Internal_RedBlackNode_Deinit(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      if (node->left_ != NULL) { \
        Mdc_Internal_RedBlackNode_Deinit(T_DataT, F_CompareFunc)( \
            node->left_ \
        ); \
        Mdc_free(node->left_); \
\
        node->left_ = NULL; \
      } \
\
      if (node->right_ != NULL) { \
        Mdc_Internal_RedBlackNode_Deinit(T_DataT, F_CompareFunc)( \
            node->right_ \
        ); \
        Mdc_free(node->right_); \
\
        node->right_ = NULL; \
      } \
\
      Mdc_Object_Deinit(T_DataT)(&node->data_); \
      Mdc_free(&node->data_); \
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
      while (current_node->right_ != NULL) { \
        current_node = current_node->right_; \
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
      return node->data_; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_ERASE( \
    T_DataT, \
    F_CompareFunc \
) \
    void Mdc_Internal_RedBlackNode_Erase(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node, \
        MDC_T_PC(T_DataT) data \
    ) { \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      lookup_result; \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      replacement; \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      replacement_child; \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      next_node; \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      parent; \
      MDC_T_P(T_DataT) temp_data; \
\
      /* Locate the node to erase. */ \
      lookup_result = Mdc_Internal_RedBlackNode_LookupNode( \
          T_DataT, \
          F_CompareFunc \
      )(node, data); \
\
      if (lookup_result == NULL) { \
        return; \
      } \
\
      /* Locate the replacement node. */ \
      if (lookup_result->right_ != NULL) { \
        replacement = Mdc_Internal_RedBlackNode_Successor( \
            T_DataT, \
            F_CompareFunc \
        )(lookup_result); \
\
        replacement_child = replacement->right_; \
      } else if (lookup_result->left_ != NULL) { \
        replacement = Mdc_Internal_RedBlackNode_Predecessor( \
            T_DataT, \
            F_CompareFunc \
        )(lookup_result); \
\
        replacement_child = replacement->left_; \
      } else { \
        /* If there is no replacement, just delete. */ \
        Mdc_Internal_RedBlackNode_Deinit(T_DataT, F_CompareFunc)( \
            lookup_result \
        ); \
\
        return; \
      } \
\
      assert(replacement != NULL); \
\
      temp_data = lookup_node->data_; \
      lookup_node->data_ = replacement->data_; \
      replacement->data_ = temp_data; \
\
      Mdc_Internal_RedBlackNode_Deinit(T_DataT, F_CompareFunc)( \
          replacement \
      ); \
      Mdc_free(replacement); \
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
      while (current_node->left_ != NULL) { \
        current_node = current_node->left_; \
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
      if (node->parent_ == NULL) { \
        return NULL; \
      } \
\
      return node->parent_->parent_; \
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
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      current_node; \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      parent_node; \
      int compare_result; \
\
      if (root == NULL) { \
        node->color_ = Mdc_Internal_RedBlackColor_kBlack; \
        return node; \
      } \
\
      /* Look for the target node position with equal data. */ \
      parent_node = NULL; \
      current_node = root; \
\
      while (current_node != NULL) { \
        parent_node = current_node; \
\
        compare_result = F_CompareFunc( \
            node->data_, \
            current_node->data_ \
        ); \
\
        if (compare_result < 0) { \
          current_node = current_node->right_; \
        } else if (compare_result > 0) { \
          current_node = current_node->left_; \
        } else /* if (compare_result == 0) */ { \
          return root; \
        } \
      } \
\
      /* Insert the new node into the correct location. */ \
      if (compare_result < 0) { \
        parent_node->left_ = node; \
      } else /* if (compare_result > 0) */ { \
        parent_node->right_ = node; \
      } \
\
      node->parent_ = parent_node; \
      node->color_ = Mdc_Internal_RedBlackColor_kRed; \
\
      /* TODO: Implement rebalancing. */ \
\
      return root; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_LOOKUP( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Lookup(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node, \
        MDC_T_PC(T_DataT) data \
    ) { \
      return (MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))) \
          Mdc_Internal_RedBlackNode_LookupNodeConst( \
              T_DataT, \
              F_CompareFunc \
          )(node, data); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_LOOKUP_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_LookupConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node, \
        MDC_T_PC(T_DataT) data \
    ) { \
      MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      current_node; \
      int compare_result; \
\
      current_node = node; \
\
      while (current_node != NULL) { \
        compare_result = F_CompareFunc( \
            data, \
            current_node->data_ \
        ); \
\
        if (compare_result < 0) { \
          current_node = current_node->right_; \
        } else if (compare_result > 0) { \
          current_node = current_node->left_; \
        } else { \
          return current_node; \
        } \
      } \
\
      return NULL; \
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
      if (current_node->right_ != NULL) { \
        next_node = current_node->right_; \
        while (next_node->left_ != NULL) { \
          next_node = next_node->left_; \
        } \
\
        return next_node; \
      } \
\
      /* Find the first greater ancestor. */ \
      next_node = current_node->parent_; \
      while (next_node != NULL && next_node->right_ == current_node) { \
        current_node = next_node; \
        next_node = next_node->parent_; \
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
      return node->parent_; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_NODE_PREDECESSOR( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackNode_Predecessor(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) node \
    ) { \
      return MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
          Mdc_Internal_RedBlackNode_PredecessorConst(T_DataT, F_CompareFunc)( \
              node \
          ); \
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
      predecessor = node->left_; \
      if (predecessor == NULL) { \
        return NULL; \
      } \
\
      while (predecessor->right_ != NULL) { \
        predecessor = predecessor->right_; \
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
      parent = node->parent_; \
      right_child = node->right_; \
\
      if (right_child != NULL) { \
        node->parent_ = right_child; \
        node->right_ = right_child->left_; \
        if (right_child->left_ != NULL) { \
          right_child->left_->parent_ = node; \
        } \
\
        right_child->parent_ = parent; \
        right_child->left_ = node; \
      } \
\
      if (parent != NULL) { \
        if (parent->left_ == node) { \
          parent->left_ = right_child; \
        } else { \
          parent->right_ = right_child; \
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
      parent = node->parent_; \
      left_child = node->left_; \
\
      if (left_child != NULL) { \
        node->parent_ = left_child; \
        node->left_ = left_child->right_; \
        if (left_child->right_ != NULL) { \
          left_child->right_->parent_ = node; \
        } \
\
        left_child->parent_ = parent; \
        left_child->right_ = node; \
      } \
\
      if (parent != NULL) { \
        if (parent->left_ == node) { \
          parent->left_ = left_child; \
        } else { \
          parent->right_ = left_child; \
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
      parent = node->parent_; \
      if (parent == NULL) { \
        return NULL; \
      } \
\
      if (parent->left_ == node) { \
        return parent->right_; \
      } else /* if (parent->right == node) */ { \
        return parent->left_; \
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
      return MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
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
      successor = node->right_; \
      if (successor == NULL) { \
        return NULL; \
      } \
\
      while (successor->left_ != NULL) { \
        successor = successor->left_; \
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
      parent = node->parent_; \
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
    /*MDC_INTERNAL_DEFINE_RED_BLACK_NODE_INIT_FROM_DATA( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_INIT_FROM_DATA_COPY( \
        T_DataT, \
        F_CompareFunc \
    ) \
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
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE_ERASE(T_DataT, F_CompareFunc) \
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
