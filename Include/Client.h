#ifndef CLIENT_H
#define CLIENT_H

#include "Actor.h"
#include <string>

class Client: public Actor{
private:
  std::string gsm;
public:

  Client();
  Client(const std::string& ln, const std::string& fn, int id, const std::string& gsm);
  Client(const Client& other);
  virtual ~Client();
 
  Client& operator=(const Client& other);
  std::string getGsm()const;

  void setGsm(const std::string& gsm);
  
  std::string tuple() const override;
  std::string toString() const override;
   
};

#endif
