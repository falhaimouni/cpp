#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

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
    int getRawBits()const;
    void setRawBits(int raw);
    float toFloat() const;
    int toInt() const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif