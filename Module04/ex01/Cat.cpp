#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat created with brain" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain); // deep copy
    std::cout << "Cat copied with brain" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain); // deep copy
        std::cout << "Cat assigned with brain" << std::endl;
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destroyed with brain" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!!!" << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}

void Cat::setIdea(int index, const std::string& idea)
{
    if (brain)
    {
        brain->setIdea(index, idea);
    }
}

std::string Cat::getIdea(int index) const {
    if (brain)
    {
        return brain->getIdea(index);
    }
    return "";
}