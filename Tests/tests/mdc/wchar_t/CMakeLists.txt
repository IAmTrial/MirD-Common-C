target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/filew_tests.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/filew_tests.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/wide_decoding_tests.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/wide_decoding_tests.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/wide_encoding_tests.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/wide_encoding_tests.h"
    PUBLIC)

add_subdirectory("wide_example_text")
