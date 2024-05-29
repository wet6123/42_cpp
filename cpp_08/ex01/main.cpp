#include "Span.hpp"
#include <iostream>
#include <list>

int main()
{
	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);

	Span sp2 = sp;
	sp2.addNumber(1);
	sp2.addNumber(0);

	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	// 여러개 넣는 함수
	Span sp3(10000);
	std::list<int> tmp;
	for (int i = 0; i < 10000; i++)
		tmp.push_back(i);

	sp3.insert<std::list<int> >(tmp.begin(), tmp.end());
	std::cout << sp3.shortestSpan() << std::endl;
	std::cout << sp3.longestSpan() << std::endl;

	return 0;
}