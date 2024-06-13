#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    setData(DATAFILE);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj)
{
    *this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj)
{
    _data = obj._data;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{}

int BitcoinExchange::parseDate(const std::string &date)
{
    for(unsigned int i = 0; i < date.size(); i++)
    {
        if (i != 4 && i != 7 && std::isdigit(date[i]) == false)
            throw std::invalid_argument("Error: Invalid date format: not a number");
    }
    if (date.size() != 10)
        throw std::invalid_argument("Error: Invalid date format: length");
    if (date[4] != '-' || date[7] != '-')
        throw std::invalid_argument("Error: Invalid date format: no dash");

    int year = std::strtod(date.substr(0, 4).c_str(), NULL);
    int month = std::strtod(date.substr(5, 2).c_str(), NULL);
    int day = std::strtod(date.substr(8, 2).c_str(), NULL);

    if (month > 12 || month < 1)
        throw std::invalid_argument("Error: bad input => " + date);
    if (day > 31 || day < 1)
        throw std::invalid_argument("Error: bad input => " + date);

    return (year * 10000 + month * 100 + day);
}

double BitcoinExchange::parseRate(const std::string &rate)
{
    double result = std::strtod(rate.c_str(), NULL);
    return (result);
}

double BitcoinExchange::parseValue(const std::string &amount)
{
    double result = std::strtod(amount.c_str(), NULL);
    if (result < 0 )
        throw std::invalid_argument("Error: not a positive number.");
    if (result > INT_MAX)
        throw std::invalid_argument("Error: too large a number.");
    return (result);
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
        try
        {
            int date = parseDate(tmp.substr(0, 10));
            double value = parseRate(tmp.substr(11));
            _data.insert(std::pair<int, double>(date, value));
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

void BitcoinExchange::printExchange(const char *filename)
{
    // open file
    std::ifstream amountfile;
    amountfile.open(filename);
    if (!amountfile.is_open())
    {
        std::cerr << "Error: Cannot open '" << filename << "' file" << std::endl;
        exit(1);
    }

    // read file
    std::string line;
    while(std::getline(amountfile, line))
    {
        try
        {
            // readline
            int date = parseDate(line.substr(0, 10));
            double value = parseValue(line.substr(13));
            // calculate
            double result = calculate(date, value);
            std::cout << printDate(date) << " => " << value << " = " << result << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}

double BitcoinExchange::calculate(int date, double value)
{
    // find data
    std::map<int, double>::iterator dataIt = findData(date);
    // calculate
    return (dataIt->second * value);
}

std::map<int,double>::iterator BitcoinExchange::findData(int date)
{
    std::map<int, double>::iterator dataStart = _data.begin();
    std::map<int, double>::iterator dataEnd = _data.end();
    std::map<int, double>::iterator closestIt = dataStart;

    for (std::map<int, double>::iterator dataIt = dataStart; dataIt != dataEnd; dataIt++)
    {
        if (dataIt->first == date)
            return (dataIt);
        else if (dataIt->first > date)
        {
            return (closestIt);
        }
        closestIt = dataIt;
    }
    throw std::invalid_argument("Error: Invalid date");
}

std::string BitcoinExchange::printDate(int date)
{
    std::string result;
    for(unsigned int i = 0; i < 4 - std::to_string(date / 10000).size(); i++)
        result += '0';
    result += std::to_string(date / 10000);

    result += '-';

    for(unsigned int i = 0; i < 2 - std::to_string((date % 10000) / 100).size(); i++)
        result += '0';
    result += std::to_string((date % 10000) / 100);

    result += '-';

    for(unsigned int i = 0; i < 2 - std::to_string(date % 100).size(); i++)
        result += '0';
    result += std::to_string(date % 100);
    return (result);
}