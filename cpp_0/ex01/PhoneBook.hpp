#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

#include <string>
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int contactCount;
    int currentIndex;

    void    updateStatus();
    bool    readField(const std::string &prompt, std::string &out);

public:
    PhoneBook();

    int     addContact();
    void    searchContact() const;
};


#endif