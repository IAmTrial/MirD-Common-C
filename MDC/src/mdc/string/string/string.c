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

#include "../../../../include/mdc/string/string.h"

#include <stdlib.h>

struct Mdc_String MDC_STRING_UNINIT = { 0 };

enum {
  kInitialCapacity = 4
};

struct Mdc_String* Mdc_String_InitEmpty(struct Mdc_String* str) {
  str->capacity_ = kInitialCapacity;

  str->str_ = malloc(str->capacity_ * sizeof(str->str_[0]));
  if (str->str_ == NULL) {
    goto return_bad;
  }

  str->length_ = 0;
  str->str_[0] = '\0';

  return str;

return_bad:
  *str = MDC_STRING_UNINIT;

  return NULL;
}

struct Mdc_String* Mdc_String_InitFromChar(
    struct Mdc_String* str,
    size_t count,
    char ch
) {
  str->capacity_ = count + 1;

  str->str_ = malloc(str->capacity_ * sizeof(str->str_[0]));
  if (str->str_ == NULL) {
    goto return_bad;
  }

  str->length_ = count;

  Mdc_CharTraits_AssignStr(&str->str_[0], count, ch);
  str->str_[count] = '\0';

  return str;

return_bad:
  *str = MDC_STRING_UNINIT;

  return NULL;
}

struct Mdc_String* Mdc_String_InitStrTail(
    struct Mdc_String* str,
    const struct Mdc_String* src,
    size_t pos
) {
  return Mdc_String_InitSubstr(str, src, pos, str->length_ - pos);
}

struct Mdc_String* Mdc_String_InitSubstr(
    struct Mdc_String* str,
    const struct Mdc_String* src,
    size_t pos,
    size_t count
) {
  if (count == Mdc_String_npos) {
    count = src->length_;
  }

  return Mdc_String_InitFromCStrTop(
      str,
      &src->str_[pos],
      count
  );
}

struct Mdc_String* Mdc_String_InitFromCStr(
    struct Mdc_String* str,
    const char* c_str
) {
  return Mdc_String_InitFromCStrTop(
      str,
      c_str,
      Mdc_CharTraits_LengthStr(c_str)
  );
}

struct Mdc_String* Mdc_String_InitFromCStrTop(
    struct Mdc_String* str,
    const char* c_str,
    size_t count
) {
  str->capacity_ = count + 1;

  str->str_ = malloc(str->capacity_ * sizeof(str->str_[0]));
  if (str->str_ == NULL) {
    goto return_bad;
  }

  str->length_ = count;

  Mdc_CharTraits_CopyStr(&str->str_[0], &c_str[0], count);
  str->str_[count] = '\0';

  return str;

return_bad:
  *str = MDC_STRING_UNINIT;

  return NULL;
}

struct Mdc_String* Mdc_String_InitConcatStrCopyWithStrCopy(
    struct Mdc_String* str,
    const struct Mdc_String* src1,
    const struct Mdc_String* src2
) {
  str->capacity_ = src1->length_ + src2->length_ + 1;

  str->str_ = malloc(str->capacity_ * sizeof(str->str_[0]));
  if (str->str_ == NULL) {
    goto return_bad;
  }

  str->length_ = src1->length_ + src2->length_;

  Mdc_CharTraits_CopyStr(&str->str_[0], &src1->str_[0], src1->length_);
  Mdc_CharTraits_CopyStr(
      &str->str_[src1->length_],
      &src2->str_[0],
      src2->length_
  );
  str->str_[str->length_] = '\0';

  return str;

return_bad:
  *str = MDC_STRING_UNINIT;

  return NULL;
}

struct Mdc_String* Mdc_String_InitConcatStrCopyWithCStr(
    struct Mdc_String* str,
    const struct Mdc_String* src1,
    const char* src2
) {
  const size_t src2_length = Mdc_CharTraits_LengthStr(src2);

  str->capacity_ = src1->length_ + src2_length + 1;

  str->str_ = malloc(str->capacity_ * sizeof(str->str_[0]));
  if (str->str_ == NULL) {
    goto return_bad;
  }

  str->length_ = src1->length_ + src2_length;

  Mdc_CharTraits_CopyStr(&str->str_[0], &src1->str_[0], src1->length_);
  Mdc_CharTraits_CopyStr(&str->str_[src1->length_], &src2[0], src2_length);
  str->str_[str->length_] = '\0';

  return str;

return_bad:
  *str = MDC_STRING_UNINIT;

  return NULL;
}

