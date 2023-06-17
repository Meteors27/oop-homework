#include <list>
#include "test.hpp"
using namespace std;

int main()
{
    test(std::list<std::string>{"foo", "bar"});
    test(std::list<int>{1, 2, 3, 4, 5});
    test(std::list<std::vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
}