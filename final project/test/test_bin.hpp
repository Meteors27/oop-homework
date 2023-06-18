#include "BinarySerialization.hpp"
#include <iostream>
#pragma once

template <typename T>
void test_bin(T a)
{
    T b;
    BinarySerialization::serialize(a, "test.data");
    BinarySerialization::deserialize(b, "test.data");
    if (a != b)
        exit(1);
    std::cout << "test successfully, output file 'test.data'" << std::endl;
    return;
}