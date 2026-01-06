#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

// ANSI Colors for readability
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
    // -------------------------------------------------------------------------
    test_separator("TEST 1: Valid Form Creation & Output");
    try
    {
        // Bureaucrat(Name, Grade)
        Bureaucrat bob("Bob", 1);
        
        // Form(Name, GradeToSign, GradeToExec)
        Form taxForm("Tax Form 28B", 50, 20);

        std::cout << "Created: " << bob << std::endl;
        std::cout << "Created: " << taxForm << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // -------------------------------------------------------------------------
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

    // -------------------------------------------------------------------------
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

    // -------------------------------------------------------------------------
    test_separator("TEST 4: Signing - SUCCESS Case");
    try
    {
        // Boss has Grade 5. Form requires Grade 10 to sign.
        Bureaucrat boss("Boss", 5);
        Form contract("Employment Contract", 10, 50);

        std::cout << "Before: " << contract << std::endl;
        
        // This should work because 5 <= 10
        boss.signForm(contract);
        
        std::cout << "After:  " << contract << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Unexpected Exception: " << e.what() << RESET << std::endl;
    }

    // -------------------------------------------------------------------------
    test_separator("TEST 5: Signing - FAILURE Case (Grade too low)");
    try
    {
        // Intern has Grade 100. Form requires Grade 50 to sign.
        Bureaucrat intern("Intern", 100);
        Form secretDoc("Top Secret", 50, 50);

        std::cout << "Bureaucrat: " << intern << std::endl;
        std::cout << "Form Requirement: " << secretDoc.getGradeSign() << std::endl;

        // This should FAIL inside signForm and print the error message defined in Bureaucrat.cpp
        intern.signForm(secretDoc);
        
        // Verify form is NOT signed
        std::cout << "Form status: " << secretDoc << std::endl;
    }
    catch (std::exception &e)
    {
        // We shouldn't actually reach here if signForm catches the exception internally 
        // as per subject requirements, but good to have just in case.
        std::cout << RED << "Main Caught: " << e.what() << RESET << std::endl;
    }

    return 0;
}