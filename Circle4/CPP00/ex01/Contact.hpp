#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

class Contact 
{
	private:
		std::string	fields[5];
	
	public:
		Contact();
		
		int		is_valid() const;
		void	set_fields();
		void	display_fields() const;
};

#endif
