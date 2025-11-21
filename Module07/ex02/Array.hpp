#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
    T *arr;
    unsigned int size;

public:
    Array()
    {
        arr = new T[0];
        size = 0;
    }
    Array(unsigned int n)
    {
        arr = new T[n];
        for (unsigned int i = 0; i < n; i++)
            arr[i] = T();
        size = n;
    }

    Array(const Array &other)
    {
        size = other.size;
        arr = new T[size];
        for (unsigned int i = 0; i < size; ++i)
            arr[i] = other.arr[i];
    }

    Array &operator=(const Array &other)
    {
        if (this != &other)
        {
            delete[] arr;
            size = other.size;
            arr = new T[size];
            for (unsigned int i = 0; i < size; ++i)
                arr[i] = other.arr[i];
        }
        return *this;

    }

    ~Array()
    {
        delete[] arr;
    }

    T &operator[](unsigned int index)
    {
        if (index >= size)
            throw std::out_of_range("Index out of bounds");
        return arr[index];
    }

    const T &operator[](unsigned int index) const
    {
        if (index >= size)
            throw std::out_of_range("Index out of bounds");
        return arr[index];
    }

    unsigned int getSize() const
    {
        return size;
    }
};

#endif
