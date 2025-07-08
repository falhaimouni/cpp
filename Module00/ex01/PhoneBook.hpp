#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int index;
    int total;
public:
    PhoneBook();
    void addContact();
    void searchContacts();
};

#endif