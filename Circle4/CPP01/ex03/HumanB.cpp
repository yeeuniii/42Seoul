#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = 0;
}

void	HumanB::attack() const
{
	if (!this->weapon)
	{
		std::cout << this->name << " has no weapon!" << std::endl;
		return ;	
	}	
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}