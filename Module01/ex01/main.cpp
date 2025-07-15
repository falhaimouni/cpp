#include "Zombie.hpp"

int main(void)
{
    int N = 5;
    int i = 0;
    if (N <= 0)
    {
        std::cout << "Error: N must be greater than 0." << std::endl;
        return (1);
    }
    Zombie* horde = zombieHorde(N, "Zombie");
    while (i < N)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return (0);
}