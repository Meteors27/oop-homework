#include <iostream>
#include "XMLSerialization.hpp"
#include "tinyxml2.h"
#include "Base64.hpp"
#include "XMLSerialization_Base64.hpp"

int main()
{
    // using namespace XMLSerialization;
    // using namespace tinyxml2;
    // // question: 模版函数的匹配
    // // 错误处理
    // tinyxml2::XMLDocument doc;
    // doc.LoadFile("serialize.xml");

    // tinyxml2::XMLPrinter printer;
    // doc.Accept(&printer);

    // std::string xmlString = printer.CStr();

    // std::cout << xmlString << std::endl;
    // std::string base64String = base64_encode(xmlString.c_str(), xmlString.length());
    // std::cout << base64_decode(base64String) << std::endl;
    std::vector<std::pair<int, std::string>> a = {{1, "hello"}, {2, "world"}}, b;

    XMLSerialization::serialize_xml_base64(a, "serialize.base64");
    XMLSerialization::deserialize_xml_base64(b, "serialize.base64");
    std::cout << (a == b ? "true" : "false") << std::endl;

    return 0;
}