struct Mdc_String* Mdc_String_InitConcatStrCopyWithChar(
    struct Mdc_String* str,
    const struct Mdc_String* src1,
    char src2
) {
  str->capacity_ = src1->length_ + 2;

  str->str_ = malloc(str->capacity_ * sizeof(str->str_[0]));
  if (str->str_ == NULL) {
    goto return_bad;
  }

  str->length_ = src1->length_ + 1;

  Mdc_CharTraits_CopyStr(&str->str_[0], &src1->str_[0], src1->length_);
  Mdc_CharTraits_AssignChar(&str->str_[src1->length_], &src2);
  str->str_[str->length_] = '\0';

  return str;

return_bad:
  *str = MDC_STRING_UNINIT;

  return NULL;
}

struct Mdc_String* Mdc_String_InitConcatStrWithStrCopy(
    struct Mdc_String* str,
    struct Mdc_String* src1,
    const struct Mdc_String* src2
) {
  str->capacity_ = src1->length_ + src2->length_ + 1;

  if (str->capacity_ > src1->capacity_) {
    str->str_ = realloc(src1->str_, str->capacity_ * sizeof(str->str_[0]));
    if (str->str_ == NULL) {
      goto return_bad;
    }
  } else {
    str->str_ = src1->str_;
    str->capacity_ = src1->capacity_;
  }

  str->length_ = src1->length_ + src2->length_;
  
  Mdc_CharTraits_CopyStr(
      &str->str_[src1->length_],
      &src2->str_[0],
      src1->length_
  );
  str->str_[str->length_] = '\0';

  *src1 = MDC_STRING_UNINIT;

  return str;

return_bad:
  *str = MDC_STRING_UNINIT;

  return NULL;
}

struct Mdc_String* Mdc_String_InitConcatStrWithCStr(
    struct Mdc_String* str,
    struct Mdc_String* src1,
    const char* src2
) {
  const size_t src2_length = Mdc_CharTraits_LengthStr(src2);

  str->capacity_ = src1->length_ + src2_length + 1;

  if (str->capacity_ > src1->capacity_) {
    str->str_ = realloc(src1->str_, str->capacity_ * sizeof(str->str_[0]));
    if (str->str_ == NULL) {
      goto return_bad;
    }
  } else {
    str->str_ = src1->str_;
    str->capacity_ = src1->capacity_;
  }

  str->length_ = src1->length_ + src2_length;
  
  Mdc_CharTraits_CopyStr(&str->str_[src1->length_], &src2[0], src1->length_);
  str->str_[str->length_] = '\0';

  *src1 = MDC_STRING_UNINIT;

  return str;

return_bad:
  *str = MDC_STRING_UNINIT;

  return NULL;
}

struct Mdc_String* Mdc_String_InitConcatStrWithChar(
    struct Mdc_String* str,
    struct Mdc_String* src1,
    char src2
) {
  str->capacity_ = src1->length_ + 2;

  if (str->capacity_ > src1->capacity_) {
    str->str_ = realloc(src1->str_, str->capacity_ * sizeof(str->str_[0]));
    if (str->str_ == NULL) {
      goto return_bad;
    }
  } else {
    str->str_ = src1->str_;
    str->capacity_ = src1->capacity_;
  }

  str->length_ = src1->length_ + 1;
  
  Mdc_CharTraits_AssignChar(&str->str_[src1->length_], &src2);
  str->str_[str->length_] = '\0';

  *src1 = MDC_STRING_UNINIT;

  return str;

return_bad:
  *str = MDC_STRING_UNINIT;

  return NULL;
}

struct Mdc_String* Mdc_String_InitConcatCStrWithStrCopy(
    struct Mdc_String* str,
    const char* src1,
    const struct Mdc_String* src2
) {
  const size_t src1_length = Mdc_CharTraits_LengthStr(src1);

  str->capacity_ = src1_length + src2->length_ + 1;

  str->str_ = malloc(str->capacity_ * sizeof(str->str_[0]));
  if (str->str_ == NULL) {
    goto return_bad;
  }

  Mdc_CharTraits_CopyStr(&str->str_[0], &src1[0], src1_length);
  Mdc_CharTraits_CopyStr(
      &str->str_[src1_length],
      &src2->str_[0],
      src2->length_
  );
  str->str_[str->length_] = '\0';

  return str;

return_bad:
  *str = MDC_STRING_UNINIT;

  return NULL;
}

struct Mdc_String* Mdc_String_InitConcatCStrWithStr(
    struct Mdc_String* str,
    const char* src1,
    struct Mdc_String* src2
) {
  const size_t src1_length = Mdc_CharTraits_LengthStr(src1);

  str->capacity_ = src1_length + src2->length_ + 1;

  if (str->capacity_ > src2->capacity_) {
    str->str_ = malloc(str->capacity_ * sizeof(str->str_[0]));
    if (str->str_ == NULL) {
      goto return_bad;
    }
  } else {
    str->str_ = src2->str_;
    str->capacity_ = src2->capacity_;
  }

  str->length_ = src1_length + src2->length_;

  Mdc_CharTraits_MoveStr(
      &str->str_[src1_length],
      &src2->str_[0],
      src2->length_
  );
  Mdc_CharTraits_CopyStr(&str->str_[0], &src1[0], src1_length);
  str->str_[str->length_] = '\0';

  *src2 = MDC_STRING_UNINIT;

  return str;

return_bad:
  *str = MDC_STRING_UNINIT;

  return NULL;
}

