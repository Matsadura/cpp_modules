#include "BitcoinExchange.hpp"

// static void printDatabase(const std::map<std::string, double> &database)
// {
//     std::map<std::string, double>::const_iterator it;
//     for (it = database.begin(); it != database.end(); ++it)
//     {
//         std::cout << it->first << " => " << it->second << std::endl;
//     }
// }

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange bitcoinExchange;
        bitcoinExchange.processInputFile(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}