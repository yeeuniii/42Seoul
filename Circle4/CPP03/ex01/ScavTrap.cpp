#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap()
{
	this->name = "anonymous";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
	std::cout << S_COLOR << "ScavTrap ";
	std::cout << WHITE << this->name << " construct by default." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
	std::cout << S_COLOR << "ScavTrap ";
	std::cout << WHITE << this->name << " construct." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap): ClapTrap()
{
	*this = scavTrap;
	std::cout << S_COLOR << "ScavTrap ";
	std::cout << WHITE << this->name << " construct." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << S_COLOR << "ScavTrap ";
	std::cout << WHITE << this->name << " destruct." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &scavTrap)
{
	this->name = scavTrap.name;
	this->hitPoint = scavTrap.hitPoint;
	this->energyPoint = scavTrap.energyPoint;
	this->attackDamage = scavTrap.attackDamage;
	return *this;
}

bool	ScavTrap::checkAlive() const
{
	if (this->hitPoint == 0)
	{
		std::cout << S_COLOR << "ScavTrap ";
		std::cout << WHITE << this->name << " is died." << std::endl; 	
	}
	return this->hitPoint;
}

bool	ScavTrap::checkEnergy() const
{
	if (this->energyPoint == 0)
	{
		std::cout << S_COLOR << "ScavTrap ";
		std::cout << WHITE << this->name << " has no energy." << std::endl; 	
	}
	return this->energyPoint;
}

void	ScavTrap::attack(const std::string &target)
{
	if (!(checkAlive() && checkEnergy()))
		return ;
	this->energyPoint--;
	std::cout << S_COLOR << "ScavTrap ";
	std::cout << WHITE << this->name << " attacks " << target 
			<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

bool	ScavTrap::isGateKeeper() const
{
	if (gateKeeperMode)
	{
		std::cout << S_COLOR << "ScavTrap ";
		std::cout << WHITE << this->name << " is already gatekeeper." << std::endl;
	}
	return gateKeeperMode;
}

void	ScavTrap::guardGate()
{
	if (!(checkAlive() && checkEnergy()) || isGateKeeper())
		return ;
	this->gateKeeperMode = true;
	this->energyPoint--;
	std::cout << S_COLOR << "ScavTrap ";
	std::cout << WHITE << this->name << " is now in gatekeeper mode." << std::endl;
}