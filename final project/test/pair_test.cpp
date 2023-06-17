#include "test.hpp"
using namespace std;

int main()
{
    test(pair<int, int>(1, 2));
    test(pair<double, string>(-1.23, "world"));
    test(pair<pair<int, double>, vector<string>>(pair<int, double>(1, 2.3), vector<string>({"hello", "world"})));
    return 0;
}