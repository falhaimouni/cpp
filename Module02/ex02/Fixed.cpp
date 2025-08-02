#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int intValue)
{
    value = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    value = roundf(floatValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    value = other.value;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        value = other.value;
    return *this;
}

bool Fixed::operator>(const Fixed &other) const { return value > other.value; }
bool Fixed::operator<(const Fixed &other) const { return value < other.value; }
bool Fixed::operator>=(const Fixed &other) const { return value >= other.value; }
bool Fixed::operator<=(const Fixed &other) const { return value <= other.value; }
bool Fixed::operator==(const Fixed &other) const { return value == other.value; }
bool Fixed::operator!=(const Fixed &other) const { return value != other.value; }

Fixed Fixed::operator+(const Fixed &other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed &other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed &other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed &other) const { return Fixed(this->toFloat() / other.toFloat()); }

Fixed& Fixed::operator++()//pre fix
{
    value++;
    return *this;
}

Fixed Fixed::operator++(int)//post fix
{
    Fixed tmp = *this;
    ++(*this);
    return tmp;
}

Fixed& Fixed::operator--()
{
    value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    --(*this);
    return tmp;
}

float Fixed::toFloat() const
{
    return (float)value / (1 << fractionalBits);
}

int Fixed::toInt() const
{
    return value >> fractionalBits;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
