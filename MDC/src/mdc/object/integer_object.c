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

#include "../../../include/mdc/object/integer_object.h"

/**
 * Static
 */

#define MDC_INTEGER_UNINIT { 0 }

static const struct Mdc_Integer Mdc_Integer_kUninit =
    MDC_INTEGER_UNINIT;

/**
 * External
 */

/**
 * Initialization/deinitialization
 */

static struct Mdc_Integer* Mdc_Integer_Init(
    struct Mdc_Integer* integer
) {
  return integer;
}

struct Mdc_Integer* Mdc_Integer_InitDefault(
    struct Mdc_Integer* integer
) {
  struct Mdc_Integer* init_integer;

  init_integer = Mdc_Integer_Init(integer);
  if (init_integer != integer) {
    goto return_bad;
  }

  integer->value_ = 0;

  return integer;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_InitFromValue(
    struct Mdc_Integer* integer,
    int value
) {
  struct Mdc_Integer* init_integer;

  init_integer = Mdc_Integer_Init(integer);
  if (init_integer != integer) {
    goto return_bad;
  }

  integer->value_ = value;

  return integer;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_InitCopy(
    struct Mdc_Integer* dest,
    const struct Mdc_Integer* src
) {
  struct Mdc_Integer* init_dest;

  init_dest = Mdc_Integer_Init(dest);
  if (init_dest != dest) {
    goto return_bad;
  }

  dest->value_ = src->value_;

  return dest;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_InitMove(
    struct Mdc_Integer* dest,
    struct Mdc_Integer* src
) {
  struct Mdc_Integer* init_dest;

  init_dest = Mdc_Integer_Init(dest);
  if (init_dest != dest) {
    goto return_bad;
  }

  dest->value_ = src->value_;
  src->value_ = 0;

  return dest;

return_bad:
  return NULL;
}

void Mdc_Integer_Deinit(struct Mdc_Integer* integer) {
  *integer = Mdc_Integer_kUninit;
}

/**
 * Assignment functions
 */

struct Mdc_Integer* Mdc_Integer_AssignCopy(
    struct Mdc_Integer* dest,
    const struct Mdc_Integer* src
) {
  struct Mdc_Integer temp;
  struct Mdc_Integer* init_temp;
  struct Mdc_Integer* assign_dest;

  init_temp = Mdc_Integer_InitCopy(&temp, src);
  if (init_temp != &temp) {
    goto return_bad;
  }

  assign_dest = Mdc_Integer_AssignMove(dest, &temp);
  if (assign_dest != dest) {
    goto deinit_temp;
  }

  Mdc_Integer_Deinit(&temp);

  return dest;

deinit_temp:
  Mdc_Integer_Deinit(&temp);

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_AssignMove(
    struct Mdc_Integer* dest,
    struct Mdc_Integer* src
) {
  dest->value_ = src->value_;
  src->value_ = 0;

  return dest;
}

/**
 * Increment/decrement operators
 */

struct Mdc_Integer* Mdc_Integer_PreIncrement(
    struct Mdc_Integer* integer
) {
  integer->value_ += 1;

  return integer;
}

struct Mdc_Integer* Mdc_Integer_PreDecrement(
    struct Mdc_Integer* integer
) {
  integer->value_ -= 1;

  return integer;
}

struct Mdc_Integer* Mdc_Integer_PostIncrement(
    struct Mdc_Integer* out,
    struct Mdc_Integer* in
) {
  const struct Mdc_Integer* init_out;

  init_out = Mdc_Integer_InitFromValue(out, in->value_);
  if (init_out != out) {
    goto return_bad;
  }

  in->value_ += 1;

  return out;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_PostDecrement(
    struct Mdc_Integer* out,
    struct Mdc_Integer* in
) {
  const struct Mdc_Integer* init_out;

  init_out = Mdc_Integer_InitFromValue(out, in->value_);
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

struct Mdc_Integer* Mdc_Integer_Add(
    struct Mdc_Integer* out,
    const struct Mdc_Integer* op1,
    const struct Mdc_Integer* op2
) {
  const struct Mdc_Integer* init_out;

  init_out = Mdc_Integer_InitFromValue(
      out,
      Mdc_Integer_GetValue(op1) + Mdc_Integer_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_Subtract(
    struct Mdc_Integer* out,
    const struct Mdc_Integer* op1,
    const struct Mdc_Integer* op2
) {
  const struct Mdc_Integer* init_out;

  init_out = Mdc_Integer_InitFromValue(
      out,
      Mdc_Integer_GetValue(op1) - Mdc_Integer_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_Multiply(
    struct Mdc_Integer* out,
    const struct Mdc_Integer* op1,
    const struct Mdc_Integer* op2
) {
  const struct Mdc_Integer* init_out;

  init_out = Mdc_Integer_InitFromValue(
      out,
      Mdc_Integer_GetValue(op1) * Mdc_Integer_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_Divide(
    struct Mdc_Integer* out,
    const struct Mdc_Integer* op1,
    const struct Mdc_Integer* op2
) {
  const struct Mdc_Integer* init_out;

  init_out = Mdc_Integer_InitFromValue(
      out,
      Mdc_Integer_GetValue(op1) / Mdc_Integer_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_Modulo(
    struct Mdc_Integer* out,
    const struct Mdc_Integer* op1,
    const struct Mdc_Integer* op2
) {
  const struct Mdc_Integer* init_out;

  init_out = Mdc_Integer_InitFromValue(
      out,
      Mdc_Integer_GetValue(op1) % Mdc_Integer_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_BitwiseNot(
    struct Mdc_Integer* out,
    const struct Mdc_Integer* in
) {
  const struct Mdc_Integer* init_out;

  init_out = Mdc_Integer_InitFromValue(
      out,
      ~Mdc_Integer_GetValue(in)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_BitwiseAnd(
    struct Mdc_Integer* out,
    const struct Mdc_Integer* op1,
    const struct Mdc_Integer* op2
) {
  const struct Mdc_Integer* init_out;

  init_out = Mdc_Integer_InitFromValue(
      out,
      Mdc_Integer_GetValue(op1) & Mdc_Integer_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_BitwiseOr(
    struct Mdc_Integer* out,
    const struct Mdc_Integer* op1,
    const struct Mdc_Integer* op2
) {
  const struct Mdc_Integer* init_out;

  init_out = Mdc_Integer_InitFromValue(
      out,
      Mdc_Integer_GetValue(op1) | Mdc_Integer_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_BitwiseXor(
    struct Mdc_Integer* out,
    const struct Mdc_Integer* op1,
    const struct Mdc_Integer* op2
) {
  const struct Mdc_Integer* init_out;

  init_out = Mdc_Integer_InitFromValue(
      out,
      Mdc_Integer_GetValue(op1) ^ Mdc_Integer_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_BitwiseLeftShift(
    struct Mdc_Integer* out,
    const struct Mdc_Integer* op1,
    const struct Mdc_Integer* op2
) {
  const struct Mdc_Integer* init_out;

  init_out = Mdc_Integer_InitFromValue(
      out,
      Mdc_Integer_GetValue(op1) << Mdc_Integer_GetValue(op2)
  );
  if (init_out != out) {
    goto return_bad;
  }

  return out;

return_bad:
  return NULL;
}

struct Mdc_Integer* Mdc_Integer_BitwiseRightShift(
    struct Mdc_Integer* out,
    const struct Mdc_Integer* op1,
    const struct Mdc_Integer* op2
) {
  const struct Mdc_Integer* init_out;

  init_out = Mdc_Integer_InitFromValue(
      out,
      Mdc_Integer_GetValue(op1) >> Mdc_Integer_GetValue(op2)
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

bool Mdc_Integer_Equal(
    const struct Mdc_Integer* integer1,
    const struct Mdc_Integer* integer2
) {
  return integer1->value_ == integer2->value_;
}

bool Mdc_Integer_EqualValue(
    const struct Mdc_Integer* integer,
    int value
) {
  return integer->value_ == value;
}

int Mdc_Integer_Compare(
    const struct Mdc_Integer* integer1,
    const struct Mdc_Integer* integer2
) {
  return Mdc_Integer_GetValue(integer1) - Mdc_Integer_GetValue(integer2);
}

int Mdc_Integer_CompareValue(
    const struct Mdc_Integer* integer,
    int value
) {
  return Mdc_Integer_GetValue(integer) - value;
}

/**
 * Etc. functions
 */

size_t Mdc_Integer_Hash(const struct Mdc_Integer* integer) {
  return Mdc_Integer_GetValue(integer) % (size_t) -1;
}

void Mdc_Integer_Swap(
    struct Mdc_Integer* integer1,
    struct Mdc_Integer* integer2
) {
  struct Mdc_Integer temp;

  temp = *integer1;
  *integer1 = *integer2;
  *integer2 = temp;
}

int Mdc_Integer_GetValue(const struct Mdc_Integer* integer) {
  return integer->value_;
}

void Mdc_Integer_SetValue(struct Mdc_Integer* integer, int value) {
  integer->value_ = value;
}
