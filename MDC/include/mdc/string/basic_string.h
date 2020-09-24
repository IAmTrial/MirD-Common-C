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

#ifndef MDC_C_STRING_BASIC_STRING_H_
#define MDC_C_STRING_BASIC_STRING_H_

#include <stddef.h>

#include "../object_metadata/object_metadata.h"
#include "../std/stdbool.h"
#include "char_traits.h"

#include "../../../dllexport_define.inc"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define MDC_BASIC_STRING_NPOS ((size_t) -1)

struct Mdc_BasicString {
  const struct Mdc_CharTraits* char_traits;

  void* str_;
  size_t length_;
  size_t capacity_;
};

/**
 * Initialization/deinitialization
 */

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_InitEmpty(
    struct Mdc_BasicString* str,
    const struct Mdc_CharTraits* char_traits
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_InitFromChar(
    struct Mdc_BasicString* str,
    const struct Mdc_CharTraits* char_traits,
    size_t count,
    uintmax_t ch
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_InitStrTail(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicString* src,
    size_t pos
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_InitSubstr(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicString* src,
    size_t pos,
    size_t count
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_InitFromCStr(
    struct Mdc_BasicString* str,
    const struct Mdc_CharTraits* char_traits,
    const void* c_str
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_InitFromCStrTop(
    struct Mdc_BasicString* str,
    const struct Mdc_CharTraits* char_traits,
    const void* c_str,
    size_t count
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_InitCopy(
    struct Mdc_BasicString* dest,
    const struct Mdc_BasicString* src
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_InitMove(
    struct Mdc_BasicString* dest,
    struct Mdc_BasicString* src
);

/**
 * Deinitializes the string.
 *
 * @param[in, out] str this string
 */
DLLEXPORT void Mdc_BasicString_Deinit(struct Mdc_BasicString* str);

/**
 * Metadata
 */

DLLEXPORT const struct Mdc_ObjectMetadata*
Mdc_BasicString_GetObjectMetadataTemplate(void);

/**
 * Assignment functions
 */

/**
 * Initializes the destination string by copying the source string.
 *
 * @param[out] dest destination string
 * @param[in] src source string
 * @return dest if successful, otherwise NULL
 */
DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_AssignCopy(
    struct Mdc_BasicString* dest,
    const struct Mdc_BasicString* src
);

/**
 * Initializes the destination string by moving the source string.
 *
 * @param[out] dest destination string
 * @param[in] src source string
 * @return dest if successful, otherwise NULL
 */
DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_AssignMove(
    struct Mdc_BasicString* dest,
    struct Mdc_BasicString* src
);

/**
 * Concat functions
 */

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_ConcatStrCopyWithStrCopy(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicString* src1,
    const struct Mdc_BasicString* src2
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_ConcatStrCopyWithCStr(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicString* src1,
    const void* src2
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_ConcatStrCopyWithChar(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicString* src1,
    uintmax_t src2
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_ConcatStrWithStrCopy(
    struct Mdc_BasicString* str,
    struct Mdc_BasicString* src1,
    const struct Mdc_BasicString* src2
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_ConcatStrWithCStr(
    struct Mdc_BasicString* str,
    struct Mdc_BasicString* src1,
    const void* src2
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_ConcatStrWithChar(
    struct Mdc_BasicString* str,
    struct Mdc_BasicString* src1,
    uintmax_t src2
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_ConcatCStrWithStrCopy(
    struct Mdc_BasicString* str,
    const void* src1,
    const struct Mdc_BasicString* src2
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_ConcatCStrWithStr(
    struct Mdc_BasicString* str,
    const void* src1,
    struct Mdc_BasicString* src2
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_ConcatCharWithStrCopy(
    struct Mdc_BasicString* str,
    uintmax_t src1,
    const struct Mdc_BasicString* src2
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_ConcatCharWithStr(
    struct Mdc_BasicString* str,
    uintmax_t src1,
    struct Mdc_BasicString* src2
);

/**
 * Returns the pointer to the character at the specified position. No
 * bounds checking is performed.
 *
 * @param[in] str this string
 * @param[in] pos the position of the character
 * @return the pointer to the character at the specified position
 */
DLLEXPORT void* Mdc_BasicString_Access(
    struct Mdc_BasicString* str,
    size_t pos
);

/**
 * Returns the pointer to the character at the specified position. No
 * bounds checking is performed.
 *
 * @param[in] str this string
 * @param[in] pos the position of the character
 * @return the pointer to the character at the specified position
 */
DLLEXPORT const void* Mdc_BasicString_AccessConst(
    const struct Mdc_BasicString* str,
    size_t pos
);

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
DLLEXPORT void* Mdc_BasicString_At(
    struct Mdc_BasicString* str,
    size_t pos
);

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
DLLEXPORT const void* Mdc_BasicString_AtConst(
    const struct Mdc_BasicString* str,
    size_t pos
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_AppendChar(
    struct Mdc_BasicString* dest,
    size_t count,
    uintmax_t ch
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_AppendStr(
    struct Mdc_BasicString* dest,
    const struct Mdc_BasicString* src
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_AppendStrTail(
    struct Mdc_BasicString* dest,
    const struct Mdc_BasicString* src,
    size_t pos
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_AppendSubstr(
    struct Mdc_BasicString* dest,
    const struct Mdc_BasicString* src,
    size_t pos,
    size_t count
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_AppendCStr(
    struct Mdc_BasicString* dest,
    const void* src
);

DLLEXPORT struct Mdc_BasicString* Mdc_BasicString_AppendCStrTop(
    struct Mdc_BasicString* dest,
    const void* src,
    size_t count
);

/**
 * Returns the pointer to the last character in the string.
 *
 * @param[in] str this string
 * @return the pointer to the last character in the string
 */
DLLEXPORT void* Mdc_BasicString_Back(struct Mdc_BasicString* str);

/**
 * Returns the pointer to the last character in the string.
 *
 * @param[in] str this string
 * @return the pointer to the last character in the string
 */
DLLEXPORT const void* Mdc_BasicString_BackConst(
    const struct Mdc_BasicString* str
);

/**
 * Returns the number of allocated spaces for characters in the
 * string.
 *
 * @param[in] str this string
 * @return the number of allocated spaces in the string
 */
DLLEXPORT size_t Mdc_BasicString_Capacity(const struct Mdc_BasicString* str);

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
DLLEXPORT int Mdc_BasicString_CompareStr(
    const struct Mdc_BasicString* str1,
    const struct Mdc_BasicString* str2
);

/**
 * Lexicographically compares a substring and string. Returns 0 if
 * they are the same, a negative value if the first string is "less"
 * than the second string, and a positive value if the first string is
 * "greater" than the second string.
 *
 * @param[in] str1 the first string
 * @param[in] pos1 the starting position of the first substring
 * @param[in] count1 the number of characters in the first substring
 * @param[in] str2 the second string
 * @return 0 if the strings have equivalent characters, negative value if
 *    str1 < str2, and positive value if str1 > str2
 */
DLLEXPORT int Mdc_BasicString_CompareSubstr(
    const struct Mdc_BasicString* str1,
    size_t pos1,
    size_t count1,
    const struct Mdc_BasicString* str2
);

/**
 * Lexicographically compares two substrings. Returns 0 if they are
 * the same, a negative value if the first string is "less" than the
 * second string, and a positive value if the first string is
 * "greater" than the second string.
 *
 * @param[in] str1 the first string
 * @param[in] pos1 the starting position of the first substring
 * @param[in] count1 the number of characters in the first substring
 * @param[in] str2 the second string
 * @param[in] pos2 the starting position of the second substring
 * @param[in] count2 the number of characters in the second substring
 * @return 0 if the strings have equivalent characters, negative value if
 *    str1 < str2, and positive value if str1 > str2
 */
DLLEXPORT int Mdc_BasicString_CompareSubstrs(
    const struct Mdc_BasicString* str1,
    size_t pos1,
    size_t count1,
    const struct Mdc_BasicString* str2,
    size_t pos2,
    size_t count2
);

/**
 * Lexicographically compares two strings. Returns 0 if they are the
 * same, a negative value if the first string is "less" than the
 * second string, and a positive value if the first string is
 * "greater" than the second string.
 *
 * @param[in] str the first string
 * @param[in] c_str the second string
 * @return 0 if the strings have equivalent characters, negative value if
 *    str1 < str2, and positive value if str1 > str2
 */
DLLEXPORT int Mdc_BasicString_CompareCStr(
    const struct Mdc_BasicString* str,
    const void* c_str
);

/**
 * Lexicographically compares a substring and string. Returns 0 if
 * they are the same, a negative value if the first string is "less"
 * than the second string, and a positive value if the first string is
 * "greater" than the second string.
 *
 * @param[in] str the first string
 * @param[in] pos1 the starting position of the first substring
 * @param[in] count1 the number of characters in the first substring
 * @param[in] c_str the second string
 * @return 0 if the strings have equivalent characters, negative value if
 *    str1 < str2, and positive value if str1 > str2
 */
DLLEXPORT int Mdc_BasicString_CompareCSubstr(
    const struct Mdc_BasicString* str,
    size_t pos1,
    size_t count1,
    const void* c_str
);

/**
 * Lexicographically compares two substrings. Returns 0 if they are
 * the same, a negative value if the first string is "less" than the
 * second string, and a positive value if the first string is
 * "greater" than the second string.
 *
 * @param[in] str the first string
 * @param[in] pos1 the starting position of the first substring
 * @param[in] count1 the number of characters in the first substring
 * @param[in] c_str the second string
 * @param[in] count2 the number of characters in the second substring
 * @return 0 if the strings have equivalent characters, negative value if
 *    str1 < str2, and positive value if str1 > str2
 */
DLLEXPORT int Mdc_BasicString_CompareCSubstrs(
    const struct Mdc_BasicString* str,
    size_t pos1,
    size_t count1,
    const void* c_str,
    size_t count2
);

/**
 * Removes all characters from the string. Invalidates pointers
 * and interators to elements.
 *
 * @param[in, out] str this string
 */
DLLEXPORT void Mdc_BasicString_Clear(struct Mdc_BasicString* str);

/**
 * Returns the pointer to the array of contiguous characters that is
 * managed by this string.
 *
 * @param[in] str this string
 * @return the pointer to the array managed by this string
 */
DLLEXPORT const void* Mdc_BasicString_CStr(const struct Mdc_BasicString* str);

/**
 * Returns the pointer to the array of contiguous characters that is
 * managed by this string.
 *
 * @param[in] str this string
 * @return the pointer to the array managed by this string
 */
DLLEXPORT void* Mdc_BasicString_Data(struct Mdc_BasicString* str);

/**
 * Returns the pointer to the array of contiguous characters that is
 * managed by this string.
 *
 * @param[in] str this string
 * @return the pointer to the array managed by this string
 */
DLLEXPORT const void* Mdc_BasicString_DataConst(const struct Mdc_BasicString* str);

/**
 * Returns whether the string contains any characters.
 *
 * @param[in] str this string
 * @return true if the string contains at least one character,
 *    otherwise false
 */
DLLEXPORT bool Mdc_BasicString_Empty(const struct Mdc_BasicString* str);

/**
 * Returns whether two strings contains equivalent characters.
 *
 * @param[in] str1 the first string
 * @param[in] str2 the second string
 * @return true if the string have equivalent characters, false otherwise
 */
DLLEXPORT bool Mdc_BasicString_EqualStr(
    const struct Mdc_BasicString* str1,
    const struct Mdc_BasicString* str2
);

/**
 * Returns whether two strings contains equivalent characters.
 *
 * @param[in] str the first string
 * @param[in] c_str the second string
 * @return true if the string have equivalent characters, false otherwise
 */
DLLEXPORT bool Mdc_BasicString_EqualCStr(
    const struct Mdc_BasicString* str,
    const void* c_str
);

/**
 * Returns the pointer to the first character in the string.
 *
 * @param[in] str this string
 * @return the pointer to the first character in the string
 */
DLLEXPORT void* Mdc_BasicString_Front(struct Mdc_BasicString* str);

/**
 * Returns the pointer to the first character in the string.
 *
 * @param[in] str this string
 * @return the pointer to the first character in the string
 */
DLLEXPORT const void* Mdc_BasicString_FrontConst(const struct Mdc_BasicString* str);

/**
 * Returns the number of characters in the string.
 *
 * @param str this string
 * @return the number of characters in the string
 */
DLLEXPORT size_t Mdc_BasicString_Length(const struct Mdc_BasicString* str);

/**
 * Removes the last character in the string. If the string is empty,
 * then there is undefined behavior. Iterators and references to the
 * last element are invalidated.
 *
 * @param[in] str this string
 */
DLLEXPORT void Mdc_BasicString_PopBack(struct Mdc_BasicString* str);

/**
 * Appends the character to the end of the string. The end iterator is
 * invalidated. If the new size is greater than capacity, then all
 * iterators are invalidated.
 *
 * @param[in, out] str this string
 * @param[in] ch the character to append
 */
DLLEXPORT void Mdc_BasicString_PushBack(struct Mdc_BasicString* str, uintmax_t ch);

/**
 * Increases the capacity of this string. If the string's capacity is
 * larger than or equal to the specified new capacity, then the
 * function does nothing.
 *
 * @param[in] str this string
 * @param[in] new_capacity the desired new capacity for this vector
 */
DLLEXPORT void Mdc_BasicString_Reserve(struct Mdc_BasicString* str, size_t new_capacity);

/**
 * Requests for the string's character capacity to shrink down to the
 * string's character count.
 *
 * @param[in] str this string
 */
DLLEXPORT void Mdc_BasicString_ShrinkToFit(struct Mdc_BasicString* str);

/**
 * Returns the number of characters in the string.
 *
 * @param str this string
 * @return the number of characters in the string
 */
DLLEXPORT size_t Mdc_BasicString_Size(const struct Mdc_BasicString* str);

/**
 * Swaps the contents of two strings.
 *
 * @param[in, out] str1 first string
 * @param[in, out] str2 second string
 */
DLLEXPORT void Mdc_BasicString_Swap(
    struct Mdc_BasicString* str1,
    struct Mdc_BasicString* str2
);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#include "../../../dllexport_undefine.inc"
#endif /* MDC_C_STRING_BASIC_STRING_H_ */

#include "basic_string/string.h"
#include "basic_string/wstring.h"
