#include <iostream>
#include "BinarySerialization.hpp"

// print vector
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &obj)
{
    os << "[";
    for (auto it = obj.begin(); it != obj.end(); ++it)
    {
        os << *it;
        if (it != obj.end() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

int main()
{
    // using namespace XMLSerialization;
    // using namespace tinyxml2;
    // // question: 模版函数的匹配
    // // 错误处理
    std::unique_ptr<std::vector<int>> a(new std::vector<int>{1, 2, 3, 4, 5}), b;
    using namespace BinarySerialization;

    serialize(a, "test.data");
    deserialize(b, "test.data");

    std::cout << (*a == *b ? "true" : "false") << std::endl;
    std::cout << *b << std::endl;
    return 0;
}