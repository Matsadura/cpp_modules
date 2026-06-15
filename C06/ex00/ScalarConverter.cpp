#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal)
{
    std::stringstream ss(literal);
    char              c;
    float             f;
    double            d;

    if (literal.size() > 1 && literal.find('e') != std::string::npos)
    {
        printError();
        return;
    }
    std::cout << std::setprecision(1);
    std::cout << std::fixed;
    if (handlePseudo(literal, d))
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << d << "f\n";
        std::cout << "double: " << d << "\n";
    }
    else if (handleDouble(ss, d))
        printAll(static_cast<double>(d));
    else if (handleFloat(ss, f))
        printAll(static_cast<double>(f));
    else if (handleChar(ss, c))
        printAll(static_cast<double>(c));
    else
        printError();
}