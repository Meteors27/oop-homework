#include "test_xml.hpp"
#include <utility>
#include <string>
using namespace std;
int main()
{
    test_xml(pair<int, int>(1, 2));
    test_xml(pair<double, string>(-1.23, "world"));
    test_xml(pair<pair<int, double>, string>(pair<int, double>(1, 2.3), "world"));
    return 0;
}