#include "XMLSerialization.hpp"
#include "Base64.hpp"
#include "tinyxml2.h"
#include <fstream>
#include <string>
#include <iostream>
#pragma once

namespace XMLSerialization
{
    template <typename T>
    void serialize_xml_base64(const T &obj, const std::string &filename);

    template <typename T>
    void deserialize_xml_base64(T &obj, const std::string &filename);
}

template <typename T>
void XMLSerialization::serialize_xml_base64(const T &obj, const std::string &filename)
{
    XMLDocument doc;
    XMLElement *root = doc.NewElement("serialization");
    doc.InsertEndChild(root);
    serialize_xml(obj, doc, root);
    tinyxml2::XMLPrinter printer;
    doc.Accept(&printer);
    std::string xmlString = printer.CStr();
    std::string base64String = base64_encode(xmlString.c_str(), xmlString.length());
    std::ofstream fout(filename);
    fout << base64String;
    fout.close();
}

template <typename T>
void XMLSerialization::deserialize_xml_base64(T &obj, const std::string &filename)
{
    std::ifstream fin(filename);
    std::string base64String;
    fin >> base64String;
    fin.close();
    std::string xmlString = base64_decode(base64String);

    XMLDocument doc;
    doc.Parse(xmlString.c_str());
    XMLElement *root = doc.FirstChildElement("serialization");
    if (!root)
        throw std::runtime_error("Invalid XML format: missing root element");
    XMLElement *node = root->FirstChildElement();
    deserialize_xml(obj, doc, node);
}
