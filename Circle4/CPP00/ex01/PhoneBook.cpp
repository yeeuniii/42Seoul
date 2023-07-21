#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>
#include <cstring>
#include <iomanip>

PhoneBook::PhoneBook()
{
	memset(this->contacts, 0, sizeof(Contact) * 8);
	this->size = 0;
	this->input = None;
}

void	PhoneBook::runAddCommand()
{
	Contact	contact = askContact();

	if (std::cin.eof())
		return ;
	if (!contact.isFilled())
	{
		std::cout << RED "The contact entered has an empty field." << std::endl;
		return ;
	}
	addContact(contact);
}

Contact	PhoneBook::askContact()
{
	Contact	contact;
	std::string	tmp;

	std::cout << BLUE "All fields of contact CANNOT be empty." << std::endl;
	std::cout << WHITE "First name : ";
	getline(std::cin, tmp);
	contact.setFirstName(tmp);
	std::cout << "Last name : ";
	getline(std::cin, tmp);
	contact.setLastName(tmp);
	std::cout << "Nickname : ";
	getline(std::cin, tmp);
	contact.setNickname(tmp);
	std::cout << "Phone number : ";
	getline(std::cin, tmp);
	contact.setPhoneNumber(tmp);
	std::cout << "Darkest secret : ";
	getline(std::cin, tmp);
	contact.setDarkestSecret(tmp);
	return contact;
}

void	PhoneBook::addContact(Contact contact)
{
	if (this->size < 8)
	{
		this->contacts[this->size] = contact;
		this->size++;
		return ;
	}
	for (int idx = 0; idx < 7; idx++)
		this->contacts[idx] = this->contacts[idx + 1];
	this->contacts[7] = contact;
}

void	PhoneBook::runSearchCommand() const
{
	int	index;

	displayContacts();
	index = getIndex();
	if (std::cin.eof())
		return ;
	searchContact(index);
}

void	PhoneBook::displayContacts() const
{
	Contact			contact;
	
	std::cout << std::string(45, '-') << std::endl;
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "first name";
	std::cout << "|" << std::setw(10) << "last name";
	std::cout << "|" << std::setw(10) << "nickname";
	std::cout << "|" << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	for (int idx = 0; idx < this->size; idx++)
	{
		contact = this->contacts[idx];
		std::cout << "|" << std::setw(10) << idx;
		std::cout << "|" << std::setw(10) << conformToFormat(contact.getFirstName());
		std::cout << "|" << std::setw(10) << conformToFormat(contact.getLastName());
		std::cout << "|" << std::setw(10) << conformToFormat(contact.getNickname());
		std::cout << "|"  << std::endl;
	}
	std::cout << std::string(45, '-') << std::endl;
}

std::string	PhoneBook::conformToFormat(std::string string)
{
	std::string	new_string;

	if (string.size() <= 10)
		return string;
	new_string = string.substr(0, 9) + ".";
	return new_string;
}

int	PhoneBook::getIndex() const
{
	std::string	index;

	std::cout << BLUE "Enter index of contacts to display : ";
	std::getline(std::cin, index);
	if (std::cin.eof() || !isDigitString(index))
		return -1;
	return convertStrToInt(index);
}

void	PhoneBook::searchContact(int index) const
{
	if (!isValidIndex(index))
	{
		std::cout << RED "The index of contacts range from 0 to 7." << std::endl;
		return ;
	}
	this->contacts[index].display();
}

bool	PhoneBook::isValidIndex(int index) const
{
	return (index >= 0 && index < this->size);
}

void	PhoneBook::askInput()
{
	std::string	input_value;

	std::cout << WHITE "Enter one number of below commands." << std::endl;
	std::cout << "(1)ADD, (2)SEARCH and (3)EXIT." << std::endl;
	std::cout << "Input : ";
	getline(std::cin, input_value);
	setInput(input_value);
}

void	PhoneBook::setInput(std::string input)
{
	int	number = convertStrToInt(input);

	this->input = None;
	if (number >= 1 && number <= 3)
		this->input = Type(number);
}

void	PhoneBook::runCommand()
{
	if (isEnd())
		return ;
	if (this->input == ADD)
	{
		runAddCommand();
		return ;
	}
	if (this->input == SEARCH)
	{
		runSearchCommand();
		return ;
	}
	std::cout << RED " *** Note that the phonebook program only accepts" << std::endl 
		<< "(1)ADD, (2)SEARCH and (3)EXIT. Try again. ***" << std::endl;
}

bool	PhoneBook::isEnd()
{
	return (this->input == EXIT || std::cin.eof());
}

void	PhoneBook::startProgram()
{
	std::cout << "----------START PHONEBOOK PROGRAM----------" << std::endl;
	while (!isEnd())
	{
		askInput();
		runCommand();
		std::cout << WHITE << std::endl;
	}
	std::cout << "----------END PHONEBOOK PROGRAM----------" << std::endl;
}
