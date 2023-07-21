#pragma once
#ifndef _PHONEBOOK_H__
#define _PHONEBOOK_H__

#include "Contact.hpp"
#include <string>

typedef	enum e_type
{
	None,
	ADD,
	SEARCH,
	EXIT
}	Type;

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		size;
		Type	input;
	
	public:
		PhoneBook();

		void	startProgram();
		int		isEnd();
		
		void	setInput(std::string input);
		void	askInput();

		void	runCommand();

		void	runAddCommand();
		Contact	askContact();
		void	addContact(Contact contact);

		void	runSearchCommand() const;
		void	displayContacts() const;

		int		getIndex() const;
		void	searchContact(int index) const;
		int		isValidIndex(int index) const;


		static std::string	conformToFormat(std::string string);

};

#endif
