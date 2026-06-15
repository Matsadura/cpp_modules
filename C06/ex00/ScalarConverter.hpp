#ifndef SCALAR_CONVERTER_H
#define SCALAR_CONVERTER_H

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class ScalarConverter
{
  private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

  public:
    static void convert(const std::string &literal);
};

bool handlePseudo(const std::string &literal, double &d);
bool handleChar(std::stringstream &ss, char &c);
bool handleDouble(std::stringstream &ss, double &d);
bool handleFloat(std::stringstream &ss, float &f);

void printChar(double from);
void printFloat(double from);
void printInt(double from);
void printAll(double val);
void printError(void);
#endif