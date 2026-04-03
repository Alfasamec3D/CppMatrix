cmake_minimum_required(VERSION 3.13)

project("Matrix" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp)

add_library(matrix lib/matrix.cpp)

target_include_directories(matrix PUBLIC "include")

target_link_libraries(main PRIVATE matrix)


option(BUILD_TESTS "Build tests" ON)
if (BUILD_TESTS)
    add_subdirectory(tests)
endif()