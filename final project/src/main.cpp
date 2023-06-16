#include <iostream>
#include "BinarySerialization.hpp"
using namespace BinarySerialization;

#include <vector>

template <typename T>
void serialize(const T &obj)
{
    for (int i = 0; i < sizeof(T); ++i)
    {
        for (int j = 7; j >= 0; --j)
        {
            std::cout << (((*((char *)&obj + i)) >> j) & 1);
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

int main()
{
    // int a = 16, b;
    // serialize(a, "test.bin");
    // deserialize(b, "test.bin");
    // std::cout << "a = " << a << std::endl;
    // std::cout << "b = " << b << std::endl;
    return 0;
}