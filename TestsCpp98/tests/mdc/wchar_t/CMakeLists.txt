target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/wide_decoding_tests.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/wide_decoding_tests.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/wide_encoding_tests.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/wide_encoding_tests.hpp"
    PUBLIC)

add_subdirectory("wide_example_text")
