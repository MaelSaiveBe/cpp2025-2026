#include "Option.h"
#include <iostream>
#include <string>

namespace carconfig {
using std::string;
Option::Option() {
  code = "0000";
  label = "default option";
  price = 0.0;
}

Option::Option(const string &c, const string &l, float p) {

  setCode(c);
  setLabel(l);
  setPrice(p);
}

Option::Option(const Option &other) {
  code = other.code;
  label = other.label;
  price = other.price;
}

Option::~Option() {}

//-----------------getters------------------------------

string Option::getCode() const { return code; }

string Option::getLabel() const { return label; }

float Option::getPrice() const { return price; }

//---------------Setters--------------------------------
void Option::setCode(const string &c) {

  if(c.length()!=4)throw OptionException("Le code doit comporter 4 caractères");
  code = c;
}

void Option::setLabel(const string &l) {
  if(l.length()==0)throw OptionException("L'intitulé ne peut être vide");
  label = l;
}

void Option::setPrice(float p) { 
  if(p<0)throw OptionException("Le prix doit être positif.");
  price = p; }

std::ostream &operator<<(std::ostream &os, const Option &op) {
  os << "[Code: " << op.code << ", Label: " << op.label
     << ", Prix: " << op.price << "€]";
  return os;
}

Option& Option::operator--(){
  this->setPrice(this->getPrice()-50.0);
  return *this;
}

Option Option::operator--(int){
  Option temp(*this);
  --(*this);
  return temp;
}

std::istream &operator>>(std::istream &is, Option &op) {
  std::string codetemp, labelTemp;
  float priceTemp;

  std::cout << "entrer le code: " << std::endl;
  is >> codetemp;
  std::cin.ignore();
  std::cout << "entrer le label: " << std::endl;
  std::getline(is, labelTemp);
  std::cout << "entrer le prix: " << std::endl;
  is >> priceTemp;
  std::cin.ignore();
  op.setCode(codetemp);
  op.setPrice(priceTemp);
  op.setLabel(labelTemp);

  return is;
}
void Option::display() const {
  std::cout << "Option(code: " << code << ", label: " << label
            << ", Prix: " << price << std::endl;
}

} // namespace carconfig
