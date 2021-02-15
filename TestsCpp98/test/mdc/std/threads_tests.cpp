/**
 * Mir Drualga Common For C++98
 * Copyright (C) 2021  Mir Drualga
 *
 * This file is part of Mir Drualga Common For C++98.
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

#include "threads_tests.hpp"

#include <stddef.h>
#include <stdio.h>

#include <mdc/std/assert.h>
#include <mdc/std/threads.hpp>

namespace mdc_test {
namespace std_test {

static int Increment(void* value) {
  int* actual_value = (int*) value;
  
  // Separate operations on a copy forces a race condition.
  int temp = *actual_value;
  temp += 1;

#if defined(_MSC_VER)
  Sleep(1);
#elif defined(__GNUC__)
  usleep(1);
#endif

  *actual_value = temp;

  return 0;
}

static void AssertRaceCondition() {
  enum {
    kThreadsCount = 256
  };

  size_t i;

  ::std::thread* threads[kThreadsCount];

  int value = 0;

  for (i = 0; i < kThreadsCount; i += 1) {
    threads[i] = new ::std::thread(&Increment, &value);
  }

  for (i = 0; i < kThreadsCount; i += 1) {
    threads[i]->join();
    delete threads[i];
  }

  assert(value > 0);
  assert(value <= kThreadsCount);
}

void Threads_RunTests() {
  AssertRaceCondition();
}

} // namespace std_test
} // namespace mdc_test
