#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() 
    : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
    std::cout << "AForm default constructor called.\n";
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "AForm parameterized constructor called.\n";
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "AForm copy constructor called.\n";
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called.\n";
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade is too low!";
}


const std::string &AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

const char* AForm::NotSignedException::what() const throw()
{
    return "AForm: Form is not signed!";
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned)
        throw NotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform)
{
    os << "AForm \"" << Aform.getName() << "\" "
       << (Aform.getIsSigned() ? "is signed" : "is not signed")
       << ", grade required to sign: " << Aform.getGradeToSign()
       << ", grade required to execute: " << Aform.getGradeToExecute();
    return os;
}
