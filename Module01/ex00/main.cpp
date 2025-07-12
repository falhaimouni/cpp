#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    Zombie* zombie1 = newZombie("Zombie1");
    zombie1->announce();
    randomChump("Zombie2");
    delete zombie1;
    return (0);
}
