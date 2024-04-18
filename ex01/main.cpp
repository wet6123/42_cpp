#include "phonebook.hpp"
#include "contact.hpp"

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
		std::cin >> cmd;

		if (cmd.compare(ADD) == 0)
		{
			std::cout.width(17);
			std::cout << std::right << "first name : ";
			std::cin >> firstName;
			std::cout.width(17);
			std::cout << std::right << "last name : ";
			std::cin >> lastName;
			std::cout.width(17);
			std::cout << std::right << "nickname : ";
			std::cin >> nickName;
			std::cout.width(17);
			std::cout << std::right << "phone number : ";
			std::cin >> phoneNumber;
			std::cout.width(17);
			std::cout << std::right << "darkest secret : ";
			std::cin >> darkestSecret;

			phoneBook.add(firstName, lastName, nickName, phoneNumber, darkestSecret);

			std::cout << "contact successfully added\n";
		}
		else if (cmd.compare(SEARCH) == 0)
		{
			std::cout << "Please enter the index of the contact you want to find\n";
			std::cin >> idx;
			if (idx < 0 || idx >= N)
			{
				std::cout << "Wrong index: enter 0 ~ 7\n";
				continue;
			}
			phoneBook.search(idx);
		}
		else if (cmd.compare(EXIT) == 0)
		{
			break;
		}
		else
		{
			std::cout << "Wrong command\n";
		}
		
		if (std::cin.eof())
		{ // EOF 입력 처리
			clearerr(stdin);
			std::cin.clear();
		}
	}
}
