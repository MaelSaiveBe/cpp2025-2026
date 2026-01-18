#include "Employee.h"
#include <sstream>


//variables Statique------------

 const std::string Employee::ADMINISTRATIVE = "Administratif";
 const std::string Employee::SELLER = "Vendeur";


// --- Constructeurs ---

Employee::Employee()
    : Actor(){
        login = "";
        password = nullptr;
        role = "";
    }

Employee::Employee(const std::string& ln,const std::string& fn, int id,const std::string& login,const std::string& role)
    : Actor(ln, fn, id){
        this->login = login;
        this->password = nullptr;
        this->role = role;
    }

Employee::Employee(const Employee& other)
    : Actor(other){
    if (other.password != nullptr) {
        password = new std::string(*other.password);
    }else password= nullptr;
}

// --- Destructeur ---

Employee::~Employee() {
    std::cout<<"[Destructeur Employee]"<<std::endl;
    delete password;
}

// --- Opérateur = ---

Employee& Employee::operator=(const Employee& other) {
        Actor::operator=(other);

        login = other.login;
        role = other.role;

        delete password;
        password = nullptr;

        if (other.password != nullptr) {
            password = new std::string(*other.password);
        }
    return *this;
}

// --- Gestion du mot de passe ---

void Employee::setPassword(const std::string& mdp) {
    delete password;
    password = new std::string(mdp);
}

void Employee::resetPassword() {
    delete password;
    password = nullptr;
}

// --- Getters ---
std::string Employee::getPassword() const{
    return *this->password;
}
std::string Employee::getLogin() const {
    return login;
}

std::string Employee::getRole() const {
    return role;
}

void Employee::setRole(const std::string& newRole){
    if(newRole == ADMINISTRATIVE || newRole == SELLER)
        this->role = newRole;
    
}

//Setter ------
void Employee::setLogin(const std::string& newLogin){
    this->login = newLogin;
}

// --- Méthodes virtuelles ---

std::string Employee::tuple() const {
std::string result = std::to_string(getId()) + ";"
                     + getLastName() + ";"
                     + getFirstName() + ";"
                     + role;
return result;
}


std::string Employee::toString() const {
    std::string buffer = "[" + role.substr(0,1) + std::to_string(getId())+"] "
                         + getLastName() + " "
                         + getFirstName(); 
    return buffer;
}


// --- Opérateur << ---

std::ostream& operator<<(std::ostream& os, const Employee& e) {
    os << e.toString();
    return os;
}
