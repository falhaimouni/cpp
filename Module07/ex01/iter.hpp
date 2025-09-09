#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>
#include <cctype>

template <typename T, typename F> // the second param to tell the
// compiler that i accept any type of function
void iter(T arr[], size_t len, F f)
{
    size_t i = 0;
    while (i < len)
    {
        f(arr[i]);
        i++;
    }
}

#endif