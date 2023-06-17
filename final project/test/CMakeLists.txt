add_executable(arithmetic_test arithmetic_test.cpp)
add_executable(string_test string_test.cpp)
add_executable(vector_test vector_test.cpp)
add_executable(list_test list_test.cpp)
add_executable(set_test set_test.cpp)
add_executable(pair_test pair_test.cpp)
add_executable(map_test map_test.cpp)

add_executable(arithmetic_test_xml arithmetic_test_xml.cpp ../src/tinyxml2.cpp)
add_executable(string_test_xml string_test_xml.cpp ../src/tinyxml2.cpp)
add_executable(vector_test_xml vector_test_xml.cpp ../src/tinyxml2.cpp)
add_executable(list_test_xml list_test_xml.cpp ../src/tinyxml2.cpp)
add_executable(set_test_xml set_test_xml.cpp ../src/tinyxml2.cpp)
add_executable(pair_test_xml pair_test_xml.cpp ../src/tinyxml2.cpp)
add_executable(map_test_xml map_test_xml.cpp ../src/tinyxml2.cpp)

add_executable(base64_test base64_test.cpp ../src/tinyxml2.cpp)

add_executable(unique_ptr_test unique_ptr_test.cpp)

add_executable(user_defined_type_test user_defined_type_test.cpp)