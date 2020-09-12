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

#include "../../../include/mdc/object/short_object.h"

#include "../../../include/mdc/std/threads.h"

/**
 * Static
 */

/**
 * Object initialization/deinitialization
 */

#define MDC_SHORT_UNINIT { 0 }

static const struct Mdc_Short Mdc_Short_kUninit = MDC_SHORT_UNINIT;

/**
 * External
 */

/**
 * Initialization/deinitialization
 */

static struct Mdc_Short* Mdc_Short_Init(struct Mdc_Short* shrt) {
  return shrt;
}

struct Mdc_Short* Mdc_Short_InitDefault(struct Mdc_Short* shrt) {
  const struct Mdc_Short* init_short;

  init_short = Mdc_Short_Init(shrt);
  if (init_short != shrt) {
    goto return_bad;
  }

  shrt->value_ = 0;

  return shrt;

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_InitFromValue(
    struct Mdc_Short* shrt,
    short value
) {
  shrt->value_ = value;

  return shrt;
}

struct Mdc_Short* Mdc_Short_InitCopy(
    struct Mdc_Short* dest,
    const struct Mdc_Short* src
) {
  const struct Mdc_Short* init_short;

  init_short = Mdc_Short_Init(dest);
  if (init_short != dest) {
    goto return_bad;
  }

  dest->value_ = src->value_;

  return dest;

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_InitMove(
    struct Mdc_Short* dest,
    struct Mdc_Short* src
) {
  const struct Mdc_Short* init_short;

  init_short = Mdc_Short_Init(dest);
  if (init_short != dest) {
    goto return_bad;
  }

  dest->value_ = src->value_;
  src->value_ = 0;

  return dest;

return_bad:
  return NULL;
}

void Mdc_Short_Deinit(struct Mdc_Short* shrt) {
  *shrt = Mdc_Short_kUninit;
}

/**
 * Assignment functions
 */

struct Mdc_Short* Mdc_Short_AssignCopy(
    struct Mdc_Short* dest,
    const struct Mdc_Short* src
) {
  struct Mdc_Short temp;
  const struct Mdc_Short* init_temp;
  const struct Mdc_Short* assign_dest;

  init_temp = Mdc_Short_InitCopy(&temp, src);
  if (init_temp != &temp) {
    goto return_bad;
  }

  assign_dest = Mdc_Short_AssignMove(dest, &temp);
  if (assign_dest != dest) {
    goto deinit_temp;
  }

  Mdc_Short_Deinit(&temp);

  return dest;

deinit_temp:
  Mdc_Short_Deinit(&temp);

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_AssignMove(
    struct Mdc_Short* dest,
    struct Mdc_Short* src
) {
  dest->value_ = src->value_;
  src->value_ = 0;

  return dest;
}

/**
 * Increment/decrement operators
 */

struct Mdc_Short* Mdc_Short_PreIncrement(
    struct Mdc_Short* shrt
) {
  shrt->value_ += 1;

  return shrt;
}

struct Mdc_Short* Mdc_Short_PreDecrement(
    struct Mdc_Short* shrt
) {
  shrt->value_ -= 1;

  return shrt;
}

struct Mdc_Short* Mdc_Short_PostIncrement(
    struct Mdc_Short* out,
    struct Mdc_Short* in
) {
  const struct Mdc_Short* init_out;

  init_out = Mdc_Short_InitFromValue(out, in->value_);
  if (init_out != out) {
    goto return_bad;
  }

  in->value_ += 1;

  return out;

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_PostDecrement(
    struct Mdc_Short* out,
    struct Mdc_Short* in
) {
  const struct Mdc_Short* init_out;

  init_out = Mdc_Short_InitFromValue(out, in->value_);
  if (init_out != out) {
    goto return_bad;
  }

  in->value_ -= 1;

  return out;

return_bad:
  return NULL;
}

/**
 * Arithmetic operators
 */

struct Mdc_Short* Mdc_Short_Add(
    struct Mdc_Short* out,
    const struct Mdc_Short* op1,
    const struct Mdc_Short* op2
) {
  const struct Mdc_Short* init_out;

  init_out = Mdc_Short_InitFromValue(
      out,
      Mdc_Short_GetValue(op1) + Mdc_Short_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_Subtract(
    struct Mdc_Short* out,
    const struct Mdc_Short* op1,
    const struct Mdc_Short* op2
) {
  const struct Mdc_Short* init_out;

  init_out = Mdc_Short_InitFromValue(
      out,
      Mdc_Short_GetValue(op1) - Mdc_Short_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_Multiply(
    struct Mdc_Short* out,
    const struct Mdc_Short* op1,
    const struct Mdc_Short* op2
) {
  const struct Mdc_Short* init_out;

  init_out = Mdc_Short_InitFromValue(
      out,
      Mdc_Short_GetValue(op1) * Mdc_Short_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_Divide(
    struct Mdc_Short* out,
    const struct Mdc_Short* op1,
    const struct Mdc_Short* op2
) {
  const struct Mdc_Short* init_out;

  init_out = Mdc_Short_InitFromValue(
      out,
      Mdc_Short_GetValue(op1) / Mdc_Short_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_Modulo(
    struct Mdc_Short* out,
    const struct Mdc_Short* op1,
    const struct Mdc_Short* op2
) {
  const struct Mdc_Short* init_out;

  init_out = Mdc_Short_InitFromValue(
      out,
      Mdc_Short_GetValue(op1) % Mdc_Short_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_BitwiseNot(
    struct Mdc_Short* out,
    const struct Mdc_Short* in
) {
  const struct Mdc_Short* init_out;

  init_out = Mdc_Short_InitFromValue(
      out,
      ~Mdc_Short_GetValue(in)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_BitwiseAnd(
    struct Mdc_Short* out,
    const struct Mdc_Short* op1,
    const struct Mdc_Short* op2
) {
  const struct Mdc_Short* init_out;

  init_out = Mdc_Short_InitFromValue(
      out,
      Mdc_Short_GetValue(op1) & Mdc_Short_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_BitwiseOr(
    struct Mdc_Short* out,
    const struct Mdc_Short* op1,
    const struct Mdc_Short* op2
) {
  const struct Mdc_Short* init_out;

  init_out = Mdc_Short_InitFromValue(
      out,
      Mdc_Short_GetValue(op1) | Mdc_Short_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_BitwiseXor(
    struct Mdc_Short* out,
    const struct Mdc_Short* op1,
    const struct Mdc_Short* op2
) {
  const struct Mdc_Short* init_out;

  init_out = Mdc_Short_InitFromValue(
      out,
      Mdc_Short_GetValue(op1) ^ Mdc_Short_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_BitwiseLeftShift(
    struct Mdc_Short* out,
    const struct Mdc_Short* op1,
    const struct Mdc_Short* op2
) {
  const struct Mdc_Short* init_out;

  init_out = Mdc_Short_InitFromValue(
      out,
      Mdc_Short_GetValue(op1) << Mdc_Short_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Short* Mdc_Short_BitwiseRightShift(
    struct Mdc_Short* out,
    const struct Mdc_Short* op1,
    const struct Mdc_Short* op2
) {
  const struct Mdc_Short* init_out;

  init_out = Mdc_Short_InitFromValue(
      out,
      Mdc_Short_GetValue(op1) >> Mdc_Short_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

/**
 * Comparison operators
 */

bool Mdc_Short_Equal(
    const struct Mdc_Short* short1,
    const struct Mdc_Short* short2
) {
  return Mdc_Short_GetValue(short1) == Mdc_Short_GetValue(short2);
}

bool Mdc_Short_EqualValue(
    const struct Mdc_Short* shrt,
    short value
) {
  return Mdc_Short_GetValue(shrt) == value;
}

int Mdc_Short_Compare(
    const struct Mdc_Short* short1,
    const struct Mdc_Short* short2
) {
  return Mdc_Short_GetValue(short1) - Mdc_Short_GetValue(short2);
}

int Mdc_Short_CompareValue(
    const struct Mdc_Short* shrt,
    short value
) {
  return Mdc_Short_GetValue(shrt) - value;
}

/**
 * Etc. functions
 */

size_t Mdc_Short_Hash(const struct Mdc_Short* shrt) {
  return Mdc_Short_GetValue(shrt) % (size_t) -1;
}

void Mdc_Short_Swap(
    struct Mdc_Short* short1,
    struct Mdc_Short* short2
) {
  struct Mdc_Short temp;

  temp = *short1;
  *short1 = *short2;
  *short2 = temp;
}

short Mdc_Short_GetValue(const struct Mdc_Short* shrt) {
  return shrt->value_;
}

void Mdc_Short_SetValue(struct Mdc_Short* shrt, short value) {
  shrt->value_ = value;
}
