#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int contactCount;
    int currentIndex;

public:
    void    addContact();
    void    searchContact() const;
    
};


#endif