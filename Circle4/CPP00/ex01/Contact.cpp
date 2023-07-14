#include "Contact.hpp"
#include <string>

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
	std::string	field_string[5] = {"first name", "last name", "nickname", "phone number", "darkest secret"};

	for (int idx = 0; idx < 5; idx++)
	{
		std::cout << "Input " << field_string[idx] << " : ";
		std::cin >> this->fields[idx];
	}
}

void	Contact::display_fields() const
{
	for (int idx = 0; idx < 5; idx++)
		std::cout << this->fields[idx] << std::endl;
}
