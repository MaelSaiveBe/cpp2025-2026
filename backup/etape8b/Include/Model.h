#ifndef MODEL_H
#define MODEL_H

#include <cstdlib>
#include <istream>
enum Engine { Petrol, Diesel, Electric, Hybrid };
namespace carconfig {


class Model {

private:
  int power;
  char *name;
  float basePrice;
  Engine engine;

public:
  //constructors ---------------------------
  Model(const char *, int, Engine, float);
  Model();
  Model(const Model &);
  ~Model();

  //setters ----------------------------------
  void setName(const char *);
  void setEngine(Engine);
  void setBasePrice(float);
  void setPower(int);

  //getters ----------------------------------
  char *getName() const;
  int getPower() const;
  float getBasePrice() const;
  Engine getEngine() const;

  //Utils --------------------------------------------
  void display() const;
  std::string toString() const;
  static Engine stringToEngine(const std::string& s);
  static std::string engineToString(Engine e);

  //Oprerator -------------------------------------------------------
  Model &operator=(const Model &other);
  friend std::ostream& operator<<(std::ostream &os, const Model &m);
  friend std::istream& operator>>(std::istream &is, Model &m);

};
} // namespace carconfig
#endif
