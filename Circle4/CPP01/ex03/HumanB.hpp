#pragma once
#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon		*weapon;
		std::string	name;
	
	public:
		HumanB(std::string name);
		
		void	setWeapon(Weapon &weapon);
		void	attack() const;
};

#endif
