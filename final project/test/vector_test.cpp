#include "test.hpp"
using namespace std;
int main()
{
    test(vector<string>{"foo", "bar"});
    test(vector<int>{1, 2, 3, 4, 5});
    test(vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    return 0;
}