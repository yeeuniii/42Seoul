#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	this->name = "anonymous";
	std::cout << "Zombie " << this->name << " construct." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie " << this->name << " construct." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " destruct." << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
