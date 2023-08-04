#pragma once
#ifndef __FRAGTRAP_H__
#define __FRAGTRAP_H__

#include "ClapTrap.hpp"
#include <string>

#define	F_COLOR	"\e[0;35m"

class FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &fragTrap);
		virtual	~FragTrap();
		FragTrap&	operator=(const FragTrap &fragTrap);

		void	highFivesGuys(void) const;
};

#endif