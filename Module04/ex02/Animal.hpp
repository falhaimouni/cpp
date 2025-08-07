#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal(); // Declare virtual destructor for proper cleanup of derived classes

    std::string	getType() const;
    virtual void makeSound() const = 0; // Declare makeSound as a pure virtual function to make Animal an abstract class
};
// Declare makeSound as virtual to allow polymorphic behavior

#endif