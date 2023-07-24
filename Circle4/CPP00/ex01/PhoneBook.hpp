#pragma once
#ifndef _PHONEBOOK_H__
#define _PHONEBOOK_H__

#include "Contact.hpp"
#include <string>

class PhoneBook
{
	private:
		Contact		contacts[8];
		int			size;
		std::string	input;
			
		void	askInput();
		void	runCommand();

		void	runAddCommand();
		Contact	askContact();
		void	addContact(Contact contact);

		void	runSearchCommand() const;
		void	displayContacts() const;

		bool	isEnd();
		int		getIndex() const;
		void	searchContact(int index) const;
		bool	isValidIndex(int index) const;

	public:
		PhoneBook();

		void	startProgram();
		static std::string	conformToFormat(std::string string);
};

#endif
