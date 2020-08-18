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

#ifndef MDC_C_STRING_STRING_H_
#define MDC_C_STRING_STRING_H_

#include <stddef.h>

#include "../std/stdbool.h"
#include "char_traits.h"

enum {
  Mdc_String_npos = (size_t) -1
};

struct Mdc_String {
  char* str_;
  size_t length_;
  size_t capacity_;
};

struct Mdc_String MDC_STRING_UNINIT;

struct Mdc_String* Mdc_String_InitEmpty(struct Mdc_String* str);

struct Mdc_String* Mdc_String_InitFromChar(
    struct Mdc_String* str,
    size_t count,
    char ch
);

struct Mdc_String* Mdc_String_InitStrTail(
    struct Mdc_String* str,
    const struct Mdc_String* src,
    size_t pos
);

struct Mdc_String* Mdc_String_InitSubstr(
    struct Mdc_String* str,
    const struct Mdc_String* src,
    size_t pos,
    size_t count
);

struct Mdc_String* Mdc_String_InitFromCStr(
    struct Mdc_String* str,
    const char* c_str
);

struct Mdc_String* Mdc_String_InitFromCStrTop(
    struct Mdc_String* str,
    const char* c_str,
    size_t count
);

struct Mdc_String* Mdc_String_InitConcatStrCopyWithStrCopy(
    struct Mdc_String* str,
    const struct Mdc_String* src1,
    const struct Mdc_String* src2
);

struct Mdc_String* Mdc_String_InitConcatStrCopyWithCStr(
    struct Mdc_String* str,
    const struct Mdc_String* src1,
    const char* src2
);

struct Mdc_String* Mdc_String_InitConcatStrCopyWithChar(
    struct Mdc_String* str,
    const struct Mdc_String* src1,
    char src2
);

struct Mdc_String* Mdc_String_InitConcatStrWithStrCopy(
    struct Mdc_String* str,
    struct Mdc_String* src1,
    const struct Mdc_String* src2
);

struct Mdc_String* Mdc_String_InitConcatStrWithCStr(
    struct Mdc_String* str,
    struct Mdc_String* src1,
    const char* src2
);

struct Mdc_String* Mdc_String_InitConcatStrWithChar(
    struct Mdc_String* str,
    struct Mdc_String* src1,
    char src2
);

struct Mdc_String* Mdc_String_InitConcatCStrWithStrCopy(
    struct Mdc_String* str,
    const char* src1,
    const struct Mdc_String* src2
);

struct Mdc_String* Mdc_String_InitConcatCStrWithStr(
    struct Mdc_String* str,
    const char* src1,
    struct Mdc_String* src2
);

struct Mdc_String* Mdc_String_InitConcatCharWithStrCopy(
    struct Mdc_String* str,
    char src1,
    const struct Mdc_String* src2
);

struct Mdc_String* Mdc_String_InitConcatCharWithStr(
    struct Mdc_String* str,
    char src1,
    struct Mdc_String* src2
);

/**
 * Initializes the destination string by copying the source string.
 *
 * @param[out] dest destination string
 * @param[in] src source string
 * @return dest if successful, otherwise NULL
 */
struct Mdc_String* Mdc_String_InitCopy(
    struct Mdc_String* dest,
    const struct Mdc_String* src
);

/**
 * Initializes the destination string by moving the source string.
 *
 * @param[out] dest destination string
 * @param[in] src source string
 * @return dest if successful, otherwise NULL
 */
struct Mdc_String* Mdc_String_InitMove(
    struct Mdc_String* dest,
    struct Mdc_String* src
);

/**
 * Deinitializes the string.
 *
 * @param[in, out] str this string
 */
void Mdc_String_Deinit(struct Mdc_String* str);

/**
 * Returns the pointer to the character at the specified position. No
 * bounds checking is performed.
 *
 * @param[in] str this string
 * @param[in] pos the position of the character
 * @return the pointer to the character at the specified position
 */
char* Mdc_String_Access(struct Mdc_String* str, size_t pos);

/**
 * Returns the pointer to the character at the specified position. No
 * bounds checking is performed.
 *
 * @param[in] str this string
 * @param[in] pos the position of the character
 * @return the pointer to the character at the specified position
 */
const char* Mdc_String_AccessConst(const struct Mdc_String* str, size_t pos);

/**
 * Returns the pointer to the character at the specified position. If
 * an out-of-bounds position is specified, then the null pointer is
 * returned.
 *
 * @param[in] str this string
 * @param[in] pos the position of the character
 * @return the pointer to the character at the specified position,
 *    otherwise NULL
 */
char* Mdc_String_At(struct Mdc_String* str, size_t pos);

/**
 * Returns the pointer to the character at the specified position. If
 * an out-of-bounds position is specified, then the null pointer is
 * returned.
 *
 * @param[in] str this string
 * @param[in] pos the position of the character
 * @return the pointer to the character at the specified position,
 *    otherwise NULL
 */
const char* Mdc_String_AtConst(const struct Mdc_String* str, size_t pos);

struct Mdc_String* Mdc_String_AppendChar(
    struct Mdc_String* dest,
    size_t count,
    char ch
);

struct Mdc_String* Mdc_String_AppendStr(
    struct Mdc_String* dest,
    const struct Mdc_String* src
);

