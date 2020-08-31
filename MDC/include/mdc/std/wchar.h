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

#ifndef MDC_C_STD_WCHAR_H_
#define MDC_C_STD_WCHAR_H_

#include <stddef.h>
#include <wchar.h>

#if !defined(__cplusplus) && __STDC_VERSION__ < 199409L

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if _MSC_VER <= 1200

/**
 * String manipulation
 */

wchar_t* wcscpy(wchar_t* dest, const wchar_t* src);
wchar_t* wcsncpy(wchar_t* dest, const wchar_t* src, size_t count);
wchar_t* wcscat(wchar_t* dest, const wchar_t* src);
wchar_t* wcsncat(wchar_t* dest, const wchar_t* src, size_t count);

/**
 * String examination
 */

size_t wcslen(const wchar_t* str);
int wcscmp(const wchar_t* lhs, const wchar_t* rhs);
int wcsncmp(const wchar_t* lhs, const wchar_t* rhs, size_t count);
int wcscoll(const wchar_t* lhs, const wchar_t* rhs);
wchar_t* wcschr(const wchar_t* str, wchar_t ch);
wchar_t* wcsrchr(const wchar_t* str, wchar_t ch);
size_t wcsspn(const wchar_t* dest, const wchar_t* src);
size_t wcscspn(const wchar_t* dest, const wchar_t* src);
wchar_t* wcspbrk(const wchar_t* dest, const wchar_t* str);
wchar_t* wcsstr(const wchar_t* dest, const wchar_t* src);

#endif /* _MSC_VER <= 1200 */

/**
 * Wide character array manipulation
 */

wchar_t* wmemcpy(wchar_t* dest, const wchar_t* src, size_t count);
wchar_t* wmemmove(wchar_t* dest, const wchar_t* src, size_t count);
int wmemcmp(const wchar_t* lhs, const wchar_t* rhs, size_t count);
wchar_t* wmemchr(const wchar_t* ptr, wchar_t ch, size_t count);
wchar_t* wmemset(wchar_t* dest, wchar_t ch, size_t count);

#ifdef __cplusplus
} /* __cplusplus */
#endif /* __cplusplus */

#endif /* !defined(__cplusplus) && __STDC_VERSION__ < 199409L */

#endif /* MDC_C_STD_WCHAR_H_ */
