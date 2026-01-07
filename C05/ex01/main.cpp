#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"

void    test_separator(std::string title)
{
    std::cout << "\n" << BLUE << "=== " << title << " ===" << RESET << std::endl;
}

int main( void )
{
    test_separator("TEST 1: Valid Form Creation & Output");
    try
    {
        Bureaucrat bob("Bob", 1);
        
        Form taxForm("Tax Form 28B", 50, 20);

        std::cout << "Created: " << bob << std::endl;
        std::cout << "Created: " << taxForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    test_separator("TEST 2: Form Creation Error (Grade Too High)");
    try
    {
        std::cout << "Attempting to create Form with Sign Grade 0..." << std::endl;
        Form invalid("Impossible", 0, 50);
        std::cout << RED << "FAIL: Should not be here!" << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << GREEN << "Success: Caught expected exception: " << e.what() << RESET << std::endl;
    }

    test_separator("TEST 3: Form Creation Error (Grade Too Low)");
    try
    {
        std::cout << "Attempting to create Form with Exec Grade 151..." << std::endl;
        Form invalid("LazyForm", 50, 151);
        std::cout << RED << "FAIL: Should not be here!" << RESET << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << GREEN << "Success: Caught expected exception: " << e.what() << RESET << std::endl;
    }

    test_separator("TEST 4: Signing - SUCCESS Case");
    try
    {
        Bureaucrat boss("Boss", 5);
        Form contract("Employment Contract", 10, 50);

        std::cout << "Before: " << contract << std::endl;
        
        boss.signForm(contract);
        
        std::cout << "After:  " << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Unexpected Exception: " << e.what() << RESET << std::endl;
    }

    test_separator("TEST 5: Signing - FAILURE Case (Grade too low)");
    try
    {
        Bureaucrat intern("Intern", 100);
        Form secretDoc("Top Secret", 50, 50);

        std::cout << "Bureaucrat: " << intern << std::endl;
        std::cout << "Form Requirement: " << secretDoc.getGradeSign() << std::endl;

        intern.signForm(secretDoc);
        
        std::cout << "Form status: " << secretDoc << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Main Caught: " << e.what() << RESET << std::endl;
    }

    return 0;
}