cmake_minimum_required(VERSION 3.10)

project(MDC)

if (MSVC)
    add_definitions("-D_CRT_SECURE_NO_WARNINGS")
endif (MSVC)

add_subdirectory(MDC)
add_subdirectory(Tests)
add_subdirectory(MDCcpp98)
add_subdirectory(TestsCpp98)
