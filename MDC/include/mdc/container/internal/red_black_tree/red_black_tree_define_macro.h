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

#ifndef MDC_C_CONTAINER_INTERNAL_RED_BLACK_TREE_RED_BLACK_TREE_DEFINE_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_RED_BLACK_TREE_RED_BLACK_TREE_DEFINE_MACRO_H_

#include <stddef.h>

#include "../../../macro/template_macro.h"
#include "../../../malloc/malloc.h"
#include "../../../std/assert.h"
#include "../../../std/stdbool.h"
#include "../red_black_node.h"
#include "red_black_tree_name_macro.h"

/**
 * Prerequisites
 */

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_PREREQUISITES( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_INTERNAL_DEFINE_RED_BLACK_NODE( \
        T_DataT, \
        F_CompareFunc \
    )

/**
 * Static
 */

#define MDC_INTERNAL_RED_BLACK_TREE_UNINIT { 0 }

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_K_UNINIT( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_C(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_kUninit(T_DataT, F_CompareFunc) = \
        MDC_INTERNAL_RED_BLACK_TREE_UNINIT;

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_CONSTANTS( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_INTERNAL_DEFINE_RED_BLACK_TREE_K_UNINIT(T_DataT, F_CompareFunc)

/**
 * Functions
 */

/**
 * Initialize / Deinitialize
 */

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_INIT_EMPTY( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_InitEmpty(T_DataT, F_CompareFunc)(void) { \
      MDC_T(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree; \
\
      tree.root_ = NULL; \
\
      return tree; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_INIT_COPY( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_InitCopy(T_DataT, F_CompareFunc)( \
        MDC_T(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) src \
    ) { \
      MDC_T(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) dest; \
\
      tree.root_ = NULL; \
      if (src->root_) { \
        tree.root_ = malloc(sizeof(*tree.root_)); \
        if (tree.root_ == NULL) { \
          return Mdc_Internal_RedBlackTree_kUninit(T_DataT, F_CompareFunc); \
        } \
\
        *tree.root_ = Mdc_Internal_RedBlackNode_InitCopy( \
            T_DataT, \
            F_CompareFunc \
        )(src->root_); \
      } \
\
      return dest; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_DEINIT( \
    T_DataT, \
    F_CompareFunc \
) \
    void Mdc_Internal_RedBlackTree_Deinit(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree \
    ) { \
      Mdc_Internal_RedBlackNode_Deinit(T_DataT, F_CompareFunc)( \
          tree->root_ \
      ); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_BACK( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_Back(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree \
    ) { \
      return (MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))) \
          Mdc_Internal_RedBlackTree_BackConst(T_DataT, F_CompareFunc)( \
              tree \
          ); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_BACK_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_BackConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree \
    ) { \
      return Mdc_Internal_RedBlackNode_BackNodeConst( \
          T_DataT, \
          F_CompareFunc \
      )(tree->root_); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_ERASE( \
    T_DataT, \
    F_CompareFunc \
) \
    void Mdc_Internal_RedBlackTree_Erase(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree, \
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
      lookup_result = Mdc_Internal_RedBlackNode_Lookup( \
          T_DataT, \
          F_CompareFunc \
      )(node, data); \
\
      if (lookup_result == NULL) { \
        return; \
      } \
\
      /* Locate the replacement node. */ \
      if (lookup_result->right != NULL) { \
        replacement = Mdc_Internal_RedBlackNode_Successor( \
            T_DataT, \
            F_CompareFunc \
        )(lookup_result); \
\
        replacement_child = replacement->right; \
      } else if (lookup_result->left != NULL) { \
        replacement = Mdc_Internal_RedBlackNode_Predecessor( \
            T_DataT, \
            F_CompareFunc \
        )(lookup_result); \
\
        replacement_child = replacement->left; \
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
      temp_data = lookup_result->data; \
      lookup_result->data = replacement->data; \
      replacement->data = temp_data; \
\
      Mdc_Internal_RedBlackNode_Deinit(T_DataT, F_CompareFunc)( \
          replacement \
      ); \
      Mdc_free(replacement); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_FRONT( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_Front(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree \
    ) { \
      return (MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))) \
          Mdc_Internal_RedBlackTree_FrontConst(T_DataT, F_CompareFunc)( \
              tree \
          ); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_FRONT_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_FrontConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree \
    ) { \
      return Mdc_Internal_RedBlackNode_FrontNodeConst( \
          T_DataT, \
          F_CompareFunc \
      )(tree->root_); \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_INSERT(T_DataT, F_CompareFunc) \
    void Mdc_Internal_RedBlackTree_Insert(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree, \
        MDC_T_P(T_DataT) data \
    ) { \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      current_node; \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      parent_node; \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      node; \
      int compare_result; \
\
      if (tree->root_ == NULL) { \
        tree->root_ = Mdc_malloc(sizeof(*tree->root_)); \
        if (tree->root_ == NULL) { \
          return NULL; \
        } \
\
        *tree->root_ = Mdc_Internal_RedBlackNode_InitFromData( \
            T_DataT, \
            F_CompareFunc \
        )(data); \
        tree->root_->color = Mdc_Internal_RedBlackColor_kBlack; \
\
        return; \
      } \
\
      /* Look for the target node position with equal data. */ \
      parent_node = NULL; \
      current_node = tree->root_; \
\
      do { \
        parent_node = current_node; \
\
        compare_result = F_CompareFunc( \
            data, \
            Mdc_Internal_RedBlackNode_Data(T_DataT, F_CompareFunc)( \
                current_node \
            ); \
        ); \
\
        if (compare_result < 0) { \
          current_node = current_node->left; \
        } else if (compare_result > 0) { \
          current_node = current_node->right; \
        } else /* if (compare_result == 0) */ { \
          /* Data already exists, do not insert. */ \
          return root; \
        } \
      } while (current_node != NULL); \
\
      /* Insert the new node into the correct location. */ \
      node = Mdc_malloc(sizeof(*node)); \
      if (node == NULL) { \
        return NULL; \
      } \
\
      *node = Mdc_Internal_RedBlackNode_InitFromData( \
          T_DataT, \
          F_CompareFunc \
      )(data); \
      node->color = Mdc_Internal_RedBlackColor_kRed; \
      node->parent = parent_node; \
\
      if (compare_result < 0) { \
        parent_node->left = node; \
      } else /* if (compare_result > 0) */ { \
        parent_node->right = node; \
      } \
\
      /* TODO: Implement rebalancing. */ \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_INSERT_COPY( \
    T_DataT, \
    F_CompareFunc \
) \
    void Mdc_Internal_RedBlackTree_InsertCopy(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree, \
        MDC_T_PC(T_DataT) data \
    ) { \
      MDC_T(T_DataT) data_copy; \
      MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      return_value; \
\
      data_copy = Mdc_Object_InitCopy(T_DataT)(data); \
\
      return_value = Mdc_Internal_RedBlackTree_Insert( \
          T_DataT, \
          F_CompareFunc \
      )(root, &data_copy); \
\
      Mdc_Object_Deinit(T_DataT)(&data_copy); \
\
      return return_value; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_LOOKUP(T_DataT, F_CompareFunc) \
    MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_Lookup(T_DataT, F_CompareFunc)( \
        MDC_T_P(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree, \
        MDC_T_PC(T_DataT) data \
    ) { \
      return (MDC_T_P(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc))) \
          Mdc_Internal_RedBlackTree_LookupConst(T_DataT, F_CompareFunc)( \
              tree, \
              data \
          ); \
    }


#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_LOOKUP_CONST( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
    Mdc_Internal_RedBlackTree_LookupConst(T_DataT, F_CompareFunc)( \
        MDC_T_PC(Mdc_Internal_RedBlackTree(T_DataT, F_CompareFunc)) tree, \
        MDC_T_PC(T_DataT) data \
    ) { \
      MDC_T_PC(Mdc_Internal_RedBlackNode(T_DataT, F_CompareFunc)) \
      current_node; \
      int compare_result; \
\
      current_node = tree->root_; \
\
      while (current_node != NULL) { \
        compare_result = F_CompareFunc( \
            data, \
            current_node->data \
        ); \
\
        if (compare_result < 0) { \
          current_node = current_node->left; \
        } else if (compare_result > 0) { \
          current_node = current_node->right; \
        } else { \
          return current_node; \
        } \
      } \
\
      return NULL; \
    }

#define MDC_INTERNAL_DEFINE_RED_BLACK_TREE_FUNCTIONS( \
    T_DataT, \
    F_CompareFunc \
) \
    MDC_INTERNAL_DEFINE_RED_BLACK_TREE_INIT_EMPTY(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_TREE_INIT_COPY(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_TREE_DEINIT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_TREE_BACK(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_TREE_BACK_CONST(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_TREE_ERASE(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_TREE_FRONT(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_TREE_FRONT_CONST(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_TREE_INSERT( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_TREE_INSERT_COPY( \
        T_DataT, \
        F_CompareFunc \
    ) \
    MDC_INTERNAL_DEFINE_RED_BLACK_TREE_LOOKUP(T_DataT, F_CompareFunc) \
    MDC_INTERNAL_DEFINE_RED_BLACK_TREE_LOOKUP_CONST( \
        T_DataT, \
        F_CompareFunc \
    ) \

#endif /* MDC_C_CONTAINER_INTERNAL_RED_BLACK_TREE_RED_BLACK_TREE_DEFINE_MACRO_H_ */
