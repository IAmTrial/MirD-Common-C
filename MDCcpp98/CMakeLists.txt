cmake_minimum_required(VERSION 3.10)

project(MDCcpp98)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED true)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Header and source files
set(INCLUDE_HEADERS
    "dllexport_define.inc"
    "dllexport_define.inc"
    "include/mdc/error/exit_on_error.hpp"
    "include/mdc/std/condition_variable.hpp"
    "include/mdc/std/mutex.hpp"
    "include/mdc/std/threads.hpp"
    "include/mdc/wchar_t/wide_decoding.hpp"
    "include/mdc/wchar_t/wide_encoding.hpp"
)

set(SRC_C
    "src/mdc/error/exit_on_error.cpp"
    "src/mdc/std/condition_variable/condition_variable.cpp"
    "src/mdc/std/condition_variable/condition_variable_any.cpp"
    "src/mdc/std/mutex/call_once.cpp"
    "src/mdc/std/mutex/mutex.cpp"
    "src/mdc/std/mutex/recursive_mutex.cpp"
    "src/mdc/std/threads/threads.cpp"
    "src/mdc/wchar_t/wide_decoding.cpp"
    "src/mdc/wchar_t/wide_encoding.cpp"
)

set(SRC_HEADERS)

# Output static LIB
add_library(libMDCcpp98 STATIC ${SRC_C} ${SRC_HEADERS} ${INCLUDE_HEADERS})

target_include_directories(
    libMDCcpp98
    PUBLIC "include"
)

target_link_libraries(libMDCcpp98 libMDCc)

add_dependencies(libMDCcpp98 libMDCc)

# Output DLL
add_library(MDCcpp98 SHARED ${SRC_C} ${SRC_HEADERS} ${INCLUDE_HEADERS})

target_compile_definitions(MDCcpp98 PRIVATE MDC_CPP98_DLLEXPORT)
target_compile_definitions(MDCcpp98 INTERFACE MDC_CPP98_DLLEXPORT)

target_include_directories(
    MDCcpp98
    PUBLIC "include"
)

target_link_libraries(MDCcpp98 libMDCc)
add_dependencies(MDCcpp98 libMDCc)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_C} ${INCLUDE_HEADERS})

install(TARGETS MDCcpp98 libMDCcpp98)
