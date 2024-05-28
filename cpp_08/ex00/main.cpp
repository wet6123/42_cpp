#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	try
	{
		std::cout << *(easyfind(v, 5)) << std::endl;
		std::cout << *(easyfind(v, 10)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Element not found" << std::endl;
	}

	std::list<int> l;
	for (int i = 0; i < 10; i++)
		l.push_back(i);
	try
	{
		std::cout << *(easyfind(v, 5)) << std::endl;
		std::cout << *(easyfind(v, 10)) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Element not found" << std::endl;
	}

	return 0;
}