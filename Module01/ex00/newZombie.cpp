#include "Zombie.hpp"
#include "string.h"

Zombie* newZombie( std::string name)
{
    Zombie* zombie = new Zombie(name);
    return (zombie);
}