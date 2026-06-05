#include "ScalarConverter.hpp"
#include <cctype>
#include <climits>
#include <ostream>
#include <sstream>

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    std::cout << "ScalarConverter assignment operator called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "Char: impossible\nInt: impossible\nFloat: nanf\nDouble: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
    {
        std::cout << "Char: impossible\nInt: impossible\nFloat: inff\nDouble: inf" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "Char: impossible\nInt: impossible\nFloat: -inff\nDouble: -inf" << std::endl;
        return;
    }

    std::string toParse = literal;
    if (toParse.length() > 1 && toParse[toParse.length() - 1] == 'f')
        toParse.erase(toParse.length() - 1);

    std::stringstream ss(toParse);
    long double lit;

    if (!(ss >> lit))
    {
        if (toParse.length() == 1)
            lit = static_cast<long double>(toParse[0]);
        else
        {
            std::cerr << "Error: Invalid literal" << std::endl;
            return;
        }
    }

    char Char = static_cast<char>(lit);
    std::cout << "Char: ";
    if (lit > CHAR_MAX || lit < CHAR_MIN)
        std::cout << "Impossible" << std::endl;
    else if (!std::isprint(Char))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << Char << "'" << std::endl;

    int Int = static_cast<int>(lit);
    std::cout << "Int: ";
    if (lit > INT_MAX || lit < INT_MIN)
    {
        std::cout << "Impossible" << std::endl;
    }
    else
    {
        std::cout << Int << std::endl;
    }

    float Float   = static_cast<float>(lit);
    double Double = static_cast<double>(lit);

    bool hasFraction = (lit - static_cast<long long>(lit) != 0);

    std::cout << "Float: " << Float;
    if (!hasFraction)
        std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "Double: " << Double;
    if (!hasFraction)
        std::cout << ".0";
    std::cout << std::endl;
}