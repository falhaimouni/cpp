#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("Default") {
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called." << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    hitPoint = 100;
    energyPoint = 50;
    attackDamage = 20;
    std::cout << "ScavTrap parameterized constructor called for " << name << "." << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called." << std::endl;
}

// Assignment operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    ClapTrap::operator=(other);
    std::cout << "ScavTrap assignment operator called." << std::endl;
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called." << std::endl;
}

// Override attack
void ScavTrap::attack(const std::string& target) {
    if (energyPoint > 0 && hitPoint > 0) {
        std::cout << "ScavTrap " << name << " fiercely attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoint--;
    } else {
        std::cout << "ScavTrap " << name << " has no energy to attack!" << std::endl;
    }
    std::cout << "Energy left: " << energyPoint << ", Hit points: " << hitPoint << std::endl;
}

// guardGate
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}
