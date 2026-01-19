#include "Client.h"
#include <iostream>

//------------------------------- Constructors -------------------------------
Client::Client()
    : Actor(){
        this->gsm = "";
    }

Client::Client(const std::string& ln,const std::string& fn, int id, const std::string& gsm)
    : Actor(ln, fn, id){
        this->gsm = gsm;
    }

Client::Client(const Client& other)
    : Actor(other){
        this->gsm = other.gsm;
    }

//-------------------------------------------------------------------------------
Client::~Client(){
    std::cout<<"[Destructeur Client]"<<std::endl;
}
//------------------------------- Operator -------------------------------

Client& Client::operator=(const Client& other) {

    Actor::operator=(other);
    this->gsm = other.gsm;
    
    return *this;
}

bool Client::operator<(const Client& other) const{
    if (this->getLastName() == other.getLastName())
        return this->getFirstName() < other.getFirstName();
    return this->getLastName() < other.getLastName();
}


std::ostream& operator<<(std::ostream& os, const Client& c) {
    os << "<Client>" << std::endl;

    os << "<lastName>" << std::endl;
    os << c.getLastName() << std::endl;
    os << "</lastName>" << std::endl;

    os << "<firstName>" << std::endl;
    os << c.getFirstName() << std::endl;
    os << "</firstName>" << std::endl;

    os << "<id>" << std::endl;
    os << c.getId() << std::endl;
    os << "</id>" << std::endl;

    os << "<gsm>" << std::endl;
    os << c.getGsm() << std::endl;
    os << "</gsm>" << std::endl;

    os << "</Client>" << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Client& c) {
    std::string ligne;

    // <Client>
    std::getline(is, ligne);

    // lastName
    std::getline(is, ligne); 
    std::getline(is, ligne); 
    c.setLastName(ligne);
    std::getline(is, ligne); 

    // firstName
    std::getline(is, ligne); 
    std::getline(is, ligne); 
    c.setFirstName(ligne);
    std::getline(is, ligne); 

    // id
    std::getline(is, ligne); 
    std::getline(is, ligne);
    c.setId(std::stoi(ligne));
    std::getline(is, ligne);

    // gsm
    std::getline(is, ligne);
    std::getline(is, ligne);
    c.setGsm(ligne);
    std::getline(is, ligne);

    // </Client>
    std::getline(is, ligne);

    return is;
}

//-------------getters/setters-------------------
std::string Client::getGsm() const {
    return gsm;
}

void Client::setGsm(const std::string& gsm) {
    this->gsm = gsm;
}

//-------------override ------------------------

std::string Client::toString() const {
    std::string result;

    result = "[C";
    result = result + std::to_string(getId());
    result = result + "] ";
    result = result + getLastName();
    result = result + " ";
    result = result + getFirstName();

    return result;
}


std::string Client::tuple() const {
    std::string result = std::to_string(getId()) + ";"
                         + getLastName() + ";"
                         + getFirstName() + ";"
                         + gsm;
    return result;
}

