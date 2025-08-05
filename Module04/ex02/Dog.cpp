#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog created with brain" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog copied with brain" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
        std::cout << "Dog assigned with brain" << std::endl;
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed with brain" << std::endl;
}

void Dog::makeSound()const
{
    std::cout << "Woof!!!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}
