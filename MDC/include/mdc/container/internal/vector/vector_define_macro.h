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

#ifndef MDC_C_CONTAINER_INTERNAL_VECTOR_VECTOR_DEFINE_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_VECTOR_VECTOR_DEFINE_MACRO_H_

#include "../../../macro/template_macro.h"
#include "../../../malloc/malloc.h"
#include "../../../std/assert.h"
#include "../../../std/stdbool.h"
#include "vector_name_macro.h"

#define MDC_INTERNAL_VECTOR_UNINIT { 0 }

#define Mdc_Vector_kUninit(T_ValueT) \
    MDC_MACRO_CONCAT(Mdc_Vector(T_ValueT), kUninit)

#define MDC_INTERNAL_DEFINE_VECTOR_UNINIT_CONST(T_ValueT) \
    static MDC_T(Mdc_Vector(T_ValueT)) Mdc_Vector_kUninit(T_ValueT) = \
        MDC_INTERNAL_VECTOR_UNINIT;

/**
 * Constants
 */

#define Mdc_Vector_kInitialCapacity(T_ValueT) \
    Mdc_Object_Member(Mdc_Vector(T_ValueT), kInitialCapacity)

#define MDC_INTERNAL_DEFINE_VECTOR_K_INITIAL_CAPACITY(T_ValueT) \
    enum { \
      Mdc_Vector_kInitialCapacity(T_ValueT) = 4, \
    };

#define MDC_INTERNAL_DEFINE_VECTOR_CONSTANTS(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_K_INITIAL_CAPACITY(T_ValueT)

/**
 * Functions
 */

/**
 * Initialize / Deinitialize
 */

#define MDC_INTERNAL_DEFINE_VECTOR_INIT_EMPTY(T_ValueT) \
    MDC_T(Mdc_Vector(T_ValueT)) Mdc_Vector_InitEmpty(T_ValueT)(void) { \
      MDC_T(Mdc_Vector(T_ValueT)) vector; \
\
      vector.count_ = 0; \
      vector.capacity_ = Mdc_Vector_kInitialCapacity(T_ValueT); \
      vector.data_ = Mdc_malloc( \
          vector.capacity_ * sizeof(vector.data_[0]) \
      ); \
\
      if (vector.data_ == NULL) { \
        return Mdc_Vector_kUninit(T_ValueT); \
      } \
\
      return vector; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_INIT_COPY(T_ValueT) \
    MDC_T(Mdc_Vector(T_ValueT)) Mdc_Vector_InitCopy(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) src \
    ) { \
      size_t i; \
\
      MDC_T(Mdc_Vector(T_ValueT)) vector; \
\
      vector.count_ = src->count_; \
      vector.capacity_ = src->capacity_; \
      vector.data_ = malloc( \
          vector.capacity_ * sizeof(vector.data_[0]) \
      ); \
\
      if (vector.data_ == NULL) { \
        return Mdc_Vector_kUninit(T_ValueT); \
      } \
\
      for (i = 0; i < vector.count_; i += 1) { \
        vector.data_[i] = Mdc_Object_InitCopy(T_ValueT)( \
            &src->data_[i] \
        ); \
      } \
\
      return vector; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_INIT_MOVE(T_ValueT) \
    MDC_T(Mdc_Vector(T_ValueT)) Mdc_Vector_InitMove(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) src \
    ) { \
      MDC_T(Mdc_Vector(T_ValueT)) vector; \
\
      vector = *src; \
      *src = Mdc_Vector_kUninit(T_ValueT); \
\
      return vector; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_DEINIT(T_ValueT) \
    void Mdc_Vector_Deinit(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector \
    ) { \
      size_t i; \
\
      if (vector->data_ != NULL) { \
        Mdc_Vector_Clear(T_ValueT)(vector); \
        Mdc_free(vector->data_); \
        vector->data_ = NULL; \
      } \
\
      *vector = Mdc_Vector_kUninit(T_ValueT); \
    }

/**
 * Assignment
 */

#define MDC_INTERNAL_DEFINE_VECTOR_ASSIGN_COPY(T_ValueT) \
    MDC_T_P(Mdc_Vector(T_ValueT)) Mdc_Vector_AssignCopy(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) dest, \
        MDC_T_PC(Mdc_Vector(T_ValueT)) src \
    ) { \
      size_t i; \
\
      if (dest == src) { \
        return dest; \
      } \
\
      /* Deinit all previous elements. */ \
      Mdc_Vector_Clear(T_ValueT)(vector); \
\
      if (dest->capacity_ < src->count_) { \
        Mdc_Vector_Reserve(T_ValueT)(dest, src->capacity_); \
      } \
\
      *dest = Mdc_Vector_InitCopy(T_ValueT)(src); \
\
      return dest; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_ASSIGN_MOVE(T_ValueT) \
    MDC_T_P(Mdc_Vector(T_ValueT)) Mdc_Vector_AssignMove(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) dest, \
        MDC_T_P(Mdc_Vector(T_ValueT)) src \
    ) { \
      size_t i; \
\
      if (dest == src) { \
        return dest; \
      } \
\
      /* Deinit all previous elements. */ \
      Mdc_Vector_Clear(T_ValueT)(vector); \
      Mdc_free(dest->data_); \
\
      vector = *src; \
      *src = Mdc_Vector_kUninit(T_ValueT); \
\
      return vector; \
    }

