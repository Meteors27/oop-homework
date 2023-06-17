#include <list>
#include "test_xml.hpp"
using namespace std;

int main()
{
    test_xml(std::list<std::string>{"foo", "bar"});
    test_xml(std::list<int>{1, 2, 3, 4, 5});
    test_xml(std::list<std::vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
}