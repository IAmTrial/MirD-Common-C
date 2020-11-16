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

#ifndef MDC_C_WCHAR_T_FILEW_H_
#define MDC_C_WCHAR_T_FILEW_H_

#if _MSC_VER < 1600

#define MDC_INTERNAL_CSTR_LIT_TO_CWSTR_LIT( \
    prefix, \
    lit \
) prefix ## lit



#define MDC_INTERNAL_EXPAND_MACRO(prefix, x) \
    MDC_INTERNAL_CSTR_LIT_TO_CWSTR_LIT(prefix, x)

#define __FILEW__ MDC_INTERNAL_EXPAND_MACRO(L, __FILE__)

#endif /* _MSC_VER < 1600 */

#endif /* MDC_C_WCHAR_T_FILEW_H_ */
