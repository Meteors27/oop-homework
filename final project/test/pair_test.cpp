#include "BinarySerialization.hpp"
#include <iostream>

using namespace BinarySerialization;
using namespace std;

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
    test(pair<int, int>(1, 2));
    test(pair<double, string>(-1.23, "world"));
    test(pair<pair<int, double>, vector<string>>(pair<int, double>(1, 2.3), vector<string>({"hello", "world"})));
    return 0;
}