cmake_minimum_required(VERSION 3.11)

# Name of the project, also is the name of the file
project(Tests)

# Define requirements for C
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Output test EXE
add_executable(${PROJECT_NAME})
add_subdirectory("tests")

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/Tests/tests")
target_link_libraries(${PROJECT_NAME} MDCc)
