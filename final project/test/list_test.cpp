#include "BinarySerialization.hpp"
#include <list>
#include <vector>
using namespace BinarySerialization;

template <typename T>
void test(T a)
{
    T b;
    serialize(a, "test.data");
    deserialize(b, "test.data");
    if (a != b)
        exit(1);
    return;
}

int main()
{
    test(std::list<std::string>{"foo", "bar"});
    test(std::list<int>{1, 2, 3, 4, 5});
    test(std::list<std::vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
}