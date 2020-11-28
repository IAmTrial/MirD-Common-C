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

#ifndef MDC_C_OBJECT_OBJECT_H_
#define MDC_C_OBJECT_OBJECT_H_

/**
 * The following macro arg prefix indicates the following:
 * R: return type, specifies the complete identifier of the type or
 *    any alias (e.g. const struct Mdc_String*, MDC_T_PC(Mdc_String)).
 * T: type, specifies the tag name of the type identifier
 *    (e.g. Mdc_String). Typedef aliases will fail.
 * A: arg, specifies the MDC typedef names using MDC_T family of
 *    qualifier function-macros (e.g. MDC_T_PC(Mdc_String)).
 * Q: qualifier function-macro name, specifies the name of the MDC_T
 *    qualifier function-macro to use in combination with a successive
 *    "T" arg (e.g. MDC_T, MDC_T_PCV). This is required for template
 *    types.
 *
 * Only the first prefix applies. All other successive characters are
 * purely used for naming (e.g. TA1 uses the "T" rule).
 *
 * All T can be converted to A with Q or an explicit MDC_T
 * function-macro, and all A can be used in place of R.
 */

#include "internal/object_declare_macros.h"
#include "internal/object_name_macros.h"

#endif /* MDC_C_OBJECT_OBJECT_H_ */
