#include "Zombie.hpp"
#include "string.h"

void randomChump( std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}