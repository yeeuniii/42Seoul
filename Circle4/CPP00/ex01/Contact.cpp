#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>
#include <cstring>

Contact::Contact()
{
	memset(this->fields, 0, sizeof(std::string) * 5);
}

int		Contact::is_valid() const
{
	int	idx = 0;

	while (idx < 5 && !is_whitespace_string(this->fields[idx]))
		idx++;
	return (idx == 5);
}

void	Contact::set_fields()
{
	for (int idx = 0; idx < 5; idx++)
	{
		std::cout << get_field_name(idx) << " : ";
		getline(std::cin, this->fields[idx]);
	}
}

void	Contact::display_fields() const
{
	for (int idx = 0; idx < 5; idx++)
	{
		std::cout << get_field_name(idx) << " : ";
		std::cout << this->fields[idx] << std::endl;
	}
}

std::string	Contact::get_field_name(int idx)
{
	std::string	field_string[5] = {"First name", "Last name", "Nickname", "Phone number", "Darkest secret"};

	return field_string[idx];
}

std::string	Contact::get_format_field(int idx) const
{
	std::string	field = this->fields[idx];
	std::string	format_field;

	if (field.size() > 10)
		format_field = field.substr(0, 9) + ".";
	format_field = std::string(10 - field.size(), ' ') + field;
	return format_field;
}