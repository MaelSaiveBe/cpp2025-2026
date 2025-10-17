#include "Car.h"
#include <iostream>
#include <ostream>
namespace carconfig {


Car::Car() 
  : name("Projet Inconnu"),
    model() // pas "model = Model();"
{


}

// Constructeur paramétré
Car::Car(const std::string& n, const Model& m) {
    name = n;
    model = m;   
}

// Constructeur de copie
Car::Car(const Car& obj) {
    name = obj.name;
    model = obj.model;
}

Car::~Car() {
    // Rien de spécial  pas de mémoire dynamique
}

// Getters
std::string Car::getName() const {
    return name;
}

const Model& Car::getModel() const {
    return this->model;
}

// Setters
void Car::setName(const std::string& newName) {
    name = newName;
}

void Car::setModel(const Model& newModel) {
    model = newModel;
}

void Car::addOption(const Option& option){
  for(int i=0; i<5;i++){
    if(options[i] == nullptr){
      options[i] = new Option(option);
      break;
    }
  }
}

void Car::removeOption(const std::string& target){
  for(int i = 0; i<5; i++){
    if(options[i]->getCode() == target){
      free(options[i]);
      options[i] == nullptr;
    }
  }
}

void Car::display()const{
  std::cout<< "Car.display(): "<< std::endl;

  std::cout<< " Name: "<<this->getName()<< std::endl;
  std::cout<< " Model: "<< std::endl;
  this->model.display();
}
}
