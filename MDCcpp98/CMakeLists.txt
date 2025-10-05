cmake_minimum_required(VERSION 3.11)

# Name of the project, also is the name of the file
project(MDCcpp98)

# Define requirements for C
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define requirements for C++
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Remove MinGW compiled binary "lib" prefix
if (MINGW)
    set(CMAKE_IMPORT_LIBRARY_PREFIX "")
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
    set(CMAKE_STATIC_LIBRARY_PREFIX "")
endif (MINGW)

# Build output
option(${PROJECT_NAME}_BUILD_SHARED_LIBS "Build using shared libraries" OFF)
if (${PROJECT_NAME}_BUILD_SHARED_LIBS)
    add_library(${PROJECT_NAME} SHARED)
    target_compile_definitions(${PROJECT_NAME}
        INTERFACE MDC_CPP98_DLLIMPORT
        PRIVATE MDC_CPP98_DLLEXPORT)
    target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/MDCcpp98/src")
    target_link_libraries(${PROJECT_NAME} PRIVATE MDCc)
else()
    add_library(${PROJECT_NAME} STATIC)
    target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/MDCcpp98/src")
    target_link_libraries(${PROJECT_NAME} PRIVATE MDCc)
endif()

add_subdirectory("src")

# Project source listing
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES)
