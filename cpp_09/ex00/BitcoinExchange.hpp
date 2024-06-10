#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <iterator>
# include <cstdlib>

# define DATAFILE "data.csv"

class BitcoinExchange
{
	private:
		std::map<int, double> _data;
		std::map<int, int> _amount;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const char *filename);
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange& operator=(const BitcoinExchange& obj);
		~BitcoinExchange(void);

		void setData(const char *filename);
		void setAmount(const char *filename);
		// 입출력 다시 세팅
		std::map<int, int>::iterator printExchange(void);
};

#endif