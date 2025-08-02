#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog created: " << type << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    type = other.type;
    std::cout << "Dog copied: " << type << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other) {
        Animal::operator=(other);
        type = other.type;
        std::cout << "Dog assigned: " << type << std::endl;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destroyed: " << type << std::endl;
}

void    Dog::makeSound()const
{
    std::cout << "Woof!" << std::endl;
}
