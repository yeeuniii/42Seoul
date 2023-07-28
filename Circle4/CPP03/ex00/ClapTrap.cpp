#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void): name("anonymous"), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string name): hitPoint(10), energyPoint(10), attackDamage(0)
{
	this->name = name;
	std::cout << "ClapTrap " << this->name << " construct" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	this->name = clapTrap.name;
	this->hitPoint = clapTrap.hitPoint;
	this->energyPoint = clapTrap.energyPoint;
	this->attackDamage = clapTrap.attackDamage;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " destruct" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& clapTrap)
{
	if (this != &clapTrap)
	{
		this->name = clapTrap.name;
		this->hitPoint = clapTrap.hitPoint;
		this->energyPoint = clapTrap.energyPoint;
		this->attackDamage = clapTrap.attackDamage;
	}
	return *this;
}