/**
 * Comparison
 */

#define MDC_INTERNAL_DEFINE_VECTOR_EQUAL(T_ValueT) \
    bool Mdc_Vector_Equal(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector1, \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector2 \
    ) { \
      size_t i; \
\
      bool is_element_equal; \
\
      if (vector1 == vector2) { \
        return true; \
      } \
\
      if (vector1->count_ != vector2->count_) { \
        return false; \
      } \
\
      for (i = 0; i < vector1->count_; i += 1) { \
        is_element_equal = Mdc_Object_DefaultEqual(T_ValueT, T_ValueT)( \
            &vector1->data_[i], \
            &vector2->data_[i] \
        ); \
\
        if (!is_element_equal) { \
          return false; \
        } \
      } \
\
      return true; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_COMPARE(T_ValueT) \
    int Mdc_Vector_Compare(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector1, \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector2 \
    ) { \
      size_t i; \
\
      size_t lesser_element_count; \
      int compare_element; \
\
      if (vector1 == vector2) { \
        return 0; \
      } \
\
      lesser_element_count = (vector1->count_ < vector2->count_) \
          ? vector1->count_ \
          : vector2->count_; \
\
      for (i = 0; i < lesser_element_count; i += 1) { \
        compare_element = Mdc_Object_DefaultCompare(T_ValueT, T_ValueT)( \
            &vector1->data_[i], \
            &vector2->data_[i] \
        ); \
\
        if (compare_element != 0) { \
          return compare_element; \
        } \
      } \
\
      if (vector1->count_ < vector2->count_) { \
        return -1; \
      } else if (vector1->count_ > vector2->count_) { \
        return 1; \
      } else /* if (vector1->count_ == vector2->count_) */ { \
        return 0; \
      } \
    }

/**
 * Member access
 */

#define MDC_INTERNAL_DEFINE_VECTOR_ACCESS(T_ValueT) \
    MDC_T_P(T_ValueT) Mdc_Vector_Access(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector, \
        size_t pos \
    ) { \
      return (MDC_T_P(T_ValueT)) \
          Mdc_Vector_AccessConst(T_ValueT)(vector, pos); \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_ACCESS_CONST(T_ValueT) \
    MDC_T_PC(T_ValueT) Mdc_Vector_AccessConst(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector, \
        size_t pos \
    ) { \
      return &vector->data_[pos]; \
    }

/**
 * General Functions
 */

#define MDC_INTERNAL_DEFINE_VECTOR_AT(T_ValueT) \
    MDC_T_P(T_ValueT) Mdc_Vector_At(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector, \
        size_t pos \
    ) { \
      return (MDC_T_P(T_ValueT)) Mdc_Vector_AtConst(T_ValueT)( \
          vector, \
          pos \
      ); \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_AT_CONST(T_ValueT) \
    MDC_T_PC(T_ValueT) Mdc_Vector_AtConst(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector, \
        size_t pos \
    ) { \
      if (pos >= vector->count_) { \
        return NULL;\
      } \
\
      return Mdc_Vector_AccessConst(T_ValueT)(vector, pos); \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_BACK(T_ValueT) \
    MDC_T_P(T_ValueT) Mdc_Vector_Back(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector \
    ) { \
      return (MDC_T_P(T_ValueT)) Mdc_Vector_BackConst(T_ValueT)(vector); \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_BACK_CONST(T_ValueT) \
    MDC_T_PC(T_ValueT) Mdc_Vector_BackConst(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector \
    ) { \
      return &vector->data_[vector->count_ - 1]; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_CAPACITY(T_ValueT) \
    size_t Mdc_Vector_Capacity(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector \
    ) { \
      return vector->capacity_; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_CLEAR(T_ValueT) \
    void Mdc_Vector_Clear(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector \
    ) { \
      for (; vector->count_ > 0; vector->count_ -= 1) { \
        Mdc_Object_Deinit(T_ValueT)( \
            &vector->data_[vector->count_ - 1] \
        ); \
      } \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_DATA(T_ValueT) \
    MDC_T_P(T_ValueT) Mdc_Vector_Data(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector \
    ) { \
      return (MDC_T_P(T_ValueT)) \
          Mdc_Vector_DataConst(T_ValueT)(vector); \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_DATA_CONST(T_ValueT) \
    MDC_T_PC(T_ValueT) Mdc_Vector_DataConst(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector \
    ) { \
      return vector->data_; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_EMPTY(T_ValueT) \
    bool Mdc_Vector_Empty(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector \
    ) { \
      return vector->count_ > 0; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_FRONT(T_ValueT) \
    MDC_T_P(T_ValueT) Mdc_Vector_Front(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector \
    ) { \
      return (MDC_T_P(T_ValueT)) \
        Mdc_Vector_FrontConst(T_ValueT)(vector); \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_FRONT_CONST(T_ValueT) \
    MDC_T_PC(T_ValueT) Mdc_Vector_FrontConst(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector \
    ) { \
      return &vector->data_[0]; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_POP_BACK(T_ValueT) \
    void Mdc_Vector_PopBack(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector \
    ) { \
      Mdc_Object_Deinit(T_ValueT)(&vector->data_[vector->count_ - 1]); \
      vector->count_ -= 1; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_PUSH_BACK(T_ValueT) \
    void Mdc_Vector_PushBack(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector, \
        MDC_T_P(T_ValueT) value \
    ) { \
      if (vector->count_ == vector->capacity_) { \
        Mdc_Vector_Reserve(T_ValueT)(vector, vector->capacity_ * 2); \
      } \
\
      vector->data_[vector->count_] = Mdc_Object_InitMove(T_ValueT)(value); \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_PUSH_BACK_COPY(T_ValueT) \
    void Mdc_Vector_PushBackCopy(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector, \
        MDC_T_PC(T_ValueT) value \
    ) { \
      if (vector->count_ == vector->capacity_) { \
        Mdc_Vector_Reserve(T_ValueT)(vector, vector->capacity_ * 2); \
      } \
\
      vector->data_[vector->count_] = Mdc_Object_InitCopy(T_ValueT)(value); \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_RESIZE(T_ValueT) \
    void Mdc_Vector_Resize(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector, \
        size_t count, \
        MDC_T_PC(T_ValueT) value \
    ) { \
      if (count == vector->count_) { \
        return; \
      } \
\
      if (count < vector->count_) { \
        for (; vector->count_ > count; vector->count_ -= 1) { \
          Mdc_Object_Deinit(T_ValueT)(&vector->data_[vector->count_ - 1]); \
        } \
\
        return; \
      } \
\
      assert(count > vector->count_); \
\
      if (count > vector->capacity_) { \
        Mdc_Vector_Reserve(T_ValueT)(vector, count * 2); \
      } \
\
      for (; vector->count_ < count; vector->count_ += 1) { \
        vector->data_[vector->count_] = \
            Mdc_Object_InitCopy(T_ValueT)(value); \
      } \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_RESERVE(T_ValueT) \
    void Mdc_Vector_Reserve(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector, \
        size_t new_cap \
    ) { \
      MDC_T_P(Mdc_Vector(T_ValueT)) realloc_result; \
\
      if (new_cap <= vector->capacity_) { \
        return; \
      } \
\
      realloc_result = Mdc_realloc( \
          vector->data_, \
          new_cap * sizeof(vector->data_[0]) \
      );\
\
      if (realloc_result == NULL) { \
        return; \
      } \
\
      vector->data_ = realloc_result; \
      vector->capacity = new_cap; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_SHRINK_TO_FIT(T_ValueT) \
    void Mdc_Vector_ShrinkToFit(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector \
    ) { \
      MDC_T_P(Mdc_Vector(T_ValueT)) realloc_result; \
\
      if (vector->count_ == vector->capacity_) { \
        return; \
      } \
\
      realloc_result = Mdc_realloc( \
          vector->data_, \
          vector->count_ * sizeof(vector->data_[0]) \
      );\
\
      if (realloc_result == NULL) { \
        return; \
      } \
\
      vector->data_ = realloc_result; \
      vector->capacity_ = vector->count_; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_SIZE(T_ValueT) \
    size_t Mdc_Vector_Size(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector \
    ) { \
      return vector->count_; \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_SWAP(T_ValueT) \
    void Mdc_Vector_Swap(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector1, \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector2 \
    ) { \
      MDC_T(Mdc_Vector(T_ValueT)) temp_vector; \
\
      temp_vector = Mdc_Vector_InitMove(T_ValueT)(vector1); \
\
      Mdc_Vector_AssignMove(T_ValueT)(vector1, vector2); \
      Mdc_Vector_AssignMove(T_ValueT)(vector2, &temp_vector); \
\
      Mdc_Vector_Deinit(T_ValueT)(&temp_vector); \
    }

#define MDC_INTERNAL_DEFINE_VECTOR_FUNCTIONS(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_UNINIT_CONST(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_INIT_EMPTY(T_ValueT) \
    //MDC_INTERNAL_DEFINE_VECTOR_INIT_COPY(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_INIT_MOVE(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_DEINIT(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_ASSIGN_COPY(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_ASSIGN_MOVE(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_EQUAL(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_COMPARE(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_ACCESS(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_ACCESS_CONST(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_AT(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_AT_CONST(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_BACK(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_BACK_CONST(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_CAPACITY(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_CLEAR(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_DATA(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_DATA_CONST(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_EMPTY(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_FRONT(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_FRONT_CONST(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_POP_BACK(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_PUSH_BACK(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_PUSH_BACK_COPY(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_RESIZE(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_SHRINK_TO_FIT(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_SIZE(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_SWAP(T_ValueT)

#endif /* MDC_C_CONTAINER_INTERNAL_VECTOR_VECTOR_DEFINE_MACRO_H_ */
