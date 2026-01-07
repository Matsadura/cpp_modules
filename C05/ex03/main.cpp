#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Colors for readable output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

void    test_header(std::string title)
{
    std::cout << "\n" << BLUE << ">>> " << title << " <<<" << RESET << std::endl;
}

int main(void)
{
    // Seed for Robotomy randomness
    std::srand(std::time(NULL));

    // --------------------------------------------------------------------------
    test_header("1. TESTING SHRUBBERY CREATION FORM (Target: 'home')");
    // Sign: 145, Exec: 137
    try {
        Bureaucrat  gardener("Gardener", 137);
        AForm* shrub = new ShrubberyCreationForm("home");

        std::cout << "Form Info: " << *shrub << std::endl;
        
        // Attempt to execute before signing (Should Fail)
        std::cout << YELLOW << "[Test] Execute unsigned form:" << RESET << std::endl;
        gardener.executeForm(*shrub);

        // Sign it
        std::cout << YELLOW << "[Test] Sign form:" << RESET << std::endl;
        gardener.signForm(*shrub);

        // Execute it (Should Create file 'home_shrubbery')
        std::cout << YELLOW << "[Test] Execute signed form:" << RESET << std::endl;
        gardener.executeForm(*shrub);
        std::cout << GREEN << "(Check your directory for 'home_shrubbery' file!)" << RESET << std::endl;

		delete shrub;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // --------------------------------------------------------------------------
    test_header("2. TESTING ROBOTOMY REQUEST FORM (Target: 'Bender')");
    // Sign: 72, Exec: 45
    try {
        Bureaucrat  doc("Doctor", 45);
        Bureaucrat  intern("Intern", 150);
        AForm* robo = new RobotomyRequestForm("Bender");

        // Intern tries to sign (Should Fail)
        std::cout << YELLOW << "[Test] Low grade sign attempt:" << RESET << std::endl;
        intern.signForm(*robo);
        // Doctor signs
        std::cout << YELLOW << "[Test] Proper grade sign:" << RESET << std::endl;
        doc.signForm(*robo);

        // Execute multiple times to test 50% chance
        std::cout << YELLOW << "[Test] Execution randomness (Running 4 times):" << RESET << std::endl;
        doc.executeForm(*robo);
        doc.executeForm(*robo);
        doc.executeForm(*robo);
        doc.executeForm(*robo);

		delete robo;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    // --------------------------------------------------------------------------
    test_header("3. TESTING PRESIDENTIAL PARDON FORM (Target: 'Criminal')");
    // Sign: 25, Exec: 5
    try {
        Bureaucrat  president("Zaphod", 5);
        Bureaucrat  vp("Vice President", 20); // Can sign (20 < 25) but CANNOT execute (20 > 5)
        AForm* pardon = new PresidentialPardonForm("Criminal");

        // VP signs
        std::cout << YELLOW << "[Test] VP signs the form:" << RESET << std::endl;
        vp.signForm(*pardon);

        // VP tries to execute (Should Fail)
        std::cout << YELLOW << "[Test] VP tries to execute (Grade too low):" << RESET << std::endl;
        vp.executeForm(*pardon);

        // President executes
        std::cout << YELLOW << "[Test] President executes:" << RESET << std::endl;
        president.executeForm(*pardon);
		delete pardon;
    }
    catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }

    return (0);
}