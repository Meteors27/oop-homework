# Serialization
Name: 夏裕诚

Student ID: 3210101006
## Features I've implemented
1. Binary Serialization and Deserialization (support `arithmetic`, `std::string`, `STL Containers`)
2. XML Serialization and Deserialization(support `arithmetic`, `std::string`, `STL Containers`)
3. Both modules should provide a convenient mechanism to support the serialization of `user defined types`
4. [Bonus] XML Base64 Serialization and Deserialization
5. [Bonus] `std::unique_ptr` Serialization and Deserialization in Binary and XML

In short, I've completed all the requirements and bonuses.
## How to run the code

```bash
mkdir build
cd build
cmake ..
make
```
then you will get all the executable file `serialization` in the `./build/test` directory.

it would be something like this:

```
CMakeFiles
Makefile
cmake_install.cmake
pair_test
pair_test_xml
set_test
set_test_xml
arithmetic_test
arithmetic_test_xml
string_test
string_test_xml
list_test
list_test_xml
map_test
vector_test
map_test_xml
vector_test_xml
user_defined_type_test
user_defined_type_test_xml
base64_test
unique_ptr_test
```
Each test file is a test for a specific type, and the `_xml` file is the test for XML serialization and deserialization.

As I use `CMake Unit Test`, you can run all the tests, if it passed (return 0, exit without failure), then it means that my code works well.

Actually, if you can run cmake and make, it means that my code works well, because cmake will fail if there is any error in these tests.



