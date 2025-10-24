#include "Model.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <string>

namespace carconfig {

Model::Model() {
  std::cout << "Constructeur par défaut Model()" << std::endl;
  name = nullptr;
  power = 0;
  basePrice = 0.0;
  setName("Default name");
}

Model::Model(const char *name, int power, Engine moteur, float basePrice) {
  this->power = power;
  this->basePrice = basePrice;
  this->engine = moteur;
  this->name = nullptr;

  setName(name);
}

Model::Model(const Model &obj) {
  this->power = obj.power;

  this->basePrice = obj.basePrice;

  this->engine = obj.engine;

  this->name = nullptr;
  setName(obj.getName());
}

Model::~Model() {

  std::cout << "Destructeur Model" << std::endl;
  if (this->name) {
    delete[] this->name;
  };
}
//--------------------SETTER ----------------------

//
void Model::setName(const char *name) {
  if (this->name)
    delete[] this->name;
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
  std::cout << this->name << std::endl;
}

void Model::setPower(int p) { this->power = p; }
void Model::setEngine(Engine e) { this->engine = e; }

void Model::setBasePrice(float bp) { this->basePrice = bp; }

//------------------GETTER-------------------------
//

char *Model::getName() const { return name; }

int Model::getPower() const { return power; }

float Model::getBasePrice() const { return basePrice; }

Engine Model::getEngine() const { return engine; }

//----------------UTILS------------------------------
//

void Model::display() const {
  std::cout << "Model-------------------------------------------------" << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "Model.display(): " << std::endl;
  std::cout << "  nom du model: " << this->getName() << std::endl;

  std::cout << "  puissance: " << getPower() << std::endl;
  std::cout << "  type du moteur: " << getEngine() << std::endl;
  std::cout << "  Prix de Base: " << getBasePrice() << std::endl;
  std::cout << "-------------------------------------------------" << std::endl;
  std::cout << "-------------------------------------------------Model" << std::endl;
}

Model &Model::operator=(const Model &other) {
  power = other.power;
  basePrice = other.basePrice;
  engine = other.engine;
  setName(other.getName());

  return *this;
}

std::ostream &operator<<(std::ostream &os, const Model &m) {
  os << "Model----------------------" << std::endl
     << "Nom: " << m.getName() << std::endl
     << "Puissance: " << m.getPower() << " Type moteur: " << m.getEngine()
     << std::endl
     << "Prix de Base: " << m.getBasePrice()<<std::endl;
  os << "----------------------Model";
  return os;
}
std::istream &operator>>(std::istream &is, Model &m) {
  std::string name;
  int power;
  int engineType;
  float basePrice;

  std::cout << "Nom du modèle : ";
  std::getline(is, name);
  std::cout << "Puissance : ";
  is >> power;

  std::cout << "Type moteur (0=Essence, 1=Diesel, 2=Electrique, 3=Hybride) : ";
  is >> engineType;

  std::cout << "Prix de base : ";
  is >> basePrice;

  m.setName(name.c_str());
  m.setPower(power);
  m.setEngine(static_cast<Engine>(engineType));
  m.setBasePrice(basePrice);

  return is;
}
}
