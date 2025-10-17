
#ifndef OPTION_H
#define OPTION_H

#include <string>
#include <iostream>

namespace carconfig {

class Option {
private:
    std::string code;
    std::string label;
    float price;
public:
    // --- Constructeurs ---
    Option();
    Option(const std::string& c, const std::string& l, float p);
    Option(const Option& other);

    // --- Destructeur ---
    ~Option();

    // --- Getters ---
    std::string getCode() const;
    std::string getLabel() const;
    float getPrice() const;

    // --- Setters ---
    void setCode(const std::string& c);
    void setLabel(const std::string& l);
    void setPrice(float p);

    // ---Utils-- ---
    void display() const;
};

} 

#endif
