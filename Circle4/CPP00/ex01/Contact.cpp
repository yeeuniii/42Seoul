#include "Contact.hpp"
#include <iostream>

Contact::Contact()
{
	memset(this->fields, 0, sizeof(std::string) * 5);
}

int		Contact::is_valid() const
{
	int	idx = 0;

	while (idx < 5 && this->fields[idx].size())
		idx++;
	return (idx == 5);
}

void	Contact::set_fields()
{
	for (int idx = 0; idx < 5; idx++)
	{
		std::cout << get_fields_name(idx) << " : ";
		std::cin >> this->fields[idx];
	}
}

void	Contact::display_fields() const
{
	for (int idx = 0; idx < 5; idx++)
	{
		std::cout << get_fields_name(idx) << " : ";
		std::cout << this->fields[idx] << std::endl;
	}
}

std::string	Contact::get_fields_name(int idx)
{
	std::string	field_string[5] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};

	return field_string[idx];
}

void	Contact::print_to_format(int idx) const
{
	std::string	field = this->fields[idx];

	if (field.size() > 10)
	{
		std::cout << field.substr(0, 9) << ".";
		return ;
	}
	std::cout << std::string(10 - field.size(), ' ') << field;
}
