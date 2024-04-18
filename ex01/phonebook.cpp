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
	std::cout.width(10);
	std::cout << std::right << selected;
	std::cout << "|";
	std::cout.width(10);
	std::cout << std::right << _getTenChr(phoneBook[selected].getFirstName());
	std::cout << "|";
	std::cout.width(10);
	std::cout << std::right << _getTenChr(phoneBook[selected].getLastName());
	std::cout << "|";
	std::cout.width(10);
	std::cout << std::right << _getTenChr(phoneBook[selected].getNickName());
	std::cout << "\n";
}