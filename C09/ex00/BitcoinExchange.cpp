#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    loadDatabase("data.csv");
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _database = other._database;
    }
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: Could not open database file.");

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string        date;
        double             value;

        if (std::getline(iss, date, ',') && iss >> value)
            _database[date] = value;
    }
}

/**
 * ValidateDate - Validates the format and values of a date string in the format YYYY-MM-DD.
 * @date: The date string to validate.
 */
void BitcoinExchange::ValidateDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        throw std::invalid_argument("Error: Invalid date format. Expected YYYY-MM-DD. => " + date);

    for (std::size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            throw std::invalid_argument("Error: date " + date + " contains non-digit characters. ");
    }

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009)
        throw std::invalid_argument("Error: year " + intToString(year) + " must be 2009 or later..");

    if (month < 1 || month > 12)
        throw std::invalid_argument("Error: month " + intToString(month) + " must be between 1 and 12.");

    if (day < 1 || day > 31)
        throw std::invalid_argument("Error: day " + intToString(day) + " must be between 1 and 31.");

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        throw std::invalid_argument("Error: day " + intToString(day) + " must be between 1 and 30 for the given month.");

    if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear && day > 29)
            throw std::invalid_argument("Error: February " + intToString(day) + " has only 29 days in a leap year.");
        if (!isLeapYear && day > 28)
            throw std::invalid_argument("Error: February " + intToString(day) + " has only 28 days in a non-leap year.");
    }
}

/**
 * ValidateValue - Validates a numeric value represented as a string.
 * @value: The value string to validate.
 */
void BitcoinExchange::ValidateValue(const std::string &value)
{
    if (value.empty())
        throw std::invalid_argument("Error: value is empty.");

    for (std::size_t i = 0; i < value.length(); ++i)
    {
        if (!std::isdigit(value[i]) && value[i] != '.' && value[i] != '-' && value[i] != '+')
            throw std::invalid_argument("Error: value " + value + " contains non-digit characters.");
    }

    double numericValue = std::atof(value.c_str());
    if (numericValue < 0)
        throw std::invalid_argument("Error: value " + value + " must be a positive number.");

    if (numericValue > 1000)
        throw std::invalid_argument("Error: value " + value + " must not exceed 1000.");
}

std::string strip(const std::string &str)
{
    const std::string whitespace = " \t\n\r\f\v";

    size_t start = str.find_first_not_of(whitespace);
    if (start == std::string::npos)
        return "";

    size_t end = str.find_last_not_of(whitespace);

    return str.substr(start, end - start + 1);
}

/**
 * processInputFile - Processes an input file containing date-value pairs.
 * @filename: The name of the input file to process.
 */
void BitcoinExchange::processInputFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: Could not open input file " + filename + ".");

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream iss(line);

        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cout << "Error: bad input => " << strip(line) << std::endl;
            continue;
        }
        std::string date  = strip(line.substr(0, pipePos));
        std::string value = strip(line.substr(pipePos + 1));

        try
        {
            ValidateDate(date);
            ValidateValue(value);
            double value_numeric = std::atof(value.c_str());

            std::map<std::string, double>::const_iterator it = _database.find(date);
            if (it == _database.end())
            {
                it = _database.upper_bound(date);
                if (it == _database.begin())
                {
                    std::cerr << "Error: bad input => " << date << std::endl;
                    continue;
                }
                --it;
            }

            double exchangeRate = it->second;
            double result       = value_numeric * exchangeRate;

            std::cout << date << " => " << value_numeric << " = " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

std::string intToString(int n)
{
    std::stringstream ss;
    ss << n;
    return ss.str();
}