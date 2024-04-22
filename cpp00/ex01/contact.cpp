#include "contact.hpp"

Contact::Contact()
: firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("")
{}

std::string Contact::getFirstName()		{	return firstName;		}
std::string Contact::getLastName()		{	return lastName;		}
std::string Contact::getNickName()		{	return nickName;		}
std::string Contact::getPhoneNumber()	{	return phoneNumber;		}
std::string Contact::getDarkestSecret()	{	return darkestSecret;	}

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}
void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}
void Contact::setNickName(std::string nickName)
{
	this->nickName =  nickName;
}
void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}
