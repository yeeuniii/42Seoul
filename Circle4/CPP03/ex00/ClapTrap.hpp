#pragma once
#ifndef __ClapTrap_HPP__
#define __ClapTrap_HPP__

#include <string>

class ClapTrap
{
	private:
		std::string	name;
		unsigned int	hitPoint;
		unsigned int	energyPoint;
		unsigned int	attackDamage;
		
	public:
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& clapTrap);
		~ClapTrap(void);
		ClapTrap& operator=(ClapTrap const& clapTrap);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

};

#endif