#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <iterator>
# include <cstdlib>
# include <cctype>
# include <climits>
# include <sstream>

# define DATAFILE "data.csv"

class BitcoinExchange
{
	private:
		std::map<int, double> _data;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		~BitcoinExchange(void);

		// parsing
		int parseDate(const std::string &date);
		double parseRate(const std::string &rate);
		double parseValue(const std::string &value);

		void setData(const char *filename);
		// print all
		void printExchange(const char *filename);
		// calculate 1
		double calculate(int date, double value);
		std::map<int,double>::iterator findData(int date);
		std::string printDate(int date);
		unsigned int howManyDigit(int n);
};

#endif