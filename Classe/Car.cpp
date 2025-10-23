#include "Car.h"
#include <iostream>
#include <ostream>
namespace carconfig {
using std::string;

Car::Car() 
  : name("Projet Inconnu"),
    model() // pas "model = Model();"????
{
  for(int i=0; i<5; i++){
    options[i] = nullptr;
  }
}

// Constructeur paramétré
Car::Car(const std::string& n, const Model& m) {
    name = n;
    model = m;   
  for(int i=0; i<5; i++){
    options[i] = nullptr;
  }
}

// Constructeur de copie
Car::Car(const Car& obj) {
    name = obj.name;
    model = obj.model;
  for(int i=0; i<5; i++){
    if(obj.options[i]!= nullptr){
    options[i] = new Option(*obj.options[i]);
    }else{
      options[i] = nullptr;
    }
  }
}

Car::~Car() {

  for(int i =0; i<5; i++){
    delete options[i];
    options[i] = nullptr;
  }

}

// Getters
std::string Car::getName() const {
    return name;
}

const Model& Car::getModel() const {
    return this->model;
}

const float Car::getPrice()const {
  float sum =0.0;
  for (int i = 0; i < 5; i++){
    if(options[i]!= nullptr)
    sum += options[i]->getPrice();
  }return sum;
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
      delete options[i];
      options[i] = nullptr;
      break;
    }
  }
}

void Car::optionToString() const {
  std::cout<<"Options(";
  for(int i =0;i<5;i++){
    if(options[i] != nullptr){
    std::cout<<"index "<<i+1;
    std::cout<<"code: ";
    std::cout<<options[i]->getCode();
    std::cout<<" label: ";
    std::cout<<options[i]->getLabel();
    std::cout<<" price: ";
    std::cout<<options[i]->getPrice();
    std::cout<<";";
    }     
  }
    std::cout<<")"<<std::endl;
}

void Car::display()const{
  std::cout<< "Car.display(): "<< std::endl;

  std::cout<< " Name: "<<this->getName()<< std::endl;
  std::cout<< " Model: "<< std::endl;
  this->model.display();
  this->optionToString();
}
}
