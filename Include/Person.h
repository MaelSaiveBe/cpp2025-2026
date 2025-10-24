#ifndef PERSON_H
#define PERSON_H


#include <istream>
#include <ostream>
#include <string>
#include <strstream>

using std::string;


class Person{
  private:
  string lastName;
  string firstName;

public:

  // --- Constructeurs ---
  Person();
  Person(const string& fn, const string& ln);
  Person(const Person& other);

  // --- Destructeurs ---
  ~Person();

  // --- Getters ---

  string getLastName()const ;
  string getFirstName()const ;
  
  // --- Setters ---

  void setLastName(const string newLastName);
  void setFirstName(const string newFirstName);

  friend std::ostream& operator<<(std::ostream& os, const Person& p);
  friend std::istream& operator>>(std::istream& is, Person& p);

  Person& operator=(const Person& p);

};
#endif PERSON_H
