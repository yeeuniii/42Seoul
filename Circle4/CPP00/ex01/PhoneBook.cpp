#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	memset(this->contacts, 0, sizeof(Contact) * 8);
	this->size = 0;
	this->input = None;
}

void	PhoneBook::set_input(std::string input)
{
	int	number = convert_str_to_int(input);

	this->input = None;
	if (number >= 1 && number <= 3)
		this->input = type(number);
}

type	PhoneBook::get_input() const
{
	return (this->input);
}

void	PhoneBook::run_add()
{
	Contact	contact;

	std::cout << BLUE "All fields of contact CANNOT be empty." << std::endl;
	contact.set_fields();
	add_contact(contact);
}

void	PhoneBook::add_contact(Contact contact)
{
	if (!contact.is_valid())
	{
		std::cout << RED "Contact entered has empty fields" << std::endl;
		return ;
	}
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

void	PhoneBook::run_search() const
{
	display_contacts();
	search_contact();
}

void	PhoneBook::display_contacts() const
{
	std::string		format_fields[3];
	Contact			contact;

	std::cout << std::string(45, '-') << std::endl;
	std::cout << "|" << std::string(5, ' ') << "index";
	std::cout << "|" << "first name";
	std::cout << "|" << std::string(1, ' ') << "last name";
	std::cout << "|" << std::string(2, ' ') << "nickname";
	std::cout << "|" << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	for (int idx = 0; idx < 8; idx++)
	{
		contact = this->contacts[idx];
		std::cout << "|" << std::string(9, ' ') << idx;
		std::cout << "|";
		contact.print_to_format(0);
		std::cout << "|";
		contact.print_to_format(1);
		std::cout << "|";
		contact.print_to_format(2);
		std::cout << "|"  << std::endl;
	}
	std::cout << std::string(45, '-') << std::endl;
}

void	PhoneBook::search_contact() const
{
	std::string	input;
	int			index;

	std::cout << BLUE "Enter index of contacts to display : ";
	getline(std::cin, input);
	index = convert_str_to_int(input);
	if ((index < 0 || index > 8) || (index == 0 && input != "0"))
	{
		std::cout << RED "The index of contacts range from 0 to 7." << std::endl;
		return ;
	}
	this->contacts[index].display_fields();
}

void	PhoneBook::handle_input()
{
	if (this->input == ADD)
	{
		run_add();
		return ;
	}
	if (this->input == SEARCH)
	{
		run_search();
		return ;
	}
	std::cout << RED " *** Note that the phonebook program only accepts" << std::endl 
		<< "(1)ADD, (2)SEARCH and (3)EXIT. Try again. ***" << std::endl;
}

void	PhoneBook::ask_input()
{
	std::string	input;

	std::cout << WHITE "Enter one number of below commands." << std::endl;
	std::cout << "(1)ADD, (2)SEARCH and (3)EXIT." << std::endl;
	std::cout << "Input : ";
	getline(std::cin, input);
	set_input(input);
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

