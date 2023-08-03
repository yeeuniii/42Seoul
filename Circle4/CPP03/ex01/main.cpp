#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap	scavtrap1("one");
	ScavTrap	scavtrap2;
	ScavTrap	scavtrap3(scavtrap1);

	return 0;
}