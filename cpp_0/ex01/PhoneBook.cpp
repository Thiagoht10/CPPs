#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    contactCount = 0;
    currentIndex = 0;
}

void    PhoneBook::updateStatus()
{
    if(contactCount < 8)
        contactCount += 1;
    if((currentIndex + 1) % 8 == 0)
        currentIndex = 0;
    else
        currentIndex += 1;
}

bool    PhoneBook::readField(const std::string &prompt, std::string &out)
{
    std::string field;

    while(1)
    {
        std::cout << prompt;
        if(!std::getline(std::cin, field))
            return (false);
        if(field.empty())
        {
            std::cout << RED << "Empty field is not allowed!\n" << RESET;
            continue;
        }
        out = field;
        break;
    }
    return (true);
}

int PhoneBook::addContact()
{
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;

    if(!readField("First name: ", first_name))
        return (0);
    if(!readField("Last name: ", last_name))
        return (0);
    if(!readField("Nick name: ", nick_name))
        return (0);
    if(!readField("Phone number: ", phone_number))
        return (0);
    if(!readField("Darkest secret: ", darkest_secret))
        return (0);
    
    contacts[currentIndex].setFirstName(first_name);
    contacts[currentIndex].setLastName(last_name);
    contacts[currentIndex].setNickName(nick_name);
    contacts[currentIndex].setPhoneNumber(phone_number);
    contacts[currentIndex].setDarkestSecret(darkest_secret);

    updateStatus();
    return (1);
}