#include "BinarySerialization.hpp"
#include <iostream>
#include <string>
#include <vector>
struct DDL
{
    std::string name;
    int left_days;
    std::vector<std::string> ref_books;

    void serialize(const std::string &filename)
    {
        BinarySerialization::serializer serializer(filename);
        serializer.serialize(name);
        serializer.serialize(left_days);
        serializer.serialize(ref_books);
    }

    void deserialize(const std::string &filename)
    {
        BinarySerialization::deserializer deserializer(filename);
        deserializer.deserialize(name);
        deserializer.deserialize(left_days);
        deserializer.deserialize(ref_books);
    }

    bool operator==(const DDL &other) const
    {
        return name == other.name && left_days == other.left_days && ref_books == other.ref_books;
    }

    bool operator!=(const DDL &other) const
    {
        return !(*this == other);
    }
};

int main()
{
    DDL ddl1 = {"C++ Primer", 10, {"C++ Primer", "Effective C++"}}, ddl2;
    ddl1.serialize("ddl.bin");
    ddl2.deserialize("ddl.bin");
    if (ddl1 != ddl2)
        exit(1);
    std::cout << "test successfully, output file 'ddl.bin'" << std::endl;
}