struct Mdc_String* Mdc_String_InitConcatCharWithStrCopy(
    struct Mdc_String* str,
    char src1,
    const struct Mdc_String* src2
) {
  str->capacity_ = src2->length_ + 2;

  str->str_ = malloc(str->capacity_ * sizeof(str->str_[0]));
  if (str->str_ == NULL) {
    goto return_bad;
  }

  str->length_ = src2->length_ + 1;

  Mdc_CharTraits_AssignChar(&str->str_[0], &src1);
  Mdc_CharTraits_CopyStr(&str->str_[1], &src2->str_[0], src2->length_);
  str->str_[str->length_] = '\0';

  return str;

return_bad:
  *str = MDC_STRING_UNINIT;

  return NULL;
}

struct Mdc_String* Mdc_String_InitConcatCharWithStr(
    struct Mdc_String* str,
    char src1,
    struct Mdc_String* src2
) {
  str->capacity_ = src2->length_ + 2;

  if (str->capacity_ > src2->capacity_) {
    str->str_ = malloc(str->capacity_ * sizeof(str->str_[0]));
    if (str->str_ == NULL) {
      goto return_bad;
    }
  } else {
    str->str_ = src2->str_;
    str->capacity_ = src2->capacity_;
  }

  str->length_ = src2->length_ + 1;

  Mdc_CharTraits_MoveStr(&str->str_[1], &src2->str_[0], src2->length_);
  Mdc_CharTraits_AssignChar(&str->str_[0], &src1);
  str->str_[str->length_] = '\0';

  *src2 = MDC_STRING_UNINIT;

  return str;

return_bad:
  *str = MDC_STRING_UNINIT;

  return NULL;
}

struct Mdc_String* Mdc_String_InitCopy(
    struct Mdc_String* dest,
    const struct Mdc_String* src
) {
  return Mdc_String_InitSubstr(dest, src, 0, Mdc_String_npos);
}

struct Mdc_String* Mdc_String_InitMove(
    struct Mdc_String* dest,
    struct Mdc_String* src
) {
  *dest = *src;
  *src = MDC_STRING_UNINIT;

  return dest;
}

void Mdc_String_Deinit(struct Mdc_String* str) {
  if (str->str_ != NULL) {
    free(str->str_);
  }

  *str = MDC_STRING_UNINIT;
}

char* Mdc_String_Access(struct Mdc_String* str, size_t pos) {
  return (char*) Mdc_String_AccessConst(str, pos);
}

const char* Mdc_String_AccessConst(
    const struct Mdc_String* str,
    size_t pos
) {
  return &str->str_[pos];
}

char* Mdc_String_At(struct Mdc_String* str, size_t pos) {
  return (char*) Mdc_String_AtConst(str, pos);
}

const char* Mdc_String_AtConst(const struct Mdc_String* str, size_t pos) {
  if (pos < 0 || pos >= str->length_) {
    goto return_bad;
  }

  return &str->str_[pos];

return_bad:
  return NULL;
}

struct Mdc_String* Mdc_String_AppendChar(
    struct Mdc_String* dest,
    size_t count,
    char ch
) {
  size_t new_length;
  size_t new_capacity;

  char* end;

  new_length = dest->length_ + count;
  new_capacity = dest->capacity_;

  /* Increase capacity if needed. */
  if (new_length >= dest->capacity_) {
    while (new_capacity <= new_length) {
      new_capacity *= 2;
    }

    Mdc_String_Reserve(dest, new_capacity);

    if (dest->capacity_ < new_capacity) {
      goto return_bad;
    }
  }

  end = Mdc_String_Back(dest) + 1;

  Mdc_CharTraits_AssignStr(end, count, ch);
  end[count] = '\0';

  dest->length_ = new_length;

  return dest;

return_bad:
  return NULL;
}

struct Mdc_String* Mdc_String_AppendStr(
    struct Mdc_String* dest,
    const struct Mdc_String* src
) {
  return Mdc_String_AppendStrTail(
      dest,
      src,
      0
  );
}

struct Mdc_String* Mdc_String_AppendStrTail(
    struct Mdc_String* dest,
    const struct Mdc_String* src,
    size_t pos
) {
  return Mdc_String_AppendSubstr(
      dest,
      src,
      pos,
      Mdc_String_npos
  );
}

struct Mdc_String* Mdc_String_AppendSubstr(
    struct Mdc_String* dest,
    const struct Mdc_String* src,
    size_t pos,
    size_t count
) {
  if (count == Mdc_String_npos) {
    count = src->length_;
  }

  return Mdc_String_AppendCStrTop(
      dest,
      &src->str_[pos],
      count
  );
}

