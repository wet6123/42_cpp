#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	// argc != 2 이면 에러 처리
	if (argc != 2)
	{
		std::cerr << "Error: Invalid arguments" << std::endl;
		return (1);
	}
	// data 파일을 읽음
	std::ifstream data("data.csv");
	// 입력된 파일을 읽음
	std::ifstream file(argv[1]);
	// 날짜 => 개수 = 가격 형식으로 출력
	//  ㄴ 에러처리
	//  ㄴ 개수 범위 0 ~ 1000
	//  ㄴ 날짜 범위
	// 파일을 닫음

	return (0);
}