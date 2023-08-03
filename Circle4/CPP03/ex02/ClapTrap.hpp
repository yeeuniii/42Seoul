#pragma once
#ifndef __ClapTrap_HPP__
#define __ClapTrap_HPP__

#include <string>

class ClapTrap
{
	protected:
		std::string	name;
		unsigned int	hitPoint;
		unsigned int	energyPoint;
		unsigned int	attackDamage;
		
		bool	checkAlive();
		bool	checkEnergy();
	
	public:
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& clapTrap);
		virtual	~ClapTrap(void);
		ClapTrap& operator=(ClapTrap const& clapTrap);

		std::string		getName() const;
		unsigned int	getAttackDamage() const;
		void			setAttackDamage(unsigned int amount);

		virtual void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	displayStatus() const;
};

#endif