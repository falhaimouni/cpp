#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap()
    : ClapTrap("Default_clap_name"), FragTrap("Default"), ScavTrap("Default"), name("Default") {
    hitPoint = 100;        // from FragTrap
    energyPoint = 50;      // from ScavTrap
    attackDamage = 30;     // from FragTrap
    std::cout << "DiamondTrap default constructor called." << std::endl;
}

// Parameterized constructor
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 30;
    std::cout << "DiamondTrap parameterized constructor called for " << name << "." << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name) {
    std::cout << "DiamondTrap copy constructor called." << std::endl;
}

// Assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        name = other.name;
        std::cout << "DiamondTrap assignment operator called." << std::endl;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called." << std::endl;
}

// whoAmI
void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap named \"" << name
              << "\" and my ClapTrap name is \"" << ClapTrap::name << "\"." << std::endl;
}
