#include "XMLSerialization.hpp"
#include <iostream>
#pragma once

template <typename T>
void test_xml(T a)
{
    T b, c;
    XMLSerialization::serialize_xml(a, "test", "test.xml");
    XMLSerialization::deserialize_xml(b, "test", "test.xml");

    XMLSerialization::serialize_xml(a, "test.xml");
    XMLSerialization::deserialize_xml(c, "test.xml");
    if (a != b || a != c)
        exit(1);
    std::cout << "test successfully, output file 'test.xml'" << std::endl;
    return;
}