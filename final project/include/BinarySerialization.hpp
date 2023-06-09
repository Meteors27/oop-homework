#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#pragma once

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

    template <typename T>
    void serialize(const std::list<T> &obj, std::ostream &os);

    template <typename T>
    void deserialize(std::list<T> &obj, std::istream &is);

    template <typename T>
    void serialize(const std::set<T> &obj, std::ostream &os);

    template <typename T>
    void deserialize(std::set<T> &obj, std::istream &is);

    template <typename T1, typename T2>
    void serialize(const std::pair<T1, T2> &obj, std::ostream &os);

    template <typename T1, typename T2>
    void deserialize(std::pair<T1, T2> &obj, std::istream &is);

    template <typename T1, typename T2>
    void serialize(const std::map<T1, T2> &obj, std::ostream &os);

    template <typename T1, typename T2>
    void deserialize(std::map<T1, T2> &obj, std::istream &is);

    template <typename T>
    void serialize(const std::unique_ptr<T> &obj, std::ostream &os);

    template <typename T>
    void deserialize(std::unique_ptr<T> &obj, std::istream &is);

    class serializer
    {
    public:
        serializer(const std::string &filename) : os(filename, std::ios::binary)
        {
            if (!os.is_open())
            {
                std::cerr << "Error opening file " << filename << std::endl;
                exit(1);
            }
        }

        template <typename T>
        void serialize(const T &obj)
        {
            BinarySerialization::serialize(obj, os);
        }

        ~serializer()
        {
            os.close();
        }

    private:
        std::ofstream os;
    };

    class deserializer
    {
    public:
        deserializer(const std::string &filename) : is(filename, std::ios::binary)
        {
            if (!is.is_open())
            {
                std::cerr << "Error opening file " << filename << std::endl;
                exit(1);
            }
        }

        template <typename T>
        void deserialize(T &obj)
        {
            BinarySerialization::deserialize(obj, is);
        }

        ~deserializer()
        {
            is.close();
        }

    private:
        std::ifstream is;
    };
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
    size_t size = obj.size();
    os.write(reinterpret_cast<const char *>(&size), sizeof(size)); // TODO: check if this is correct
    os.write(obj.c_str(), size);                                   // TODO: check if this is correct
}

void BinarySerialization::deserialize(std::string &obj, std::istream &is)
{
    size_t size;
    is.read(reinterpret_cast<char *>(&size), sizeof(size));
    obj.resize(size);
    is.read(&obj[0], size);
}

template <typename T>
void BinarySerialization::serialize(const std::vector<T> &obj, std::ostream &os)
{
    size_t size = obj.size();
    os.write(reinterpret_cast<const char *>(&size), sizeof(size));
    for (auto &elem : obj)
        serialize(elem, os);
}

template <typename T>
void BinarySerialization::deserialize(std::vector<T> &obj, std::istream &is)
{
    size_t size;
    is.read(reinterpret_cast<char *>(&size), sizeof(size));
    obj.resize(size);
    for (auto &elem : obj)
        deserialize(elem, is);
}

template <typename T>
void BinarySerialization::serialize(const std::list<T> &obj, std::ostream &os)
{
    size_t size = obj.size();
    os.write(reinterpret_cast<const char *>(&size), sizeof(size));
    for (auto &elem : obj)
        serialize(elem, os);
}

template <typename T>
void BinarySerialization::deserialize(std::list<T> &obj, std::istream &is)
{
    size_t size;
    is.read(reinterpret_cast<char *>(&size), sizeof(size));
    for (size_t i = 0; i < size; i++)
    {
        T elem;
        deserialize(elem, is);
        obj.push_back(elem);
    }
}

template <typename T>
void BinarySerialization::serialize(const std::set<T> &obj, std::ostream &os)
{
    size_t size = obj.size();
    os.write(reinterpret_cast<const char *>(&size), sizeof(size));
    for (auto &elem : obj)
        serialize(elem, os);
}

template <typename T>
void BinarySerialization::deserialize(std::set<T> &obj, std::istream &is)
{
    size_t size;
    is.read(reinterpret_cast<char *>(&size), sizeof(size));
    for (size_t i = 0; i < size; i++)
    {
        T elem;
        deserialize(elem, is);
        obj.insert(elem);
    }
}

template <typename T1, typename T2>
void BinarySerialization::serialize(const std::pair<T1, T2> &obj, std::ostream &os)
{
    serialize(obj.first, os);
    serialize(obj.second, os);
}

template <typename T1, typename T2>
void BinarySerialization::deserialize(std::pair<T1, T2> &obj, std::istream &is)
{
    deserialize(obj.first, is);
    deserialize(obj.second, is);
}

template <typename T1, typename T2>
void BinarySerialization::serialize(const std::map<T1, T2> &obj, std::ostream &os)
{
    size_t size = obj.size();
    os.write(reinterpret_cast<const char *>(&size), sizeof(size));
    for (auto &elem : obj)
    {
        serialize(elem.first, os);
        serialize(elem.second, os);
    }
}

template <typename T1, typename T2>
void BinarySerialization::deserialize(std::map<T1, T2> &obj, std::istream &is)
{
    size_t size;
    is.read(reinterpret_cast<char *>(&size), sizeof(size));
    for (size_t i = 0; i < size; i++)
    {
        std::pair<T1, T2> elem;
        deserialize(elem.first, is);
        deserialize(elem.second, is);
        obj.insert(elem);
    }
}

template <typename T>
void BinarySerialization::serialize(const std::unique_ptr<T> &obj, std::ostream &os)
{
    serialize(*obj, os);
}

template <typename T>
void BinarySerialization::deserialize(std::unique_ptr<T> &obj, std::istream &is)
{
    obj = std::make_unique<T>();
    deserialize(*obj, is);
}
