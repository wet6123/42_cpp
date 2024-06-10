#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    *this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    _data = obj._data;
    _amount = obj._amount;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(const char *filename)
{
    setData(DATAFILE);
    setAmount(filename);
}

void BitcoinExchange::setData(const char *filename)
{
    // open file
    std::ifstream datafile;
    datafile.open(filename);
    if (!datafile.is_open())
    {
        std::cerr << "Error: Cannot open '" << filename << "' file" << std::endl;
        exit(1);
    }

    // set data
    std::string tmp;
    while (std::getline(datafile, tmp))
    {
        std::string date = tmp.substr(0, 10);
        if (date[4] != '-' || date[7] != '-')
        {
            std::cerr << "Error: Invalid date format" << std::endl;
            exit(1);
        }
        if (date.substr(5, 2) > "12" || date.substr(8, 2) > "31")
        {
            std::cerr << "Error: Invalid date range" << std::endl;
            exit(1);
        }
        double count = std::strtod(tmp.substr(11).c_str(), NULL);
        // _data.insert(std::pair<int, double>(std::stoi(date.substr(8, 2)), count));
        _data.insert({std::stoi(date.substr(8, 2)), count});
    }
}

void BitcoinExchange::setAmount(const char *filename)
{
    // open file
    std::ifstream amountfile;
    amountfile.open(filename);
    if (!amountfile.is_open())
    {
        std::cerr << "Error: Cannot open '" << filename << "' file" << std::endl;
        exit(1);
    }

    // set amount
    std::string tmp;
    while (std::getline(amountfile, tmp))
    {
        std::string date = tmp.substr(0, 10);
        if (date[4] != '-' || date[7] != '-')
        {
            std::cerr << "Error: Invalid date format" << std::endl;
            exit(1);
        }
        if (date.substr(5, 2) > "12" || date.substr(8, 2) > "31")
        {
            std::cerr << "Error: Invalid date range" << std::endl;
            exit(1);
        }
        int count = std::stoi(tmp.substr(11));
        if (count < 0 || count > 1000)
        {
            std::cerr << "Error: Invalid amount range" << std::endl;
            exit(1);
        }
        // _amount.insert(std::pair<int, int>(std::stoi(date.substr(8, 2)), count));
        _amount.insert({std::stoi(date.substr(8, 2)), count});
    }
}

std::map<int, int>::iterator BitcoinExchange::printExchange(void)
{
    return (_amount.begin());
}