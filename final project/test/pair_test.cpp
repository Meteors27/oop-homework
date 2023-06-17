#include "test_bin.hpp"
using namespace std;

int main()
{
    test_bin(pair<int, int>(1, 2));
    test_bin(pair<double, string>(-1.23, "world"));
    test_bin(pair<pair<int, double>, vector<string>>(pair<int, double>(1, 2.3), vector<string>({"hello", "world"})));
    return 0;
}