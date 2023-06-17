#include "test_xml.hpp"
int main()
{
    test_xml(int{1});
    test_xml((unsigned int){1});
    test_xml((long long){1});
    test_xml((unsigned long long){1});
    test_xml((float){1});
    test_xml((double){1});
    test_xml((char){1});
    test_xml((unsigned char){1});
    test_xml((short){1});
    test_xml((unsigned short){1});
    test_xml((bool){true});

    return 0;
}