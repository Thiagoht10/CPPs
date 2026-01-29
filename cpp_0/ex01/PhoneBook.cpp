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

    std::cout << "\n";
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
    std::cout << GREEN << "\nContact added successfully\n" << RESET;
    return (1);
}

std::string PhoneBook::formatField(const std::string &str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    PhoneBook::printHeader() const
{
    std::cout << "\n";
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First Name" << "|";
    std::cout << std::setw(10) << std::right << "Last Name" << "|";
    std::cout << std::setw(10) << std::right << "NickName" << "\n";
}

void    PhoneBook::printTable() const
{
    int i;
    std::string first_name;
    std::string last_name;
    std::string nick_name;

    printHeader();

    i = 0;
    while (i < contactCount)
    {
        first_name = contacts[i].getFirstName();
        last_name = contacts[i].getLastName();
        nick_name = contacts[i].getNickName();

        std::cout << std::setw(10) << std::right << i << "|";
        std::cout << std::setw(10) << std::right << formatField(first_name) << "|";
        std::cout << std::setw(10) << std::right << formatField(last_name) << "|";
        std::cout << std::setw(10) << std::right << formatField(nick_name) << "\n";
        i++;
    }
}

void    PhoneBook::printContact(const int &idx) const
{
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;

    first_name = contacts[idx].getFirstName();
    last_name = contacts[idx].getLastName();
    nick_name = contacts[idx].getNickName();
    phone_number = contacts[idx].getPhoneNumber();
    darkest_secret = contacts[idx].getDarkestSecret();

    std::cout << "\n" << YELLOW;
    std::cout << "First name: " << first_name << "\n";
    std::cout << "Last name: " << last_name << "\n";
    std::cout << "NickName: " << nick_name << "\n";
    std::cout << "Phone number: " << phone_number << "\n";
    std::cout << "Darkest secret: " << darkest_secret << "\n";
    std::cout << RESET;
}

bool    PhoneBook::isValidInput(const std::string &str) const
{
    int i;

    if(str.empty())
    {
        std::cout << "\n" << RED << "Wrong index" << RESET << "\n";
        return (false);
    }

    i = 0;
    while(str[i])
    {
        if(!std::isdigit(str[i]))
        {
            std::cout << "\n" << RED << "Wrong index" << RESET << "\n";
            return (false);
        }
        i++;
    }
    return (true);
}

int PhoneBook::searchContact() const
{
    std::string input;
    int idx;

    if(contactCount > 0)
    {
        printTable();
        std::cout << "\nPlease! Choose one index to show the contact\n";
        if(!std::getline(std::cin, input))
            return (0);
        if(!isValidInput(input))
            return (1);
        idx = atoi(input.c_str());
        if(idx > contactCount - 1)
        {
            std::cout << "\n" << RED << "Wrong index" << RESET << "\n";
            return (1);
        }
        printContact(idx);
    }
    else
        std::cout << RED << "\nEmpty contact list\n" << RESET;
    return (1);
}
