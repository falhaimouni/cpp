#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

/*
fixed point number is a way of storing numbers with decimal precision
but without using real floating hardware(float or double types)
instead , you store the number as an integer and pretend there's 
fixed decimal point.

What does "8 fractional bits" mean?
It means the last 8 bits of the number are used to represent the decimal (fractional) part.
So when we convert a decimal to fixed-point, we multiply it by 2⁸ = 256.
That way, the first 8 bits = fraction
The rest = integer part

if you want to store decimal number like 1.5 
1.5 × 256 = 384
int value = 384
but in my mind its 
value / 256.0f = 1.5

in our program :
shift left when storing (multibly by 256)
shift right or divide when reading. 
*/ 
class Fixed
{
private:
    int value;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const int val);
    Fixed(const float val);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    float toFloat() const;
    int toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif