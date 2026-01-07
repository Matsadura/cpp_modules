#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

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
    Intern  someRandomIntern;
    Bureaucrat boss("Boss", 1);

    test_header("1. INTERN CREATES ROBOTOMY REQUEST");
    {
        AForm* rrf = someRandomIntern.makeForm("Robotomy", "Bender");
        if (rrf)
        {
            std::cout << *rrf << std::endl;
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
    }

    test_header("2. INTERN CREATES SHRUBBERY CREATION");
    {
        AForm* scf = someRandomIntern.makeForm("Shrubbery", "Home");
        if (scf)
        {
            std::cout << *scf << std::endl;
            boss.signForm(*scf);
            boss.executeForm(*scf);
            delete scf;
        }
    }

    test_header("3. INTERN CREATES PRESIDENTIAL PARDON");
    {
        AForm* ppf = someRandomIntern.makeForm("Presidential", "Criminal");
        if (ppf)
        {
            std::cout << *ppf << std::endl;
            boss.signForm(*ppf);
            boss.executeForm(*ppf);
            delete ppf;
        }
    }

    test_header("4. INTERN TRIES TO CREATE UNKNOWN FORM");
    {
        AForm* wrong = someRandomIntern.makeForm("fake form", "Target");
        
        if (wrong == NULL)
        {
            std::cout << GREEN << "Success: Intern returned NULL for invalid form." << RESET << std::endl;
        }
        else
        {
            std::cout << RED << "Fail: Intern created something for invalid input!" << RESET << std::endl;
            delete wrong;
        }
    }

    return (0);
}