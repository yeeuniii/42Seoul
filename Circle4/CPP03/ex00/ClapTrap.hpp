#pragma once
#ifndef __ClapTrap_HPP__
#define __ClapTrap_HPP__

#include <string>

#define WHITE "\e[0;37m"
#define C_COLOR "\e[0;32m"

class ClapTrap
{
	private:
		std::string	name;
		unsigned int	hitPoint;
		unsigned int	energyPoint;
		unsigned int	attackDamage;
		
		bool	checkAlive() const;
		bool	checkEnergy() const;
	
	public:
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& clapTrap);
		~ClapTrap(void);
		ClapTrap& operator=(const ClapTrap& clapTrap);

		std::string		getName() const;
		unsigned int	getAttackDamage() const;
		void			setAttackDamage(unsigned int amount);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	displayStatus() const;
};

#endif
