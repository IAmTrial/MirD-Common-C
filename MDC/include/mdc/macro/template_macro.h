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

#ifndef MDC_C_MACRO_TEMPLATE_MACRO_H_
#define MDC_C_MACRO_TEMPLATE_MACRO_H_

#include "concat_macro.h"

#define MDC_T(type_name) \
    MDC_MACRO_CONCAT(Mdc_Internal_T_, type_name)

#define MDC_T_P(type_name) \
    MDC_MACRO_CONCAT(Mdc_Internal_T_P_, type_name)

#define MDC_T_C(type_name) \
    MDC_MACRO_CONCAT(Mdc_Internal_T_C_, type_name)

#define MDC_T_PC(type_name) \
    MDC_MACRO_CONCAT(Mdc_Internal_T_PC_, type_name)

#define MDC_T_V(type_name) \
    MDC_MACRO_CONCAT(Mdc_Internal_T_V_, type_name)

#define MDC_T_PV(type_name) \
    MDC_MACRO_CONCAT(Mdc_Internal_T_PV_, type_name)

#define MDC_T_CV(type_name) \
    MDC_MACRO_CONCAT(Mdc_Internal_T_CV_, type_name)

#define MDC_T_PCV(type_name) \
    MDC_MACRO_CONCAT(Mdc_Internal_T_PCV_, type_name)

#define MDC_INTERNAL_T_DECLARE_TYPEDEFS(type_name) \
    typedef type_name MDC_T(type_name); \
    typedef type_name* MDC_T_P(type_name); \
    typedef type_name const MDC_T_C(type_name); \
    typedef type_name const* MDC_T_PC(type_name); \
    typedef type_name volatile MDC_T_V(type_name); \
    typedef type_name volatile* MDC_T_PV(type_name); \
    typedef type_name const volatile MDC_T_CV(type_name); \
    typedef type_name const volatile* MDC_T_PCV(type_name);

#define MDC_INTERNAL_T_DECLARE_DATA_TYPE_TYPEDEFS(data_type, tag_name) \
    typedef data_type tag_name MDC_T(tag_name); \
    typedef data_type tag_name* MDC_T_P(tag_name); \
    typedef data_type tag_name const MDC_T_C(tag_name); \
    typedef data_type tag_name const* MDC_T_PC(tag_name); \
    typedef data_type tag_name volatile MDC_T_V(tag_name); \
    typedef data_type tag_name volatile* MDC_T_PV(tag_name); \
    typedef data_type tag_name const volatile MDC_T_CV(tag_name); \
    typedef data_type tag_name const volatile* MDC_T_PCV(tag_name);

#define MDC_T_DECLARE_TYPEDEFS(type_name) \
    MDC_INTERNAL_T_DECLARE_TYPEDEFS(type_name) \

#define MDC_T_DECLARE_DATA_TYPE_TYPEDEFS(data_type, tag_name) \
    MDC_INTERNAL_T_DECLARE_DATA_TYPE_TYPEDEFS(data_type, tag_name) \


#define MDC_MACRO_TEMPLATE_1(T) \
    MDC_MACRO_CONCAT(MDC_MACRO_CONCAT(__, T), __)

#define MDC_MACRO_TEMPLATE_2(T1, T2) \
    MDC_MACRO_TEMPLATE_1(MDC_MACRO_CONCAT(MDC_MACRO_CONCAT(T1, _), T2))

#define MDC_MACRO_TEMPLATE_3(T1, T2, T3) \
    MDC_MACRO_TEMPLATE_2( \
        MDC_MACRO_CONCAT(MDC_MACRO_CONCAT(T1, _), T2), \
        T3 \
    )

#define MDC_MACRO_TEMPLATE_4(T1, T2, T3, T4) \
    MDC_MACRO_TEMPLATE_3( \
        MDC_MACRO_CONCAT(MDC_MACRO_CONCAT(T1, _), T2), \
        T3, T4 \
    )

#define MDC_MACRO_TEMPLATE_5(T1, T2, T3, T4, T5) \
    MDC_MACRO_TEMPLATE_4( \
        MDC_MACRO_CONCAT(MDC_MACRO_CONCAT(T1, _), T2), \
        T3, T4, T5 \
    )

#define MDC_MACRO_TEMPLATE_6(T1, T2, T3, T4, T5, T6) \
    MDC_MACRO_TEMPLATE_5( \
        MDC_MACRO_CONCAT(MDC_MACRO_CONCAT(T1, _), T2), \
        T3, T4, T5, T6 \
    )

#define MDC_MACRO_TEMPLATE_7(T1, T2, T3, T4, T5, T6, T7) \
    MDC_MACRO_TEMPLATE_6( \
        MDC_MACRO_CONCAT(MDC_MACRO_CONCAT(T1, _), T2), \
        T3, T4, T5, T6, T7 \
    )

#define MDC_MACRO_TEMPLATE_8(T1, T2, T3, T4, T5, T6, T7, T8) \
    MDC_MACRO_TEMPLATE_7( \
        MDC_MACRO_CONCAT(MDC_MACRO_CONCAT(T1, _), T2), \
        T3, T4, T5, T6, T7, T8 \
    )

#define MDC_MACRO_TEMPLATE_9(T1, T2, T3, T4, T5, T6, T7, T8, T9) \
    MDC_MACRO_TEMPLATE_8( \
        MDC_MACRO_CONCAT(MDC_MACRO_CONCAT(T1, _), T2), \
        T3, T4, T5, T6, T7, T8, T9 \
    )

#endif /* MDC_C_MACRO_TEMPLATE_MACRO_H_ */
