#include <iostream>
#include "BinarySerialization.hpp"
using namespace BinarySerialization;

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
    // question: 模版函数的匹配
    return 0;
}