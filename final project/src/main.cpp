#include <iostream>
#include "XMLSerialization.hpp"

// print pair
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &obj)
{
    os << "(" << obj.first << ", " << obj.second << ")";
    return os;
}

int main()
{
    using namespace XMLSerialization;
    // question: 模版函数的匹配
    // 错误处理
    // std::string a = "Hello World!", b;
    std::pair<std::string, std::string> a("r3wr", "Hello World!"), b;
    // int a = 1, b;
    serialize_xml(a, "gaga", "serialize.xml");
    deserialize_xml(b, "gaga", "serialize.xml");
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "Done" << std::endl;

    return 0;
}