#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange
{
  private:
    std::map<std::string, double> _database;
    void                          loadDatabase(const std::string &filename);
    void                          ValidateDate(const std::string &date);
    void                          ValidateValue(const std::string &value);

    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

  public:
    BitcoinExchange();
    ~BitcoinExchange();
    void processInputFile(const std::string &filename);
  
  };

std::string intToString(int n);
std::string strip(const std::string& str);
#endif