cmake_minimum_required(VERSION 3.11)

project("Matrix")


enable_testing()

find_package(GTest REQUIRED)

add_executable(main main.cpp)

add_executable(endTest test/test.cpp)

add_library(matrix src/matrix.cpp)

include_directories("include")

target_link_libraries (main matrix)

target_link_libraries(endTest matrix gtest gtest_main)

add_test(NAME MatrixEndTest COMMAND endTest)