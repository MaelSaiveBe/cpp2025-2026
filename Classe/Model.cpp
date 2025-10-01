#include "Model.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>

Model::Model() {
  std::cout << "Constructeur par défaut Model()" << std::endl;
  name = nullptr;
  setName("Default name");
}

Model::Model(int power, char* name, float basePrice, Engine moteur){
  this->power = power;
  this->basePrice = basePrice;
  this->engine = moteur;
  setName(name);

} 

Model::Model(Model &obj){
  this->power = obj.power;
  
  this->basePrice= obj.basePrice;
  
  this->engine = obj.engine;

  setName(obj.getName());

}

Model::~Model() {

  std::cout << "Destructeur Model" << std::endl;
  if(name){
    delete[] name;
  };
}

void Model::setName(char* name) {
  if (!name)
    return;
  if (name)
    delete[] name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}
