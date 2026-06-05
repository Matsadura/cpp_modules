#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <string>

class ScalarConverter
{
  public:
    static void convert(const std::string &literal);

  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();
};

#endif /* SCALARCONVERTER_HPP */