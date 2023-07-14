#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <iostream>

typedef	enum e_type
{
	None,
	ADD,
	SEARCH,
	EXIT
}	type;

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		size;
		type	input;
	
	public:
		PhoneBook();

		void	run_program();
		void	run_add();
		void	run_search();
		void	add_contact(Contact contact);
	//	void	search_contact();
	//	void	display_contacts() const;
		void	set_input(std::string input);
		type	get_input() const;
		void	ask_input();
		void	handle_input();
};

#endif
