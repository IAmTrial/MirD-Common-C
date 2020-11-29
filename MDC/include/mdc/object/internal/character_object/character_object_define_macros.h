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

#ifndef MDC_C_OBJECT_INTERNAL_CHARACTER_OBJECT_CHARACTER_OBJECT_DEFINE_MACROS_H_
#define MDC_C_OBJECT_INTERNAL_CHARACTER_OBJECT_CHARACTER_OBJECT_DEFINE_MACROS_H_

#include "../../../macro/template_macro.h"
#include "../../../std/stdbool.h"
#include "character_object_typedef.h"
#include "character_object_name_macros.h"

/**
 * Initialize / Deinitialize
 */

#define MDC_DEFINE_CHARACTER_INIT_DEFAULT(T_CharacterT) \
    MDC_T(T_CharacterT) Mdc_Character_InitDefault(T_CharacterT)(void) { \
      /* Should actually return an unspecified value. */ \
      return 0; \
    }

#define MDC_DEFINE_CHARACTER_INIT_FROM_VALUE(T_CharacterT) \
    MDC_T(T_CharacterT) Mdc_Character_InitFromValue(T_CharacterT)( \
        MDC_T(T_CharacterT) value \
    ) { \
      return value; \
    }

#define MDC_DEFINE_CHARACTER_INIT_COPY(T_CharacterT) \
    MDC_T(T_CharacterT) Mdc_Character_InitCopy(T_CharacterT)( \
        MDC_T_PC(T_CharacterT) character \
    ) { \
      return *character; \
    }

#define MDC_DEFINE_CHARACTER_INIT_MOVE(T_CharacterT) \
    MDC_T(T_CharacterT) Mdc_Character_InitMove(T_CharacterT)( \
        MDC_T_P(T_CharacterT) character \
    ) { \
      return *character; \
    }

#define MDC_DEFINE_CHARACTER_DEINIT(T_CharacterT) \
    void Mdc_Character_Deinit(T_CharacterT)(MDC_T_P(T_CharacterT) character) { \
      /* This is left empty on purpose. There is nothing to do. */ \
    }

/**
 * Assignment
 */

#define MDC_DEFINE_CHARACTER_ASSIGN_COPY(T_CharacterT) \
    MDC_T_P(T_CharacterT) Mdc_Character_AssignCopy(T_CharacterT)( \
        MDC_T_P(T_CharacterT) dest, \
        MDC_T_PC(T_CharacterT) src \
    ) { \
      *dest = *src; \
      return dest; \
    }

#define MDC_DEFINE_CHARACTER_ASSIGN_MOVE(T_CharacterT) \
    MDC_T_P(T_CharacterT) Mdc_Character_AssignMove(T_CharacterT)( \
        MDC_T_P(T_CharacterT) dest, \
        MDC_T_P(T_CharacterT) src \
    ) { \
      *dest = *src; \
      return dest; \
    }

/**
 * Logical
 */

#define MDC_DEFINE_CHARACTER_LOGICAL_NOT(T_CharacterT) \
    bool Mdc_Character_LogicalNot(T_CharacterT)( \
        MDC_T_P(T_CharacterT) character \
    ) { \
      return Mdc_Character_LogicalNotConst(T_CharacterT)(character); \
    }

#define MDC_DEFINE_CHARACTER_LOGICAL_NOT_CONST(T_CharacterT) \
    bool Mdc_Character_LogicalNotConst(T_CharacterT)( \
        MDC_T_PC(T_CharacterT) character \
    ) { \
      return !(*character); \
    }

#define MDC_DEFINE_CHARACTER_LOGICAL_AND(T_CharacterT) \
    bool Mdc_Character_LogicalAnd(T_CharacterT)( \
        MDC_T_PC(T_CharacterT) character1, \
        MDC_T_PC(T_CharacterT) character2 \
    ) { \
      return (*character1) && (*character2); \
    }

#define MDC_DEFINE_CHARACTER_LOGICAL_OR(T_CharacterT) \
    bool Mdc_Character_LogicalOr(T_CharacterT)( \
        MDC_T_PC(T_CharacterT) character1, \
        MDC_T_PC(T_CharacterT) character2 \
    ) { \
      return (*character1) || (*character2); \
    }

/**
 * Comparison
 */

#define MDC_DEFINE_CHARACTER_EQUAL(T_CharacterT) \
    bool Mdc_Character_Equal(T_CharacterT)( \
        MDC_T_PC(T_CharacterT) character1, \
        MDC_T_PC(T_CharacterT) character2 \
    ) { \
      return (*character1) == (*character2); \
    }

#define MDC_DEFINE_CHARACTER_COMPARE(T_CharacterT) \
    int Mdc_Character_Compare(T_CharacterT)( \
        MDC_T_PC(T_CharacterT) character1, \
        MDC_T_PC(T_CharacterT) character2 \
    ) { \
      if (*character1 < *character2) { \
        return -1; \
      } else if (*character1 > *character2) { \
        return 1; \
      } else /* if (*character1 == *character2) */ { \
        return 0; \
      } \
    }

/**
 * General Functions
 */

#define MDC_DEFINE_CHARACTER_SWAP(T_CharacterT) \
    void Mdc_Character_Swap(T_CharacterT)( \
        MDC_T_P(T_CharacterT) character1, \
        MDC_T_P(T_CharacterT) character2 \
    ) { \
      MDC_T(T_CharacterT) temp_character; \
\
      temp_character = *character1; \
      *character1 = *character2; \
      *character2 = temp_character; \
    }

#define MDC_INTERNAL_DEFINE_CHARACTER_FUNCTIONS(T_CharacterT) \
    MDC_DEFINE_CHARACTER_INIT_DEFAULT(T_CharacterT) \
    MDC_DEFINE_CHARACTER_INIT_FROM_VALUE(T_CharacterT) \
    MDC_DEFINE_CHARACTER_INIT_COPY(T_CharacterT) \
    MDC_DEFINE_CHARACTER_INIT_MOVE(T_CharacterT) \
    MDC_DEFINE_CHARACTER_DEINIT(T_CharacterT) \
    MDC_DEFINE_CHARACTER_ASSIGN_COPY(T_CharacterT) \
    MDC_DEFINE_CHARACTER_ASSIGN_MOVE(T_CharacterT) \
    MDC_DEFINE_CHARACTER_LOGICAL_NOT(T_CharacterT) \
    MDC_DEFINE_CHARACTER_LOGICAL_NOT_CONST(T_CharacterT) \
    MDC_DEFINE_CHARACTER_LOGICAL_AND(T_CharacterT) \
    MDC_DEFINE_CHARACTER_LOGICAL_OR(T_CharacterT) \
    MDC_DEFINE_CHARACTER_EQUAL(T_CharacterT) \
    MDC_DEFINE_CHARACTER_COMPARE(T_CharacterT) \
    MDC_DEFINE_CHARACTER_SWAP(T_CharacterT)

#endif /* MDC_C_OBJECT_INTERNAL_CHARACTER_OBJECT_CHARACTER_OBJECT_DEFINE_MACROS_H_ */
