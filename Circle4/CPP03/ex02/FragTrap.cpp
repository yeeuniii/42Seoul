#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	this->name = "anonymous";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "FlagTrap " << this->name << " construct by default." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << "FlagTrap " << this->name << " construct." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
	this->name = fragTrap.name;
	this->hitPoint = fragTrap.hitPoint;
	this->energyPoint = fragTrap.energyPoint;
	this->attackDamage = fragTrap.attackDamage;
	std::cout << "FlagTrap " << this->name << " construct." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " destruct." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &fragTrap)
{
	if (this != &fragTrap)
	{
		this->name = fragTrap.name;
		this->hitPoint = fragTrap.hitPoint;
		this->energyPoint = fragTrap.energyPoint;
		this->attackDamage = fragTrap.attackDamage;
	}
	return *this;
}