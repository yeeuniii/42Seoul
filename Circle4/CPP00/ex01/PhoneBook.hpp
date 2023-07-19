#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"
#include <string>

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

		void	start_program();
		int		is_end();
		
		void	set_input(std::string input);
		void	ask_input();

		void	run_command();

		void	run_add_command();
		Contact	ask_contact();
		void	add_contact(Contact contact);

		void	run_search_command() const;
		void	display_contacts() const;

		int		get_index() const;
		void	search_contact(int index) const;
		int		is_valid_index(int index) const;


		static std::string	conform_to_format(std::string str);

};

#endif
