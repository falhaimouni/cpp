#include "Cat.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Cat created: " << type << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    type = other.type;
    std::cout << "Cat copied: " << type << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other) {
        Animal::operator=(other);
        type = other.type;
        std::cout << "Cat assigned: " << type << std::endl;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed: " << type << std::endl;
}

void    Cat::makeSound()const
{
    std::cout << "Meow!!!" << std::endl;
}
