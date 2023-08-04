#pragma once
#ifndef __DiamondTrap_HPP__
#define __DiamondTrap_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

#define D_COLOR "\e[0;34m"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	name;

	public:
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap& diamondTrap);
		virtual ~DiamondTrap(void);
		DiamondTrap& operator=(DiamondTrap const& diamondTrap);

		void	whoAmI() const;
};

#endif