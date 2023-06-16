#include <iostream>
#include <fstream>
#define DEBUG 1

namespace BinarySerialization
{
    template <typename T>
    void serialize(const T &obj, const std::string &filename);

    template <typename T>
    void deserialize(T &obj, const std::string &filename);

    template <typename T>
    void serialize(const T &obj, std::ostream &os);

    template <typename T>
    void deserialize(T &obj, std::istream &is);

    void serialize(const std::string &obj, std::ostream &os);

    void deserialize(std::string &obj, std::istream &is);

    template <typename T>
    void serialize(const std::vector<T> &obj, std::ostream &os);

    template <typename T>
    void deserialize(std::vector<T> &obj, std::istream &is);

    // TODO: static assert that T is an arithmetic type
    // question: 模版函数的匹配
}

template <typename T>
void BinarySerialization::serialize(const T &obj, const std::string &filename)
{
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs.is_open())
    {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(1);
    }
    serialize(obj, ofs);
    ofs.close();
}

template <typename T>
void BinarySerialization::deserialize(T &obj, const std::string &filename)
{
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs.is_open())
    {
        std::cerr << "Error opening file " << filename << std::endl;
        exit(1);
    }
    deserialize(obj, ifs);
    ifs.close();
}

template <typename T>
void BinarySerialization::serialize(const T &obj, std::ostream &os)
{
    static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");
    os.write(reinterpret_cast<const char *>(&obj), sizeof(T));
}

template <typename T>
void BinarySerialization::deserialize(T &obj, std::istream &is)
{
    static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");
    is.read(reinterpret_cast<char *>(&obj), sizeof(T));
}

void BinarySerialization::serialize(const std::string &obj, std::ostream &os)
{
#if DEBUG
    std::cout << "Serializing string" << std::endl;
#endif
    size_t size = obj.size();
    os.write(reinterpret_cast<const char *>(&size), sizeof(size)); // TODO: check if this is correct
    os.write(obj.c_str(), size);                                   // TODO: check if this is correct
}

void BinarySerialization::deserialize(std::string &obj, std::istream &is)
{
#if DEBUG
    std::cout << "Deserializing string" << std::endl;
#endif
    size_t size;
    is.read(reinterpret_cast<char *>(&size), sizeof(size));
    obj.resize(size);
    is.read(&obj[0], size);
}

template <typename T>
void BinarySerialization::serialize(const std::vector<T> &obj, std::ostream &os)
{
#if DEBUG
    std::cout << "Serializing vector" << std::endl;
#endif
    size_t size = obj.size();
    os.write(reinterpret_cast<const char *>(&size), sizeof(size));
    for (auto &elem : obj)
        serialize(elem, os);
}

template <typename T>
void BinarySerialization::deserialize(std::vector<T> &obj, std::istream &is)
{
#if DEBUG
    std::cout << "Deserializing vector" << std::endl;
#endif
    size_t size;
    is.read(reinterpret_cast<char *>(&size), sizeof(size));
    obj.resize(size);
    for (auto &elem : obj)
        deserialize(elem, is);
}