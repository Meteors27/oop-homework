cmake_minimum_required(VERSION 3.22)
project(Object_Serialization VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)
aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC)
add_executable(${PROJECT_NAME} ${SRC})
add_subdirectory(test)

enable_testing()
add_test(arithmetic_test ${CMAKE_SOURCE_DIR}/build/test/arithmetic_test)
add_test(string_test ${CMAKE_SOURCE_DIR}/build/test/string_test)
add_test(vector_test ${CMAKE_SOURCE_DIR}/build/test/vector_test)