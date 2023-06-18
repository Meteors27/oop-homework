#include <iostream>
#include "BinarySerialization.hpp"
using namespace BinarySerialization;
int main()
{
    std::unique_ptr<std::vector<int>> a(new std::vector<int>{1, 2, 3, 4, 5}), b;

    serialize(a, "test.data");
    deserialize(b, "test.data");

    if (*a != *b)
        exit(1);

    std::cout << "test successfully, output file 'test.data'" << std::endl;
    return 0;
}