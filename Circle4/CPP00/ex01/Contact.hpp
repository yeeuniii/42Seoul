#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>

class Contact 
{
	private:
		std::string	fields[5];
	
	public:
		Contact();
		
		int		is_valid() const;
		void	set_fields();
		void	display_fields() const;
		std::string	get_format_field(int idx) const;

		static std::string	get_field_name(int idx);
};

#endif
