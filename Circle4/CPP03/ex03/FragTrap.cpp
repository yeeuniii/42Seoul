#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	this->name = "anonymous";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << F_COLOR << "FragTrap ";
	std::cout << WHITE << this->name << " construct by default." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
	std::cout << F_COLOR << "FragTrap ";
	std::cout << WHITE << this->name << " construct." << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) : ClapTrap(fragTrap)
{
	*this = fragTrap;
	std::cout << F_COLOR << "FragTrap ";
	std::cout << WHITE << this->name << " construct." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << F_COLOR << "FragTrap ";
	std::cout << WHITE << this->name << " destruct." << std::endl;
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

void	FragTrap::highFivesGuys() const
{
	if (!checkAlive())
		return ;
	std::cout << F_COLOR << "FragTrap ";
	std::cout << WHITE << this->name << " slaps High Five!! 🙌" << std::endl;
}