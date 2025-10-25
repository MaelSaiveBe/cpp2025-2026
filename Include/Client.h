#ifndef CLIENT_H
#define CLIENT_H

#include "Actor.h"
#include <string>

class Client: public Actor{
private:
  std::string& gsm;
public:

 Client();
  Client(const std::string& ln, const string& fn, int id, const string& gsm);
 Client(const Client& other);
 
 string getGsm();

 void setGsm();
  
   
};

#endif
