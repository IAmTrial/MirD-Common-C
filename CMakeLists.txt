cmake_minimum_required(VERSION 3.11)

project(MDC)

if (MSVC)
    add_definitions("-D_CRT_SECURE_NO_WARNINGS")
endif (MSVC)

add_subdirectory(MDCc)

option(ENABLE_MDC_C_TESTS "Enable tests for MDCc.")
if (ENABLE_MDC_C_TESTS)
    add_subdirectory(Tests)
endif (ENABLE_MDC_C_TESTS)

add_subdirectory(MDCcpp98)

option(ENABLE_MDC_CPP98_TESTS "Enable tests for MDCc.")
if (ENABLE_MDC_CPP98_TESTS)
    add_subdirectory(TestsCpp98)
endif (ENABLE_MDC_CPP98_TESTS)
