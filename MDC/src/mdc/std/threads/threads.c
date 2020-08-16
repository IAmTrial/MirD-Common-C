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

#include "../../../../include/mdc/std/threads.h"

#if __STDC_VERSION__ < 201112L || defined(__STDC_NO_THREADS__)

#include <process.h>
#include <stdlib.h>

struct ThreadArgsWrapper {
  thrd_start_t func_;
  void* arg_;
};

static unsigned int __stdcall RunThreadFuncShim(void* arg_wrapper) {
  struct ThreadArgsWrapper args_wrapper_copy;
  int result;

  args_wrapper_copy = *(struct ThreadArgsWrapper*) arg_wrapper;
  free(arg_wrapper);

  result = args_wrapper_copy.func_(args_wrapper_copy.arg_);

  return result;
}

int thrd_create(thrd_t* thrd, thrd_start_t func, void* arg) {
  struct ThreadArgsWrapper* args_wrapper;

  args_wrapper = malloc(sizeof(*args_wrapper));

  if (args_wrapper == NULL) {
    return thrd_nomem;
  }

  args_wrapper->func_ = func;
  args_wrapper->arg_ = arg;

  *thrd = (HANDLE) _beginthreadex(
      NULL,
      0,
      &RunThreadFuncShim,
      args_wrapper,
      0,
      NULL
  );

  if (*thrd == NULL) {
    free(args_wrapper);

    return thrd_error;
  }

  return thrd_success;
}

int thrd_equal(thrd_t lhs, thrd_t rhs) {
  DWORD lhs_id;
  DWORD rhs_id;

  lhs_id = GetThreadId(lhs);
  rhs_id = GetThreadId(rhs);

  return lhs_id == rhs_id;
}

thrd_t thrd_current(void) {
  return GetCurrentThread();
}

void thrd_yield(void) {
  Sleep(0);
}

void thrd_exit(int res) {
  _endthreadex(res);
}

int thrd_detach(thrd_t thr) {
  BOOL is_close_handle_success;

  is_close_handle_success = CloseHandle(thr);

  if (!is_close_handle_success) {
    goto return_bad;
  }

  return thrd_success;

return_bad:
  return thrd_error;
}

int thrd_join(thrd_t thr, int *res) {
  DWORD wait_result;
  BOOL is_get_exit_code_success;
  BOOL is_close_handle_success;

  wait_result = WaitForSingleObject(thr, INFINITE);
  if (wait_result == WAIT_FAILED) {
    goto return_bad;
  }

  if (res != NULL) {
    is_get_exit_code_success = GetExitCodeThread(thr, res);
    if (!is_get_exit_code_success) {
      goto return_bad;
    }
  }

  is_close_handle_success = CloseHandle(thr);
  if (!is_close_handle_success) {
    goto return_bad;
  }

  return thrd_success;

return_bad:
  return thrd_error;
}

#endif /* __STDC_VERSION__ < 201112L || defined(__STDC_NO_THREADS__) */
