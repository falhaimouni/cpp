#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main() {
    srand(time(NULL));

    Bureaucrat bob("Bob", 1);
    Bureaucrat joe("Joe", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << shrub << std::endl;
    std::cout << robo << std::endl;
    std::cout << pardon << std::endl;

    joe.signForm(shrub);   // too low
    bob.signForm(shrub);   // ok
    bob.executeForm(shrub);// ok

    bob.signForm(robo);
    bob.executeForm(robo);

    bob.signForm(pardon);
    bob.executeForm(pardon);

    return 0;
}
