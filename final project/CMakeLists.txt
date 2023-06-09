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
add_test(list_test ${CMAKE_SOURCE_DIR}/build/test/list_test)
add_test(set_test ${CMAKE_SOURCE_DIR}/build/test/set_test)
add_test(pair_test ${CMAKE_SOURCE_DIR}/build/test/pair_test)
add_test(map_test ${CMAKE_SOURCE_DIR}/build/test/map_test)

add_test(arithmetic_test_xml ${CMAKE_SOURCE_DIR}/build/test/arithmetic_test_xml)
add_test(string_test_xml ${CMAKE_SOURCE_DIR}/build/test/string_test_xml)
add_test(vector_test_xml ${CMAKE_SOURCE_DIR}/build/test/vector_test_xml)
add_test(list_test_xml ${CMAKE_SOURCE_DIR}/build/test/list_test_xml)
add_test(set_test_xml ${CMAKE_SOURCE_DIR}/build/test/set_test_xml)
add_test(pair_test_xml ${CMAKE_SOURCE_DIR}/build/test/pair_test_xml)
add_test(map_test_xml ${CMAKE_SOURCE_DIR}/build/test/map_test_xml)

add_test(base64_test ${CMAKE_SOURCE_DIR}/build/test/base64_test)

add_test(unique_ptr_test ${CMAKE_SOURCE_DIR}/build/test/unique_ptr_test)

add_test(user_defined_type_test ${CMAKE_SOURCE_DIR}/build/test/user_defined_type_test)
add_test(user_defined_type_test_xml ${CMAKE_SOURCE_DIR}/build/test/user_defined_type_test_xml)