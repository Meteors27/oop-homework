#include <iostream>
#include "BinarySerialization.hpp"
using namespace std;
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
    test(vector<string>{"foo", "bar"});
    test(vector<int>{1, 2, 3, 4, 5});
    test(vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    return 0;
}