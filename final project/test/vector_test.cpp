#include "test_bin.hpp"
using namespace std;
int main()
{
    test_bin(vector<string>{"foo", "bar"});
    test_bin(vector<int>{1, 2, 3, 4, 5});
    test_bin(vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    return 0;
}