#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "----------TEST----------" << std::endl;
	{
		FragTrap	fragtrap;

		// fragtrap.takeDamage(100);
		// fragtrap.beRepaired(10);
		fragtrap.displayStatus();
		fragtrap.highFivesGuys();
	}
	return 0;
}