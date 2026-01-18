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
public:
    enum Code {
        INVALID_LENGTH, // mdp <6 caractères
        ALPHA_MISSING,  // aucune lettre
        DIGIT_MISSING,  // aucun chiffre
        NO_PASSWORD
    };

private:
    Code code;

public:
    PasswordException(const std::string& msg, Code c)
        : Exception(msg), code(c) {}

    Code getCode() const { return code; }
};

#endif
