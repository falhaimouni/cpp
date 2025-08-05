// WrongCat.cpp
#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat created: " << type << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat copied: " << type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
        std::cout << "WrongCat assigned: " << type << std::endl;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed: " << type << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Miaaaawww (wrong cat?)" << std::endl;
}
