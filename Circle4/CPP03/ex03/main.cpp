#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "----------TEST----------" << std::endl;
	{
		DiamondTrap	diamondtrap("DDD");
		FragTrap	fragtrap("FFF");

		diamondtrap.displayStatus();
		fragtrap.displayStatus();
		diamondtrap.attack(fragtrap.getName());
		fragtrap.attack(diamondtrap.getName());
		diamondtrap.whoAmI();	
	}
	return 0;
}