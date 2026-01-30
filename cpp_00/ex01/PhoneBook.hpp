#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[38;2;212;219;5m"
#define RESET   "\033[0m"

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <stdlib.h>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact     contacts[8];
    int         contactCount;
    int         currentIndex;

    void        updateStatus();
    bool        readField(const std::string &prompt, std::string &out);
    bool        isValidInput(const std::string &str) const;
    std::string formatField(const std::string &str) const;
    void        printHeader() const;
    void        printTable() const;
    void        printContact(const int &idx) const;

public:
    PhoneBook();

    int         addContact();
    int         searchContact() const;
};


#endif