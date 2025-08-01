#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    value = other.value;
    std::cout << "Copy constructor called" << std::endl;
}

// copy assignment operator 
Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other) //this checks if the object not assigning itself.
    {
        value = other.value;
        std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this; //returns the refernce for an object.
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
    std::cout << "setRawBits member function called" << std::endl;
}
