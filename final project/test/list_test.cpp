#include <list>
#include "test_bin.hpp"
using namespace std;

int main()
{
    test_bin(std::list<std::string>{"foo", "bar"});
    test_bin(std::list<int>{1, 2, 3, 4, 5});
    test_bin(std::list<std::vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
}