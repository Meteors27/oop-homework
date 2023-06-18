#include <iostream>
#include "XMLSerialization_Base64.hpp"

int main()
{
    std::vector<std::pair<int, std::string>> a = {{1, "hello"}, {2, "world"}}, b;
    XMLSerialization::serialize_xml_base64(a, "serialize.base64");
    XMLSerialization::deserialize_xml_base64(b, "serialize.base64");
    if (a != b)
        exit(1);
    std::cout << "test successfully, output file 'serialize.base64'" << std::endl;
    return 0;
}