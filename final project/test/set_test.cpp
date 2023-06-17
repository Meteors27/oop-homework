#include <set>
#include "test.hpp"
using namespace std;
int main()
{
    test(set<string>{"foo", "bar"});
    test(set<int>{1, 2, 3, 4, 5});
    test(set<set<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    return 0;
}