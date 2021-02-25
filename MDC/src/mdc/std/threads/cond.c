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

int cnd_init(cnd_t* cond) {
  cond->waiter_event_ = CreateEventA(NULL, TRUE, FALSE, NULL);

  if (cond->waiter_event_ == NULL) {
    goto bad_return;
  }

  cond->is_broadcast = FALSE;
  cond->has_signal_pass = TRUE;

  return thrd_success;

bad_return:
  return thrd_error;
}

void cnd_destroy(cnd_t* cond) {
  BOOL close_handle_result;

  close_handle_result = CloseHandle(cond->waiter_event_);
}

int cnd_signal(cnd_t* cond) {
  BOOL is_pulse_success;

  cond->is_broadcast = FALSE;
  cond->has_signal_pass = FALSE;

  is_pulse_success = PulseEvent(cond->waiter_event_);

  if (!is_pulse_success) {
    goto return_bad;
  }

  return thrd_success;

return_bad:
  return thrd_error;
}

int cnd_broadcast(cnd_t* cond) {
  BOOL is_pulse_success;

  cond->is_broadcast = TRUE;
  cond->has_signal_pass = FALSE;

  is_pulse_success = PulseEvent(cond->waiter_event_);

  if (!is_pulse_success) {
    goto return_bad;
  }

  return thrd_success;

return_bad:
  return thrd_error;
}

int cnd_wait(cnd_t* cond, mtx_t* mutex) {
  DWORD wait_result;
  LONG has_signal_pass;
  int mtx_unlock_result;
  int mtx_lock_result;

  /*
  * Infinitely wait, breaking out on a broadcast, or being the
  * first thread to interlock after the signal.
  */
  do {
    mtx_unlock_result = mtx_unlock(mutex);
    if (mtx_unlock_result != thrd_success) {
      goto return_bad;
    }

    wait_result = WaitForSingleObject(
        cond->waiter_event_,
        INFINITE
    );

    if (wait_result == WAIT_FAILED) {
      goto return_bad;
    }

    has_signal_pass = InterlockedExchange(&cond->has_signal_pass, 1);
  } while (has_signal_pass && cond->is_broadcast);

  mtx_lock_result = mtx_lock(mutex);

  if (mtx_lock_result != thrd_success) {
  }

  return thrd_success;

return_bad:
  return thrd_error;
}

#elif defined(__GNUC__)

#include <errno.h>

int cnd_init(cnd_t* cond) {
  int result;

  result = pthread_cond_init(cond, NULL);

  if (result == 0) {
    return thrd_success;
  } else if (result == ENOMEM) {
    return thrd_nomem;
  } else {
    return thrd_error;
  }
}

void cnd_destroy(cnd_t* cond) {
  pthread_cond_destroy(cond);
}

int cnd_signal(cnd_t* cond) {
  int result;

  result = pthread_cond_signal(cond);

  return (result == 0) ? thrd_success : thrd_error;
}

int cnd_broadcast(cnd_t* cond) {
  int result;

  result = pthread_cond_broadcast(cond);

  return (result == 0) ? thrd_success : thrd_error;
}

int cnd_wait(cnd_t* cond, mtx_t* mutex) {
  int result;

  result = pthread_cond_wait(cond, mutex);

  return (result == 0) ? thrd_success : thrd_error;
}

#endif

#endif /* __STDC_VERSION__ < 201112L || defined(__STDC_NO_THREADS__) */
