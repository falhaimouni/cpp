#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    const int SIZE = 2;
    Animal* animals[SIZE];

    // Fill half with Dogs, half with Cats
    for (int i = 0; i < SIZE; ++i) {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Testing deep copy ---\n";
    Dog originalDog;
    originalDog.setIdea(0, "Chase the cat!");
    Dog copiedDog = originalDog;  // Calls copy constructor

    std::cout << "Original Dog Idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea:   " << copiedDog.getIdea(0) << std::endl;

    originalDog.setIdea(0, "Eat a bone.");
    std::cout << "After changing original:\n";
    std::cout << "Original Dog Idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog Idea:   " << copiedDog.getIdea(0) << std::endl;

    std::cout << "\n--- Cleaning up ---\n";
    for (int i = 0; i < SIZE; ++i) {
        delete animals[i];  // Should call Dog/Cat -> Animal -> Brain destructors
    }

    return 0;
}
