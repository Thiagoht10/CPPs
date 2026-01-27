#include "Contact.hpp"

Contact::Contact()
{
    //The constructor is empty because std::string is empty initialization.
}

void Contact::setFirstName(const std::string &value)
{
    _firstName = value;
}

void Contact::setLastName(const std::string &value)
{
    _lastName = value;
}

void Contact::setNickName(const std::string &value)
{
    _nickName = value;
}

void    Contact::setPhoneNumber(const std::string &value)
{
    _phoneNumber = value;
}

void    Contact::setDarkestSecret(const std::string &value)
{
    _darkestSecret = value;
}

std::string Contact::getFirstName() const
{
    return _firstName;
}

std::string Contact::getLastName() const
{
    return _lastName;
}

std::string Contact::getNickName() const
{
    return _nickName;
}

std::string Contact::getPhoneNumber() const
{
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return _darkestSecret;
}
