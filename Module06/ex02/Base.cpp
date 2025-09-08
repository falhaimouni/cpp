#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base()
{}

Base * generate(void)
{
    srand(time(NULL));
    int r = rand() % 3;

    switch (r)
    {
    case 0 :
        return new A();
    case 1 :
        return new B();
    case 2 :
        return new C();
    }
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer : This is A class\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Pointer : This is B class\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Pointer : This is C class\n";
    else
        std::cout << "Pointer : This is Unknowen class\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Reference : This is A class\n";
        return ;
    }
    catch (...) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Reference : This is B class\n";
        return ;
    }
    catch (...) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Reference : This is C class\n";
        return ;
    }
    catch (...) {}
    std::cout << "Reference : This is Unknowen class\n";
}