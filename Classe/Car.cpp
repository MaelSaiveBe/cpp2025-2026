#include "Car.h"
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <tuple>
namespace carconfig {
using std::string;

Car::Car()
    : name("Projet Inconnu"), model() // pas "model = Model();"????
{
  for (int i = 0; i < 5; i++) {
    options[i] = nullptr;
  }
}

// Constructeur paramétré
Car::Car(const std::string &n, const Model &m) {
  name = n;
  model = m;
  for (int i = 0; i < 5; i++) {
    options[i] = nullptr;
  }
}

Car::Car(const Car &obj) {
  name = obj.name;
  model = obj.model;
  for (int i = 0; i < 5; i++) {
    if (obj.options[i] != nullptr) {
      options[i] = new Option(*obj.options[i]);
    } else {
      options[i] = nullptr;
    }
  }
}

Car::~Car() {

  for (int i = 0; i < 5; i++) {
    delete options[i];
    options[i] = nullptr;
  }
}

// Getters
std::string Car::getName() const { return name; }

const Model &Car::getModel() const { return this->model; }

const float Car::getPrice() const {
  float sum = 0.0;
  for (int i = 0; i < 5; i++) {
    if (options[i] != nullptr)
      sum += options[i]->getPrice();
  }
  return sum + getModel().getBasePrice();
}

// Setters
void Car::setName(const std::string &newName) { name = newName; }

void Car::setModel(const Model &newModel) { model = newModel; }

void Car::addOption(const Option &option) {
  for (int i = 0; i < 5; i++) {
    if (options[i] == nullptr) {
      options[i] = new Option(option);
      break;
    }
  }
}

void Car::removeOption(const std::string &target) {
  for (int i = 0; i < 5; i++) {

    if (options[i] != nullptr) {
      if (options[i]->getCode() == target) {
        delete options[i];
        options[i] = nullptr;
        break;
      }
    }
  }
}

Car &Car::operator=(const Car &other) {
  if (this != &other) {
    name = other.name;
    model = other.model;
    for (int i = 0; i < 5; ++i) {
      delete options[i];
      options[i] = (other.options[i]) ? new Option(*other.options[i]) : nullptr;
    }
  }
  return *this;
}

Car Car::operator+(const Option &op) const {
  Car result = Car(*this);
  result.addOption(op);
  return result;
}

Car operator+(const Option &op, const Car &car) { return car + op; }

Car Car::operator-(const std::string &code) const {
  Car result = Car(*this);
  result.removeOption(code);
  return result;
}
Car Car::operator-(const Option &op) const {
  Car result = Car(*this);
  result.removeOption(op.getCode());
  return result;
}

bool Car::operator<(const Car& other)const{
  return this->getPrice()<other.getPrice();
}

bool Car::operator>(const Car&other)const{
  return this->getPrice()>other.getPrice();
}

bool Car::operator==(const Car& other)const{
  return this->getPrice()==other.getPrice();
}

std::ostream& operator<<(std::ostream& os, const Car& car){
  os<<"Car------------------------------------------"<<std::endl;
  os<<"Nom: "<<car.getName()<<std::endl<<car.getModel()<<std::endl;
  os<<car.optionToString();
  os<<"------------------------------------------Car"<<std::endl;
  return os;
}


Option* Car::operator[](int index){
  return options[index];
}


string Car::optionToString() const {
  string temp;
  temp+= "Options(";
  for (int i = 0; i < 5; i++) {
    if (options[i] != nullptr) {
      temp+="[";
      temp+= std::to_string(i + 1);
      temp +="] ";
      temp+="code: ";
    temp += options[i]->getCode();
      temp+= " label: ";
      temp+= options[i]->getLabel();
      temp+= " price: ";
      temp+= std::to_string(options[i]->getPrice());
      temp+= ";\n";
    }
  }
  return temp+")";
}

void Car::display() const {
  std::cout << "Car.display(): " << std::endl;

  std::cout << " Name: " << this->getName() << std::endl;
  std::cout << " Model: " << std::endl;
  this->model.display();
  std::cout<<this->optionToString();
}
} // namespace carconfig
