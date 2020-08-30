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

#include "../../../include/mdc/string/basic_string.h"

#include <stdlib.h>
#include <string.h>

#include "../../../include/mdc/std/stdint.h"

enum {
  kInitialCapacity = 4
};

/**
 * Static
 */

static size_t Mdc_UnBasicString_ElementsIndexToBytesIndex(
    size_t ch_size,
    size_t pos
) {
  return ch_size * pos;
}

static const void* Mdc_UnBasicString_AccessConst(
    const void* str,
    size_t ch_size,
    size_t pos
) {
  const unsigned char* const str_as_bytes = str;

  size_t bytes_pos;

  bytes_pos = Mdc_UnBasicString_ElementsIndexToBytesIndex(ch_size, pos);

  return (const void*) &str_as_bytes[bytes_pos];
}

static void* Mdc_UnBasicString_Access(
    void* str,
    size_t ch_size,
    size_t pos
) {
  return (void*) Mdc_UnBasicString_AccessConst(str, ch_size, pos);
}

static struct Mdc_BasicString* Mdc_BasicString_InitMoveCStrConcatCStr(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicStringMetadata* metadata,
    void* src1,
    size_t src1_length,
    size_t src1_capacity,
    const void* src2,
    size_t src2_length
) {
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  void* concat_start_ptr;
  void* end_ptr;

  /* Copy-assign metadata. */
  str->metadata = malloc(sizeof(*str->metadata));
  if (str->metadata == NULL) {
    goto return_bad;
  }

  *str->metadata = *metadata;

  /* Set remaining members. */
  str->capacity_ = src1_length + src2_length + 1;

  if (str->capacity_ > src1_capacity) {
    str->str_ = realloc(src1, str->capacity_ * sizes->ch_size);
    if (str->str_ == NULL) {
      goto free_metadata;
    }
  } else {
    str->str_ = src1;
    str->capacity_ = src1_capacity;
  }

  str->length_ = src1_length + src2_length;

  /* Concat src2, then concat null-terminator. */
  concat_start_ptr = Mdc_UnBasicString_Access(
      str->str_,
      sizes->ch_size,
      src1_length
  );
  functions->copy_overlap_str(concat_start_ptr, src2, src2_length);

  end_ptr = Mdc_UnBasicString_Access(
      str->str_,
      sizes->ch_size,
      str->length_
  );
  functions->assign_str(end_ptr, 1, '\0');

  return str;

free_metadata:
  free(str->metadata);

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

static struct Mdc_BasicString* Mdc_BasicString_InitCopyCStrConcatCStr(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicStringMetadata* metadata,
    const void* src1,
    size_t src1_length,
    const void* src2,
    size_t src2_length
) {
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  size_t src1_capacity;
  void* src1_copy;

  void* src1_copy_end_ptr;

  src1_capacity = src1_length + src2_length + 1;

  /* Duplicate src1. */
  src1_copy = malloc(src1_capacity * sizes->ch_size);
  if (src1_copy == NULL) {
    goto return_bad;
  }

  functions->copy_nonoverlap_str(src1_copy, src1, src1_length);

  src1_copy_end_ptr = Mdc_UnBasicString_Access(
      src1_copy,
      sizes->ch_size,
      src1_length
  );
  functions->assign_str(src1_copy_end_ptr, 1, '\0');

  return Mdc_BasicString_InitMoveCStrConcatCStr(
      str,
      metadata,
      src1_copy,
      src1_length,
      src1_capacity,
      src2,
      src2_length
  );

return_bad:
  return NULL;
}

/**
 * External
 */

struct Mdc_BasicString* Mdc_BasicString_InitEmpty(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicStringMetadata* metadata
) {
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  /* Copy-assign metadata. */
  str->metadata = malloc(sizeof(*str->metadata));
  if (str->metadata == NULL) {
    goto return_bad;
  }

  *str->metadata = *metadata;

  /* Set remaining members. */
  str->capacity_ = kInitialCapacity;

  str->str_ = malloc(str->capacity_ * sizes->ch_size);
  if (str->str_ == NULL) {
    goto free_metadata;
  }

  str->length_ = 0;

  functions->assign_str(str->str_, 1, '\0');

  return str;

free_metadata:
  free(str->metadata);

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_InitFromChar(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicStringMetadata* metadata,
    size_t count,
    uintmax_t ch
) {
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  void* end_ptr;

  /* Copy-assign metadata. */
  str->metadata = malloc(sizeof(*str->metadata));
  if (str->metadata == NULL) {
    goto return_bad;
  }

  *str->metadata = *metadata;

  /* Set remaining members. */
  str->capacity_ = count + 1;

  str->str_ = malloc(str->capacity_ * sizes->ch_size);
  if (str->str_ == NULL) {
    goto return_bad;
  }

  str->length_ = count;

  functions->assign_str(str->str_, count, ch);

  end_ptr = Mdc_UnBasicString_Access(str->str_, sizes->ch_size, count);
  functions->assign_str(end_ptr, 1, '\0');

  return str;

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_InitStrTail(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicString* src,
    size_t pos
) {
  return Mdc_BasicString_InitSubstr(str, src, pos, Mdc_BasicString_npos);
}

struct Mdc_BasicString* Mdc_BasicString_InitSubstr(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicString* src,
    size_t pos,
    size_t count
) {
  const struct Mdc_BasicStringMetadata* const metadata = src->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  const void* tail_start_ptr;

  if (count == Mdc_BasicString_npos) {
    count = src->length_ - pos;
  }

  tail_start_ptr = Mdc_UnBasicString_AccessConst(
      src->str_,
      sizes->ch_size,
      pos
  );

  return Mdc_BasicString_InitFromCStrTop(
      str,
      metadata,
      tail_start_ptr,
      count
  );
}

struct Mdc_BasicString* Mdc_BasicString_InitFromCStr(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicStringMetadata* metadata,
    const void* c_str
) {
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  return Mdc_BasicString_InitFromCStrTop(
      str,
      metadata,
      c_str,
      functions->length_str(c_str)
  );
}

struct Mdc_BasicString* Mdc_BasicString_InitFromCStrTop(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicStringMetadata* metadata,
    const void* c_str,
    size_t count
) {
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  void* end_ptr;

  /* Copy-assign metadata. */
  str->metadata = malloc(sizeof(*str->metadata));
  if (str->metadata == NULL) {
    goto return_bad;
  }

  *str->metadata = *metadata;

  /* Set remaining members. */
  str->capacity_ = count + 1;

  str->str_ = malloc(str->capacity_ * sizes->ch_size);
  if (str->str_ == NULL) {
    goto return_bad;
  }

  str->length_ = count;

  functions->copy_nonoverlap_str(str->str_, c_str, count);

  end_ptr = Mdc_UnBasicString_Access(str->str_, sizes->ch_size, count);
  functions->assign_str(end_ptr, 1, '\0');

  return str;

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_InitConcatStrCopyWithStrCopy(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicString* src1,
    const struct Mdc_BasicString* src2
) {
  const struct Mdc_BasicStringMetadata* const metadata = src1->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  struct Mdc_BasicString* init_str_concat;

  init_str_concat = Mdc_BasicString_InitCopyCStrConcatCStr(
      str,
      metadata,
      src1->str_,
      src1->length_,
      src2->str_,
      src2->length_
  );

  if (init_str_concat != str) {
    goto return_bad;
  }

  return str;

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_InitConcatStrCopyWithCStr(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicString* src1,
    const void* src2
) {
  const struct Mdc_BasicStringMetadata* const metadata = src1->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  struct Mdc_BasicString* init_str_concat;

  init_str_concat = Mdc_BasicString_InitCopyCStrConcatCStr(
      str,
      metadata,
      src1->str_,
      src1->length_,
      src2,
      functions->length_str(src2)
  );

  if (init_str_concat != str) {
    goto return_bad;
  }

  return str;

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_InitConcatStrCopyWithChar(
    struct Mdc_BasicString* str,
    const struct Mdc_BasicString* src1,
    uintmax_t src2
) {
  const struct Mdc_BasicStringMetadata* const metadata = src1->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  struct Mdc_BasicString* init_str_concat;

  init_str_concat = Mdc_BasicString_InitCopyCStrConcatCStr(
      str,
      metadata,
      src1->str_,
      src1->length_,
      &src2,
      1
  );

  if (init_str_concat != str) {
    goto return_bad;
  }

  return str;

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_InitConcatStrWithStrCopy(
    struct Mdc_BasicString* str,
    struct Mdc_BasicString* src1,
    const struct Mdc_BasicString* src2
) {
  const struct Mdc_BasicStringMetadata* const metadata = src1->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  struct Mdc_BasicString* init_str_concat;

  init_str_concat = Mdc_BasicString_InitMoveCStrConcatCStr(
      str,
      metadata,
      src1->str_,
      src1->length_,
      src1->capacity_,
      src2->str_,
      src2->length_
  );

  if (init_str_concat != str) {
    goto return_bad;
  }

  return str;

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_InitConcatStrWithCStr(
    struct Mdc_BasicString* str,
    struct Mdc_BasicString* src1,
    const void* src2
) {
  const struct Mdc_BasicStringMetadata* const metadata = src1->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  struct Mdc_BasicString* init_str_concat;

  init_str_concat = Mdc_BasicString_InitMoveCStrConcatCStr(
      str,
      metadata,
      src1->str_,
      src1->length_,
      src1->capacity_,
      src2,
      functions->length_str(src2)
  );

  if (init_str_concat != str) {
    goto return_bad;
  }

  return str;

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_InitConcatStrWithChar(
    struct Mdc_BasicString* str,
    struct Mdc_BasicString* src1,
    uintmax_t src2
) {
  const struct Mdc_BasicStringMetadata* const metadata = src1->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  struct Mdc_BasicString* init_str_concat;

  init_str_concat = Mdc_BasicString_InitMoveCStrConcatCStr(
      str,
      metadata,
      src1->str_,
      src1->length_,
      src1->capacity_,
      &src2,
      1
  );

  if (init_str_concat != str) {
    goto return_bad;
  }

  return str;

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_InitConcatCStrWithStrCopy(
    struct Mdc_BasicString* str,
    const void* src1,
    const struct Mdc_BasicString* src2
) {
  const struct Mdc_BasicStringMetadata* const metadata = src2->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  struct Mdc_BasicString* init_str_concat;

  init_str_concat = Mdc_BasicString_InitCopyCStrConcatCStr(
      str,
      metadata,
      src1,
      functions->length_str(src1),
      src2->str_,
      src2->length_
  );

  if (init_str_concat != str) {
    goto return_bad;
  }

  return str;

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_InitConcatCStrWithStr(
    struct Mdc_BasicString* str,
    const void* src1,
    struct Mdc_BasicString* src2
) {
  const struct Mdc_BasicStringMetadata* const metadata = src2->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  struct Mdc_BasicString* init_str_concat;

  init_str_concat = Mdc_BasicString_InitCopyCStrConcatCStr(
      str,
      metadata,
      src1,
      functions->length_str(src1),
      src2->str_,
      src2->length_
  );

  if (init_str_concat != str) {
    goto return_bad;
  }

  return str;

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_InitConcatCharWithStrCopy(
    struct Mdc_BasicString* str,
    uintmax_t src1,
    const struct Mdc_BasicString* src2
) {
  const struct Mdc_BasicStringMetadata* const metadata = src2->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  struct Mdc_BasicString* init_str_concat;

  init_str_concat = Mdc_BasicString_InitCopyCStrConcatCStr(
      str,
      metadata,
      &src1,
      1,
      src2->str_,
      src2->length_
  );

  if (init_str_concat != str) {
    goto return_bad;
  }

  return str;

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_InitConcatCharWithStr(
    struct Mdc_BasicString* str,
    uintmax_t src1,
    struct Mdc_BasicString* src2
) {
  const struct Mdc_BasicStringMetadata* const metadata = src2->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  struct Mdc_BasicString* init_str_concat;

  init_str_concat = Mdc_BasicString_InitCopyCStrConcatCStr(
      str,
      metadata,
      &src1,
      functions->length_str(&src1),
      src2->str_,
      src2->length_
  );

  if (init_str_concat != str) {
    goto return_bad;
  }

  return str;

return_bad:
  *str = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_InitCopy(
    struct Mdc_BasicString* dest,
    const struct Mdc_BasicString* src
) {
  return Mdc_BasicString_InitSubstr(dest, src, 0, Mdc_BasicString_npos);
}

struct Mdc_BasicString* Mdc_BasicString_InitMove(
    struct Mdc_BasicString* dest,
    struct Mdc_BasicString* src
) {
  /* Copy-assign metadata. */
  dest->metadata = malloc(sizeof(*dest->metadata));
  if (dest->metadata == NULL) {
    goto return_bad;
  }

  *dest->metadata = *src->metadata;

  dest->str_ = src->str_;
  dest->length_ = src->length_;
  dest->capacity_ = src->capacity_;

  return dest;

return_bad:
  *dest = MDC_BASIC_STRING_UNINIT;

  return NULL;
}

void Mdc_BasicString_Deinit(struct Mdc_BasicString* str) {
  if (str->str_ != NULL) {
    free(str->str_);
  }

  if (str->metadata != NULL) {
    free(str->metadata);
  }

  *str = MDC_BASIC_STRING_UNINIT;
}

void* Mdc_BasicString_Access(
    struct Mdc_BasicString* str,
    size_t pos
) {
  return (void*) Mdc_BasicString_AccessConst(str, pos);
}

const void* Mdc_BasicString_AccessConst(
    const struct Mdc_BasicString* str,
    size_t pos
) {
  const struct Mdc_BasicStringMetadata* const metadata = str->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  return Mdc_UnBasicString_AccessConst(str->str_, sizes->ch_size, pos);
}

void* Mdc_BasicString_At(
    struct Mdc_BasicString* str,
    size_t pos
) {
  return (void*) Mdc_BasicString_AtConst(str, pos);
}

const void* Mdc_BasicString_AtConst(
    const struct Mdc_BasicString* str,
    size_t pos
) {
  if (pos < 0 || pos >= str->length_) {
    goto return_bad;
  }

  return Mdc_BasicString_AccessConst(str, pos);

return_bad:
  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_AppendChar(
    struct Mdc_BasicString* dest,
    size_t count,
    uintmax_t ch
) {
  const struct Mdc_BasicStringMetadata* const metadata = dest->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  size_t new_length;
  size_t new_capacity;

  void* concat_start_ptr;
  void* end_ptr;

  new_length = dest->length_ + count;
  new_capacity = dest->capacity_;

  /* Increase capacity if needed. */
  if (new_length >= dest->capacity_) {
    while (new_capacity <= new_length) {
      new_capacity *= 2;
    }

    Mdc_BasicString_Reserve(dest, new_capacity);

    if (dest->capacity_ < new_capacity) {
      goto return_bad;
    }
  }

  concat_start_ptr = Mdc_UnBasicString_Access(
      dest->str_,
      sizes->ch_size,
      dest->length_
  );
  functions->assign_str(concat_start_ptr, count, ch);

  end_ptr = Mdc_UnBasicString_Access(
      dest->str_,
      sizes->ch_size,
      new_length
  );
  functions->assign_str(end_ptr, 1, '\0');

  dest->length_ = new_length;

  return dest;

return_bad:
  return NULL;
}

struct Mdc_BasicString* Mdc_BasicString_AppendStr(
    struct Mdc_BasicString* dest,
    const struct Mdc_BasicString* src
) {
  return Mdc_BasicString_AppendStrTail(
      dest,
      src,
      0
  );
}

struct Mdc_BasicString* Mdc_BasicString_AppendStrTail(
    struct Mdc_BasicString* dest,
    const struct Mdc_BasicString* src,
    size_t pos
) {
  return Mdc_BasicString_AppendSubstr(
      dest,
      src,
      pos,
      Mdc_BasicString_npos
  );
}

struct Mdc_BasicString* Mdc_BasicString_AppendSubstr(
    struct Mdc_BasicString* dest,
    const struct Mdc_BasicString* src,
    size_t pos,
    size_t count
) {
  const struct Mdc_BasicStringMetadata* const metadata = dest->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  const void* tail_start_ptr;

  if (count == Mdc_BasicString_npos) {
    count = src->length_;
  }

  tail_start_ptr = Mdc_UnBasicString_AccessConst(
      src->str_,
      sizes->ch_size,
      pos
  );

  return Mdc_BasicString_AppendCStrTop(
      dest,
      tail_start_ptr,
      count
  );
}

struct Mdc_BasicString* Mdc_BasicString_AppendCStr(
    struct Mdc_BasicString* dest,
    const void* src
) {
  const struct Mdc_BasicStringMetadata* const metadata = dest->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  return Mdc_BasicString_AppendCStrTop(
      dest,
      src,
      functions->length_str(src)
  );
}

struct Mdc_BasicString* Mdc_BasicString_AppendCStrTop(
    struct Mdc_BasicString* dest,
    const void* src,
    size_t count
) {
  const struct Mdc_BasicStringMetadata* const metadata = dest->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  size_t new_length;
  size_t new_capacity;

  void* concat_start_ptr;
  void* end_ptr;

  new_length = dest->length_ + count;
  new_capacity = dest->capacity_;

  /* Increase capacity if needed. */
  if (new_length >= dest->capacity_) {
    while (new_capacity <= new_length) {
      new_capacity *= 2;
    }

    Mdc_BasicString_Reserve(dest, new_capacity);

    if (dest->capacity_ < new_capacity) {
      goto return_bad;
    }
  }

  concat_start_ptr = Mdc_UnBasicString_Access(
      dest->str_,
      sizes->ch_size,
      dest->length_
  );
  functions->copy_overlap_str(concat_start_ptr, src, count);

  end_ptr = Mdc_UnBasicString_Access(
      dest->str_,
      sizes->ch_size,
      new_length
  );
  functions->assign_str(end_ptr, 1, '\0');

  dest->length_ = new_length;

  return dest;

return_bad:
  return NULL;
}

void* Mdc_BasicString_Back(struct Mdc_BasicString* str) {
  return (void*) Mdc_BasicString_BackConst(str);
}

const void* Mdc_BasicString_BackConst(
    const struct Mdc_BasicString* str
) {
  const struct Mdc_BasicStringMetadata* const metadata = str->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  return Mdc_UnBasicString_AccessConst(
      str->str_,
      sizes->ch_size,
      str->length_ - 1
  );
}

size_t Mdc_BasicString_Capacity(const struct Mdc_BasicString* str) {
  return str->capacity_;
}

int Mdc_BasicString_CompareStr(
    const struct Mdc_BasicString* str1,
    const struct Mdc_BasicString* str2
) {
  const struct Mdc_BasicStringMetadata* const metadata = str1->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  return Mdc_BasicString_CompareSubstr(str1, 0, str1->length_, str2);
}

int Mdc_BasicString_CompareSubstr(
    const struct Mdc_BasicString* str1,
    size_t pos1,
    size_t count1,
    const struct Mdc_BasicString* str2
) {
  const struct Mdc_BasicStringMetadata* const metadata = str1->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  return Mdc_BasicString_CompareSubstrs(
      str1,
      pos1,
      count1,
      str2,
      0,
      Mdc_BasicString_npos
  );
}

int Mdc_BasicString_CompareSubstrs(
    const struct Mdc_BasicString* str1,
    size_t pos1,
    size_t count1,
    const struct Mdc_BasicString* str2,
    size_t pos2,
    size_t count2
) {
  const struct Mdc_BasicStringMetadata* const metadata = str1->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  if (count2 == Mdc_BasicString_npos
      || count2 > str2->length_ - pos2) {
    count2 = str2->length_ - pos2;
  }

  return Mdc_BasicString_CompareCSubstrs(
      str1,
      pos1,
      count1,
      Mdc_UnBasicString_Access(str2->str_, sizes->ch_size, pos2),
      count2
  );
}

int Mdc_BasicString_CompareCStr(
    const struct Mdc_BasicString* str,
    const void* c_str
) {
  const struct Mdc_BasicStringMetadata* const metadata = str->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  return Mdc_BasicString_CompareCSubstr(
      str,
      0,
      str->length_,
      c_str
  );
}

int Mdc_BasicString_CompareCSubstr(
    const struct Mdc_BasicString* str,
    size_t pos1,
    size_t count1,
    const void* c_str
) {
  const struct Mdc_BasicStringMetadata* const metadata = str->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  return Mdc_BasicString_CompareCSubstrs(
      str,
      pos1,
      count1,
      c_str,
      functions->length_str(c_str)
  );
}

int Mdc_BasicString_CompareCSubstrs(
    const struct Mdc_BasicString* str,
    size_t pos1,
    size_t count1,
    const void* c_str,
    size_t count2
) {
  const struct Mdc_BasicStringMetadata* const metadata = str->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;
  const uintmax_t null_term_ch = '\0';

  bool is_str_length_equal;
  bool is_str_length_less_than;

  size_t compare_length;
  int compare_result;

  const void* access_end_ptr;

  /* Limit count1 to the length of str. */
  if (count1 > str->length_ - pos1) {
    count1 = str->length_ - pos1;
  }

  /* Compare the strings up to the length of the shorter one. */
  is_str_length_equal = (count1 == count2);
  is_str_length_less_than = (count1 < count2);

  if (is_str_length_less_than) {
    compare_length = count1;
  } else {
    compare_length = count2;
  }

  compare_result = functions->compare_str(str->str_, c_str, compare_length);

  if (compare_result != 0 || is_str_length_equal) {
    return compare_result;
  }

  /* Treat the shorter one's end char as null-term. */
  if (is_str_length_less_than) {
    access_end_ptr = Mdc_UnBasicString_AccessConst(
        c_str,
        sizes->ch_size,
        compare_length
    );

    return functions->compare_str(
        &null_term_ch,
        access_end_ptr,
        1
    );
  } else {
    access_end_ptr = Mdc_UnBasicString_AccessConst(
        str->str_,
        sizes->ch_size,
        compare_length
    );

    return functions->compare_str(
        access_end_ptr,
        &null_term_ch,
        1
    );
  }
}

void Mdc_BasicString_Clear(struct Mdc_BasicString* str) {
  const struct Mdc_BasicStringMetadata* const metadata = str->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  functions->assign_str(str->str_, 1, '\0');
  str->length_ = 0;
}

const void* Mdc_BasicString_CStr(const struct Mdc_BasicString* str) {
  return str->str_;
}

void* Mdc_BasicString_Data(struct Mdc_BasicString* str) {
  return (void*) Mdc_BasicString_DataConst(str);
}

const void* Mdc_BasicString_DataConst(const struct Mdc_BasicString* str) {
  return Mdc_BasicString_CStr(str);
}

bool Mdc_BasicString_Empty(const struct Mdc_BasicString* str) {
  return Mdc_BasicString_Length(str) == 0;
}

bool Mdc_BasicString_EqualStr(
    const struct Mdc_BasicString* str1,
    const struct Mdc_BasicString* str2
) {
  const struct Mdc_BasicStringMetadata* const metadata = str1->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  int compare_result;

  if (str1->length_ != str2->length_) {
    return false;
  }

  compare_result = functions->compare_str(
      str1->str_,
      str2->str_,
      str1->length_
  );

  return (compare_result == 0);
}

bool Mdc_BasicString_EqualCStr(
    const struct Mdc_BasicString* str,
    const void* c_str
) {
  const struct Mdc_BasicStringMetadata* const metadata = str->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  const uintmax_t kNullTermCh = '\0';

  int compare_result;
  const void* c_str_end_ptr;

  compare_result = functions->compare_str(
      str->str_,
      c_str,
      str->length_
  );

  if (compare_result != 0) {
    return compare_result;
  }

  c_str_end_ptr = Mdc_UnBasicString_AccessConst(
      c_str,
      sizes->ch_size,
      str->length_
  );

  return functions->compare_str(&kNullTermCh, c_str, 1);
}

void* Mdc_BasicString_Front(struct Mdc_BasicString* str){
  return (void*) Mdc_BasicString_FrontConst(str);
}

const void* Mdc_BasicString_FrontConst(const struct Mdc_BasicString* str) {
  const struct Mdc_BasicStringMetadata* const metadata = str->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  return Mdc_UnBasicString_AccessConst(
      str->str_,
      sizes->ch_size,
      0
  );
}

size_t Mdc_BasicString_Length(const struct Mdc_BasicString* str) {
  return str->length_;
}

void Mdc_BasicString_PopBack(struct Mdc_BasicString* str) {
  const struct Mdc_BasicStringMetadata* const metadata = str->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  void* new_end_ptr;

  str->length_ -= 1;

  new_end_ptr = Mdc_UnBasicString_Access(
      str->str_,
      sizes->ch_size,
      str->length_
  );
  functions->assign_str(new_end_ptr, 1, '\0');
}

void Mdc_BasicString_PushBack(struct Mdc_BasicString* str, uintmax_t ch) {
  const struct Mdc_BasicStringMetadata* const metadata = str->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  size_t new_length;
  size_t new_capacity;

  void* old_end_ptr;
  void* new_end_ptr;

  new_length = str->length_ + 1;

  if (new_length >= str->capacity_) {
    new_capacity = str->capacity_ * 2;

    Mdc_BasicString_Reserve(str, new_capacity);
  }

  old_end_ptr = Mdc_UnBasicString_Access(
      str->str_,
      sizes->ch_size,
      str->length_
  );
  functions->assign_char(old_end_ptr, &ch);

  str->length_ += 1;

  new_end_ptr = Mdc_UnBasicString_Access(
      str->str_,
      sizes->ch_size,
      str->length_
  );
  functions->assign_str(new_end_ptr, 1, '\0');
}

void Mdc_BasicString_Reserve(
    struct Mdc_BasicString* str,
    size_t new_capacity
) {
  const struct Mdc_BasicStringMetadata* const metadata = str->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  if (new_capacity <= str->capacity_) {
    return;
  }

  char* realloc_cstring = realloc(str->str_, new_capacity * sizes->ch_size);
  if (realloc_cstring == NULL) {
    goto return_bad;
  }

  str->str_ = realloc_cstring;
  str->capacity_ = new_capacity;

  return;

return_bad:
  return;
}

void Mdc_BasicString_ShrinkToFit(struct Mdc_BasicString* str) {
  const struct Mdc_BasicStringMetadata* const metadata = str->metadata;
  const struct Mdc_CharTraitsSizes* const sizes =
      &metadata->char_traits.sizes;
  const struct Mdc_CharTraitsFunctions* const functions =
      &metadata->char_traits.functions;

  size_t new_cap;
  char* realloc_cstring;

  new_cap = str->length_ + 1;

  realloc_cstring = realloc(str->str_, new_cap * sizes->ch_size);
  if (realloc_cstring == NULL) {
    goto return_bad;
  }

  str->str_ = realloc_cstring;
  str->capacity_ = new_cap;

  return;

return_bad:
  return;
}

size_t Mdc_BasicString_Size(const struct Mdc_BasicString* str) {
  return Mdc_BasicString_Length(str);
}

void Mdc_BasicString_Swap(
    struct Mdc_BasicString* str1,
    struct Mdc_BasicString* str2
) {
  struct Mdc_BasicString temp;

  temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}

bool Mdc_BasicStringMetadata_Equal(
    const struct Mdc_BasicStringMetadata* metadata1,
    const struct Mdc_BasicStringMetadata* metadata2
) {
  return memcmp(metadata1, metadata2, sizeof(*metadata1)) == 0;
}