struct Mdc_String* Mdc_String_AppendStrTail(
    struct Mdc_String* dest,
    const struct Mdc_String* src,
    size_t pos
);

struct Mdc_String* Mdc_String_AppendSubstr(
    struct Mdc_String* dest,
    const struct Mdc_String* src,
    size_t pos,
    size_t count
);

struct Mdc_String* Mdc_String_AppendCStr(
    struct Mdc_String* dest,
    const char* src
);

struct Mdc_String* Mdc_String_AppendCStrTop(
    struct Mdc_String* dest,
    const char* src,
    size_t count
);

/**
 * Returns the pointer to the last character in the string.
 *
 * @param[in] str this string
 * @return the pointer to the last character in the string
 */
char* Mdc_String_Back(struct Mdc_String* str);

/**
 * Returns the pointer to the last character in the string.
 *
 * @param[in] str this string
 * @return the pointer to the last character in the string
 */
const char* Mdc_String_BackConst(const struct Mdc_String* str);

/**
 * Returns the number of allocated spaces for characters in the
 * string.
 *
 * @param[in] str this string
 * @return the number of allocated spaces in the string
 */
size_t Mdc_String_Capacity(const struct Mdc_String* str);

/**
 * Lexicographically compares two strings. Returns 0 if they are the
 * same, a negative value if the first string is "less" than the
 * second string, and a positive value if the first string is
 * "greater" than the second string.
 *
 * @param[in] str1 the first string
 * @param[in] str2 the second string
 * @return 0 if the strings have equivalent characters, negative value if
 *    str1 < str2, and positive value if str1 > str2
 */
int Mdc_String_Compare(
    const struct Mdc_String* str1,
    const struct Mdc_String* str2
);

/**
 * Removes all characters from the string. Invalidates pointers
 * and interators to elements.
 *
 * @param[in, out] str this string
 */
void Mdc_String_Clear(struct Mdc_String* str);

/**
 * Returns the pointer to the array of contiguous characters that is
 * managed by this string.
 *
 * @param[in] str this string
 * @return the pointer to the array managed by this string
 */
const char* Mdc_String_CStr(const struct Mdc_String* str);

/**
 * Returns the pointer to the array of contiguous characters that is
 * managed by this string.
 *
 * @param[in] str this string
 * @return the pointer to the array managed by this string
 */
char* Mdc_String_Data(struct Mdc_String* str);

/**
 * Returns the pointer to the array of contiguous characters that is
 * managed by this string.
 *
 * @param[in] str this string
 * @return the pointer to the array managed by this string
 */
const char* Mdc_String_DataConst(const struct Mdc_String* str);

/**
 * Returns whether the string contains any characters.
 *
 * @param[in] str this string
 * @return true if the string contains at least one character,
 *    otherwise false
 */
bool Mdc_String_Empty(const struct Mdc_String* str);

/**
 * Returns whether two maps contains equivalent characters.
 *
 * @param[in] str1 the first string
 * @param[in] str2 the second string
 * @return true if the string have equivalent characters, false otherwise
 */
bool Mdc_String_Equal(
    const struct Mdc_String* str1,
    const struct Mdc_String* str2
);

/**
 * Returns the pointer to the first character in the string.
 *
 * @param[in] str this string
 * @return the pointer to the first character in the string
 */
char* Mdc_String_Front(struct Mdc_String* str);

/**
 * Returns the pointer to the first character in the string.
 *
 * @param[in] str this string
 * @return the pointer to the first character in the string
 */
const char* Mdc_String_FrontConst(const struct Mdc_String* str);

/**
 * Returns the number of characters in the string.
 *
 * @param str this string
 * @return the number of characters in the string
 */
size_t Mdc_String_Length(const struct Mdc_String* str);

/**
 * Removes the last character in the string. If the string is empty,
 * then there is undefined behavior. Iterators and references to the
 * last element are invalidated.
 *
 * @param[in] str this string
 */
void Mdc_String_PopBack(struct Mdc_String* str);

/**
 * Appends the character to the end of the string. The end iterator is
 * invalidated. If the new size is greater than capacity, then all
 * iterators are invalidated.
 *
 * @param[in, out] str this string
 * @param[in] ch the character to append
 */
void Mdc_String_PushBack(struct Mdc_String* str, char ch);

/**
 * Increases the capacity of this string. If the string's capacity is
 * larger than or equal to the specified new capacity, then the
 * function does nothing.
 *
 * @param[in] str this string
 * @param[in] new_capacity the desired new capacity for this vector
 */
void Mdc_String_Reserve(struct Mdc_String* str, size_t new_capacity);

/**
 * Requests for the string's character capacity to shrink down to the
 * string's character count.
 *
 * @param[in] str this string
 */
void Mdc_String_ShrinkToFit(struct Mdc_String* str);

/**
 * Returns the number of characters in the string.
 *
 * @param str this string
 * @return the number of characters in the string
 */
size_t Mdc_String_Size(const struct Mdc_String* str);

/**
 * Swaps the contents of two strings.
 *
 * @param[in, out] str1 first string
 * @param[in, out] str2 second string
 */
void Mdc_String_Swap(struct Mdc_String* str1, struct Mdc_String* str2);

#endif /* MDC_C_STRING_STRING_H_ */
