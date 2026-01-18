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

