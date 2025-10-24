#include "Person.h"
#include <iostream>
#include <string>

Person::Person(){
  this->setFirstName("John");
  this->setLastName("Doe");
}

Person::Person(const string& fn, const string& ln){
  this->setLastName(ln);
  this->setFirstName(fn);
}

Person::Person(const Person& other){
  this->setFirstName(other.getFirstName());
  this->setLastName(other.getLastName());
}

string Person::getLastName()const{
  return this->lastName;
}

string Person::getFirstName()const{
  return this->firstName;
}

void Person::setLastName(const string newLastName){
  this->lastName = newLastName;
}

void Person::setFirstName(const string newFirstName){
  this->firstName = newFirstName;
}

std::ostream& operator<<(std::ostream os, const Person& p){
  os<<"Person--------------------"<<std::endl;
  os<<"Prenom: "<<p.getFirstName()<<std::endl<<"Nom de Famille: "<<p.getLastName()<<std::endl;
  os<<"--------------------Person";
  return os;
}

std::istream& operator>>(std::istream is, Person& p){
  string fn,ln;
  std::cout<<"Entrer le prénom: "<<std::endl;
  std::getline(is, fn);

  std::cout<<"Entrer le nom de famille: "<<std::endl;
  std::getline(is, ln);
  
  p.setFirstName(fn);
  p.setLastName(ln);

  return is;
}

Person& Person::operator=(const Person& p){
  this->setLastName(p.getLastName());
  this->setFirstName(p.getFirstName());
  return *this;
}
