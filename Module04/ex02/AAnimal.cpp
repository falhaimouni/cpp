#include "AAnimal.hpp"

Animal::Animal() : type("Default")
{
    std::cout << "Animal created: " << type << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
    std::cout << "Animal copied: " << type << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    if (this != &other) {
        type = other.type;
        std::cout << "Animal assigned: " << type << std::endl;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destroyed: " << type << std::endl;
}

std::string Animal::getType()const
{
    return(this->type);
}

void    Animal::makeSound()const
{
    std::cout << "Any animal sound" << std::endl;
}