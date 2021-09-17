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

#include "thread_tests.hpp"

#include <stddef.h>
#include <stdio.h>

#include <mdc/std/assert.h>
#include <mdc/std/mutex.hpp>
#include <mdc/std/threads.hpp>
#include "std_example_funcs/std_increment.hpp"

namespace mdc_test {
namespace std_test {
namespace {

enum {
  kOnceDefaultValue = 0,
  kOnceTargetValue = 42
};

static int once_value = kOnceDefaultValue;

static void SetOnceTarget(void) {
  size_t i;

  for (i = 0; i < kOnceTargetValue; i += 1) {
    Increment(&once_value);
  }
}

static int SetOnceTargetMultithread(void* arg) {
  enum {
    kIterationCount = 8
  };

  size_t i;

  ::std::once_flag* flag = reinterpret_cast< ::std::once_flag*>(arg);

  for (i = 0; i < kIterationCount; i += 1) {
    ::std::call_once(*flag, &SetOnceTarget);
  }

  return 0;
}

static void AssertCallOnceSingle(void) {
  ::std::once_flag flag;

  once_value = kOnceDefaultValue;

  SetOnceTargetMultithread(&flag);

  assert(once_value == kOnceTargetValue);
}

static void AssertCallOnceMulti(void) {
  enum {
    kThreadsCount = 256
  };

  size_t i;

  ::std::thread* threads[kThreadsCount];
  ::std::once_flag flag;

  once_value = kOnceDefaultValue;

  for (i = 0; i < kThreadsCount; i += 1) {
    threads[i] = new ::std::thread(&SetOnceTargetMultithread, &flag);
  }

  for (i = 0; i < kThreadsCount; i += 1) {
    threads[i]->join();
    delete threads[i];
  }

  assert(once_value == kOnceTargetValue);
}

} // namespace

void OnceFlag_RunTests() {
  AssertCallOnceSingle();
  AssertCallOnceMulti();
}

} // namespace std_test
} // namespace mdc_test
