#pragma once
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"
#include <string>

#define S_COLOR "\e[0;33m"
#define S_ENERGY 50

class ScavTrap: virtual public ClapTrap
{
	private:
		bool	gateKeeperMode;

		bool	isGateKeeper() const;

	public:
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &scavTrap);
		virtual	~ScavTrap();
		ScavTrap& operator=(const ScavTrap &scavTrap);

		virtual void	attack(const std::string &target);
		void	guardGate();
};

#endif