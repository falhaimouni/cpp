#ifndef AANIMAL_HPP
#define AANIMAL_HPP

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
    virtual void makeSound() const = 0;
};

#endif