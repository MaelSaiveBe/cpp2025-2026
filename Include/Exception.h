#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception {
protected:
    std::string message;

public:
    // Constructeur
    Exception(const std::string& msg = "Erreur") : message(msg) {}

    // Getter pour le message
    std::string getMessage() const { return message; }

    virtual ~Exception() = default;
};


class OptionException : public Exception {
public:
    // Constructeur : redirige vers Exception
    OptionException(const std::string& msg = "Erreur Option") 
        : Exception(msg) {}
};


class PasswordException : public Exception {
private:
    int code;

public:

    static const int INVALID_LENGTH = 1; //<6
    static const int ALPHA_MISSING =2;
    static const int DIGIT_MISSING= 3;  // aucun chiffre
    static const int NO_PASSWORD = 4;
    PasswordException(const std::string& msg, int c)
        : Exception(msg), code(c) {}

    int getCode() const { return code; }
};


class XmlFileSerializerException : public Exception {
private:
    int code;

public:
    static const int NOT_ALLOWED =1;
    static const int FILE_NOT_FOUND =2;
    static const int END_OF_FILE =3;

    XmlFileSerializerException(const std::string& msg, int c)
        : Exception(msg), code(c) {}

    int getCode() const { return code; }

};
#endif
