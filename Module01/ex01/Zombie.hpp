#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
    std::string name;
public:
    Zombie();
    ~Zombie();
    void setName(std::string name);
    void announce(void);
};

Zombie* zombieHorde( int N, std::string name);

#endif