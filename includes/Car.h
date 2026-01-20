#ifndef CAR_H
#define CAR_H

#include "Model.h"
#include "Option.h"
#include <string>

namespace carconfig {

class Car {
private:
  std::string name;
  Model model;
  Option *options[5];

public:
  // --- Constructeurs ---
  Car();
  Car(const std::string &name, const Model &m);
  Car(const Car &other);

  // --- Destructeur ---
  ~Car();

  // --- Getters ---
  std::string getName() const;
  const Model &getModel() const;
  const float getPrice() const;

  // --- Setters ---
  void setName(const std::string &newName);
  void setModel(const Model &newModel);

  //----option management --------------
  void addOption(const Option &option);
  void removeOption(const std::string &target);
  //----------Operator------------------------
  Car &operator=(const Car &other);
  Car operator+(const Option &op) const;
  Car operator-(const Option &op) const;
  Car operator-(const std::string &code) const;
  friend Car operator+(const Option &op, const Car &car);
  bool operator<(const Car &) const;
  bool operator>(const Car &) const;
  bool operator==(const Car &) const;
  friend std::ostream& operator<<(std::ostream& os, const Car& c);
  friend std::istream& operator>>(std::istream& is, Car& c);

  Option*& operator[](int index);
  Option* operator[](int index)const;

  //----Utils--------
  void display() const;
  void save() const;
  void load(std::string filename);

  std::string optionToString() const;
};
} // namespace carconfig
#endif
