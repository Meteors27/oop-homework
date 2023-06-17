#include "BinarySerialization.hpp"
#include <set>
#include <string>
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
    test(set<string>{"foo", "bar"});
    test(set<int>{1, 2, 3, 4, 5});
    test(set<set<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    return 0;
}