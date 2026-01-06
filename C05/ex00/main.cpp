#include "Bureaucrat.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"

int main( void )
{
    std::cout << BLUE << "--- TEST 1: Standard Valid Construction ---" << RESET << std::endl;
    try {
        Bureaucrat a("Bob", 150);
        Bureaucrat b("Alice", 1);
        
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "--- TEST 2: Constructor Grade Too High (0) ---" << RESET << std::endl;
    try {
        Bureaucrat high("TooHigh", 0);
        std::cout << RED << "FAIL: Should have thrown exception!" << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << GREEN << "Success: Caught exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "--- TEST 3: Constructor Grade Too Low (151) ---" << RESET << std::endl;
    try {
        Bureaucrat low("TooLow", 151);
        std::cout << RED << "FAIL: Should have thrown exception!" << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << GREEN << "Success: Caught exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "--- TEST 4: Increment Grade 1 (Should Fail) ---" << RESET << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        std::cout << "Current: " << boss << std::endl;
        
        std::cout << YELLOW << "Attempting to increment grade 1..." << RESET << std::endl;
        boss.incrementGrade();
        
        std::cout << RED << "FAIL: Should have thrown exception!" << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << GREEN << "Success: Caught exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "--- TEST 5: Decrement Grade 150 (Should Fail) ---" << RESET << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        std::cout << "Current: " << intern << std::endl;
        
        std::cout << YELLOW << "Attempting to decrement grade 150..." << RESET << std::endl;
        intern.decrementGrade();
        
        std::cout << RED << "FAIL: Should have thrown exception!" << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << GREEN << "Success: Caught exception: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << BLUE << "--- TEST 6: Valid Modifications ---" << RESET << std::endl;
    try {
        Bureaucrat norm("Norman", 50);
        std::cout << "Start: " << norm << std::endl;
        
        norm.incrementGrade();
        std::cout << "After Increment (50 -> 49): " << norm << std::endl;
        
        norm.decrementGrade();
        std::cout << "After Decrement (49 -> 50): " << norm << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << "FAIL: Unexpected exception: " << e.what() << RESET << std::endl;
    }

    return 0;
}