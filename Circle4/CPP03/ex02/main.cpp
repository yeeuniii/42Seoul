#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "----------TEST1----------" << std::endl;
	{
		FragTrap	fragtrap;

		fragtrap.displayStatus();
		fragtrap.highFivesGuys();
	}
	return 0;
}