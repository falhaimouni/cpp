#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        Bureaucrat bob("Bob", 1);
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }

    std::cout << "---------------------" << std::endl;

    form = someRandomIntern.makeForm("coffee request", "Bob");
    if (form)
    {
        delete form;
    }
    return 0;
}
