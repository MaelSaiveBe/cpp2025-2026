#ifndef ACTOR_H
#define ACTOR_H

#include "Person.h"
#include <string>
#include <tuple>


class Actor : public Person {
private:
  int id;

public:
    // --- Constructeurs / destructeur ---
    Actor(); 
    Actor(const std::string& name, const std::string& firstname, int id);
    Actor(const Actor& other);

    // --- Getters / Setters ---
    int getId() const;
    void setId(int newId);

    // --- Méthodes virtuelles ---
    virtual std::string tuple() const = 0; 
    virtual std::string toString() const= 0;

    //--- Operator ---
    Actor& operator=(const Actor& other); 
};


#endif
