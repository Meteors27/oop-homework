#include "test.hpp"

int main()
{
    test(int{1});
    test((unsigned int){1});
    test((long){1});
    test((unsigned long){1});
    test((long long){1});
    test((unsigned long long){1});
    test((float){1});
    test((double){1});
    test((long double){1});
    test((char){1});
    test((unsigned char){1});
    test((short){1});
    test((unsigned short){1});
    test((bool){true});
    return 0;
}