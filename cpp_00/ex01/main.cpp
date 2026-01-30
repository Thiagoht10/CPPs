#include "PhoneBook.hpp"

PhoneBook phone_book;

int main(void)
{
    std::string option;

    std::cout << GREEN << "\nWellcome to PhoneBook\n" << RESET;
    while(1)
    {
        std::cout << "\nPlease! Choose one option.\n";
        std::cout << "Options: ADD, SEARCH or EXIT.\n";
        if(!std::getline(std::cin, option))
            break ;
        if(option == "ADD")
        {
            if(!phone_book.addContact())
            {
                std::cout << RED << "\nError to add contact\n" << RESET;
                break ;
            }
        }
        else if (option == "SEARCH")
        {
            if(!phone_book.searchContact())
            {
                std::cout << RED << "\nError to search contacts\n" << RESET;
                break ;
            }
        }
        else if(option == "EXIT")
            break ;
    }
    return (0);
}