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

#ifndef MDC_C_CONTAINER_INTERNAL_VECTOR_VECTOR_DECLARE_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_VECTOR_VECTOR_DECLARE_MACRO_H_

#include <stddef.h>

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../../../std/stdbool.h"
#include "vector_name_macro.h"

/**
 * Struct
 */

#define MDC_INTERNAL_DECLARE_VECTOR_STRUCT(T_ValueT) \
    struct Mdc_Vector(T_ValueT) { \
      size_t count_; \
      size_t capacity_; \
      MDC_T_P(T_ValueT) data_; \
    }; \
    MDC_T_DECLARE_DATA_TYPE_TYPEDEFS(struct, Mdc_Vector(T_ValueT))

/**
 * Functions
 */

/**
 * Initialize / Deinitialize
 */

#define MDC_INTERNAL_DECLARE_VECTOR_INIT_EMPTY(T_ValueT) \
    MDC_DECLARE_OBJECT_INIT_DEFAULT(Mdc_Vector(T_ValueT))

#define MDC_INTERNAL_DECLARE_VECTOR_INIT_COPY(T_ValueT) \
    MDC_DECLARE_OBJECT_INIT_COPY(Mdc_Vector(T_ValueT))

#define MDC_INTERNAL_DECLARE_VECTOR_INIT_MOVE(T_ValueT) \
    MDC_DECLARE_OBJECT_INIT_MOVE(Mdc_Vector(T_ValueT))

#define MDC_INTERNAL_DECLARE_VECTOR_DEINIT(T_ValueT) \
    MDC_DECLARE_OBJECT_DEINIT(Mdc_Vector(T_ValueT))

/**
 * Assignment
 */

#define MDC_INTERNAL_DECLARE_VECTOR_ASSIGN_COPY(T_ValueT) \
    MDC_DECLARE_OBJECT_ASSIGN_COPY(Mdc_Vector(T_ValueT))

#define MDC_INTERNAL_DECLARE_VECTOR_ASSIGN_MOVE(T_ValueT) \
    MDC_DECLARE_OBJECT_ASSIGN_MOVE(Mdc_Vector(T_ValueT))

/**
 * Comparison
 */

#define MDC_INTERNAL_DECLARE_VECTOR_EQUAL(T_ValueT) \
    MDC_DECLARE_OBJECT_DEFAULT_EQUAL( \
        Mdc_Vector(T_ValueT), \
        Mdc_Vector(T_ValueT) \
    )

#define MDC_INTERNAL_DECLARE_VECTOR_COMPARE(T_ValueT) \
    MDC_DECLARE_OBJECT_DEFAULT_COMPARE( \
        Mdc_Vector(T_ValueT), \
        Mdc_Vector(T_ValueT) \
    )

/**
 * Member access
 */

#define MDC_INTERNAL_DECLARE_VECTOR_ACCESS(T_ValueT) \
    MDC_DECLARE_OBJECT_SUBSCRIPT( \
        MDC_T_P(T_ValueT), \
        Mdc_Vector(T_ValueT), \
        MDC_T(Mdc_Size) \
    )

#define MDC_INTERNAL_DECLARE_VECTOR_ACCESS_CONST(T_ValueT) \
    MDC_DECLARE_OBJECT_SUBSCRIPT_CONST( \
        MDC_T_PC(T_ValueT), \
        Mdc_Vector(T_ValueT), \
        MDC_T(Mdc_Size) \
    )

/**
 * General Functions
 */

#define MDC_INTERNAL_DECLARE_VECTOR_AT(T_ValueT) \
    MDC_T_P(T_ValueT) Mdc_Vector_At(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_AT_CONST(T_ValueT) \
    MDC_T_PC(T_ValueT) Mdc_Vector_AtConst(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector, \
        size_t pos \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_BACK(T_ValueT) \
    MDC_T_P(T_ValueT) Mdc_Vector_Back(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_BACK_CONST(T_ValueT) \
    MDC_T_PC(T_ValueT) Mdc_Vector_BackConst(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_CAPACITY(T_ValueT) \
    size_t Mdc_Vector_Capacity(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_CLEAR(T_ValueT) \
    void Mdc_Vector_Clear(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_DATA(T_ValueT) \
    MDC_T_P(T_ValueT) Mdc_Vector_Data(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_DATA_CONST(T_ValueT) \
    MDC_T_PC(T_ValueT) Mdc_Vector_DataConst(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_EMPTY(T_ValueT) \
    bool Mdc_Vector_Empty(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_FRONT(T_ValueT) \
    MDC_T_P(T_ValueT) Mdc_Vector_Front(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_FRONT_CONST(T_ValueT) \
    MDC_T_PC(T_ValueT) Mdc_Vector_FrontConst(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_POP_BACK(T_ValueT) \
    void Mdc_Vector_PopBack(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_PUSH_BACK(T_ValueT) \
    void Mdc_Vector_PushBack(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector, \
        MDC_T_P(T_ValueT) value \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_PUSH_BACK_COPY(T_ValueT) \
    void Mdc_Vector_PushBackCopy(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector, \
        MDC_T_PC(T_ValueT) value \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_RESIZE(T_ValueT) \
    void Mdc_Vector_Resize(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector, \
        size_t count, \
        MDC_T_PC(T_ValueT) value \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_RESERVE(T_ValueT) \
    void Mdc_Vector_Reserve(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector, \
        size_t new_cap \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_SHRINK_TO_FIT(T_ValueT) \
    void Mdc_Vector_ShrinkToFit(T_ValueT)( \
        MDC_T_P(Mdc_Vector(T_ValueT)) vector \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_SIZE(T_ValueT) \
    size_t Mdc_Vector_Size(T_ValueT)( \
        MDC_T_PC(Mdc_Vector(T_ValueT)) vector \
    );

#define MDC_INTERNAL_DECLARE_VECTOR_SWAP(T_ValueT) \
    MDC_DECLARE_OBJECT_SWAP(Mdc_Vector(T_ValueT))

#define MDC_INTERNAL_DECLARE_VECTOR_FUNCTIONS(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_INIT_EMPTY(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_INIT_COPY(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_INIT_MOVE(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_DEINIT(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_ASSIGN_COPY(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_ASSIGN_MOVE(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_EQUAL(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_COMPARE(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_ACCESS(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_ACCESS_CONST(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_AT(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_AT_CONST(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_BACK(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_BACK_CONST(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_CAPACITY(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_CLEAR(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_DATA(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_DATA_CONST(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_EMPTY(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_FRONT(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_FRONT_CONST(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_POP_BACK(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_PUSH_BACK(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_PUSH_BACK_COPY(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_RESIZE(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_RESERVE(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_SHRINK_TO_FIT(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_SIZE(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_SWAP(T_ValueT)

#endif /* MDC_C_CONTAINER_INTERNAL_VECTOR_VECTOR_DECLARE_MACRO_H_ */
