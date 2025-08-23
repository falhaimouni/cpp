#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 10);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;
        Bureaucrat b2("Bob", 0);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b3("Charlie", 151);
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