struct Mdc_String* Mdc_String_AppendCStr(
    struct Mdc_String* dest,
    const char* src
) {
  return Mdc_String_AppendCStrTop(
      dest,
      src,
      Mdc_CharTraits_LengthStr(src)
  );
}

struct Mdc_String* Mdc_String_AppendCStrTop(
    struct Mdc_String* dest,
    const char* src,
    size_t count
) {
  size_t new_length;
  size_t new_capacity;

  char* end;

  new_length = dest->length_ + count;
  new_capacity = dest->capacity_;

  /* Increase capacity if needed. */
  if (new_length >= dest->capacity_) {
    while (new_capacity <= new_length) {
      new_capacity *= 2;
    }

    Mdc_String_Reserve(dest, new_capacity);

    if (dest->capacity_ < new_capacity) {
      goto return_bad;
    }
  }

  end = Mdc_String_Back(dest) + 1;

  Mdc_CharTraits_MoveStr(end, src, count);
  end[count] = '\0';

  dest->length_ = new_length;

  return dest;

return_bad:
  return NULL;
}

char* Mdc_String_Back(struct Mdc_String* str) {
  return (char*) Mdc_String_BackConst(str);
}

const char* Mdc_String_BackConst(const struct Mdc_String* str) {
  return &str->str_[str->length_ - 1];
}

size_t Mdc_String_Capacity(const struct Mdc_String* str) {
  return str->capacity_;
}

int Mdc_String_Compare(
    const struct Mdc_String* str1,
    const struct Mdc_String* str2
) {
  return Mdc_CharTraits_CompareStr(
      str1->str_,
      str2->str_,
      str1->length_ + 1
  );
}

void Mdc_String_Clear(struct Mdc_String* str) {
  str->str_[0] = '\0';
  str->length_ = 0;
}

const char* Mdc_String_CStr(const struct Mdc_String* str) {
  return str->str_;
}

char* Mdc_String_Data(struct Mdc_String* str) {
  return (char*) Mdc_String_DataConst(str);
}

const char* Mdc_String_DataConst(const struct Mdc_String* str) {
  return Mdc_String_CStr(str);
}

bool Mdc_String_Empty(const struct Mdc_String* str) {
  return Mdc_String_Length(str) == 0;
}

bool Mdc_String_Equal(
    const struct Mdc_String* str1,
    const struct Mdc_String* str2
) {
  int compare_result;

  if (str1->length_ != str2->length_) {
    return false;
  }

  compare_result = Mdc_CharTraits_CompareStr(
      str1->str_,
      str2->str_,
      str1->length_
  );

  return (compare_result == 0);
}

char* Mdc_String_Front(struct Mdc_String* str) {
  return (char*) Mdc_String_FrontConst(str);
}

const char* Mdc_String_FrontConst(const struct Mdc_String* str) {
  return &str->str_[0];
}

size_t Mdc_String_Length(const struct Mdc_String* str) {
  return str->length_;
}

void Mdc_String_PopBack(struct Mdc_String* str) {
  str->length_ -= 1;
  str->str_[str->length_] = '\0';
}

void Mdc_String_PushBack(struct Mdc_String* str, char ch) {
  size_t new_length;
  size_t new_capacity;

  new_length = str->length_ + 1;

  if (new_length >= str->capacity_) {
    new_capacity = str->capacity_ * 2;

    Mdc_String_Reserve(str, new_capacity);
  }

  str->str_[str->length_] = ch;
  str->length_ += 1;
  str->str_[str->length_] = '\0';
}

void Mdc_String_Reserve(struct Mdc_String* str, size_t new_capacity) {
  if (new_capacity <= str->capacity_) {
    return;
  }

  char* realloc_cstring = realloc(
      str->str_, new_capacity * sizeof(str->str_[0])
  );
  if (realloc_cstring == NULL) {
    goto return_bad;
  }

  str->str_ = realloc_cstring;
  str->capacity_ = new_capacity;

  return;

return_bad:
  return;
}

void Mdc_String_ShrinkToFit(struct Mdc_String* str) {
  size_t new_cap;
  char* realloc_cstring;

  new_cap = str->length_ + 1;

  realloc_cstring = realloc(str->str_, new_cap * sizeof(str->str_[0]));
  if (realloc_cstring == NULL) {
    goto return_bad;
  }

  str->str_ = realloc_cstring;
  str->capacity_ = new_cap;

  return;

return_bad:
  return;
}

size_t Mdc_String_Size(const struct Mdc_String* str) {
  return Mdc_String_Length(str);
}

void Mdc_String_Swap(struct Mdc_String* str1, struct Mdc_String* str2) {
  struct Mdc_String temp;

  temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}
