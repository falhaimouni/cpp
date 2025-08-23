#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() 
    : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
    std::cout << "Form default constructor called.\n";
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form parameterized constructor called.\n";
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Form copy constructor called.\n";
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called.\n";
}

// ===== Exceptions =====
const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade is too low!";
}


const std::string &Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form \"" << form.getName() << "\" "
       << (form.getIsSigned() ? "is signed" : "is not signed")
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute();
    return os;
}
