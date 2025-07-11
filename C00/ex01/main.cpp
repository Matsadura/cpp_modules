#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phone;

    std::cout << "Welcome to your phonebook!" << std::endl;
    while (1)
    {
        std::string input;
        std::cout << "CMD: ", std::cin >> input;
        if (input.compare("ADD") == 0)
            phone.addContact();
        else if (input.compare("SEARCH") == 0)
            phone.displayContacts();
        else if (input.compare("EXIT") == 0)
            exit(EXIT_SUCCESS);
    }
    return (0);
}
