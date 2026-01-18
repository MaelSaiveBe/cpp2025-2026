#include "Actor.h"

Actor::Actor():Person(){
  id = 0;
}

Actor::Actor(const string& ln, const string& fn, int id):Person(ln, fn){
  this->id =id;
}

Actor::Actor(const Actor& other):Person(other.getLastName(),other.getFirstName()){
  this->id = other.getId();
}

int Actor::getId()const{
  return this->id;
}

void Actor::setId(int newId){
  this->id= newId;
}

Actor& Actor::operator=(const Actor& other) {
  Person::operator=(other);
  id = other.id;          
  return *this;
}
