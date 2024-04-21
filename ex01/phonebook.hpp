#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "contact.hpp"
# define N 8

class PhoneBook
{
	private:
		Contact phoneBook[N];
		int idx;
		std::string _getTenChr(std::string input);
	public:
		PhoneBook(void);
		void add(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
		void search(int selected);
		int getList(void);
};

#endif