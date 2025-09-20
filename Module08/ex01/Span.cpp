#include "Span.hpp"

Span::Span()
{
}

Span::~Span()
{
}

Span::Span(const Span &other)
{
    _maxSize = other._maxSize;
    _numbers = other._numbers;
}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this; 
}

Span::Span(unsigned int n) : _maxSize(n) {}

void Span::addNumber(int value)
{
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Span is full");
    _numbers.push_back(value);
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find span");
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 0; i < sorted.size() - 1; i++) {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < minSpan)
                minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find span");
    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    return maxVal - minVal;
}