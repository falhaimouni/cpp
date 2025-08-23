#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try {
        Bureaucrat bob("Bob", 1);
        Form taxForm("Tax Form", 45, 75);

        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);

        std::cout << taxForm << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
