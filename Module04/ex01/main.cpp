#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Creating a Dog and a Cat ===" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n=== Making Sounds ===" << std::endl;
    dog->makeSound();  // Should bark
    cat->makeSound();  // Should meow

    std::cout << "\n=== Deleting Dog and Cat ===" << std::endl;
    delete dog;
    delete cat;

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Protect the house");
    
    Dog copiedDog = originalDog; // Copy constructor

    std::cout << "Original Dog's Idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog's Idea:   " << copiedDog.getBrain()->getIdea(0) << std::endl;

    // Change idea in copied dog
    copiedDog.getBrain()->setIdea(0, "Eat food");

    std::cout << "\nAfter modifying copied dog's idea:" << std::endl;
    std::cout << "Original Dog's Idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog's Idea:   " << copiedDog.getBrain()->getIdea(0) << std::endl;

    return 0;
}
