#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void): name("anonymous"), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << C_COLOR << "ClapTrap ";
	std::cout << WHITE << this->name << " construct by default." << std::endl;
}

ClapTrap::ClapTrap(const std::string name): hitPoint(10), energyPoint(10), attackDamage(0)
{
	this->name = name;
	std::cout << C_COLOR << "ClapTrap ";
	std::cout << WHITE << this->name << " construct." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	*this = clapTrap;
	std::cout << C_COLOR << "ClapTrap ";
	std::cout << WHITE << this->name << " construct." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << C_COLOR << "ClapTrap ";
	std::cout << WHITE << this->name << " destruct." << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& clapTrap)
{
	if (this != &clapTrap)
	{
		this->name = clapTrap.getName();
		this->hitPoint = clapTrap.hitPoint;
		this->energyPoint = clapTrap.energyPoint;
		this->attackDamage = clapTrap.getAttackDamage();
	}
	return *this;
}

bool	ClapTrap::checkAlive() const
{
	if (this->hitPoint == 0)
	{
		std::cout << C_COLOR << "ClapTrap ";
		std::cout << WHITE << this->name << " is died." << std::endl; 	
	}
	return this->hitPoint;
}

bool	ClapTrap::checkEnergy() const
{
	if (this->energyPoint == 0)
	{
		std::cout << C_COLOR << "ClapTrap ";
		std::cout << WHITE << this->name << " has no energy." << std::endl; 	
	}
	return this->energyPoint;
}

std::string	ClapTrap::getName() const
{
	return this->name;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return this->attackDamage;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	this->attackDamage = amount;
}

void	ClapTrap::attack(const std::string &target)
{
	if (!(checkAlive() && checkEnergy()))
		return ;
	this->energyPoint--;
	std::cout << C_COLOR << "ClapTrap ";
	std::cout << WHITE << this->name << " attacks " << target 
			<< ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!checkAlive())
		return ;
	this->hitPoint -= this->hitPoint < amount ? this->hitPoint : amount;
	std::cout << C_COLOR << "ClapTrap ";
	std::cout << WHITE << this->name 
			<< " takes damage " << amount << " points, then "
			<< this->hitPoint << " hit points left." << std::endl; 
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!(checkAlive() && checkEnergy()))
		return ;
	this->hitPoint += amount;
	this->energyPoint--;
	std::cout << C_COLOR << "ClapTrap ";
	std::cout << WHITE << this->name << " be repaired " 
			<< amount << " points, then " 
			<< this->hitPoint << " hit points left." << std::endl; 
}

void	ClapTrap::displayStatus() const
{
	std::cout << C_COLOR << "ClapTrap ";
	std::cout << WHITE << this->name << " has " 
			<< this->hitPoint << " hit point, "
			<< this->energyPoint << " energy point, and "
			<< this->attackDamage << " attack damage." << std::endl;
}