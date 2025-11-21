#include "Array.hpp"
#include <iostream>

int main()
{
    Array<int> a(5);
    for (unsigned int i = 0; i < a.getSize(); ++i)
        a[i] = i * 10;

    Array<int> c = a; // Deep copy
    std::cout << c[3] << std::endl;
    Array<int> b = a; // Deep copy
    b[0] = 999;

    std::cout << "Original array:\n";
    for (unsigned int i = 0; i < a.getSize(); ++i)
        std::cout << a[i] << " ";
    std::cout << "\n";

    std::cout << "Copied array:\n";
    for (unsigned int i = 0; i < b.getSize(); ++i)
        std::cout << b[i] << " ";
    std::cout << "\n";

    return 0;
}
