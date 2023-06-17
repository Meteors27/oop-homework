#include "test_bin.hpp"
int main()
{
    test_bin(int{1});
    test_bin((unsigned int){1});
    test_bin((long){1});
    test_bin((unsigned long){1});
    test_bin((long long){1});
    test_bin((unsigned long long){1});
    test_bin((float){1});
    test_bin((double){1});
    test_bin((long double){1});
    test_bin((char){1});
    test_bin((unsigned char){1});
    test_bin((short){1});
    test_bin((unsigned short){1});
    test_bin((bool){true});
    return 0;
}