#include "ClapTrap.hpp"

int main() {
    std::cout << "----- Creating ClapTrap with parameterized constructor -----" << std::endl;
    ClapTrap clap1("Alpha");

    std::cout << "\n----- Copy constructing from clap1 -----" << std::endl;
    ClapTrap clap2(clap1);

    std::cout << "\n----- Using default constructor and assignment -----" << std::endl;
    ClapTrap clap3;
    clap3 = clap1;

    std::cout << "\n----- Testing attack -----" << std::endl;
    clap1.attack("target1");

    std::cout << "\n----- Testing takeDamage -----" << std::endl;
    clap2.takeDamage(4);

    std::cout << "\n----- Testing beRepaired -----" << std::endl;
    clap3.beRepaired(3);

    std::cout << "\n----- Draining energy -----" << std::endl;
    for (int i = 0; i < 10; ++i) {
        clap1.attack("DummyTarget");
    }

    std::cout << "\n----- Attempting to attack with no energy -----" << std::endl;
    clap1.attack("OutOfEnergyTarget");

    std::cout << "\n----- Taking fatal damage -----" << std::endl;
    clap2.takeDamage(100);

    std::cout << "\n----- Trying to repair after being destroyed -----" << std::endl;
    clap2.beRepaired(5);

    std::cout << "\n----- End of program, destructors will be called now -----" << std::endl;
    return 0;
}
