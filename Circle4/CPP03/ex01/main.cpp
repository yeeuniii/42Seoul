#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap	scavtrap1("one");
	ScavTrap	scavtrap2("two");

	scavtrap1.guardGate();
	scavtrap1.guardGate();
	return 0;
}