#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t)
: AForm("ShrubberyCreation", 145, 137), target(t) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) this->target = other.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream file((target + "_shrubbery").c_str());
    file << "      /\\      \n"
            "     /\\*\\     \n"
            "    /\\O\\*\\    \n"
            "   /*/\\/\\/\\   \n"
            "  /\\O\\/\\*\\/\\  \n"
            " /\\*\\/\\*\\/\\/\\ \n"
            "/\\O\\/\\/*/\\/O/\\\n"
            "      ||       \n"
            "      ||       \n";
    file.close();
}
