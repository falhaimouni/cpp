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

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        value = other.value;
        std::cout << "Copy assignment operator called" << std::endl;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// val << 8 = val × 256 
Fixed::Fixed(const int val) : value(val << fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

// takes the value Multiplies it by 256 (i.e., 1 << 8)
// Rounds the result
// Stores it in value
Fixed::Fixed(const float val) : value(roundf(val * (1 << fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const
{
    return static_cast<float>(value) / (1 << fractionalBits);
}

int Fixed::toInt() const
{
    return value >> fractionalBits;
}
//operation overloading 
//allows you to print fixed objects using cout 
//Automatically converts the fixed-point value to a float before printing
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

