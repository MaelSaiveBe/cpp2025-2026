enum Engine { Petrol, Diesel, Electric, Hybrid }; 


class Model {
  
private:

  int power;
  char* name;
  float basePrice;
  Engine engine;

public:
  Model(int, char*, float, Engine);
  Model();
  Model(Model&);
  ~Model();

  void setName(char*);

  char* getName();
  
  void display();
  
};
