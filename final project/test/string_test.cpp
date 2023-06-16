#include <iostream>
#include <string>
#include "BinarySerialization.hpp"

int main()
{
    std::string a = "test", b;
    BinarySerialization::serialize(a, "test.data");
    BinarySerialization::deserialize(b, "test.data");
    if (a != b)
        exit(1);
    return 0;
}