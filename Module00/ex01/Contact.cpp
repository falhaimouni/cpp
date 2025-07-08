#include "Contact.hpp"

void Contact::setContact(std::string firstName, std::string nickname, std::string lastName, std::string phoneNumber, std::string darkestSecret)
{
    this->firstName = firstName;
    this->nickname = nickname;
    this->lastName = lastName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
    return(firstName);
}
std::string Contact::getLastName() const
{
    return(lastName);
}
std::string Contact::getPhoneNumber()const
{
    return(phoneNumber);
}
std::string Contact::getDarkestSecret()const
{
    return(darkestSecret);
}
std::string Contact::getNickname()const
{
    return(nickname);
}