#include "test_xml.hpp"
using namespace std;
int main()
{
    test_xml(vector<string>{"foo", "bar"});
    test_xml(vector<int>{1, 2, 3, 4, 5});
    test_xml(vector<vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    return 0;
}