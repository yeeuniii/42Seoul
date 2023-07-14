#include "PhoneBook.hpp"
#include <string>
#define WHITE "\e[0m"
#define RED "\e[0;31m"

PhoneBook::PhoneBook()
{
	memset(this->contacts, 0, sizeof(Contact) * 8);
	size = 0;
	input = None;
}

void	PhoneBook::set_input(std::string input)
{
	std::string	command_numbers[3] = {"1", "2", "3"};
	int	idx = 0;

	while (idx < 3 && input != command_numbers[idx])
		idx++;
	if (idx == 3)
		return ;
	this->input = type(idx + 1);
}

type	PhoneBook::get_input() const
{
	return (this->input);
}

void	PhoneBook::ask_input()
{
	std::string	input;

	std::cout << WHITE "Enter one number of below commands." << std::endl;
	std::cout << "(1)ADD, (2)SEARCH and (3)EXIT." << std::endl;
	std::cout << "Input : ";
	std::cin >> input;
	set_input(input);
}

void	PhoneBook::add_contact(Contact contact)
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

void	PhoneBook::run_add()
{
	Contact	contact;

	contact.set_fields();
	add_contact(contact);
}

//void	PhoneBook::run_search()
//{
//	display_contacts();
//	search_constact();
//}

void	PhoneBook::handle_input()
{
	if (this->input == ADD)
	{
		run_add();
		return ;
	}
//	if (this->input == SEARCH)
//	{
//		run_search();
//		return ;
//	}
	std::cout << RED " *** Note that the phonebook program only accepts"
		<< std::endl << "(1)ADD, (2)SEARCH and (3)EXIT. Try again. ***" << std::endl;
}

void	PhoneBook::run_program()
{
	std::cout << "---------START PHONEBOOK PROGRAM---------" << std::endl;
	ask_input();
	while (this->input != EXIT)
	{
		handle_input();
		std::cout << std::endl;
		ask_input();
	}
	std::cout << "---------END  PHONEBOOK  PROGRAM---------" << std::endl;
}	

