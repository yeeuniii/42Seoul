#pragma once
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"
#include <string>

class ScavTrap: public ClapTrap
{
	private:
		bool	gateKeeperMode;

	public:
		ScavTrap();
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &scavTrap);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap &scavTrap);

		void	guardGate() const;
};

#endif