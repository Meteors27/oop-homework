#include "BinarySerialization.hpp"
#pragma once

template <typename T>
void test_bin(T a)
{
    T b;
    BinarySerialization::serialize(a, "test.data");
    BinarySerialization::deserialize(b, "test.data");
    if (a != b)
        exit(1);
    return;
}