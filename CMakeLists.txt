set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
PRIVATE
    ${PROJECT_SOURCE_DIR}/src/CircularBuffer.cpp
)

target_include_directories(${PROJECT_NAME}
PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)