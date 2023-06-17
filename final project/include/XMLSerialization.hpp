#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <iostream>
#include "tinyxml2.h"
using namespace tinyxml2; // XXX: where to place this?
namespace XMLSerialization
{
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
    void deserialize_xml(T &obj, XMLDocument &doc, XMLElement *parent);

    // string
    void serialize_xml(const std::string &obj, XMLDocument &doc, XMLElement *parent);

    void deserialize_xml(std::string &obj, XMLDocument &doc, XMLElement *parent);

    // pair
    template <typename T1, typename T2>
    void serialize_xml(const std::pair<T1, T2> &obj, XMLDocument &doc, XMLElement *parent);

    template <typename T1, typename T2>
    void deserialize_xml(std::pair<T1, T2> &obj, XMLDocument &doc, XMLElement *parent);

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
    self->QueryAttribute("val", &obj);
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