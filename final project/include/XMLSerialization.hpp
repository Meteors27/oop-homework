#pragma once
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <iostream>
#include "tinyxml2.h"

namespace XMLSerialization
{

    using namespace tinyxml2;
    // file
    template <typename T>
    void serialize_xml(const T &obj, const std::string &filename);

    template <typename T>
    void serialize_xml(const T &obj, const std::string &nodeName, const std::string &filename);

    template <typename T>
    void deserialize_xml(T &obj, const std::string &filename);

    template <typename T>
    void deserialize_xml(T &obj, const std::string &nodeName, const std::string &filename);

    // arithmetic
    template <typename T>
    void serialize_xml(const T &obj, XMLDocument &doc, XMLElement *parent);

    template <typename T>
    void deserialize_xml(T &obj, XMLDocument &doc, XMLElement *self);

    // string
    void serialize_xml(const std::string &obj, XMLDocument &doc, XMLElement *parent);

    void deserialize_xml(std::string &obj, XMLDocument &doc, XMLElement *self);

    // pair
    template <typename T1, typename T2>
    void serialize_xml(const std::pair<T1, T2> &obj, XMLDocument &doc, XMLElement *parent);

    template <typename T1, typename T2>
    void deserialize_xml(std::pair<T1, T2> &obj, XMLDocument &doc, XMLElement *self);

    // vector
    template <typename T>
    void serialize_xml(const std::vector<T> &obj, XMLDocument &doc, XMLElement *parent);

    template <typename T>
    void deserialize_xml(std::vector<T> &obj, XMLDocument &doc, XMLElement *self);

    // map
    template <typename T1, typename T2>
    void serialize_xml(const std::map<T1, T2> &obj, XMLDocument &doc, XMLElement *parent);

    template <typename T1, typename T2>
    void deserialize_xml(std::map<T1, T2> &obj, XMLDocument &doc, XMLElement *self);

    // list
    template <typename T>
    void serialize_xml(const std::list<T> &obj, XMLDocument &doc, XMLElement *parent);

    template <typename T>
    void deserialize_xml(std::list<T> &obj, XMLDocument &doc, XMLElement *self);

    // set
    template <typename T>
    void serialize_xml(const std::set<T> &obj, XMLDocument &doc, XMLElement *parent);

    template <typename T>
    void deserialize_xml(std::set<T> &obj, XMLDocument &doc, XMLElement *self);
}

template <typename T>
void XMLSerialization::serialize_xml(const T &obj, const std::string &filename)
{
    XMLDocument doc;
    XMLElement *root = doc.NewElement("serialization");
    doc.InsertEndChild(root);
    serialize_xml(obj, doc, root);
    doc.SaveFile(filename.c_str());
}

template <typename T>
void XMLSerialization::serialize_xml(const T &obj, const std::string &nodeName, const std::string &filename)
{
    XMLDocument doc;
    XMLElement *root = doc.NewElement("serialization");
    doc.InsertEndChild(root);
    serialize_xml(obj, doc, root);
    root->FirstChildElement()->SetName(nodeName.c_str());
    doc.SaveFile(filename.c_str());
}

template <typename T>
void XMLSerialization::deserialize_xml(T &obj, const std::string &filename)
{
    XMLDocument doc;
    if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
        throw std::runtime_error("Failed to load XML file: " + filename);

    XMLElement *root = doc.FirstChildElement("serialization");
    if (!root)
        throw std::runtime_error("Invalid XML format: missing root element");

    XMLElement *node = root->FirstChildElement();

    deserialize_xml(obj, doc, node);
}

template <typename T>
void XMLSerialization::deserialize_xml(T &obj, const std::string &nodeName, const std::string &filename)
{
    XMLDocument doc;
    if (doc.LoadFile(filename.c_str()) != XML_SUCCESS)
        throw std::runtime_error("Failed to load XML file: " + filename);

    XMLElement *root = doc.FirstChildElement("serialization");
    if (!root)
        throw std::runtime_error("Invalid XML format: missing root element");

    XMLElement *node = root->FirstChildElement(nodeName.c_str());
    if (!node)
        throw std::runtime_error("Invalid XML format: missing node element");

    deserialize_xml(obj, doc, node);
}

template <typename T>
void XMLSerialization::serialize_xml(const T &obj, XMLDocument &doc, XMLElement *parent)
{
    static_assert(std::is_arithmetic<T>::value, "Only arithmetic types are supported");
    XMLElement *element = doc.NewElement("arithmetic");
    parent->InsertEndChild(element);
    element->SetAttribute("val", obj);
}

template <typename T>
void XMLSerialization::deserialize_xml(T &obj, XMLDocument &doc, XMLElement *self)
{
    static_assert(std::is_arithmetic<T>::value, "Only arithmetic types are supported");
    if (std::is_same<T, int>::value)
        obj = self->IntAttribute("val");
    else if (std::is_same<T, unsigned int>::value)
        obj = self->UnsignedAttribute("val");
    else if (std::is_same<T, long long>::value)
        obj = self->Int64Attribute("val");
    else if (std::is_same<T, unsigned long long>::value)
        obj = self->Unsigned64Attribute("val");
    else if (std::is_same<T, float>::value)
        obj = self->FloatAttribute("val");
    else if (std::is_same<T, double>::value)
        obj = self->DoubleAttribute("val");
    else if (std::is_same<T, char>::value)
        obj = self->IntAttribute("val");
    else if (std::is_same<T, unsigned char>::value)
        obj = self->UnsignedAttribute("val");
    else if (std::is_same<T, short>::value)
        obj = self->IntAttribute("val");
    else if (std::is_same<T, unsigned short>::value)
        obj = self->UnsignedAttribute("val");
    else if (std::is_same<T, bool>::value)
        obj = self->BoolAttribute("val");
    else
        throw std::runtime_error("Unsupported arithmetic type");
}

void XMLSerialization::serialize_xml(const std::string &obj, XMLDocument &doc, XMLElement *parent)
{
    XMLElement *element = doc.NewElement("string");
    parent->InsertEndChild(element);
    element->SetAttribute("val", obj.c_str());
}

void XMLSerialization::deserialize_xml(std::string &obj, XMLDocument &doc, XMLElement *self)
{
    obj = self->Attribute("val");
}

template <typename T1, typename T2>
void XMLSerialization::serialize_xml(const std::pair<T1, T2> &obj, XMLDocument &doc, XMLElement *parent)
{
    XMLElement *element = doc.NewElement("pair");
    parent->InsertEndChild(element);
    serialize_xml(obj.first, doc, element);
    serialize_xml(obj.second, doc, element);
    element->FirstChildElement()->SetName("first");
    element->FirstChildElement()->NextSiblingElement()->SetName("second");
}

template <typename T1, typename T2>
void XMLSerialization::deserialize_xml(std::pair<T1, T2> &obj, XMLDocument &doc, XMLElement *self)
{
    deserialize_xml(obj.first, doc, self->FirstChildElement());
    deserialize_xml(obj.second, doc, self->FirstChildElement()->NextSiblingElement());
}

template <typename T>
void XMLSerialization::serialize_xml(const std::vector<T> &obj, XMLDocument &doc, XMLElement *parent)
{
    XMLElement *element = doc.NewElement("vector");
    parent->InsertEndChild(element);
    for (const auto &item : obj)
        serialize_xml(item, doc, element);
}

template <typename T>
void XMLSerialization::deserialize_xml(std::vector<T> &obj, XMLDocument &doc, XMLElement *self)
{
    obj.clear();
    for (XMLElement *element = self->FirstChildElement(); element; element = element->NextSiblingElement())
    {
        T item;
        deserialize_xml(item, doc, element);
        obj.push_back(item);
    }
}

template <typename T1, typename T2>
void XMLSerialization::serialize_xml(const std::map<T1, T2> &obj, XMLDocument &doc, XMLElement *parent)
{
    XMLElement *element = doc.NewElement("map");
    parent->InsertEndChild(element);
    for (const auto &item : obj)
    {
        serialize_xml(item, doc, element);
    }
}

template <typename T1, typename T2>
void XMLSerialization::deserialize_xml(std::map<T1, T2> &obj, XMLDocument &doc, XMLElement *self)
{
    obj.clear();
    for (XMLElement *element = self->FirstChildElement(); element; element = element->NextSiblingElement())
    {
        std::pair<T1, T2> item;
        deserialize_xml(item, doc, element);
        obj.insert(item);
    }
}

template <typename T>
void XMLSerialization::serialize_xml(const std::list<T> &obj, XMLDocument &doc, XMLElement *parent)
{
    XMLElement *element = doc.NewElement("list");
    parent->InsertEndChild(element);
    for (const auto &item : obj)
        serialize_xml(item, doc, element);
}

template <typename T>
void XMLSerialization::deserialize_xml(std::list<T> &obj, XMLDocument &doc, XMLElement *self)
{
    obj.clear();
    for (XMLElement *element = self->FirstChildElement(); element; element = element->NextSiblingElement())
    {
        T item;
        deserialize_xml(item, doc, element);
        obj.push_back(item);
    }
}

template <typename T>
void XMLSerialization::serialize_xml(const std::set<T> &obj, XMLDocument &doc, XMLElement *parent)
{
    XMLElement *element = doc.NewElement("set");
    parent->InsertEndChild(element);
    for (const auto &item : obj)
        serialize_xml(item, doc, element);
}

template <typename T>
void XMLSerialization::deserialize_xml(std::set<T> &obj, XMLDocument &doc, XMLElement *self)
{
    obj.clear();
    for (XMLElement *element = self->FirstChildElement(); element; element = element->NextSiblingElement())
    {
        T item;
        deserialize_xml(item, doc, element);
        obj.insert(item);
    }
}