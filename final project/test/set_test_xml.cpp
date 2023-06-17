#include <set>
#include "test_xml.hpp"
using namespace std;
int main()
{
    test_xml(set<string>{"foo", "bar"});
    test_xml(set<int>{1, 2, 3, 4, 5});
    test_xml(set<set<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    return 0;
}