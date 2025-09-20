#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <limits>

class Span
{
private:
    unsigned int _maxSize;
    std::vector <int> _numbers;
public:
    Span();
    Span(unsigned int n);
    Span(const Span &other);
    int shortestSpan();
    int longestSpan();
    Span& operator=(const Span &other);
    ~Span();

    void addNumber(int value);
};




#endif