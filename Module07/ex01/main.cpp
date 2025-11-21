#include "iter.hpp"

template<typename T>
void printElement(const T& elem)
{
    std::cout << elem << " ";
}

template<typename T>
void incrementElement(T& elem)
{
    ++elem;
}

template<typename T>
void ft_toupper(T &elem)
{
    elem = std::toupper(elem);
}

template<typename T>
void ft_tolower(T &elem)
{
    elem = std::tolower(elem);
}

int main()
{
    char arr[] = {'a', 'b', 'c'};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Original array: ";
    ::iter(arr, len, printElement<char>);
    std::cout << std::endl;
    
    std::cout << "Array after iterating ft_toupper: ";
    ::iter(arr, len, ft_toupper<char>);
    ::iter(arr, len, printElement<char>);
    std::cout << std::endl;
    
    std::cout << "Array after iterating ft_tolower: ";
    ::iter(arr, len, ft_tolower<char>);
    ::iter(arr, len, printElement<char>);
    std::cout << std::endl;
    
    
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original intArray: ";
    ::iter(intArray, intSize, printElement<int>);
    std::cout << std::endl;
    
    iter(intArray, intSize, incrementElement<int>);
    
    std::cout << "After increment: ";
    ::iter(intArray, intSize, printElement<int>);
    std::cout << std::endl;
    return 0;
}


//     const int arrInt[] = {1,2,3};
// iter(arrInt, 3, printElement<int>);
// std::cout << std::endl;
