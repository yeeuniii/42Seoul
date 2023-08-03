#pragma once
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"
#include <string>

class ScavTrap: public ClapTrap
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