#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
	memset(this->contacts, 0, sizeof(Contact) * 8);
	this->size = 0;
	this->input = None;
}

// void	PhoneBook::run_add_command()
// {



// }

// void	PhoneBook::ask_contact()
// {
// 	Contact	contact;
// 	std::string	tmp;

// 	std::cout << "First name : ";
// 	getline(std::cin, tmp);

// }

void	PhoneBook::run_search_command() const
{
	int	index;

	display_contacts();
	index = get_index();
	if (std::cin.eof())
		return ;
	search_contact(index);
}

void	PhoneBook::display_contacts() const
{
	std::string		format_fields[3];
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
		std::cout << "|" << std::setw(10) << conform_to_format(contact.get_first_name());
		std::cout << "|" << std::setw(10) << conform_to_format(contact.get_first_name());
		std::cout << "|" << std::setw(10) << conform_to_format(contact.get_first_name());
		std::cout << "|"  << std::endl;
	}
	std::cout << std::string(45, '-') << std::endl;
}

std::string	PhoneBook::conform_to_format(std::string str) 
{
	std::string	new_;

	if (str.size() > 10)
		return str;
	new_ = str.substr(0, 9) + ".";
	return new_;
}

void	PhoneBook::search_contact(int index) const
{
	if (is_valid_index(index))
	{
		std::cout << RED "The index of contacts range from 0 to 7." << std::endl;
		return ;
	}
	this->contacts[index].display();
}

int	PhoneBook::get_index() const
{
	std::string	index;

	std::cout << BLUE "Enter index of contacts to display : ";
	std::getline(std::cin, index);
	if (std::cin.eof() || !is_digit_string(index))
		return -1;
	return convert_str_to_int(index);
}

int		PhoneBook::is_valid_index(int index) const
{
	return (index >= 0 && index < this->size);
}

void	PhoneBook::ask_input()
{
	std::string	input_value;

	std::cout << WHITE "Enter one number of below commands." << std::endl;
	std::cout << "(1)ADD, (2)SEARCH and (3)EXIT." << std::endl;
	std::cout << "Input : ";
	getline(std::cin, input_value);
	set_input(input_value);
}

void	PhoneBook::set_input(std::string input)
{
	int	number = convert_str_to_int(input);

	this->input = None;
	if (number >= 1 && number <= 3)
		this->input = type(number);
}

void	PhoneBook::run_command()
{
	if (is_end())
		return ;
	if (this->input == ADD)
	{
	//	run_add_command();
		return ;
	}
	if (this->input == SEARCH)
	{
		run_search_command();
		return ;
	}
	std::cout << RED " *** Note that the phonebook program only accepts" << std::endl 
		<< "(1)ADD, (2)SEARCH and (3)EXIT. Try again. ***" << std::endl;
}

int		PhoneBook::is_end()
{
	return (this->input == EXIT || std::cin.eof());
}

void	PhoneBook::start_program()
{
	std::cout << "----------START PHONEBOOK PROGRAM----------" << std::endl;
	while (!is_end())
	{
		ask_input();
		run_command();
		std::cout << std::endl;
	}
	std::cout << "----------END PHONEBOOK PROGRAM----------" << std::endl;
}