#include "PhoneBook.hpp"

/**
 * Main function for the PhoneBook application.
 */
int main(void)
{
    PhoneBook phone;

    std::cout << "Welcome back!" << std::endl;
    while (1)
    {
        std::string input;
        std::cout << "CMD: ", std::getline(std::cin, input);
		if (std::cin.fail())
		{
			std::cout << "\nSee you next time!" << std::endl;
			return(EXIT_SUCCESS);
		}
        if (input.compare("ADD") == 0)
            phone.addContact();
        else if (input.compare("SEARCH") == 0)
            phone.searchContacts();
        else if (input.compare("EXIT") == 0)
            return(0);
    }
    return (0);
}
