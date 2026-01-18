#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Actor.h"
#include <string>
#include <tuple>
#include <iostream>
#include "Exception.h"

class Employee : public Actor {
protected:
    std::string login;
    std::string* password;
    std::string role;

public:

    static const std::string ADMINISTRATIVE;
    static const std::string SELLER;
// --------------------Constructeurs / destructeur --------------------
    Employee();
    Employee(const std::string& ln,const std::string& fn,int id,const std::string& login,const std::string& role);
    Employee(const Employee& other);
    virtual ~Employee();



//-------------------- Opérateur d’affectation --------------------
    Employee& operator=(const Employee& other);




//-------------------- Getters/Setter --------------------
    std::string getPassword() const;
    void setPassword(const std::string& mdp);
    void resetPassword();
    std::string getLogin() const;
    std::string getRole() const;
    void setRole(const std::string& newRole);
    void setLogin(const std::string& newLogin);

//-------------------- override --------------------
    std::string tuple() const override;
    std::string toString() const override;
//------------------------------------------------------------
    // Opérateur <<
    friend std::ostream& operator<<(std::ostream& os, const Employee& e);
};

#endif
