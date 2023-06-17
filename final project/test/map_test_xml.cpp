#include "test_xml.hpp"
#include <map>
#include <string>
using namespace std;

int main()
{
    test_xml(map<int, string>{{1, "foo"}, {2, "bar"}});
    return 0;
}