#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	this->name = "anonymous";
	this->energyPoint = S_ENERGY;
	std::cout << D_COLOR << "DiamondTrap ";
	std::cout << WHITE << this->name << " construct by default." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	this->energyPoint = S_ENERGY;
	std::cout << D_COLOR << "DiamondTrap ";
	std::cout << WHITE << this->name << " construct." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap)
{
	*this = diamondTrap;
	std::cout << D_COLOR << "DiamondTrap ";
	std::cout << WHITE << this->name << " construct." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << D_COLOR << "DiamondTrap ";
	std::cout << WHITE << this->name << " destruct." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& diamondTrap)
{
	if (this != &diamondTrap)
	{
		this->name = diamondTrap.name;
		this->hitPoint = diamondTrap.hitPoint;
		this->energyPoint = diamondTrap.energyPoint;
		this->attackDamage = diamondTrap.energyPoint;
	}
	return *this;
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "My name is " << D_COLOR << this->name;
	std::cout << WHITE << " ,but my grandmother ClapTrap`s name is ";
	std::cout << C_COLOR << ClapTrap::name << "." << std::endl;
}