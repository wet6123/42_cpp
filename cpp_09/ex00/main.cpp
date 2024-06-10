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
	// data.csv 파일을 읽음
	std::ifstream datafile("data.csv");

	// data.csv 파일을 읽어서 data에 저장
	std::map<std::string, double> data;
	std::string tmp;
	while (std::getline(datafile, tmp))
	{
		std::string date = tmp.substr(0, 10);
		// 형식 확인
		if (date[4] != '-' || date[7] != '-')
		{
			std::cerr << "Error: Invalid date format" << std::endl;
			return (1);
		}
		// date 범위 확인
		if (date.substr(5, 2) > "12" || date.substr(8, 2) > "31")
		{
			std::cerr << "Error: Invalid date range" << std::endl;
			return (1);
		}
		double count = std::strtod(tmp.substr(11).c_str(), NULL);
		data[date] = count;
	}

	std::map<std::string, double>::iterator iter;
	for (iter = data.begin(); iter != data.end(); iter++)
	{
		std::cout << iter->first << " => " << iter->second << std::endl;
	}

	// 입력된 파일을 읽음
	std::ifstream file(argv[1]);
	// 날짜 => 개수 = 가격 형식으로 출력
	//  ㄴ 에러처리
	//  ㄴ 개수 범위 0 ~ 1000
	//  ㄴ 날짜 범위
	
	// 파일을 닫음

	return (0);
}