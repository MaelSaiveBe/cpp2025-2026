#include <set>
#include <list>
#include <string>
#include <iterator>
#include "Client.h"
#include "Employee.h"
#include "Model.h"
#include "Option.h"
#include "Car.h"


class Garage 
{ 
  private:
    Garage();
    static Garage instance;
    Garage(const Garage&) = delete;
    Garage& operator=(const Garage&) = delete;

    static carconfig::Car currentProject;

    std::set<Employee> employees;  
    std::set<Client>   clients;

    std::list<carconfig::Model>   models; 
    std::list<carconfig::Option>  options; 
 
  public: 
    
    static Garage& getInstance();
    static carconfig::Car& getCurrentProject();
    static void resetCurrentProject(); 
 
    void   addModel(const carconfig::Model & m); 
    void   displayAllModels() const; 
    carconfig::Model  getModel(int index) const; 
 
    void   addOption(const carconfig::Option & o); 
    void   displayAllOptions() const; 
    carconfig::Option getOption(int index)const; 
 
    int    addClient(const string& lastName,const string& firstName,const string& gsm); 
    void   displayClients() const; 
    void   deleteClientByIndex(int index); 
    void   deleteClientById(int id); 
    Client findClientByIndex(int index) const; 
    Client findClientById(int id) const; 
 
    int addEmployee(const string& lastName,const string& firstName,const string& login, const string& role); 
    void     displayEmployees() const; 
    void     deleteEmployeeByIndex(int index); 
    void     deleteEmployeeById(int id); 
    Employee findEmployeeByIndex(int index) const; 
    Employee findEmployeeById(int id) const; 
}; 