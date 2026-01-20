#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "Exception.h"


template<typename T>
#ifndef XMLSERIALIZER_H
#define XMLSERIALIZER_H

class XmlFileSerializer {
private:
    std::fstream file;
    std::string filename;
    char mode; // 'R' ou 'W'
    std::string collectionName;

public:
    static const char READ  = 'R';
    static const char WRITE = 'W';

    // Constructeur
    XmlFileSerializer(const std::string& fn, char m, const std::string& cn = "entities");

    XmlFileSerializer() = delete;
    XmlFileSerializer(const XmlFileSerializer&) = delete;
    XmlFileSerializer& operator=(const XmlFileSerializer&) = delete;

    ~XmlFileSerializer();

    std::string getFilename() const;
    std::string getCollectionName() const;
    bool isReadable() const;
    bool isWritable() const;

    void write(const T& val);
    T read();
};

// Inclusion du fichier .ipp pour la définition du template
#include "../includes/XmlFileSerializer.ipp"

#endif