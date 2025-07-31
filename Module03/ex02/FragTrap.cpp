#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default FragTrap") {
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap parameterized constructor called for " << name << "." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        std::cout << "FragTrap assignment operator called." << std::endl;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << this->name << "." << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->name << " requests a high five!" << std::endl;
}
