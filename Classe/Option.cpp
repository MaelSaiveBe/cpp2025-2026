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

std::ostream& operator<<(std::ostream& os, const Option& o)
{
    os << "<Option>" << std::endl;
    os << "<code>" << std::endl;
    os << o.getCode() << std::endl;
    os << "</code>" << std::endl;

    os << "<label>" << std::endl;
    os << o.getLabel() << std::endl;
    os << "</label>" << std::endl;

    os << "<price>" << std::endl;
    os << o.getPrice() << std::endl;
    os << "</price>" << std::endl;

    os << "</Option>" << std::endl;

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

std::istream& operator>>(std::istream& is, Option& o)
{
    std::string line;
    std::string code, label, priceStr;
    // <Option>
    std::getline(is, line);

    // <code>
    std::getline(is, line); 
    std::getline(is, code);
    std::getline(is, line);
    // <label>
    std::getline(is, line); 
    std::getline(is, label);
    std::getline(is, line); 
    // <price>
    std::getline(is, line); 
    std::getline(is, priceStr);
    std::getline(is, line); 
    // </Option>
    std::getline(is, line); 

    float price = std::stof(priceStr);

    o.setCode(code);
    o.setLabel(label);
    o.setPrice(price);

    return is;
}

void Option::display() const {
  std::cout << "Option(code: " << code << ", label: " << label
            << ", Prix: " << price << std::endl;
}

std::string Option::toString() const
{
    return "[Code: " + code +
           ", Label: " + label +
           ", Prix: " + std::to_string(price) + "€]";
}

} // namespace carconfig
