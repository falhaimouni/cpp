#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string.h>
#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    Weapon();
    ~Weapon();
    std::string getType() const;
    void setType(std::string type);
};

#endif