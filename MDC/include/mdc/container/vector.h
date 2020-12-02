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

#ifndef MDC_C_CONTAINER_VECTOR_H_
#define MDC_C_CONTAINER_VECTOR_H_

#include "internal/vector/vector_declare_macro.h"
#include "internal/vector/vector_define_macro.h"
#include "internal/vector/vector_name_macro.h"

#define MDC_DECLARE_VECTOR(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_STRUCT(T_ValueT) \
    MDC_INTERNAL_DECLARE_VECTOR_FUNCTIONS(T_ValueT)

#define MDC_DEFINE_VECTOR(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_CONSTANTS(T_ValueT) \
    MDC_INTERNAL_DEFINE_VECTOR_FUNCTIONS(T_ValueT)

#endif /* MDC_C_CONTAINER_VECTOR_H_ */
