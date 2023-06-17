#include <set>
#include "test_bin.hpp"
using namespace std;
int main()
{
    test_bin(set<string>{"foo", "bar"});
    test_bin(set<int>{1, 2, 3, 4, 5});
    test_bin(set<set<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    return 0;
}