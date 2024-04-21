#include "phonebook.hpp"

PhoneBook::PhoneBook()
: idx(0)
{}

std::string PhoneBook::_getTenChr(std::string input)
{
	if (input.size() <= 10)
		return (input);
	return (input.substr(0, 9).append("."));
}
void PhoneBook::add(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	if (idx == 16)
		idx = 8;
	phoneBook[idx % 8].setFirstName(firstName);
	phoneBook[idx % 8].setLastName(lastName);
	phoneBook[idx % 8].setNickName(nickName);
	phoneBook[idx % 8].setPhoneNumber(phoneNumber);
	phoneBook[idx % 8].setDarkestSecret(darkestSecret);
	idx++;
}
void PhoneBook::search(int selected)
{
	if (selected >= idx)
	{
		std::cout << "Wrong index: index out of range \n" << std::endl;
		return;
	}
	// show info line by line
	std::cout << "First Name     : " << phoneBook[selected].getFirstName() << std::endl;
	std::cout << "Last Name      : " << phoneBook[selected].getLastName() << std::endl;
	std::cout << "Nickname       : " << phoneBook[selected].getNickName() << std::endl;
	std::cout << "Phone Number   : " << phoneBook[selected].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << phoneBook[selected].getDarkestSecret() << std::endl;
	std::cout << std::endl;
}

int PhoneBook::getList(void)
{
	if (idx == 0)
	{
		std::cout << "There is no contact in the phone book.\n" << std::endl;
		return (0);
	}
	// show list
	std::cout << "Index     |First Name|Last Name |Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout.width(10);
		std::cout << std::right << i;
		std::cout << "|";
		std::cout.width(10);
		std::cout << std::right << _getTenChr(phoneBook[i].getFirstName());
		std::cout << "|";
		std::cout.width(10);
		std::cout << std::right << _getTenChr(phoneBook[i].getLastName());
		std::cout << "|";
		std::cout.width(10);
		std::cout << std::right << _getTenChr(phoneBook[i].getNickName());
		std::cout << "\n";
	}
	return (idx % 8);
}
