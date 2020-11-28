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

#include "../../../include/mdc/object/windows_integer_object.h"

#if defined(_WIN32) || defined(_WIN64)

MDC_DEFINE_UNSIGNED_INTEGER(Mdc_UCHAR)

MDC_DEFINE_SIGNED_INTEGER(Mdc_SHORT)
MDC_DEFINE_SIGNED_INTEGER(Mdc_INT)
MDC_DEFINE_SIGNED_INTEGER(Mdc_LONG)
MDC_DEFINE_SIGNED_INTEGER(Mdc_LONGLONG)

MDC_DEFINE_UNSIGNED_INTEGER(Mdc_USHORT)
MDC_DEFINE_UNSIGNED_INTEGER(Mdc_UINT)
MDC_DEFINE_UNSIGNED_INTEGER(Mdc_ULONG)
MDC_DEFINE_UNSIGNED_INTEGER(Mdc_ULONGLONG)

MDC_DEFINE_UNSIGNED_INTEGER(Mdc_BYTE)
MDC_DEFINE_UNSIGNED_INTEGER(Mdc_WORD)
MDC_DEFINE_UNSIGNED_INTEGER(Mdc_DWORD)
MDC_DEFINE_UNSIGNED_INTEGER(Mdc_DWORDLONG)

MDC_DEFINE_UNSIGNED_INTEGER(Mdc_DWORD32)
MDC_DEFINE_UNSIGNED_INTEGER(Mdc_DWORD64)

#endif /* defined(_WIN32) || defined(_WIN64) */
