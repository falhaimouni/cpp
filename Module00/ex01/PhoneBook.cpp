#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

PhoneBook::PhoneBook() : totalContacts(0), nextIndex(0) {}

static std::string getInput(const std::string& prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (input.empty()) std::cout << "Field cannot be empty.\n";
    } while (input.empty());
    return input;
}

void PhoneBook::addContact() {
    std::string firstName = getInput("First Name: ");
    std::string lastName = getInput("Last Name: ");
    std::string nickname = getInput("Nickname: ");
    std::string phoneNumber = getInput("Phone Number: ");
    std::string darkestSecret = getInput("Darkest Secret: ");

    contacts[nextIndex].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    nextIndex = (nextIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
    std::cout << "Contact added successfully.\n";
}

static std::string formatField(const std::string& str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::searchContacts() const {
    if (totalContacts == 0) {
        std::cout << "No contacts to display.\n";
        return;
    }

    std::cout << "---------------------------------------------\n";
    std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < totalContacts; ++i) {
        std::cout << "|" << std::setw(10) << i
                  << "|" << formatField(contacts[i].getFirstName())
                  << "|" << formatField(contacts[i].getLastName())
                  << "|" << formatField(contacts[i].getNickname()) << "|\n";
    }

    std::cout << "---------------------------------------------\n";

    std::cout << "Enter index to view details: ";
    std::string input;
    std::getline(std::cin, input);
    if (std::cin.eof())
        exit(0);
    if (input.length() == 1 && std::isdigit(input[0])) {
        int index = input[0] - '0';
        if (index >= 0 && index < totalContacts) {
            const Contact& c = contacts[index];
            std::cout << "First Name: " << c.getFirstName() << "\n";
            std::cout << "Last Name: " << c.getLastName() << "\n";
            std::cout << "Nickname: " << c.getNickname() << "\n";
            std::cout << "Phone Number: " << c.getPhoneNumber() << "\n";
            std::cout << "Darkest Secret: " << c.getDarkestSecret() << "\n";
            return ;
        }
    }
    std::cout << "Invalid index.\n";
}
