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

#if defined(_MSC_VER)

static void CallAsActiveThread(once_flag* flag, void (*func)(void)) {
  flag->passive_thread_event_ = CreateEventA(NULL, TRUE, FALSE, NULL);
  flag->is_event_init_ = TRUE;

  func();
  flag->is_finished_ = TRUE;

  SetEvent(flag->passive_thread_event_);
}

static void CallAsPassiveThread(once_flag* flag) {
  while (!flag->is_event_init_) {
    /* Spinlock due to uninited state */
  }

  WaitForSingleObject(flag->passive_thread_event_, INFINITE);
}

void call_once(once_flag* flag, void (*func)(void)) {
  LONG has_active_thread;

  if (flag->is_finished_) {
    return;
  }

  has_active_thread = InterlockedExchange(&flag->has_active_thread_, 1);

  if (has_active_thread == 0) {
    /* This is the active thread. */
    CallAsActiveThread(flag, func);
  } else {
    /* This is a passive thread. */
    CallAsPassiveThread(flag);
  }
}

#elif defined(__GNUC__)

void call_once(once_flag* flag, void (*func)(void)) {
  pthread_once(flag, func);
}

#endif

#endif /* __STDC_VERSION__ < 201112L || defined(__STDC_NO_THREADS__) */
