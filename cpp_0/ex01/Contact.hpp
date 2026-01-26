#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact();

    void    setFirstName(const std::string &value);
    void    setLastName(const std::string &value);
    void    setNickName(const std::string &value);
    void    setPhoneNumber(const std::string &value);
    void    setDarkestSecret(const std::string &value);
};

#endif