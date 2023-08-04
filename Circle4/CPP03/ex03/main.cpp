#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "----------TEST----------" << std::endl;
	{
		DiamondTrap	diamondtrap("DDD");
		FragTrap	fragtrap("FFF");

		diamondtrap.displayStatus();
		diamondtrap.attack(fragtrap.getName());		
	}
	return 0;
}