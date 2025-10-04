target_sources(${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/wide_encoding.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/wide_decoding.cpp"
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/wide_encoding.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/wide_decoding.hpp")
