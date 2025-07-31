#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoint(10), energyPoint(10), attackDamage(0) {
    std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10), attackDamage(0) {
    std::cout << "ClapTrap parameterized constructor called for " << name << "." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) 
    : name(other.name), hitPoint(other.hitPoint), energyPoint(other.energyPoint), attackDamage(other.attackDamage) {
    std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        name = other.name;
        hitPoint = other.hitPoint;
        energyPoint = other.energyPoint;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap assignment operator called." << std::endl;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (energyPoint > 0 && hitPoint > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoint--;
    } else {
        std::cout << "ClapTrap " << name << " cannot attack!" << std::endl;
    }
    std::cout << "Energy left: " << energyPoint << ", Hit points: " << hitPoint << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoint > 0) {
        hitPoint -= static_cast<int>(amount);
        if (hitPoint < 0) hitPoint = 0;
        std::cout << "ClapTrap " << name << " takes " << amount 
                  << " points of damage! Hit points left: " << hitPoint << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
    }
    std::cout << "Energy left: " << energyPoint << ", Hit points: " << hitPoint << std::endl;
}


void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoint > 0 && hitPoint > 0) {
        hitPoint += amount;
        energyPoint--;
        std::cout << "ClapTrap " << name << " repairs itself for " 
                  << amount << " points! Hit points now: " << hitPoint << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;
    }
    std::cout << "Energy left: " << energyPoint << ", Hit points: " << hitPoint << std::endl;
}


