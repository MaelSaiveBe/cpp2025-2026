#include "Model.h"
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <ostream>

Model::Model() {
  std::cout << "Constructeur par défaut Model()" << std::endl;
  name = nullptr;
  std::cout << "iwas here" << std::endl;
  setName("Default name");
}

Model::Model(const char *name, int power, Engine moteur, float basePrice) {
  this->power = power;
  this->basePrice = basePrice;
  this->engine = moteur;
  this->name = nullptr;

  setName(name);
}

Model::Model(Model &obj) {
  this->power = obj.power;

  this->basePrice = obj.basePrice;

  this->engine = obj.engine;

  this->name = nullptr;
  setName(obj.getName());
}

Model::~Model() {

  std::cout << "Destructeur Model" << std::endl;
  if (name) {
    delete[] name;
  };
}
//--------------------SETTER ----------------------
//
void Model::setName(const char *name) {
  if (!name)
    return;
  if (name)
    delete[] this->name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}

void Model::setPower(int p) { this->power = p; }
void Model::setEngine(Engine e) { this->engine = e; }

void Model::setBasePrice(float bp) { this->basePrice = bp; }

//------------------GETTER-------------------------
//

const char *Model::getName() { return name; }

const int Model::getPower() { return power; }

const float Model::getBasePrice() { return basePrice; }

const Engine Model::getEngine() { return engine; }

//----------------UTILS------------------------------
//

void Model::display() {
  std::cout<< "-------------------------------------------------"<<std::endl;
  std::cout<< "-------------------------------------------------"<<std::endl;
  std::cout << "Model.display(): " << std::endl;
  std::cout << "  nom du model: " << getName() << std::endl;

  std::cout << "  puissance: " << getPower() << std::endl;
  std::cout << "  nom du moteur: "<< getEngine() << std::endl;
  std::cout << "  Prix de Base: "<<getBasePrice()<< std::endl;
  std::cout<< "-------------------------------------------------"<<std::endl;
  std::cout<< "-------------------------------------------------"<<std::endl;
}

