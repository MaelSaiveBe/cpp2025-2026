#include <cstdlib>
enum Engine { Petrol,  Diesel, Electric, Hybrid };

class Model {

private:
  int power;
  char *name;
  float basePrice;
  Engine engine;

public:
  Model(const char *, int, Engine, float);
  Model();
  Model(Model &);
  ~Model();

  void setName(const char *);
  void setEngine(Engine);
  void setBasePrice(float);
  void setPower(int);

  const char *getName();
  const int getPower();
  const float getBasePrice();
  const Engine getEngine();

  void display();
};
