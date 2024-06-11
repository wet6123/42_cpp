#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <iterator>

int main(int argc, char **argv)
{
	// argc != 2 이면 에러 처리
	if (argc != 2)
	{
		std::cerr << "Error: Invalid arguments" << std::endl;
		return (1);
	}

	BitcoinExchange exchange;
	exchange.printExchange(argv[1]);

	return (0);
}