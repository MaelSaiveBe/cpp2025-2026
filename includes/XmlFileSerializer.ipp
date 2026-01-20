
#include "XmlFileSerializer.hpp"

//COnstructor --------------------------------------------------

template<typename T>
XmlFileSerializer<T>::XmlFileSerializer(const std::string& fn, char m, const std::string& cn)
    : filename(fn), mode(m), collectionName(cn)
{
    if (mode == WRITE) {
        file.open(filename, std::ios::out);
        if (!file.is_open())
            throw XmlFileSerializerException("Impossible d'ouvrir le fichier en écriture", 
                                             XmlFileSerializerException::FILE_NOT_FOUND);

        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
        file << "<" << collectionName << ">" << std::endl;
    }
    else if (mode == READ) {
        file.open(filename, std::ios::in);
        if (!file.is_open())
            throw XmlFileSerializerException("Fichier introuvable", 
                                             XmlFileSerializerException::FILE_NOT_FOUND);

        std::string line;
        std::getline(file, line);
        std::getline(file, line);
        if (!line.empty() && line.front() == '<' && line.back() == '>')
            collectionName = line.substr(1, line.size() - 2);
    }
    else {
        throw XmlFileSerializerException("Mode invalide", XmlFileSerializerException::NOT_ALLOWED);
    }
}

template<typename T>
XmlFileSerializer<T>::~XmlFileSerializer() {
    if (mode == WRITE && file.is_open()) {
        file << "</" << collectionName << ">" << std::endl;
        file.close();
    }
    else if (file.is_open()) {
        file.close();
    }
}


//Getters ----------------------------------------------------------
template<typename T>
std::string XmlFileSerializer<T>::getFilename() const { 
	return filename; 
}

template<typename T>
std::string XmlFileSerializer<T>::getCollectionName() const { 
	return collectionName;
}

template<typename T>
bool XmlFileSerializer<T>::isReadable() const { 
	return mode == READ;
}

template<typename T>
bool XmlFileSerializer<T>::isWritable() const {
	return mode == WRITE;
}


//Méthode métier -------------------------------------------------------------------
template<typename T>
void XmlFileSerializer<T>::write(const T& val) {
    if (mode != WRITE)
        throw XmlFileSerializerException("Impossible d'écrire en mode lecture", 
                                         XmlFileSerializerException::NOT_ALLOWED);
    file << val;
}

template<typename T>
T XmlFileSerializer<T>::read() {
    if (mode != READ)
        throw XmlFileSerializerException("Impossible de lire en mode écriture", 
                                         XmlFileSerializerException::NOT_ALLOWED);

    std::streampos pos = file.tellg();
    std::string line;
    if (!(file >> line))
        throw XmlFileSerializerException("Fin de fichier inattendue", 
                                         XmlFileSerializerException::END_OF_FILE);

    if (line == "</" + collectionName + ">")
        throw XmlFileSerializerException("Fin de collection atteinte", 
                                         XmlFileSerializerException::END_OF_FILE);

    
    file.seekg(pos);

    T obj;
    file >> obj;
    return obj;
}

