#ifndef MODEL_H
#define MODEL_H

#include <cstdlib>
#include <istream>
namespace carconfig {
enum Engine { Petrol, Diesel, Electric, Hybrid };

class Model {

private:
  int power;
  char *name;
  float basePrice;
  Engine engine;

public:
  Model(const char *, int, Engine, float);
  Model();
  Model(const Model &);
  ~Model();

  void setName(const char *);
  void setEngine(Engine);
  void setBasePrice(float);
  void setPower(int);

  char *getName() const;
  int getPower() const;
  float getBasePrice() const;
  Engine getEngine() const;

  void display() const;

  Model &operator=(const Model &other);
  friend std::ostream& operator<<(std::ostream &os, const Model &m);
  friend std::istream& operator>>(std::istream &is, Model &m);
};
} // namespace carconfig
#endif
