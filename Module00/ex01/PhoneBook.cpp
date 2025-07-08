#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>

PhoneBook::PhoneBook()
{
    index = 0;
    total = 0;
}
static std::string getInput(const std::string& prompt)
{
    std::string input;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (!input.empty())
            break;
        std::cout << "Field cannot be empty.\n";
    }
    return input;
}

void PhoneBook::addContact()
{
    std::string firstName = getInput("First Name: ");
    std::string lastName = getInput("Last Name: ");
    std::string nickname = getInput("Nickname: ");
    std::string phoneNumber;
    while (true) {
        phoneNumber = getInput("Phone Number: ");
        if (phoneNumber.length() > 10) {
            std::cout << "Phone number must be at most 10 digits.\n";
            continue;
        }
        bool valid = true;
        for (size_t i = 0; i < phoneNumber.length(); ++i) {
            if (!std::isdigit(phoneNumber[i])) {
                std::cout << "Phone number must contain digits only.\n";
                valid = false;
                break;
            }
        }
        if (valid)
            break;
    }
    std::string darkestSecret = getInput("Darkest Secret: ");
    contacts[index].setContact(firstName,lastName, nickname, phoneNumber, darkestSecret);
    index = (index + 1) % 8;
    if (total < 8)
        total++;
    std::cout << "Contact added successfully.\n";
}

static std::string formatField(const std::string& str) {
    std::string result;

    if (str.length() > 10) {
        result = str.substr(0, 9);
        result += ".";
    } else {
        int padding = 10 - str.length();
        result = std::string(padding, ' ') + str;
    }

    return result;
}

void PhoneBook::searchContacts(){
    if (total == 0) {
        std::cout << "No contacts to display.\n";
        return;
    }
    std::cout << "---------------------------------------------\n";
    std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    std::cout << "---------------------------------------------\n";
    int i = 0;
    while (i < total) {
        std::cout << "|" << std::setw(10) << i
                  << "|" << formatField(contacts[i].getFirstName())
                  << "|" << formatField(contacts[i].getLastName())
                  << "|" << formatField(contacts[i].getNickname()) << "|\n";
        i++;
    }
    std::cout << "---------------------------------------------\n";
    std::cout << "Enter index to view details: ";
    std::string input;
    std::getline(std::cin, input);

    if (std::cin.eof())
        exit(0);

    if (input.length() == 1 && std::isdigit(input[0])) {
        int index = input[0] - '0';

        if (index >= 0 && index < total) {
            const Contact& c = contacts[index];
            std::cout << "First Name: " << c.getFirstName() << "\n";
            std::cout << "Last Name: " << c.getLastName() << "\n";
            std::cout << "Nickname: " << c.getNickname() << "\n";
            std::cout << "Phone Number: " << c.getPhoneNumber() << "\n";
            std::cout << "Darkest Secret: " << c.getDarkestSecret() << "\n";
            return;
        }
    }
    std::cout << "Invalid index.\n";
}

