#ifndef CAR_H
#define CAR_H

#include <string>
#include "Model.h"
namespace carconfig {
class Car {
private:
    std::string name;
    Model model;

public:
    // --- Constructeurs ---
    Car();                                        
    Car(const std::string& name, const Model& m);
    Car(const Car& other);                      

    // --- Destructeur ---
    ~Car();

    // --- Getters ---
    std::string getName() const;
   const Model& getModel() const;

    // --- Setters ---
    void setName(const std::string& newName);
    void setModel(const Model& newModel);

    //----Utils--------
    void display()const;
};
}
#endif
