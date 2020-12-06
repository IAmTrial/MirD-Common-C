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

#ifndef MDC_C_CONTAINER_INTERNAL_MAP_MAP_DECLARE_MACRO_H_
#define MDC_C_CONTAINER_INTERNAL_MAP_MAP_DECLARE_MACRO_H_

#include <stddef.h>

#include "../../../macro/concat_macro.h"
#include "../../../macro/template_macro.h"
#include "../../../std/stdbool.h"
#include "../../pair.h"
#include "../red_black_node.h"
#include "map_name_macro.h"

/**
 * Prerequisites
 */

#define MDC_INTERNAL_DECLARE_PAIR_COMPARE_FIRST(T_KeyT, T_ValueT) \
    int Mdc_Pair_CompareFirst(T_KeyT, T_ValueT)( \
        MDC_T_PC(Mdc_Pair(T_KeyT, T_ValueT)) pair1, \
        MDC_T_PC(Mdc_Pair(T_KeyT, T_ValueT)) pair2 \
    );

#define MDC_INTERNAL_DECLARE_MAP_PREREQUISITES(T_KeyT, T_ValueT) \
    MDC_DECLARE_PAIR(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_PAIR_COMPARE_FIRST(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_RED_BLACK_NODE( \
        Mdc_Pair(T_KeyT, T_ValueT), \
        Mdc_Pair_CompareFirst(T_KeyT, T_ValueT) \
    )

/**
 * Struct
 */

#define MDC_INTERNAL_DECLARE_MAP_STRUCT(T_KeyT, T_ValueT) \
    struct Mdc_Map(T_KeyT, T_ValueT) { \
      struct Mdc_Internal_MapNode(T_KeyT, T_ValueT)* root_;\
      size_t count_; \
    }; \
    MDC_T_DECLARE_DATA_TYPE_TYPEDEFS(struct, Mdc_Map(T_KeyT, T_ValueT))

/**
 * Initialize / Deinitialize
 */

#define MDC_INTERNAL_DECLARE_MAP_INIT_EMPTY(T_KeyT, T_ValueT) \
    MDC_DECLARE_OBJECT_INIT_DEFAULT(Mdc_Map(T_KeyT, T_ValueT))

#define MDC_INTERNAL_DECLARE_MAP_INIT_COPY(T_KeyT, T_ValueT) \
    MDC_DECLARE_OBJECT_INIT_COPY(Mdc_Map(T_KeyT, T_ValueT))

#define MDC_INTERNAL_DECLARE_MAP_INIT_MOVE(T_KeyT, T_ValueT) \
    MDC_DECLARE_OBJECT_INIT_MOVE(Mdc_Map(T_KeyT, T_ValueT))

#define MDC_INTERNAL_DECLARE_MAP_DEINIT(T_KeyT, T_ValueT) \
    MDC_DECLARE_OBJECT_DEINIT(Mdc_Map(T_KeyT, T_ValueT))

/**
 * Assignment
 */

#define MDC_INTERNAL_DECLARE_MAP_ASSIGN_COPY(T_KeyT, T_ValueT) \
    MDC_DECLARE_OBJECT_ASSIGN_COPY(Mdc_Map(T_KeyT, T_ValueT))

#define MDC_INTERNAL_DECLARE_MAP_ASSIGN_MOVE(T_KeyT, T_ValueT) \
    MDC_DECLARE_OBJECT_ASSIGN_MOVE(Mdc_Map(T_KeyT, T_ValueT))

/**
 * Comparison
 */

#define MDC_INTERNAL_DECLARE_MAP_EQUAL(T_KeyT, T_ValueT) \
    MDC_DECLARE_OBJECT_DEFAULT_EQUAL( \
        Mdc_Map(T_KeyT, T_ValueT), \
        Mdc_Map(T_KeyT, T_ValueT) \
    )

#define MDC_INTERNAL_DECLARE_MAP_COMPARE(T_KeyT, T_ValueT) \
    MDC_DECLARE_OBJECT_DEFAULT_COMPARE( \
        Mdc_Map(T_KeyT, T_ValueT), \
        Mdc_Map(T_KeyT, T_ValueT) \
    )

/**
 * Member access
 */

#define MDC_INTERNAL_DECLARE_MAP_ACCESS(T_KeyT, T_ValueT) \
    MDC_DECLARE_OBJECT_SUBSCRIPT( \
        MDC_T_P(T_ValueT), \
        Mdc_Map(T_KeyT, T_ValueT), \
        MDC_T_PC(T_KeyT) \
    )

#define MDC_INTERNAL_DECLARE_MAP_ACCESS_CONST(T_KeyT, T_ValueT) \
    MDC_DECLARE_OBJECT_SUBSCRIPT_CONST( \
        MDC_T_PC(T_ValueT), \
        Mdc_Map(T_KeyT, T_ValueT), \
        MDC_T_PC(T_KeyT) \
    )

/**
 * General Functions
 */

#define MDC_INTERNAL_DECLARE_MAP_AT(T_KeyT, T_ValueT) \
    MDC_T_P(T_ValueT) Mdc_Map_At(T_KeyT, T_ValueT)( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key \
    );

#define MDC_INTERNAL_DECLARE_MAP_AT_CONST(T_KeyT, T_ValueT) \
    MDC_T_PC(T_ValueT) Mdc_Map_AtConst(T_KeyT, T_ValueT)( \
        MDC_T_PC(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key \
    );

#define MDC_INTERNAL_DECLARE_MAP_CLEAR(T_KeyT, T_ValueT) \
    void Mdc_Map_Clear(T_KeyT, T_ValueT)( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map \
    );

#define MDC_INTERNAL_DECLARE_MAP_CONTAINS(T_KeyT, T_ValueT) \
    bool Mdc_Map_Contains(T_KeyT, T_ValueT)( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_0(T_KeyT, T_ValueT) \
    void Mdc_Map_Emplace_0(T_KeyT, T_ValueT)( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_P(T_KeyT) key \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_1( \
    T_KeyT, T_ValueT, \
    A1 \
) \
    void Mdc_Map_Emplace_1( \
        T_KeyT, T_ValueT, \
        A1 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_P(T_KeyT) key, \
        A1 arg1 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_2( \
    T_KeyT, T_ValueT, \
    A1, A2 \
) \
    void Mdc_Map_Emplace_2( \
        T_KeyT, T_ValueT, \
        A1, A2 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_P(T_KeyT) key, \
        A1 arg1, \
        A2 arg2 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_3( \
    T_KeyT, T_ValueT, \
    A1, A2, A3 \
) \
    void Mdc_Map_Emplace_3( \
        T_KeyT, T_ValueT, \
        A1, A2, A3 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_P(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_4( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4 \
) \
    void Mdc_Map_Emplace_4( \
        T_KeyT, T_ValueT, \
        A1, A2, A3, A4 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_P(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_5( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5 \
) \
    void Mdc_Map_Emplace_5( \
        T_KeyT, T_ValueT, \
        A1, A2, A3, A4, A5 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_P(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_6( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5, A6 \
) \
    void Mdc_Map_Emplace_6( \
        T_KeyT, T_ValueT, \
        A1, A2, A3, A4, A5, A6 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_P(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_7( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5, A6, A7 \
) \
    void Mdc_Map_Emplace_7( \
        T_KeyT, T_ValueT, \
        A1, A2, A3, A4, A5, A6, A7 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_P(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6, \
        A7 arg7 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_8( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5, A6, A7, A8 \
) \
    void Mdc_Map_Emplace_8( \
        T_KeyT, T_ValueT, \
        A1, A2, A3, A4, A5, A6, A7, A8 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_P(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6, \
        A7 arg7, \
        A8 arg8 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_9( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5, A6, A7, A8, A9 \
) \
    void Mdc_Map_Emplace_9( \
        T_KeyT, T_ValueT, \
        A1, A2, A3, A4, A5, A6, A7, A8, A9 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_P(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6, \
        A7 arg7, \
        A8 arg8, \
        A9 arg9 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE(N_args) \
    MDC_MACRO_CONCAT(MDC_INTERNAL_DECLARE_MAP_EMPLACE_, N_args)

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_KEY_COPY_0(T_KeyT, T_ValueT) \
    void Mdc_Map_EmplaceKeyCopy_0(T_KeyT, T_ValueT)( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_KEY_COPY_1( \
    T_KeyT, T_ValueT, \
    A1 \
) \
    void Mdc_Map_EmplaceKeyCopy_1( \
        T_KeyT, T_ValueT, \
        A1 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key, \
        A1 arg1 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_KEY_COPY_2( \
    T_KeyT, T_ValueT, \
    A1, A2 \
) \
    void Mdc_Map_EmplaceKeyCopy_2( \
        T_KeyT, T_ValueT, \
        A1, A2 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key, \
        A1 arg1, \
        A2 arg2 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_KEY_COPY_3( \
    T_KeyT, T_ValueT, \
    A1, A2, A3 \
) \
    void Mdc_Map_EmplaceKeyCopy_3( \
        T_KeyT, T_ValueT, \
        A1, A2, A3 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_KEY_COPY_4( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4 \
) \
    void Mdc_Map_EmplaceKeyCopy_4( \
        T_KeyT, T_ValueT, \
        A1, A2, A3, A4 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_KEY_COPY_5( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5 \
) \
    void Mdc_Map_EmplaceKeyCopy_5( \
        T_KeyT, T_ValueT, \
        A1, A2, A3, A4, A5 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_KEY_COPY_6( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5, A6 \
) \
    void Mdc_Map_EmplaceKeyCopy_6( \
        T_KeyT, T_ValueT, \
        A1, A2, A3, A4, A5, A6 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_KEY_COPY_7( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5, A6, A7 \
) \
    void Mdc_Map_EmplaceKeyCopy_7( \
        T_KeyT, T_ValueT, \
        A1, A2, A3, A4, A5, A6, A7 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6, \
        A7 arg7 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_KEY_COPY_8( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5, A6, A7, A8 \
) \
    void Mdc_Map_EmplaceKeyCopy_8( \
        T_KeyT, T_ValueT, \
        A1, A2, A3, A4, A5, A6, A7, A8 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6, \
        A7 arg7, \
        A8 arg8 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_KEY_COPY_9( \
    T_KeyT, T_ValueT, \
    A1, A2, A3, A4, A5, A6, A7, A8, A9 \
) \
    void Mdc_Map_EmplaceKeyCopy_9( \
        T_KeyT, T_ValueT, \
        A1, A2, A3, A4, A5, A6, A7, A8, A9 \
    )( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key, \
        A1 arg1, \
        A2 arg2, \
        A3 arg3, \
        A4 arg4, \
        A5 arg5, \
        A6 arg6, \
        A7 arg7, \
        A8 arg8, \
        A9 arg9 \
    );

#define MDC_INTERNAL_DECLARE_MAP_EMPLACE_KEY_COPY(N_args) \
    MDC_MACRO_CONCAT(MDC_INTERNAL_DECLARE_MAP_EMPLACE_KEY_COPY_, N_args)

#define MDC_INTERNAL_DECLARE_MAP_EMPTY(T_KeyT, T_ValueT) \
    bool Mdc_Map_Empty(T_KeyT, T_ValueT)( \
        MDC_T_PC(Mdc_Map(T_KeyT, T_ValueT)) map \
    );

#define MDC_INTERNAL_DECLARE_MAP_ERASE(T_KeyT, T_ValueT) \
    size_t Mdc_Map_Erase(T_KeyT, T_ValueT)( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key \
    );

#define MDC_INTERNAL_DECLARE_MAP_INSERT_PAIR(T_KeyT, T_ValueT) \
    void Mdc_Map_InsertPair(T_KeyT, T_ValueT)( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_P(Mdc_Pair(T_KeyT, T_ValueT)) pair \
    );

#define MDC_INTERNAL_DECLARE_MAP_INSERT_PAIR_COPY(T_KeyT, T_ValueT) \
    void Mdc_Map_InsertPairCopy(T_KeyT, T_ValueT)( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(Mdc_Pair(T_KeyT, T_ValueT)) pair \
    );

#define MDC_INTERNAL_DECLARE_MAP_INSERT_OR_ASSIGN(T_KeyT, T_ValueT) \
    void Mdc_Map_InsertOrAssign(T_KeyT, T_ValueT)( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_P(T_KeyT) key, \
        MDC_T_P(T_ValueT) value \
    );

#define MDC_INTERNAL_DECLARE_MAP_INSERT_OR_ASSIGN_KEY_COPY( \
    T_KeyT, T_ValueT \
) \
    void Mdc_Map_InsertOrAssignKeyCopy(T_KeyT, T_ValueT)( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key, \
        MDC_T_P(T_ValueT) value \
    );

#define MDC_INTERNAL_DECLARE_MAP_INSERT_OR_ASSIGN_VALUE_COPY( \
    T_KeyT, T_ValueT \
) \
    void Mdc_Map_InsertOrAssignValueCopy(T_KeyT, T_ValueT)( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_P(T_KeyT) key, \
        MDC_T_PC(T_ValueT) value \
    );

#define MDC_INTERNAL_DECLARE_MAP_INSERT_OR_ASSIGN_KEY_COPY_VALUE_COPY( \
    T_KeyT, T_ValueT \
) \
    void Mdc_Map_InsertOrAssignKeyCopyValueCopy(T_KeyT, T_ValueT)( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map, \
        MDC_T_PC(T_KeyT) key, \
        MDC_T_PC(T_ValueT) value \
    );

#define MDC_INTERNAL_DECLARE_MAP_SIZE(T_KeyT, T_ValueT) \
    size_t Mdc_Map_Size(T_KeyT, T_ValueT)( \
        MDC_T_PC(Mdc_Map(T_KeyT, T_ValueT)) map \
    );

#define MDC_INTERNAL_DECLARE_MAP_SWAP(T_KeyT, T_ValueT) \
    void Mdc_Map_Swap(T_KeyT, T_ValueT)( \
        MDC_T_P(Mdc_Map(T_KeyT, T_ValueT)) map \
    );

#define MDC_INTERNAL_DECLARE_MAP_FUNCTIONS(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_INIT_EMPTY(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_INIT_COPY(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_INIT_MOVE(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_DEINIT(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_ASSIGN_COPY(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_ASSIGN_MOVE(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_EQUAL(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_COMPARE(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_ACCESS(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_ACCESS_CONST(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_AT(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_AT_CONST(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_CLEAR(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_CONTAINS(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_EMPTY(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_ERASE(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_INSERT_PAIR(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_INSERT_PAIR_COPY(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_INSERT_OR_ASSIGN(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_INSERT_OR_ASSIGN_KEY_COPY(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_INSERT_OR_ASSIGN_VALUE_COPY( \
        T_KeyT, T_ValueT \
    ) \
    MDC_INTERNAL_DECLARE_MAP_INSERT_OR_ASSIGN_KEY_COPY_VALUE_COPY( \
        T_KeyT, T_ValueT \
    ) \
    MDC_INTERNAL_DECLARE_MAP_SIZE(T_KeyT, T_ValueT) \
    MDC_INTERNAL_DECLARE_MAP_SWAP(T_KeyT, T_ValueT)

#endif /* MDC_C_CONTAINER_INTERNAL_MAP_MAP_DECLARE_MACRO_H_ */
