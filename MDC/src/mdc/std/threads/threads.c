/**
 * Mir Drualga Common For C
 * Copyright (C) 2020-2021  Mir Drualga
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

#if defined(_MSC_VER)

#include <process.h>

#include "../../../../include/mdc/malloc/malloc.h"

struct ThreadArgsWrapper {
  thrd_start_t func_;
  void* arg_;
};

static unsigned int __stdcall RunThreadFuncShim(void* arg_wrapper) {
  struct ThreadArgsWrapper args_wrapper_copy;
  int result;

  args_wrapper_copy = *(struct ThreadArgsWrapper*) arg_wrapper;
  Mdc_free(arg_wrapper);

  result = args_wrapper_copy.func_(args_wrapper_copy.arg_);

  return result;
}

int thrd_create(thrd_t* thrd, thrd_start_t func, void* arg) {
  struct ThreadArgsWrapper* args_wrapper;

  args_wrapper = Mdc_malloc(sizeof(*args_wrapper));

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
    Mdc_free(args_wrapper);

    return thrd_error;
  }

  return thrd_success;
}

int thrd_equal(thrd_t lhs, thrd_t rhs) {
  /* TODO (Mir Duralga): This does not work if the pseudo-handle is used! */
  return lhs == rhs;
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

#elif defined(__GNUC__)

#include <errno.h>
#include <sched.h>

#include "../../../../include/mdc/malloc/malloc.h"

struct ThreadArgsWrapper {
  thrd_start_t func_;
  void* arg_;
};

static void* thrd_wrap_func(void* arg_wrapper) {
  struct ThreadArgsWrapper args_wrapper_copy;

  args_wrapper_copy = *(struct ThreadArgsWrapper*) arg_wrapper;
  Mdc_free(arg_wrapper);

  return (void*) args_wrapper_copy.func_(args_wrapper_copy.arg_);
}

int thrd_create(thrd_t* thr, thrd_start_t func, void* arg) {
  struct ThreadArgsWrapper* arg_wrapper;
  int result;

  arg_wrapper = Mdc_malloc(sizeof(*arg_wrapper));
  if (arg_wrapper == NULL) {
    return ENOMEM;
  }

  arg_wrapper->func_ = func;
  arg_wrapper->arg_ = arg;

  result = pthread_create(thr, NULL, &thrd_wrap_func, arg_wrapper);

  if (result == 0) {
    return thrd_success;
  } else if (result == ENOMEM) {
    return thrd_nomem;
  } else {
    return thrd_error;
  }
}

int thrd_equal(thrd_t lhs, thrd_t rhs) {
  return pthread_equal(lhs, rhs);
}

thrd_t thrd_current(void) {
  return pthread_self();
}

void thrd_yield(void) {
  sched_yield();
}

void thrd_exit(int res) {
  pthread_exit((void*) res);
}

int thrd_detach(thrd_t thr) {
  int result;

  result = pthread_detach(thr);

  return (result == 0) ? thrd_success : thrd_error;
}

int thrd_join(thrd_t thr, int *res) {
  int result;

  result = pthread_join(thr, (void*) res);

  return (result == 0) ? thrd_success : thrd_error;
}

#endif

#endif /* __STDC_VERSION__ < 201112L || defined(__STDC_NO_THREADS__) */
