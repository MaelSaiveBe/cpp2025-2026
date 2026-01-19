#include "Garage.h"
#include <iostream> 
#include <iterator>  

using carconfig::Model;
using carconfig::Option;

// Methodes Options et models ------------------------------------
void Garage::addModel(const Model& m){
	models.push_back(m);
}

void Garage::addOption(const Option& op){
	options.push_back(op);
}

void Garage::displayAllModels()const {
	for(const Model& m : models){
		std::cout<<m.toString()<<std::endl;
	}
}

void Garage::displayAllOptions()const {
	for(const Option& opt : options){
		std::cout<<opt.toString()<<std::endl;
	}
}

Model Garage::getModel(int index) const{
	auto it = models.cbegin();
	std::advance(it, index);
	return *it;
}

Option Garage::getOption(int index) const{
	auto it = options.cbegin();
	std::advance(it, index);
	return *it;
}

//methodes Client et Employes ----------------------------

int Garage::addClient(const std::string& lastName, const std::string& firstName, const std::string& gsm) {
    Client c(lastName, firstName, Actor::currentId++, gsm);
    clients.insert(c);
    return c.getId();
}

int Garage::addEmployee(const std::string& lastName, const std::string& firstName, const std::string& login, const std::string& role) {
    Employee e(lastName, firstName, Actor::currentId++,login, role);
    employees.insert(e);
    return e.getId();
}

void Garage::displayClients() const {
    for (const Client& c : clients) {
    	std::cout << c.toString() << std::endl;
    }
}

void Garage::displayEmployees() const {
    for (const Employee& e : employees){
    	std::cout << e << std::endl;
    }
}

void Garage::deleteClientByIndex(int index) {
    if (index < 0 || index >= (int)clients.size()) return;
    auto it = clients.begin();
	std::advance(it, index);
    clients.erase(it);
}

void Garage::deleteEmployeeByIndex(int index) {
    if (index < 0 || index >= (int)employees.size()) return;
    auto it = employees.begin();
    std::advance(it, index);
    employees.erase(it);
}

void Garage::deleteClientById(int id) {
    for (auto it = clients.begin(); it != clients.end(); ++it) {
        if (it->getId() == id) { clients.erase(it); break; }
    }
}

void Garage::deleteEmployeeById(int id) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->getId() == id) { employees.erase(it); break; }
    }
}

Client Garage::findClientById(int id) const {
   for(auto it =clients.begin(); it!= clients.end(); ++it){
    	if(it->getId() == id){
    		return *it;
    	}
    }throw std::out_of_range("Client non trouvé");
}

Employee Garage::findEmployeeById(int id) const {
    for(auto it =employees.begin(); it!= employees.end(); ++it){
    	if(it->getId() == id){
    		return *it;
    	}
    }throw std::out_of_range("Employee non trouvé");
   
}


// Recherche par index
Client Garage::findClientByIndex(int index) const {
    auto it = clients.cbegin();
	std::advance(it, index);
	return *it;
}

Employee Garage::findEmployeeByIndex(int index) const {
    auto it = employees.cbegin();
	std::advance(it, index);
	return *it;
}
