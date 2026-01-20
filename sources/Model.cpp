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
  image = " ";
  setName("Default name");
}

Model::Model(const char *name, int power, Engine moteur, float basePrice) {
  this->power = power;
  this->basePrice = basePrice;
  this->engine = moteur;
  this->name = nullptr;
  image = " ";

  setName(name);
}

Model::Model(const Model &obj) {
  this->power = obj.power;

  this->basePrice = obj.basePrice;

  this->engine = obj.engine;
  image = " ";

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

void Model::setImage(const std::string& path){ this->image = path; }

//------------------GETTER-------------------------
//

char *Model::getName() const { return name; }

int Model::getPower() const { return power; }

float Model::getBasePrice() const { return basePrice; }

Engine Model::getEngine() const { return engine; }

std::string Model::getImage() const {return image;}

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
  std::cout<< "path img: "<<getImage()<<std::endl;
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

// std::ostream &operator<<(std::ostream &os, const Model &m) {
//   os << "Model----------------------" << std::endl
//      << "Nom: " << m.getName() << std::endl
//      << "Puissance: " << m.getPower() << " Type moteur: " << m.getEngine()
//      << std::endl
//      << "Prix de Base: " << m.getBasePrice()<<std::endl;
//   os << "----------------------Model";
//   return os;
// }

std::ostream& operator<<(std::ostream& os, const Model& m)
{
    os << "<Model>" << std::endl;

    os << "<name>" << std::endl;
    os << m.getName() << std::endl;
    os << "</name>" << std::endl;

    os << "<power>" << std::endl;
    os << m.getPower() << std::endl;
    os << "</power>" << std::endl;

    os << "<engine>" << std::endl;
    os << Model::engineToString(m.getEngine()) << std::endl;
    os << "</engine>" << std::endl;

    os << "<basePrice>" << std::endl;
    os << m.getBasePrice() << std::endl;
    os << "</basePrice>" << std::endl;

    os << "</Model>" << std::endl;

    return os;
}

// std::istream &operator>>(std::istream &is, Model &m) {
//   std::string name;
//   int power;
//   int engineType;
//   float basePrice;

//   std::cout << "Nom du modèle : ";
//   std::getline(is, name);
//   std::cout << "Puissance : ";
//   is >> power;

//   std::cout << "Type moteur (0=Essence, 1=Diesel, 2=Electrique, 3=Hybride) : ";
//   is >> engineType;

//   std::cout << "Prix de base : ";
//   is >> basePrice;

//   m.setName(name.c_str());
//   m.setPower(power);
//   m.setEngine(static_cast<Engine>(engineType));
//   m.setBasePrice(basePrice);

//   return is;
// }
std::istream& operator>>(std::istream& is, Model& m)
{
    std::string line;
    std::string name, powerStr, engineStr, priceStr;
    // <Model>
    std::getline(is, line); 
    // <name>
    std::getline(is, line); 
    std::getline(is, name);
    std::getline(is, line); 
    // <power>
    std::getline(is, line); 
    std::getline(is, powerStr);
    std::getline(is, line); 
    // <engine>
    std::getline(is, line); 
    std::getline(is, engineStr);
    std::getline(is, line);
    // <basePrice>
    std::getline(is, line); 
    std::getline(is, priceStr);
    std::getline(is, line); 
    // </Model>
    std::getline(is, line); 

    int power = std::stoi(powerStr);
    float price = std::stof(priceStr);
    Engine engine = Model::stringToEngine(engineStr);

    m.setName(name.c_str());
    m.setPower(power);
    m.setEngine(engine);
    m.setBasePrice(price);

    return is;
}

std::string Model::toString() const
{
    std::string result;

    result += "[";
    result += name;
    result += ", ";
    result += "img: ";
    result += getImage();
    result+= ", ";
    result += std::to_string(power);
    result += " ch, ";
    result += engineToString(engine);
    result += ", ";
    result += std::to_string(basePrice);
    result += " €]";

    return result;
}



 std::string Model::engineToString(Engine e)
{
    switch (e)
    {
        case Engine::Petrol:   return "Essence";
        case Engine::Diesel:   return "Diesel";
        case Engine::Hybrid:   return "Hybride";
        case Engine::Electric: return "Electrique";
    }
    return "";
}


 Engine Model::stringToEngine(const std::string& s)
{
    if (s == "Essence")    return Engine::Petrol;
    if (s == "Diesel")     return Engine::Diesel;
    if (s == "Hybride")    return Engine::Hybrid;
    if (s == "Electrique") return Engine::Electric;

    //throw Exception("Type de moteur invalide"); Si j'ai le temps;
}
}
