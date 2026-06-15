#include "ScalarConverter.hpp"

void printChar(double from)
{
    std::cout << "char: ";
    if (from > std::numeric_limits<char>::max() || from < std::numeric_limits<char>::min())
    {
        std::cout << "impossible\n";
        return;
    }
    char c = static_cast<char>(from);
    if (std::isprint(static_cast<char>(from)))
        std::cout << "'" << c << "'\n";
    else
        std::cout << "Non displayable\n";
}

void printFloat(double from)
{
    std::cout << "float: ";
    if (from > std::numeric_limits<float>::max() || from < std::numeric_limits<float>::min())
    {
        std::cout << "impossible\n";
        return;
    }
    float f = static_cast<float>(from);
    std::cout << f << "f\n";
}

void printDouble(double from)
{
    std::cout << "double: " << from << "\n";
}

void printInt(double from)
{
    std::cout << "int: ";
    if (from > std::numeric_limits<int>::max() || from < std::numeric_limits<int>::min())
    {
        std::cout << "impossible\n";
        return;
    }
    int n = static_cast<int>(from);
    std::cout << n << "\n";
}

void printAll(double val)
{
    printChar(val);
    printInt(val);
    printFloat(val);
    printDouble(val);
}

void printError(void)
{
    std::cout << "char: impossible\n"
              << "int: impossible\n"
              << "float: impossible\n"
              << "double: impossible\n";
}

bool handleDouble(std::stringstream &ss, double &d)
{
    ss.clear();
    ss.seekg(0);
    ss >> d;
    return ss && ss.eof();
}

bool handleFloat(std::stringstream &ss, float &f)
{
    ss.clear();
    ss.seekg(0);
    ss >> f;
    return ss && ss.get() == 'f' && ss.get() == std::char_traits<char>::eof();
}

bool handleChar(std::stringstream &ss, char &c)
{
    ss.clear();
    ss.seekg(0);
    ss >> c;
    return ss && ss.get() == std::char_traits<char>::eof();
}

bool handlePseudo(const std::string &literal, double &d)
{
    if (literal != "-inff" && literal != "+inff" && literal != "nanf" && literal != "-inf" && literal != "+inf" &&
        literal != "nan")
        return false;
    d = std::atof(literal.c_str());
    return true;
}