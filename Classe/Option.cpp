#include "Option.h"
#include <iostream>
#include <iterator>

namespace carconfig{
using std::string;
Option::Option(){
  code = "0000";
  label = "default option";
  price = 0.0;
}

Option::Option(const string& c,const string& l,float p){
  code = c;
  label = l;
  price = p;
}

Option::Option(const Option& other){
  code = other.code;
  label = other.label;
  price = other.price;
}

Option::~Option(){

}


//-----------------getters------------------------------

string Option::getCode()const{
  return code;
}

string Option::getLabel()const{
  return label;
}

float Option::getPrice()const{
  return price;
}


//---------------Setters--------------------------------
void Option::setCode(const string& c){
  code = c;
}

void Option::setLabel(const string& l){
  label = l;
}

void Option::setPrice(float p){
  price = p;
}

void Option::display() const{
  std::cout<< "Option(code: "<<code<<", label: "<<label<<", Prix: "<<price<<std::endl;
}

}
