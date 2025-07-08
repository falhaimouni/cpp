#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string firstName;
    std::string nickname;
    std::string lastName;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setContact(std::string firstName
    ,std::string lastName
    ,std::string nickname
    ,std::string phoneNumber
    ,std::string darkestSecret);

    std::string getFirstName()const;
    std::string getLastName()const;
    std::string getPhoneNumber()const;
    std::string getDarkestSecret()const;
    std::string getNickname()const;
};

#endif
