#include "phonebook.hpp"
#include "contact.hpp"
#include <cstdio>
#include <string>
#include <sstream>

int main(void)
{
	PhoneBook phoneBook;
	std::string cmd;

	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	int idx;

	std::string ADD;
	std::string SEARCH;
	std::string EXIT;

	ADD = "ADD";
	SEARCH = "SEARCH";
	EXIT = "EXIT";

	while (1)
	{
		std::cout << "**********************************\n\n";
		std::cout << "junsbae's phone book\n\n";
		std::cout << "ADD: save new contact\n";
		std::cout << "SEARCH: display a specific contact\n";
		std::cout << "EXIT\n\n";
		std::cout << "**********************************\n\n";
		std::getline(std::cin, cmd);

		if (cmd.compare(ADD) == 0)
		{
			std::cout.width(17);
			std::cout << std::right << "first name : ";
			std::getline(std::cin, firstName);
			if (std::cin.eof())
			{
				std::cout << "\n" << "Wrong input: EOF entered"<< std::endl;
				break;
			}

			std::cout.width(17);
			std::cout << std::right << "last name : ";
			std::getline(std::cin, lastName);
			if (std::cin.eof())
			{
				std::cout << "\n" << "Wrong input: EOF entered"<< std::endl;
				break;
			}

			std::cout.width(17);
			std::cout << std::right << "nickname : ";
			std::getline(std::cin, nickName);
			if (std::cin.eof())
			{
				std::cout << "\n" << "Wrong input: EOF entered"<< std::endl;
				break;
			}

			std::cout.width(17);
			std::cout << std::right << "phone number : ";
			std::getline(std::cin, phoneNumber);
			if (std::cin.eof())
			{
				std::cout << "\n" << "Wrong input: EOF entered"<< std::endl;
				break;
			}

			std::cout.width(17);
			std::cout << std::right << "darkest secret : ";
			std::getline(std::cin, darkestSecret);
			if (std::cin.eof())
			{
				std::cout << "\n" << "Wrong input: EOF entered"<< std::endl;
				break;
			}

			phoneBook.add(firstName, lastName, nickName, phoneNumber, darkestSecret);

			std::cout << "contact successfully added\n";
		}
		else if (cmd.compare(SEARCH) == 0)
		{
			if (phoneBook.getList() == 0)
				continue;

			std::cout << "Please enter the index of the contact you want to find" << std::endl;
			std::cin >> idx;
			if (std::cin.eof())
			{
				std::cout << "\n" << "Wrong input: EOF entered"<< std::endl;
				break;
			}
			else if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Input fail" << std::endl;
				continue;
			}
			else if (idx < 1 || idx > N)
			{
				std::cin.ignore();
				std::cout << "Wrong index: enter 1 ~ 8\n"  << std::endl;
				continue;
			}
			
			std::cin.ignore();
			phoneBook.search(idx - 1);
		}
		else if (cmd.compare(EXIT) == 0)
		{
			break;
		}
		else
		{
			std::cout << "Wrong command\n" << std::endl;
		}
		
		if (std::cin.eof())
		{
			std::cout << "Wrong input: EOF entered"<< std::endl;
			break;
		}

		// 구현
		// 1. 리스트 보여주고
		// 2. 인덱스 값 입력 받아서
		// 3. 정보 한줄에 정보 하나씩 출력

		// 에러 처리
		// 1. cin -> getline으로 변경
		//    공백으로 입력 구분 안되도록
		// 2. EOF 처리
		//    clearerr 처리
		// 3. 전화번호 입력중 엔터 넣었을 때 문제 생김
	}
}
