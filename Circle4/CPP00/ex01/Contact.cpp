#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>

Contact::Contact()
{
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

void	Contact::setFirstName(std::string first_name)
{
	this->firstName = first_name;
}

void	Contact::setLastName(std::string last_name)
{
	this->lastName = last_name;
}

void	Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phone_number)
{
	this->phoneNumber = phone_number;
}

void	Contact::setDarkestSecret(std::string darkest_secret)
{
	this->darkestSecret = darkest_secret;
}

std::string	Contact::getFirstName() const
{
	return this->firstName;
}

std::string	Contact::getLastName() const
{
	return this->lastName;
}

std::string	Contact::getNickname() const
{
	return this->nickname;
}

std::string	Contact::getPhoneNumber() const
{
	return this->phoneNumber;
}

std::string	Contact::getDarkestSecret() const
{
	return this->darkestSecret;
}

void	Contact::display() const
{
	std::cout << WHITE "First name : " << this->firstName << std::endl;
	std::cout << "Last name : " << this->lastName << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone number : " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret : " << this->darkestSecret << std::endl;
}

bool	Contact::isFilled() const
{
	return (true 
		&& (this->firstName.size() && !isWhitespaceString(this->firstName))
		&& (this->lastName.size() && !isWhitespaceString(this->lastName))
		&& (this->nickname.size() && !isWhitespaceString(this->nickname))
		&& (this->phoneNumber.size() && !isWhitespaceString(this->phoneNumber))
		&& (this->darkestSecret.size() && !isWhitespaceString(this->darkestSecret)));
}
