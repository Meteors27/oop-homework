#include "test_bin.hpp"
#include <map>
#include <string>
using namespace std;

int main()
{
    test_bin(map<int, string>{{1, "foo"}, {2, "bar"}});
    return 0;
}